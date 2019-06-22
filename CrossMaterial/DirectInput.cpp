#include "DirectInput.h"

//グローバル
LPDIRECTINPUT8			g_pDinput;							//DirectInputオブジェクト
LPDIRECTINPUTDEVICE8	g_pKeyDevice;						//DirectInputDeviceのオブジェクト(キーボード)
LPDIRECTINPUTDEVICE8	g_pJoyDevice[MAX_PAD];				//DirectInputDeviceのオブジェクト(ジョイパッド)
BYTE					g_keyState[256];					//キー情報格納用配列
DIJOYSTATE2				g_joyState[MAX_PAD];				//ジョイパッド情報格納用配列
POINT					g_joyPosition[MAX_PAD];				//ジョイスティックの指している座標
KEY_DATA				g_keyBoardState;					//キーの状態(キーボード)
KEY_DATA				g_joyKeyState[MAX_PAD];				//キーの状態(ジョイパッド)
static long				g_joyPadNum;						//接続されているジョイパッドの番号
DWORD					g_joyStickCount , g_joyStickMax;	//ジョイスティックの数と限界数
JOY_DATA				g_joy;
bool					g_polling[MAX_PAD];					//ポーリング
bool					g_joyPadFlag;

HRESULT InitDinput(HWND a_hWnd)
{
	//初期化
	g_pDinput = NULL;
	g_pKeyDevice = NULL;
	g_joyPadNum = 0;
	g_joyPadFlag = false;

	ZeroMemory(&g_keyBoardState , sizeof(KEY_DATA));

	for(long i = 0 ; i < MAX_PAD ; i++)
	{
		ZeroMemory(&g_joyState[i],sizeof(DIJOYSTATE2));
		g_pJoyDevice[i] = NULL;
	}

	HRESULT hr = S_OK;

	//「DirectInput」オブジェクトの作成
	if(FAILED(hr = DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,IID_IDirectInput8,(void**)&g_pDinput,NULL)))
	{
		MessageBox(NULL,TEXT("「DirectInput」オブジェクトの作成に失敗"),NULL,MB_OK);
		return hr;
	}

	//キーボード初期化
	if(FAILED(hr = InitKeyBoard(a_hWnd)))
	{
		MessageBox(NULL,TEXT("キーボードの初期化に失敗"),NULL,MB_OK);
		return hr;
	}

	//ジョイパッド初期化
	if(FAILED(hr = InitJoyPad(a_hWnd)))
	{
		MessageBox(NULL,TEXT("ジョイパッドの初期化に失敗"),NULL,MB_OK);
		return hr;
	}

	return S_OK;
}

