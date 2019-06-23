#include "DirectInput.h"

//�O���[�o��
LPDIRECTINPUT8			g_pDinput;							//DirectInput�I�u�W�F�N�g
LPDIRECTINPUTDEVICE8	g_pKeyDevice;						//DirectInputDevice�̃I�u�W�F�N�g(�L�[�{�[�h)
LPDIRECTINPUTDEVICE8	g_pJoyDevice[MAX_PAD];				//DirectInputDevice�̃I�u�W�F�N�g(�W���C�p�b�h)
BYTE					g_keyState[256];					//�L�[���i�[�p�z��
DIJOYSTATE2				g_joyState[MAX_PAD];				//�W���C�p�b�h���i�[�p�z��
POINT					g_joyPosition[MAX_PAD];				//�W���C�X�e�B�b�N�̎w���Ă�����W
KEY_DATA				g_keyBoardState;					//�L�[�̏��(�L�[�{�[�h)
KEY_DATA				g_joyKeyState[MAX_PAD];				//�L�[�̏��(�W���C�p�b�h)
static long				g_joyPadNum;						//�ڑ�����Ă���W���C�p�b�h�̔ԍ�
DWORD					g_joyStickCount , g_joyStickMax;	//�W���C�X�e�B�b�N�̐��ƌ��E��
JOY_DATA				g_joy;
bool					g_polling[MAX_PAD];					//�|�[�����O
bool					g_joyPadFlag;

HRESULT InitDinput(HWND a_hWnd)
{
	//������
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

	//�uDirectInput�v�I�u�W�F�N�g�̍쐬
	if(FAILED(hr = DirectInput8Create(GetModuleHandle(NULL),
		DIRECTINPUT_VERSION,IID_IDirectInput8,(void**)&g_pDinput,NULL)))
	{
		MessageBox(NULL,TEXT("�uDirectInput�v�I�u�W�F�N�g�̍쐬�Ɏ��s"),NULL,MB_OK);
		return hr;
	}

	//�L�[�{�[�h������
	if(FAILED(hr = InitKeyBoard(a_hWnd)))
	{
		MessageBox(NULL,TEXT("�L�[�{�[�h�̏������Ɏ��s"),NULL,MB_OK);
		return hr;
	}

	//�W���C�p�b�h������
	if(FAILED(hr = InitJoyPad(a_hWnd)))
	{
		MessageBox(NULL,TEXT("�W���C�p�b�h�̏������Ɏ��s"),NULL,MB_OK);
		return hr;
	}

	return S_OK;
}

