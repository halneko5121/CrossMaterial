#ifndef _DIRECTINPUT_H_
#define _DIRECTINPUT_H_

#define DIRECTINPUT_VERSION (0x800)
#define MAX_PAD				(1)
#define KEY_REVISION		(0x03FFFFF)

#include <dinput.h>
#include <mmsystem.h>
#include <d3dx9.h>
#include "Macro.h"

#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"winmm.lib")

/* キーボード */
enum KEY
{
	KEY_UP		= 0x0001,
	KEY_DOWN	= 0x0002,
	KEY_LEFT	= 0x0004,
	KEY_RIGHT	= 0x0008,
	KEY_Z		= 0x0010,
	KEY_X		= 0x0020,
	KEY_C		= 0x0040,
	KEY_V		= 0x0080,
	KEY_A		= 0x0100,
	KEY_S		= 0x0200,
	KEY_R		= 0x0400,
	KEY_T		= 0x0800,
	KEY_Q		= 0x1000,
	KEY_W		= 0x2000,
	KEY_SPACE	= 0x4000,
};

/* ジョイパッド(実際に使用する側) */
enum JOY_PAD_KEY
{
	PAD_KEY_UP		= 0x0001,
	PAD_KEY_DOWN	= 0x0002,
	PAD_KEY_LEFT	= 0x0004,
	PAD_KEY_RIGHT	= 0x0008,
	PAD_KEY_BOTTON1	= 0x0010,
	PAD_KEY_BOTTON2	= 0x0020,
	PAD_KEY_BOTTON3	= 0x0040,
	PAD_KEY_BOTTON4	= 0x0080,
	PAD_KEY_BOTTON5	= 0x0100,
	PAD_KEY_BOTTON6	= 0x0200,
	PAD_KEY_BOTTON7	= 0x0400,
	PAD_KEY_BOTTON8 = 0x0800,
};

/* ジョイパッド */
enum JOY_KEY
{
	JOY_KEY_BOTTON1,
	JOY_KEY_BOTTON2,
	JOY_KEY_BOTTON3,
	JOY_KEY_BOTTON4,
	JOY_KEY_BOTTON5,
	JOY_KEY_BOTTON6,
	JOY_KEY_BOTTON7,
	JOY_KEY_BOTTON8,
	JOY_KEY_UP,
	JOY_KEY_DOWN,
	JOY_KEY_LEFT,
	JOY_KEY_RIGHT,
};

/* デバイス設定 */
enum DEVICE_MODE
{
	JOY_PAD,
	KEYBOARD,
};

/* ジョイパッド構造体 */
typedef struct _JOYDATA
{
	LPDIRECTINPUTDEVICE8 *	joyDevice;
	LPDIRECTINPUT8			dInput;
	DWORD *					joyStickMax;
	DWORD *					joyStickCount;
}JOY_DATA;

/* キーの状態 */
typedef struct _KEYDATA
{
	DWORD push;
	DWORD press;
	DWORD release;
	DWORD free;
}KEY_DATA;

/* キーの状態(enum) */
enum KEY_STATE
{
	KEY_PUSH,
	KEY_PRESS,
	KEY_RELEASE,
	KEY_FREE,
};