HRESULT InitKeyBoard(HWND a_hWnd)
{
	//キーデバイスオブジェクトの作成
	if(FAILED(g_pDinput->CreateDevice(GUID_SysKeyboard,&g_pKeyDevice,NULL)))
	{
		return E_FAIL;
	}

	//デバイスをキーボードに設定
	if(FAILED(g_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//協調レベルの設定
	if(FAILED(g_pKeyDevice->SetCooperativeLevel(a_hWnd ,DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return E_FAIL;
	}

	//デバイスを「取得」する
	g_pKeyDevice->Acquire();
	return S_OK;
}

HRESULT InitJoyPad(HWND a_hWnd)
{
	//使用可能なジョイスティックの数
	g_joyStickMax = joyGetNumDevs();
	if(g_joyStickMax >= 4) g_joyStickMax = 4;

	g_joyStickCount = 0;
	g_joy.joyStickCount = &g_joyStickCount;
	g_joy.joyStickMax = &g_joyStickMax;
	g_joy.joyDevice = g_pJoyDevice;
	g_joy.dInput	= g_pDinput;
	//利用可能なゲームコントローラーの列挙関数を実行
	if(FAILED(g_pDinput->EnumDevices(DI8DEVCLASS_GAMECTRL, EnumJoysticksCallback , (VOID*)&g_joy,
		DIEDFL_ATTACHEDONLY)))
	{
		return E_FAIL;
	}

	for(long i = 0 ; i < MAX_PAD ; i++)
	{
		if(g_pJoyDevice[i])
		{
			//デバイスをジョイスティックに設定
			if(FAILED(g_pJoyDevice[i]->SetDataFormat(&c_dfDIJoystick2)))
			{
				return E_FAIL;
			}
			//協調レベルの設定
			if(FAILED(g_pJoyDevice[i]->SetCooperativeLevel(a_hWnd,DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
			{
				return E_FAIL;
			}
			//軸モード設定
			if(FAILED(g_pJoyDevice[i]->EnumObjects(EnumObjectsCallback , (void*)g_pJoyDevice[i],DIDFT_AXIS)))
			{
				return E_FAIL;
			}

			//デバイス情報取得
			DIDEVCAPS caps = {sizeof(DIDEVCAPS)};
			g_pJoyDevice[i]->GetCapabilities(&caps);

			//ポーリングが必要かどうか調べる
			if(caps.dwFlags & (DIDC_POLLEDDATAFORMAT & DIDC_POLLEDDEVICE))
			{
				g_polling[i] = true;
			}
			else
			{
				g_polling[i] = false;
			}

			//デバイスを取得
			g_pJoyDevice[i]->Acquire();
			g_joyPadFlag = true;	//ジョイパッドがつながれているのでtrueにする
		}
	}
	return S_OK;
}

BOOL CALLBACK EnumJoysticksCallback( const DIDEVICEINSTANCE * a_pdidInstance , void * a_pContext)
{
	JOY_DATA * pJoy = ((JOY_DATA *)a_pContext);
	DWORD * jCount = pJoy->joyStickCount;
	DWORD * jMaxCount = pJoy->joyStickMax;

	//デバイスの作成
	HRESULT hr = pJoy->dInput->CreateDevice(a_pdidInstance->guidInstance,&pJoy->joyDevice[*jCount] , NULL);
	
	if SUCCEEDED(hr)
	{
		return (++(*jCount) == (*jMaxCount))?(DIENUM_STOP):(DIENUM_CONTINUE);
	}
	return DIENUM_STOP;
}

BOOL CALLBACK EnumObjectsCallback( const DIDEVICEOBJECTINSTANCE * a_pdidoi , void * a_pContext)
{
	LPDIRECTINPUTDEVICE8 pJoy = (LPDIRECTINPUTDEVICE8)a_pContext;

	DIPROPRANGE diprg;

	diprg.diph.dwSize		= sizeof(DIPROPRANGE);
	diprg.diph.dwHeaderSize	= sizeof(DIPROPRANGE);
	diprg.diph.dwHow		= DIPH_BYID;
	diprg.diph.dwObj		= a_pdidoi->dwType;
	diprg.lMin				= -1000;
	diprg.lMax				= 1000;

	if(FAILED(pJoy->SetProperty(DIPROP_RANGE , &diprg.diph)))
	{
		return DIENUM_STOP;
	}

	return DIENUM_CONTINUE;
}

bool GetKeyBoardData(DWORD a_key)
{
	if(g_keyState[a_key] & 0x80)
	{
		return true;
	}
	return false;
}

bool GetJoyPadData(DWORD a_key , long a_joyID)
{
	if(a_key >= JOY_KEY_BOTTON1 && a_key <= JOY_KEY_BOTTON8)
	{
		if(g_joyState[a_joyID].rgbButtons[a_key] & 0x80)
		{
			return true;
		}
	}

	if(a_key >= JOY_KEY_UP && a_key <= JOY_KEY_RIGHT)
	{
		switch(a_key)
		{
		case JOY_KEY_UP:
			if(g_joyState[a_joyID].lY < 0x7FFF)
			{
				return true;
			}
			break;
		case JOY_KEY_DOWN:
			if(g_joyState[a_joyID].lY > 0x7FFF)
			{
				return true;
			}
			break;
		case JOY_KEY_LEFT:
			if(g_joyState[a_joyID].lX < 0x7FFF)
			{
				return true;
			}
			break;
		case JOY_KEY_RIGHT:
			if(g_joyState[a_joyID].lX > 0x7FFF)
			{
				return true;
			}
			break;
		}
	}
	return false;
}

void LimitJoyPadKey(void)
{
	DWORD key = 0;	//今のキーの状態

	static DWORD oldKeyState[MAX_PAD];

	for(long i = 0 ; i < MAX_PAD ; i++)
	{
		//key = 0;
		if(GetJoyPadData(JOY_KEY_UP,i))			{ key |= PAD_KEY_UP;		}			//上キー
		if(GetJoyPadData(JOY_KEY_DOWN,i))		{ key |= PAD_KEY_DOWN;		}			//下キー
		if(GetJoyPadData(JOY_KEY_LEFT,i))		{ key |= PAD_KEY_LEFT;		}			//左キー
		if(GetJoyPadData(JOY_KEY_RIGHT,i))		{ key |= PAD_KEY_RIGHT;		}			//右キー
		if(GetJoyPadData(JOY_KEY_BOTTON1,i))	{ key |= PAD_KEY_BOTTON1;	}			//ボタン１
		if(GetJoyPadData(JOY_KEY_BOTTON2,i))	{ key |= PAD_KEY_BOTTON2;	}			//ボタン２
		if(GetJoyPadData(JOY_KEY_BOTTON3,i))	{ key |= PAD_KEY_BOTTON3;	}			//ボタン３
		if(GetJoyPadData(JOY_KEY_BOTTON4,i))	{ key |= PAD_KEY_BOTTON4;	}			//ボタン４
		if(GetJoyPadData(JOY_KEY_BOTTON5,i))	{ key |= PAD_KEY_BOTTON5;	}			//ボタン５
		if(GetJoyPadData(JOY_KEY_BOTTON6,i))	{ key |= PAD_KEY_BOTTON6;	}			//ボタン６
		if(GetJoyPadData(JOY_KEY_BOTTON7,i))	{ key |= PAD_KEY_BOTTON7;	}			//ボタン７
		if(GetJoyPadData(JOY_KEY_BOTTON8,i))	{ key |= PAD_KEY_BOTTON8;	}			//ボタン８

		//キーが押された時
		g_joyKeyState[i].push		= key & (~oldKeyState[i]);

		//キーが押され続けている時
		g_joyKeyState[i].press		= (oldKeyState[i] & key) | g_joyKeyState[i].push;

		//キーが離された時
		g_joyKeyState[i].release	= (oldKeyState[i] & (~key));

		//キーが離され続けている時
		g_joyKeyState[i].free		= ~g_joyKeyState[i].press;

		//今のキーの状態を渡す
		oldKeyState[i] = key;
	}
}

void LimitKeyBoard(void)
{
	DWORD key = 0;	//今のキーの状態

	static DWORD oldKeyState;	//1つ前のキーの状態

	if(GetKeyBoardData(DIK_UP))		{ key |= KEY_UP;	}				//上キー
	if(GetKeyBoardData(DIK_DOWN))	{ key |= KEY_DOWN;	}				//下キー
	if(GetKeyBoardData(DIK_LEFT))	{ key |= KEY_LEFT;	}				//左キー
	if(GetKeyBoardData(DIK_RIGHT))	{ key |= KEY_RIGHT;	}				//右キー
	if(GetKeyBoardData(DIK_Z))		{ key |= KEY_Z;		}				//Zキー
	if(GetKeyBoardData(DIK_X))		{ key |= KEY_X;		}				//Xキー
	if(GetKeyBoardData(DIK_C))		{ key |= KEY_C;		}				//Cキー
	if(GetKeyBoardData(DIK_V))		{ key |= KEY_V;		}				//Vキー
	if(GetKeyBoardData(DIK_A))		{ key |= KEY_A;		}				//Aキー
	if(GetKeyBoardData(DIK_S))		{ key |= KEY_S;		}				//Sキー
	if(GetKeyBoardData(DIK_R))		{ key |= KEY_R;		}				//Rキー
	if(GetKeyBoardData(DIK_T))		{ key |= KEY_T;		}				//Tキー
	if(GetKeyBoardData(DIK_Q))		{ key |= KEY_Q;		}				//Tキー
	if(GetKeyBoardData(DIK_W))		{ key |= KEY_W;		}				//Tキー
	if(GetKeyBoardData(DIK_SPACE))	{ key |= KEY_SPACE;	}				//Tキー


	//キーが押された時
	g_keyBoardState.push	= key & (~oldKeyState);

	//キーが押され続けている時
	g_keyBoardState.press	= (key & oldKeyState) | g_keyBoardState.push;

	//キーが離された時
	g_keyBoardState.release = (oldKeyState & (~key));

	//キーが離され続けている時
	g_keyBoardState.free	= ~g_keyBoardState.press;

	//今のキーの状態を渡す
	oldKeyState = key;
}

bool CheckKeyBoard(DWORD a_key , DEVICE_MODE a_mode , KEY_STATE a_state)
{
	DWORD keyState = 0;	//キーの状態を格納する変数

	if(a_mode != KEYBOARD)	//モードがキーボードじゃなかったら
	{
		return false;	//強制false
	}

	switch(a_state)
	{
	case KEY_PUSH:			//押された時
		keyState = g_keyBoardState.push;
		break;
	case KEY_PRESS:			//押され続けている時
		keyState = g_keyBoardState.press;
		break;
	case KEY_RELEASE:		//離された時
		keyState = g_keyBoardState.release;
		break;
	case KEY_FREE:			//離され続けている時
		keyState = g_keyBoardState.free;
		break;
	}

	return ((keyState & KEY_REVISION) & a_key) != 0;
}

bool CheckJoyPadKey(DWORD a_key , DEVICE_MODE a_joyNo , KEY_STATE a_state)
{
	DWORD keyState = 0;	//キーの状態を格納する変数

	//接続されていないパッドの番号が指定されたとき
	if(a_joyNo >= (long)g_joyStickCount + JOY_PAD)
	{
		return false;	//強制的にfalseを返す
	}

	switch(a_state)
	{
	case KEY_PUSH:			//押された時
		keyState = g_joyKeyState[a_joyNo].push;
		break;
	case KEY_PRESS:			//押され続けている時
		keyState = g_joyKeyState[a_joyNo].press;
		break;
	case KEY_RELEASE:		//離された時
		keyState = g_joyKeyState[a_joyNo].release;
		break;
	case KEY_FREE:			//離され続けている時
		keyState = g_joyKeyState[a_joyNo].free;
		break;
	}

	return ((keyState & KEY_REVISION) & a_key) != 0;
}

D3DXVECTOR2 GetJoyPadPosition(DEVICE_MODE a_joyID)
{
	D3DXVECTOR2 joyPos , hangJoyPos;
	DEVICE_MODE Id;

	//接続されていないジョイパッドが指定された時
	if(a_joyID >= (long)g_joyStickCount + JOY_PAD)
	{
		return D3DXVECTOR2(0.0f,0.0f);
	}

	Id = a_joyID;	//番号を渡す
	joyPos.x = (float)g_joyPosition[Id].x;	//座標を渡す(x座標)
	joyPos.y = (float)g_joyPosition[Id].y;	//座標を渡す(y座標)
	joyPos.x -= 0x7EFF;
	joyPos.y -= 0x7EFF;
	hangJoyPos.x = abs((int)joyPos.x);	//絶対値に変換
	hangJoyPos.y = abs((int)joyPos.y);	//絶対値に変換

	//誤差修正
	if(hangJoyPos.x < 10000) { joyPos.x = 0; }
	if(hangJoyPos.y < 10000) { joyPos.y = 0; }
	return joyPos;
}

void RefreshInput(void)
{
	RefreshKeyBoard();
	LimitKeyBoard();
	LimitJoyPadKey();
	RefreshJoyPad();
	
}

void RefreshKeyBoard(void)
{
	HRESULT hr;
	if(g_pKeyDevice)
	{
		hr = g_pKeyDevice->Acquire();

		if((hr == DI_OK) || (hr == S_FALSE))
		{
			g_pKeyDevice->GetDeviceState(sizeof(g_keyState),g_keyState);
		}
		if(FAILED(hr))
		{
			g_pKeyDevice->Acquire();
			ZeroMemory(g_keyState,256);
		}
	}

}

void RefreshJoyPad(void)
{
	HRESULT hr;
	for(long i = 0 ; i < MAX_PAD ; i++)
	{
		ZeroMemory(&g_joyState[i],sizeof(DIJOYSTATE2));
		if(g_pJoyDevice[i])
		{
			//ポーリングが必要な場合
			if(g_polling[i])
			{
				g_pJoyDevice[i]->Poll();
			}

			//再アクセス
			hr = g_pJoyDevice[i]->Acquire();
			if(hr == DI_OK || hr == S_FALSE)
			{
				g_pJoyDevice[i]->GetDeviceState(sizeof(DIJOYSTATE2),&g_joyState[i]);
				g_joyPosition[i].x = g_joyState[i].lX;
				g_joyPosition[i].y = g_joyState[i].lY;
			}
		}
	}
}

void ReleaseDinput(void)
{
	if(g_pKeyDevice)
	{
		g_pKeyDevice->Unacquire();
	}

	for(long i = 0 ; i < MAX_PAD ; i++)
	{
		if(g_pJoyDevice[i])
		{
			g_pJoyDevice[i]->Unacquire();
		}
	}
	for(long i = 0 ; i < MAX_PAD ; i++)
	{
		SAFE_RELEASE(g_pJoyDevice[i]);
	}
	SAFE_RELEASE(g_pKeyDevice);
	SAFE_RELEASE(g_pDinput);
}