HRESULT InitKeyBoard(HWND a_hWnd)
{
	//�L�[�f�o�C�X�I�u�W�F�N�g�̍쐬
	if(FAILED(g_pDinput->CreateDevice(GUID_SysKeyboard,&g_pKeyDevice,NULL)))
	{
		return E_FAIL;
	}

	//�f�o�C�X���L�[�{�[�h�ɐݒ�
	if(FAILED(g_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//�������x���̐ݒ�
	if(FAILED(g_pKeyDevice->SetCooperativeLevel(a_hWnd ,DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
	{
		return E_FAIL;
	}

	//�f�o�C�X���u�擾�v����
	g_pKeyDevice->Acquire();
	return S_OK;
}

HRESULT InitJoyPad(HWND a_hWnd)
{
	//�g�p�\�ȃW���C�X�e�B�b�N�̐�
	g_joyStickMax = joyGetNumDevs();
	if(g_joyStickMax >= 4) g_joyStickMax = 4;

	g_joyStickCount = 0;
	g_joy.joyStickCount = &g_joyStickCount;
	g_joy.joyStickMax = &g_joyStickMax;
	g_joy.joyDevice = g_pJoyDevice;
	g_joy.dInput	= g_pDinput;
	//���p�\�ȃQ�[���R���g���[���[�̗񋓊֐������s
	if(FAILED(g_pDinput->EnumDevices(DI8DEVCLASS_GAMECTRL, EnumJoysticksCallback , (VOID*)&g_joy,
		DIEDFL_ATTACHEDONLY)))
	{
		return E_FAIL;
	}

	for(long i = 0 ; i < MAX_PAD ; i++)
	{
		if(g_pJoyDevice[i])
		{
			//�f�o�C�X���W���C�X�e�B�b�N�ɐݒ�
			if(FAILED(g_pJoyDevice[i]->SetDataFormat(&c_dfDIJoystick2)))
			{
				return E_FAIL;
			}
			//�������x���̐ݒ�
			if(FAILED(g_pJoyDevice[i]->SetCooperativeLevel(a_hWnd,DISCL_NONEXCLUSIVE | DISCL_BACKGROUND)))
			{
				return E_FAIL;
			}
			//�����[�h�ݒ�
			if(FAILED(g_pJoyDevice[i]->EnumObjects(EnumObjectsCallback , (void*)g_pJoyDevice[i],DIDFT_AXIS)))
			{
				return E_FAIL;
			}

			//�f�o�C�X���擾
			DIDEVCAPS caps = {sizeof(DIDEVCAPS)};
			g_pJoyDevice[i]->GetCapabilities(&caps);

			//�|�[�����O���K�v���ǂ������ׂ�
			if(caps.dwFlags & (DIDC_POLLEDDATAFORMAT & DIDC_POLLEDDEVICE))
			{
				g_polling[i] = true;
			}
			else
			{
				g_polling[i] = false;
			}

			//�f�o�C�X���擾
			g_pJoyDevice[i]->Acquire();
			g_joyPadFlag = true;	//�W���C�p�b�h���Ȃ���Ă���̂�true�ɂ���
		}
	}
	return S_OK;
}

BOOL CALLBACK EnumJoysticksCallback( const DIDEVICEINSTANCE * a_pdidInstance , void * a_pContext)
{
	JOY_DATA * pJoy = ((JOY_DATA *)a_pContext);
	DWORD * jCount = pJoy->joyStickCount;
	DWORD * jMaxCount = pJoy->joyStickMax;

	//�f�o�C�X�̍쐬
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
	DWORD key = 0;	//���̃L�[�̏��

	static DWORD oldKeyState[MAX_PAD];

	for(long i = 0 ; i < MAX_PAD ; i++)
	{
		//key = 0;
		if(GetJoyPadData(JOY_KEY_UP,i))			{ key |= PAD_KEY_UP;		}			//��L�[
		if(GetJoyPadData(JOY_KEY_DOWN,i))		{ key |= PAD_KEY_DOWN;		}			//���L�[
		if(GetJoyPadData(JOY_KEY_LEFT,i))		{ key |= PAD_KEY_LEFT;		}			//���L�[
		if(GetJoyPadData(JOY_KEY_RIGHT,i))		{ key |= PAD_KEY_RIGHT;		}			//�E�L�[
		if(GetJoyPadData(JOY_KEY_BOTTON1,i))	{ key |= PAD_KEY_BOTTON1;	}			//�{�^���P
		if(GetJoyPadData(JOY_KEY_BOTTON2,i))	{ key |= PAD_KEY_BOTTON2;	}			//�{�^���Q
		if(GetJoyPadData(JOY_KEY_BOTTON3,i))	{ key |= PAD_KEY_BOTTON3;	}			//�{�^���R
		if(GetJoyPadData(JOY_KEY_BOTTON4,i))	{ key |= PAD_KEY_BOTTON4;	}			//�{�^���S
		if(GetJoyPadData(JOY_KEY_BOTTON5,i))	{ key |= PAD_KEY_BOTTON5;	}			//�{�^���T
		if(GetJoyPadData(JOY_KEY_BOTTON6,i))	{ key |= PAD_KEY_BOTTON6;	}			//�{�^���U
		if(GetJoyPadData(JOY_KEY_BOTTON7,i))	{ key |= PAD_KEY_BOTTON7;	}			//�{�^���V
		if(GetJoyPadData(JOY_KEY_BOTTON8,i))	{ key |= PAD_KEY_BOTTON8;	}			//�{�^���W

		//�L�[�������ꂽ��
		g_joyKeyState[i].push		= key & (~oldKeyState[i]);

		//�L�[�������ꑱ���Ă��鎞
		g_joyKeyState[i].press		= (oldKeyState[i] & key) | g_joyKeyState[i].push;

		//�L�[�������ꂽ��
		g_joyKeyState[i].release	= (oldKeyState[i] & (~key));

		//�L�[�������ꑱ���Ă��鎞
		g_joyKeyState[i].free		= ~g_joyKeyState[i].press;

		//���̃L�[�̏�Ԃ�n��
		oldKeyState[i] = key;
	}
}

void LimitKeyBoard(void)
{
	DWORD key = 0;	//���̃L�[�̏��

	static DWORD oldKeyState;	//1�O�̃L�[�̏��

	if(GetKeyBoardData(DIK_UP))		{ key |= KEY_UP;	}				//��L�[
	if(GetKeyBoardData(DIK_DOWN))	{ key |= KEY_DOWN;	}				//���L�[
	if(GetKeyBoardData(DIK_LEFT))	{ key |= KEY_LEFT;	}				//���L�[
	if(GetKeyBoardData(DIK_RIGHT))	{ key |= KEY_RIGHT;	}				//�E�L�[
	if(GetKeyBoardData(DIK_Z))		{ key |= KEY_Z;		}				//Z�L�[
	if(GetKeyBoardData(DIK_X))		{ key |= KEY_X;		}				//X�L�[
	if(GetKeyBoardData(DIK_C))		{ key |= KEY_C;		}				//C�L�[
	if(GetKeyBoardData(DIK_V))		{ key |= KEY_V;		}				//V�L�[
	if(GetKeyBoardData(DIK_A))		{ key |= KEY_A;		}				//A�L�[
	if(GetKeyBoardData(DIK_S))		{ key |= KEY_S;		}				//S�L�[
	if(GetKeyBoardData(DIK_R))		{ key |= KEY_R;		}				//R�L�[
	if(GetKeyBoardData(DIK_T))		{ key |= KEY_T;		}				//T�L�[
	if(GetKeyBoardData(DIK_Q))		{ key |= KEY_Q;		}				//T�L�[
	if(GetKeyBoardData(DIK_W))		{ key |= KEY_W;		}				//T�L�[
	if(GetKeyBoardData(DIK_SPACE))	{ key |= KEY_SPACE;	}				//T�L�[


	//�L�[�������ꂽ��
	g_keyBoardState.push	= key & (~oldKeyState);

	//�L�[�������ꑱ���Ă��鎞
	g_keyBoardState.press	= (key & oldKeyState) | g_keyBoardState.push;

	//�L�[�������ꂽ��
	g_keyBoardState.release = (oldKeyState & (~key));

	//�L�[�������ꑱ���Ă��鎞
	g_keyBoardState.free	= ~g_keyBoardState.press;

	//���̃L�[�̏�Ԃ�n��
	oldKeyState = key;
}

bool CheckKeyBoard(DWORD a_key , DEVICE_MODE a_mode , KEY_STATE a_state)
{
	DWORD keyState = 0;	//�L�[�̏�Ԃ��i�[����ϐ�

	if(a_mode != KEYBOARD)	//���[�h���L�[�{�[�h����Ȃ�������
	{
		return false;	//����false
	}

	switch(a_state)
	{
	case KEY_PUSH:			//�����ꂽ��
		keyState = g_keyBoardState.push;
		break;
	case KEY_PRESS:			//�����ꑱ���Ă��鎞
		keyState = g_keyBoardState.press;
		break;
	case KEY_RELEASE:		//�����ꂽ��
		keyState = g_keyBoardState.release;
		break;
	case KEY_FREE:			//�����ꑱ���Ă��鎞
		keyState = g_keyBoardState.free;
		break;
	}

	return ((keyState & KEY_REVISION) & a_key) != 0;
}

bool CheckJoyPadKey(DWORD a_key , DEVICE_MODE a_joyNo , KEY_STATE a_state)
{
	DWORD keyState = 0;	//�L�[�̏�Ԃ��i�[����ϐ�

	//�ڑ�����Ă��Ȃ��p�b�h�̔ԍ����w�肳�ꂽ�Ƃ�
	if(a_joyNo >= (long)g_joyStickCount + JOY_PAD)
	{
		return false;	//�����I��false��Ԃ�
	}

	switch(a_state)
	{
	case KEY_PUSH:			//�����ꂽ��
		keyState = g_joyKeyState[a_joyNo].push;
		break;
	case KEY_PRESS:			//�����ꑱ���Ă��鎞
		keyState = g_joyKeyState[a_joyNo].press;
		break;
	case KEY_RELEASE:		//�����ꂽ��
		keyState = g_joyKeyState[a_joyNo].release;
		break;
	case KEY_FREE:			//�����ꑱ���Ă��鎞
		keyState = g_joyKeyState[a_joyNo].free;
		break;
	}

	return ((keyState & KEY_REVISION) & a_key) != 0;
}

D3DXVECTOR2 GetJoyPadPosition(DEVICE_MODE a_joyID)
{
	D3DXVECTOR2 joyPos , hangJoyPos;
	DEVICE_MODE Id;

	//�ڑ�����Ă��Ȃ��W���C�p�b�h���w�肳�ꂽ��
	if(a_joyID >= (long)g_joyStickCount + JOY_PAD)
	{
		return D3DXVECTOR2(0.0f,0.0f);
	}

	Id = a_joyID;	//�ԍ���n��
	joyPos.x = (float)g_joyPosition[Id].x;	//���W��n��(x���W)
	joyPos.y = (float)g_joyPosition[Id].y;	//���W��n��(y���W)
	joyPos.x -= 0x7EFF;
	joyPos.y -= 0x7EFF;
	hangJoyPos.x = abs((int)joyPos.x);	//��Βl�ɕϊ�
	hangJoyPos.y = abs((int)joyPos.y);	//��Βl�ɕϊ�

	//�덷�C��
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
			//�|�[�����O���K�v�ȏꍇ
			if(g_polling[i])
			{
				g_pJoyDevice[i]->Poll();
			}

			//�ăA�N�Z�X
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