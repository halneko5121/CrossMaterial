#pragma once
/************************************************************************************
 *																					*
 *	�����F�X�N���v�g��Define��`�����܂�											*
 *																					*
 *	�����F																			*
 *																					*
 *	�쐬���F2009�N 2�� 28��															*
 *																					*
 *	�X�V���F	�N 2��   ��															*
 *													by	�O��@�j					*
 *																					*
 ************************************************************************************/

/*================================
		Define
=================================*/
#define _AFTER
#define STOP			("SKIPSTOP")

#define MAX_TALK_STRING (500)
#define MAX_CHARAFACE	(10)				//�L�����̕\��ő�10
#define MAX_CHARAFILE_T	(9)					//�L����(ADV)�̓����t�@�C���ő�9
#define MAX_BGNAME		(10)				//�w�i�̖��O�ő�10

//�����֌W
#define SPEED_UP		(10)
#define SPEED_DOWN		(10)
#define SPEED_FLASH		(30)
#define SPEED_QUAKE		(30)
#define SPEED_SLIDE		(20)

#define COUNT_QUAKE		(15)				
#define RETURN_QUAKE_Y	(30)
#define FLASH_WAIT		(15)
//������֌W
#define TALK_CONVERT_NUM		(48)				//48�͕�����'0'�ł�
#define TALK_CHANGEPLACE		("PLACE:")			
#define TALK_CHARA_LEFT			("LEFT")			
#define TALK_CHARA_RIGHT		("RIGHT")			
#define TALK_MSGWINDOW			("MSGWINDOW:")	
#define TALK_TEXTNAME			("TEXT:")	
#define TALK_SOUNDLOAD			("SOUNDLOAD:")		
#define TALK_SOUNDRELEASE		("SOUNDRELEASE:")	
#define TALK_SOUNDPLAY			("SOUNDPLAY:")		
#define TALK_SOUNDSTOP			("SOUNDSTOP:")
#define TALK_FADE				("FADE:")
#define TALK_REVERSE			("REV")		//�L�����̌����̔��]
#define TALK_WORD				("TALK:")	//���ꂪ�������ꍇ��b���ύX

#define TALK_MAXLINE			(3)			//��b�\���̍ő�s��
#define TALK_NEXTLINE			(1)			//���ɓǂݍ��ރe�L�X�g�̃v���X�̐�
#define TALK_FONTSIZE			(30)		//��b�\���̎��̈ꕶ���̃T�C�Y

#define STRING_TALK				(4)
#define FLAG_CONTINUE			(7)					
#define DELAY_TIME				(6)
#define WAIT_TIME_AUTO			(100)
#define WAIT_TIME_SKIP			(3)

//��`�����킹��
#define R_CONVERT_PLACE			(16)		//��`�ԍ������킹�鐔
#define R_CONVERT_CHARANAME		(6)			//��`�ԍ������킹�鐔
#define CONVERT_FADE			(3)			//�t�F�[�h���E�����킹�鐔
#define CONVERT_REV				(20.f)		//���]�����Ƃ��ɊG���؂�Ȃ��悤��
#define CONVERT_REV_ROZE		(100.f)		//�N�����p
#define T_HEIGHT				(500.0f)	//�L�����G�̃T�C�Y
#define T_WIDE					(350.0f)	//�V

#define COMAND_STRING_F_OUT		(19)		//PLACE:��:FADEOUT:STOP��19�����@�@��(�ꏊ)
//#define COMAND_STRING_F_IN		(18)		//PLACE:��:FADEIN:STOP ��18�����@�@��(�ꏊ)

//�`��ʒu
#define TALK_POS_X				(80)				//��b�̕`��J�n�ʒuX���W
#define TALK_POS_X2				(740)				//��b�̕`��I���ʒuX���W
#define TALK_POS_Y				(425)				//��b�̕`��J�n�ʒuY���W
#define TALK_POS_Y2				(560)				//��b�̕`��I���ʒuY���W
#define TALK_SPACE				(15)				//�ꕶ�ꕶ�̊Ԋu
#define NEXTICON_X				(700.0f)
#define NEXTICON_Y				(510.0f)

#define POS_BG_ADVETURE_X		(400.0f)
#define POS_BG_ADVETURE_Y		(300.0f)
#define POS_CHARA_X				(-60.0f)
#define POS_CHARA_Y				(100.0f)
#define POS_CHARA2_X			(510.0f)
#define POS_CHARA2_Y			(100.0f)
#define POS_CONSOR_X			(20.0f)
#define POS_CONSOR_Y			(20.0f)
#define POS_MSGWINDOW_X			(400.0f)
#define POS_MSGWINDOW_Y			(500.0f)
#define POS_BLACK_X				(405.0f)
#define POS_BLACK_Y				(490.0f)