/*---------------------------------------------------------------------

	関数名	:HRESULT InitDinput(HWND a_hWnd)
	引数 	:HWND a_hWnd	ウィンドウハンドル
	戻り値	:成功	S_OK	失敗	E_FAIL
	役割 	:DirectInput初期化関数
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
HRESULT InitDinput(HWND a_hWnd);

/*---------------------------------------------------------------------

	関数名	:HRESULT InitKeyBoard(HWND a_hWnd)
	引数 	:HWND a_hWnd	ウィンドウハンドル
	戻り値	:成功	S_OK	失敗	E_FAIL
	役割 	:キーボード初期化関数
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
HRESULT InitKeyBoard(HWND a_hWnd);

/*---------------------------------------------------------------------

	関数名	:HRESULT InitJoyPad(HWND a_hWnd)
	引数 	:HWND a_hWnd	ウィンドウハンドル
	戻り値	:成功	S_OK	失敗	E_FAIL
	役割 	:ジョイパッド初期化関数
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
HRESULT InitJoyPad(HWND a_hWnd);

BOOL CALLBACK EnumJoysticksCallback( const DIDEVICEINSTANCE * a_pdidInstance , void * a_pContext);

BOOL CALLBACK EnumObjectsCallback( const DIDEVICEOBJECTINSTANCE * a_pdidoi , void * a_pContext);

/*---------------------------------------------------------------------

	関数名	:bool GetKeyBoardData(DWORD a_key)
	引数 	:DWORD	a_key	キー識別
	戻り値	:成功	S_OK	失敗	E_FAIL
	役割 	:キーが押されているかどうかの判定
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
bool GetKeyBoardData(DWORD a_key);

/*---------------------------------------------------------------------

	関数名	:bool GetJoyPadData(DWORD a_key , long a_joyID)
	引数 	:DWORD	a_key	キー識別
			 long	a_joyID	ジョイパッド番号
	戻り値	:bool	成功	S_OK	失敗	E_FAIL
	役割 	:キーが押されているかどうかの判定
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
bool GetJoyPadData(DWORD a_key , long a_joyID);

/*---------------------------------------------------------------------

	関数名	:void LimitJoyPadKey(void)
	引数 	:なし
	戻り値	:なし
	役割 	:キーに制限をかける
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
void LimitJoyPadKey(void);

/*---------------------------------------------------------------------

	関数名	:void LimitKeyBoard(void)
	引数 	:なし
	戻り値	:なし
	役割 	:キーに制限をかける
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
void LimitKeyBoard(void);

/*---------------------------------------------------------------------

	関数名	:bool CheckKeyBoard(DWORD a_key , KEY_STATE a_state)
	引数 	:DWORD		a_key	押されているキー
			 KEY_STATE	a_state	そのキーの状態
	戻り値	:bool	押されているとtrue,押されていないとfalse
	役割 	:キーが押されているかどうかのチェック
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
bool CheckKeyBoard(DWORD a_key , DEVICE_MODE a_mode , KEY_STATE a_state);


/*---------------------------------------------------------------------

	関数名	:bool CheckJoyPadKey(DWORD a_key , DEVICE_MODE a_joyNo , KEY_STATE a_state)
	引数 	:DWORD			a_key	押されているキー
			 DEVICE_MODE	a_joyNo	ジョイパッドの番号
			 KEY_STATE		a_state	そのキーの状態
	戻り値	:bool	押されているとtrue,押されていないとfalse
	役割 	:キーが押されているかどうかのチェック
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
bool CheckJoyPadKey(DWORD a_key , DEVICE_MODE a_joyNo , KEY_STATE a_state);

/*---------------------------------------------------------------------

	関数名	:D3DXVECTOR2 GetJoyPadPosition(DEVICE_MODE a_joyID)
	引数 	:DEVICE_MODE	a_joyID	ジョイパッドの番号
	戻り値	:D3DXVECTOR2	ジョイスティックの指している座標
	役割 	:ジョイスティックの指している座標を返す
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
D3DXVECTOR2 GetJoyPadPosition(DEVICE_MODE a_joyID);

/*---------------------------------------------------------------------

	関数名	:void RefreshInput(void)
	引数 	:なし
	戻り値	:なし
	役割 	:全デバイス状態の更新
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
void RefreshInput(void);

/*---------------------------------------------------------------------

	関数名	:void RefreshKeyBoard(void)
	引数 	:なし
	戻り値	:なし
	役割 	:キーボードの状態更新
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
void RefreshKeyBoard(void);

/*---------------------------------------------------------------------

	関数名	:void RefreshJoyPad(void)
	引数 	:なし
	戻り値	:なし
	役割 	:ジョイパッドの状態更新
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
void RefreshJoyPad(void);

/*---------------------------------------------------------------------

	関数名	:void ReleaseDinput(void)
	引数 	:なし
	戻り値	:なし
	役割 	:開放処理
	作成者	:
	更新日	:
	更新内容:

---------------------------------------------------------------------*/
void ReleaseDinput(void);

#endif	//_DIRECTINPUT_H_