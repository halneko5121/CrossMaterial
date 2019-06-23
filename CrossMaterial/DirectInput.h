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

/* �L�[�{�[�h */
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

/* �W���C�p�b�h(���ۂɎg�p���鑤) */
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

/* �W���C�p�b�h */
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

/* �f�o�C�X�ݒ� */
enum DEVICE_MODE
{
	JOY_PAD,
	KEYBOARD,
};

/* �W���C�p�b�h�\���� */
typedef struct _JOYDATA
{
	LPDIRECTINPUTDEVICE8 *	joyDevice;
	LPDIRECTINPUT8			dInput;
	DWORD *					joyStickMax;
	DWORD *					joyStickCount;
}JOY_DATA;

/* �L�[�̏�� */
typedef struct _KEYDATA
{
	DWORD push;
	DWORD press;
	DWORD release;
	DWORD free;
}KEY_DATA;

/* �L�[�̏��(enum) */
enum KEY_STATE
{
	KEY_PUSH,
	KEY_PRESS,
	KEY_RELEASE,
	KEY_FREE,
};


/*---------------------------------------------------------------------

	�֐���	:HRESULT InitDinput(HWND a_hWnd)
	���� 	:HWND a_hWnd	�E�B���h�E�n���h��
	�߂�l	:����	S_OK	���s	E_FAIL
	���� 	:DirectInput�������֐�
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
HRESULT InitDinput(HWND a_hWnd);

/*---------------------------------------------------------------------

	�֐���	:HRESULT InitKeyBoard(HWND a_hWnd)
	���� 	:HWND a_hWnd	�E�B���h�E�n���h��
	�߂�l	:����	S_OK	���s	E_FAIL
	���� 	:�L�[�{�[�h�������֐�
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
HRESULT InitKeyBoard(HWND a_hWnd);

/*---------------------------------------------------------------------

	�֐���	:HRESULT InitJoyPad(HWND a_hWnd)
	���� 	:HWND a_hWnd	�E�B���h�E�n���h��
	�߂�l	:����	S_OK	���s	E_FAIL
	���� 	:�W���C�p�b�h�������֐�
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
HRESULT InitJoyPad(HWND a_hWnd);

BOOL CALLBACK EnumJoysticksCallback( const DIDEVICEINSTANCE * a_pdidInstance , void * a_pContext);

BOOL CALLBACK EnumObjectsCallback( const DIDEVICEOBJECTINSTANCE * a_pdidoi , void * a_pContext);

/*---------------------------------------------------------------------

	�֐���	:bool GetKeyBoardData(DWORD a_key)
	���� 	:DWORD	a_key	�L�[����
	�߂�l	:����	S_OK	���s	E_FAIL
	���� 	:�L�[��������Ă��邩�ǂ����̔���
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
bool GetKeyBoardData(DWORD a_key);

/*---------------------------------------------------------------------

	�֐���	:bool GetJoyPadData(DWORD a_key , long a_joyID)
	���� 	:DWORD	a_key	�L�[����
			 long	a_joyID	�W���C�p�b�h�ԍ�
	�߂�l	:bool	����	S_OK	���s	E_FAIL
	���� 	:�L�[��������Ă��邩�ǂ����̔���
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
bool GetJoyPadData(DWORD a_key , long a_joyID);

/*---------------------------------------------------------------------

	�֐���	:void LimitJoyPadKey(void)
	���� 	:�Ȃ�
	�߂�l	:�Ȃ�
	���� 	:�L�[�ɐ�����������
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
void LimitJoyPadKey(void);

/*---------------------------------------------------------------------

	�֐���	:void LimitKeyBoard(void)
	���� 	:�Ȃ�
	�߂�l	:�Ȃ�
	���� 	:�L�[�ɐ�����������
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
void LimitKeyBoard(void);

/*---------------------------------------------------------------------

	�֐���	:bool CheckKeyBoard(DWORD a_key , KEY_STATE a_state)
	���� 	:DWORD		a_key	������Ă���L�[
			 KEY_STATE	a_state	���̃L�[�̏��
	�߂�l	:bool	������Ă����true,������Ă��Ȃ���false
	���� 	:�L�[��������Ă��邩�ǂ����̃`�F�b�N
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
bool CheckKeyBoard(DWORD a_key , DEVICE_MODE a_mode , KEY_STATE a_state);


/*---------------------------------------------------------------------

	�֐���	:bool CheckJoyPadKey(DWORD a_key , DEVICE_MODE a_joyNo , KEY_STATE a_state)
	���� 	:DWORD			a_key	������Ă���L�[
			 DEVICE_MODE	a_joyNo	�W���C�p�b�h�̔ԍ�
			 KEY_STATE		a_state	���̃L�[�̏��
	�߂�l	:bool	������Ă����true,������Ă��Ȃ���false
	���� 	:�L�[��������Ă��邩�ǂ����̃`�F�b�N
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
bool CheckJoyPadKey(DWORD a_key , DEVICE_MODE a_joyNo , KEY_STATE a_state);

/*---------------------------------------------------------------------

	�֐���	:D3DXVECTOR2 GetJoyPadPosition(DEVICE_MODE a_joyID)
	���� 	:DEVICE_MODE	a_joyID	�W���C�p�b�h�̔ԍ�
	�߂�l	:D3DXVECTOR2	�W���C�X�e�B�b�N�̎w���Ă�����W
	���� 	:�W���C�X�e�B�b�N�̎w���Ă�����W��Ԃ�
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
D3DXVECTOR2 GetJoyPadPosition(DEVICE_MODE a_joyID);

/*---------------------------------------------------------------------

	�֐���	:void RefreshInput(void)
	���� 	:�Ȃ�
	�߂�l	:�Ȃ�
	���� 	:�S�f�o�C�X��Ԃ̍X�V
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
void RefreshInput(void);

/*---------------------------------------------------------------------

	�֐���	:void RefreshKeyBoard(void)
	���� 	:�Ȃ�
	�߂�l	:�Ȃ�
	���� 	:�L�[�{�[�h�̏�ԍX�V
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
void RefreshKeyBoard(void);

/*---------------------------------------------------------------------

	�֐���	:void RefreshJoyPad(void)
	���� 	:�Ȃ�
	�߂�l	:�Ȃ�
	���� 	:�W���C�p�b�h�̏�ԍX�V
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
void RefreshJoyPad(void);

/*---------------------------------------------------------------------

	�֐���	:void ReleaseDinput(void)
	���� 	:�Ȃ�
	�߂�l	:�Ȃ�
	���� 	:�J������
	�쐬��	:
	�X�V��	:
	�X�V���e:

---------------------------------------------------------------------*/
void ReleaseDinput(void);

#endif	//_DIRECTINPUT_H_