#define POS_NOWPLACE_X			(160.0f)
#define POS_NOWPLACE_Y			(40.0f)
#define POS_CHARANAME_X			(50.0f)
#define POS_CHARANAME_Y			(370.0f)

#define POS_CHARA1_STOP			-(T_WIDE + POS_CHARA_X + CONVERT_REV)
#define POS_CHARA2_STOP			 (T_WIDE + POS_CHARA_X + CONVERT_REV)

enum POS
{
	LEFT,
	RIGHT,
};


enum TEXTURE_ADV		//TEXTURE�̔ԍ�
{	
	T_BG_BEDROOM,
	T_BG_LIVING_HIRU,
	T_BG_LIVING_NIGHT,
	T_BG_LIVING_DIE,
	T_BG_CLASSROOM,
	T_BG_BACKYARD,
	T_BG_WASTELAND,
	T_BG_BLOOD,
	T_BG_FLASH,

	T_MAX_BG,

	T_CHARA_VAN = T_MAX_BG,
	T_CHARA_CULALA,
	T_CHARA_ROZETTA,
	T_CHARA_RIDDLE,
	T_CHARA_ZION_1,
	T_CHARA_ZION_2,
	T_CHARA_RIO_1,
	T_CHARA_RIO_2,
	T_CHARA_MAGNA_1,

	T_MAX_CHARA,
	MAX_CHARA = (T_MAX_CHARA - T_MAX_BG),
 
	T_CONSOR_ADV = T_MAX_CHARA,
	T_BLACK,
	T_POWER,
	
	T_MAX_ADV,
};

enum RECT_ADV			//��`�̔ԍ�
{
	R_BG_ADV,			//�w�i
	R_CHARA_FACE1,		//1.�ʏ� 6.����
	R_CHARA_FACE2,		//2.�{   7.����
	R_CHARA_FACE3,		//3.��   8.�ł�
	R_CHARA_FACE4,		//4.�y   9.����
	R_CHARA_FACE5,		//5.��   10.(��)

	MAX_KINDFACE,

	//�L������
	R_NAME_CULIS = MAX_KINDFACE,		//�N���X
	R_NAME_VAN,							//���@��
	R_NAME_CULALA,						//�N����
	R_NAME_RIZETTE,						//���[�b�^
	R_NAME_RIDDLE,						//???
	R_NAME_FATHER,						//��
	R_NAME_MATHER,						//��
	R_NAME_XION,						//�V�I��
	R_NAME_RIO,							//���I
	R_NAME_MAGNA,						//�}�O�i

	R_MAX_CHARANAME,
	MAX_CHARANAME = (R_MAX_CHARANAME - MAX_KINDFACE),

	//���ݒn��
	R_PLACE_TEARENTE = R_MAX_CHARANAME,	//�e�A�����e�̊X
	DUMMY1,
	DUMMY2,
	DUMMY3,
	R_PLACE_CLASSROOM,	//����
	R_PLACE_BACKYARD,	//����
	R_PLACE_WASTELAND,	//�r��

	R_MAX_PLACENAME,
	MAX_PLACENAME = (R_MAX_PLACENAME - R_MAX_CHARANAME),

	//�R���\�n
	R_CONSOR_PLACE = R_MAX_PLACENAME,		//���ݒn��
	R_CONSOR_MSGWINDOW,	//���b�Z�[�W�E�B���h�E
	R_BLACK,			//���������₷�����邽�߂�
	R_ROZE1,			
	R_ROZE2,			
	R_ROZE3,
	R_NEXTICON_1,
	R_NEXTICON_2,
	R_NEXTICON_3,
	R_NEXTICON_4,

	R_MAX_ADV,		
};

enum SCRIPT_KIND		//�X�N���v�g�ɗ^����f�[�^�̎��
{
	S_KIND_BG,			//�w�i�̃X�N���v�g�ݒ�	
	S_KIND_NOWPLACE,	//�w���ݒn�x�́V
	S_KIND_CHARANAME,	//�L�������́V
	S_KIND_CHARA_LEFT,	//�L�����̎�ލ����V
	S_KIND_CHARA_RIGHT,	//�L�����̎�މE���V

	KIND_MAX,
};

enum FADE_CHARAPOS		//�t�F�[�h������L�����ʒu
{
	CHARA_LEFT,
	CHARA_RIGHT,

	MAX_CHARAPOS,
};

enum CHARANAME
{
	NAME_CULIS,					//�N���X
	NAME_VAN,					//���@��
	NAME_CULALA,				//�N����
	NAME_RIZETTE,				//���[�b�^
	NAME_RIDDLE,				//???
	NAME_FATHER,				//��
	NAME_MATHER,				//��
	NAME_XION,					//�V�I��
	NAME_RIO,					//���I
	NAME_MAGNA,					//�}�O�i

	MAX_CHARNAME,
};