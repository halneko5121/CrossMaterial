#pragma once

/************************************************************************************
 *																					*
 *	�����F�o�g�������ł�Define�̒�`												*
 *																					*
 *	�����F																			*
 *																					*
 *	�쐬���F2008�N �� ��															*
 *																					*
 *	�X�V���F2008�N �� ��															*
 *													by	����@�w					*
 *																					*
 ************************************************************************************/

enum TEXTURE_DATA_BATTLE
{
	//�X�e�[�^�X�`��
	T_STATUS_BG,		//�w�i
	T_STATUS_FC,		//�t�H���g�E�R���\�[��
	T_STATUS_NAME,		//�L�����̖��O
	T_STATUS_ZION_CG,	//�V�I���̗����G
	T_STATUS_VAN_CG,	//���@���̗����G
	T_STATUS_RIO_CG,	//���I�̗����G
	T_STATUS_FACE_CG,	//�L�����G(��)

	T_BATTLE_FIELD1,	//�o�g�����̔w�i
	T_WIN_CONDITION_BG,	//���������\�����̔w�i
	T_BATTLE_FONT,		//�o�g�����t�H���g

	T_MAPTIP,			//MAPTIP�̓����t�@�C��

	T_CHAR_ZION,		//�L�����G
	T_CHAR_VAN,			//�L�����G
	T_CHAR_RIO,			//�L�����G
	
	T_CHAR_SAHAGIN1,	//�L�����G
	T_CHAR_SAHAGIN2,	//�L�����G
	T_CHAR_LIZARDMAN1,	//�L�����G
	T_CHAR_LIZARDMAN2,	//�L�����G
	T_CHAR_LIZARDMAN3,	//�L�����G(�t�[�h�̒j)
	T_CHAR_NAME1,		//�L�����̖��O
	T_UP_EF,			//�G�t�F�N�g(�X�e�[�^�X��)
	T_ATK_EF,			//�G�t�F�N�g(�U��)
	T_ZION_SP_BG,		//���`�̔w�i
	T_VAN_SP_BG,		//���`�̔w�i
	T_RIO_SP_BG,		//���`�̔w�i
	T_TELOP,			//�}�e���A���Z�b�g���̃e���b�v
	T_FADE,				//�t�F�[�h�A�E�g���̊G
	T_WHITE_OUT,		//�z���C�g�A�E�g���̊G
	T_WHITE_OUT_VAN,	//�z���C�g�A�E�g���̊G(���@��)
	T_ATK_SP_EF,		//�G�t�F�N�g(���`)
	T_ATK_SP_EF2,
	T_SLASH,
	T_NOWLOADING,

	T_A,

	T_WAKU,

	MAX_BATTLE_TEXTURE,	//�e�N�X�`���̐�
};

enum RECT_DATA_BATTLE	//��`�f�[�^
{
	R_STATUS_BG,			//�w�i				0
	R_STATUS_ATTRIBUTE1,	//����������		1
	R_STATUS_HP,			//�HP�����			2
	R_STATUS_AP,			//�AP�����			3
	R_STATUS_MG,			//�MG�����			4
	R_STATUS_ATK,			//�ATK�����			5
	R_STATUS_DEF,			//�DEF�����			6
	R_STATUS_DEX,			//�DEX�����			7
	R_STATUS_AGL,			//�AGL�����			8
	R_STATUS_MATRIX,		//��}�g���N�X�����	9
	R_STATUS_MATERIAL,		//��}�e���A�������	10
	R_STATUS_SPECIAL,		//����꣕���		11
	R_STATUS_AP_R,			//�AP_P�����		12
	R_STATUS_MAG,			//�MAG�����			13
	R_STATUS_RES,			//�RES�����			14
	R_STATUS_MOV,			//�MOV�����			15
	R_STATUS_LUK,			//�LUK�����			16
	R_STATUS_ATTRIBUTE2,	//����������		17
	R_STATUS_USE_AP1,		//�����AP�����		18
	R_STATUS_USE_AP2,		//�����AP�����		19
	R_STATUS_SLASH1,		//��^��̕���		20
	R_STATUS_SLASH2,		//��^��̕���		21
	R_STATUS_SLASH3,		//��^��̕���		22
	R_STATUS_NUM100,		//�����̕S��		23
	R_STATUS_NUM10,			//�����̏\��		24
	R_STATUS_NUM1,			//�����̈ꌅ		25
	R_STATUS_COVER1,		//��Σ�̕���		26
	R_STATUS_COVER2,		//��Σ�̕���		27
	R_STATUS_MATRIXNAME,	//�}�g���N�X��		28
	R_STATUS_MATERIALNAME,	//�}�e���A����		29
	R_STATUS_Z_UNDINE1,		//�����ٴ��ޣ		30
	R_STATUS_Z_UNDINE2,		//��������			31
	R_STATUS_Z_SYLPH1,		//�˰ٳ���ޣ		32
	R_STATUS_Z_SYLPH2,		//��װ���ޣ			33
	R_STATUS_V_SALAMANDER1,	//��������			34
	R_STATUS_V_SALAMANDER2,	//��������			35
	R_STATUS_V_GNOME1,		//��n�Ӑo�			36
	R_STATUS_V_GNOME2,		//��|�����			37
	R_STATUS_R_SALAMANDER1,	//���ڲ����گģ		38
	R_STATUS_R_SALAMANDER2,	//��ް�ģ			39
	R_STATUS_R_UNDINE1,		//��۰�����گģ		40
	R_STATUS_R_UNDINE2,		//��������			41
	R_STATUS_Z_UN_DATAIL1,	//�����ٴ��ޣ�ڍ�	42
	R_STATUS_RECOVERY_DATAIL,//�����˰٣�ڍ�	43
	R_STATUS_Z_SY_DATAIL1,	//��װ���ޣ�ڍ�		44
	R_STATUS_V_SA_DATAIL1,	//���������ڍ�		45
	R_STATUS_V_SA_DATAIL2,	//���������ڍ�		46
	R_STATUS_V_GN_DATAIL1,	//��n�Ӑo��ڍ�		47
	R_STATUS_V_GN_DATAIL2,	//��|������ڍ�		48
	R_STATUS_R_SA_DATAIL1,	//���ڲ����گģ�ڍ�	49
	R_STATUS_R_SA_DATAIL2,	//��ް�ģ�ڍ�		50
	R_STATUS_R_UN_DATAIL1,	//��۰�����گģ�ڍ�	51
	R_STATUS_CHARA_NAME,	//���ׂ���Ȱѣ		52
	R_STATUS_ZION_CG,		//��V�I���̂b�f�	53
	R_STATUS_VAN_CG,		//����@���̂b�f�	54
	R_STATUS_RIO_CG,		//����I�̂b�f�		55
	
	R_BATTLE_FIELD1,		//�o�g�����̔w�i
	R_WIN_CONDITION_BG,		//���������\�����̔w�i
	R_WIN_CONDITION,		//��������
	R_LOSS_CONDITION,		//�s�k����
	R_WIN_ONE,				//���������@
	R_WIN_TWO,				//���������A
	R_LOSS_ONE,				//�s�k�����@
	R_PLAYER_PHASE,			//���t�F�C�Y
	R_ENEMY_PHASE,			//�G�t�F�C�Y
	R_MOVE,					//�ړ�
	R_ATACK,				//�U��
	R_SPECIAL,				//����
	R_DEFENCE,				//�h��
	R_STATUS,				//�X�e�[�^�X
	R_STAND,				//�ҋ@
	//�X�e�[�W
	R_MAPTIP_CACTUS1,		//�T�{�e��1
	R_MAPTIP_CACTUS2,		//�T�{�e��2
	R_MAPTIP_ROCK1,			//���1
	R_MAPTIP_ROCK2,			//���2
	R_MAPTIP_SAND1,			//���n1
	R_MAPTIP_SAND2,			//���n2
	R_MAPTIP_SAND3,			//���n3
	R_MAPTIP_SAND4,			//���n4
	R_MAPTIP_GREEN1,		//���n1
	R_MAPTIP_GREEN2,		//���n2
	R_MAPTIP_GREEN3,		//���n3
	R_MAPTIP_GREEN4,		//���n4
	R_MAPTIP_CHOICE,		//�J�[�\��
	R_MAPTIP_EREA,			//�G���A
	//D_MAPTIP_MAX,			//MAPTIP��`�̍ő吔
	//�L�����N�^�[
	R_CHAR_WAIT_LEFTFRONT,		//�L�����ҋ@(���O)
	R_CHAR_WAIT_LEFTBACK,		//�L�����ҋ@(����)
	R_CHAR_WAIT_RIGHTFRONT,		//�L�����ҋ@(�E�O)
	R_CHAR_WAIT_RIGHTBACK,		//�L�����ҋ@(�E��)

	R_CHAR_ATTACK_LEFTFRONT1,	//�L�����U��(���O)
	R_CHAR_ATTACK_LEFTFRONT2,	//�L�����U��(���O)
	R_CHAR_ATTACK_LEFTFRONT3,	//�L�����U��(���O)
	R_CHAR_ATTACK_LEFTFRONT4,	//�L�����U��(���O)

	R_CHAR_ATTACK_LEFTBACK1,	//�L�����U��(����)
	R_CHAR_ATTACK_LEFTBACK2,	//�L�����U��(����)
	R_CHAR_ATTACK_LEFTBACK3,	//�L�����U��(����)
	R_CHAR_ATTACK_LEFTBACK4,	//�L�����U��(����)

	R_CHAR_ATTACK_RIGHTFRONT1,	//�L�����U��(�E�O)
	R_CHAR_ATTACK_RIGHTFRONT2,	//�L�����U��(�E�O)
	R_CHAR_ATTACK_RIGHTFRONT3,	//�L�����U��(�E�O)
	R_CHAR_ATTACK_RIGHTFRONT4,	//�L�����U��(�E�O)

	R_CHAR_ATTACK_RIGHTBACK1,	//�L�����U��(�E��)
	R_CHAR_ATTACK_RIGHTBACK2,	//�L�����U��(�E��)
	R_CHAR_ATTACK_RIGHTBACK3,	//�L�����U��(�E��)
	R_CHAR_ATTACK_RIGHTBACK4,	//�L�����U��(�E��)

	R_CHAR_ZION_ATTACK_LEFTFRONT1,	//�V�I���U��(���O)
	R_CHAR_ZION_ATTACK_LEFTFRONT2,	//�V�I���U��(���O)
	R_CHAR_ZION_ATTACK_LEFTFRONT3,	//�V�I���U��(���O)
	R_CHAR_ZION_ATTACK_LEFTFRONT4,	//�V�I���U��(���O)

	R_CHAR_ZION_ATTACK_RIGHTFRONT1,	//�V�I���U��(�E�O)
	R_CHAR_ZION_ATTACK_RIGHTFRONT2,	//�V�I���U��(�E�O)
	R_CHAR_ZION_ATTACK_RIGHTFRONT3,	//�V�I���U��(�E�O)
	R_CHAR_ZION_ATTACK_RIGHTFRONT4,	//�V�I���U��(�E�O)

	R_GAME_OVER,
	R_ZION_NAME,
	R_VAN_NAME,
	R_RIO_NAME,
	R_BATTLE_ICON,	//�A�C�R��

	R_MATERIAL_UNDINE,	//�}�e���A����	��
	R_MATERIAL_SYIPH,	//�}�e���A�����@��
	R_MATERIAL_GNOM,	//�}�e���A�����@�y

	R_SIMPLE_BG,		//�ȈՒn�`�X�e�[�^�X�w�i
	R_SIMPLE_EFFECT,	//��������
	R_SIMPLE_CHARA_BG,	//�ȈՃX�e�[�^�X�L�����w�i
	R_SIMPLE_NUM100,	//�����̕S��(�ȈՃX�e�[�^�X)
	R_SIMPLE_NUM10,		//�����\��(�ȈՃX�e�[�^�X�p)
	R_SIMPLE_NUM1,		//�����̈ꌅ(�ȈՃX�e�[�^�X�p)	

	R_SIMPLE_SLASH,		//��^��̕���(�ȈՃX�e�[�^�X�p)
	R_SIMPLE_NAME,		//�L�����̃t���l�[��(�ȈՃX�e�[�^�X�p)
	R_SIMPLE_UPDOWN,	//�����A����

	R_ZION_WAIT_LEFTFRONT,		//�V�I���ҋ@(���O)
	R_ZION_WAIT_LEFTBACK,		//�V�I���ҋ@(����)
	R_ZION_WAIT_RIGHTFRONT,		//�V�I���ҋ@(�E�O)
	R_ZION_WAIT_RIGHTBACK,		//�V�I���ҋ@(�E��)
	R_ZION_WAIT_LF_ATK_1,		//�V�I�����O�U��
	R_ZION_WAIT_LF_ATK_2,		//�V�I�����O�U��
	R_ZION_WAIT_LF_ATK_3,		//�V�I�����O�U��
	R_ZION_WAIT_LF_ATK_4,		//�V�I�����O�U��
	R_ZION_WAIT_LB_ATK_1,		//�V�I�����O�U��
	R_ZION_WAIT_LB_ATK_2,		//�V�I�����O�U��
	R_ZION_WAIT_LB_ATK_3,		//�V�I�����O�U��
	R_ZION_WAIT_LB_ATK_4,		//�V�I�����O�U��
	R_ZION_WAIT_RF_ATK_1,		//�V�I�����O�U��
	R_ZION_WAIT_RF_ATK_2,		//�V�I�����O�U��
	R_ZION_WAIT_RF_ATK_3,		//�V�I�����O�U��
	R_ZION_WAIT_RF_ATK_4,		//�V�I�����O�U��
	R_ZION_WAIT_RB_ATK_1,		//�V�I�����O�U��
	R_ZION_WAIT_RB_ATK_2,		//�V�I�����O�U��
	R_ZION_WAIT_RB_ATK_3,		//�V�I�����O�U��
	R_ZION_WAIT_RB_ATK_4,		//�V�I�����O�U��


	R_VAN_WAIT_LEFTFRONT,		//���@���ҋ@(���O)
	R_VAN_WAIT_LEFTBACK,		//���@���ҋ@(����)
	R_VAN_WAIT_RIGHTFRONT,		//���@���ҋ@(�E�O)
	R_VAN_WAIT_RIGHTBACK,		//���@���ҋ@(�E��)
	R_VAN_WAIT_LF_ATK_1,		//�V�I�����O�U��
	R_VAN_WAIT_LF_ATK_2,		//�V�I�����O�U��
	R_VAN_WAIT_LF_ATK_3,		//�V�I�����O�U��
	R_VAN_WAIT_LF_ATK_4,		//�V�I�����O�U��
	R_VAN_WAIT_LB_ATK_1,		//�V�I�����O�U��
	R_VAN_WAIT_LB_ATK_2,		//�V�I�����O�U��
	R_VAN_WAIT_LB_ATK_3,		//�V�I�����O�U��
	R_VAN_WAIT_LB_ATK_4,		//�V�I�����O�U��
	R_VAN_WAIT_RF_ATK_1,		//�V�I�����O�U��
	R_VAN_WAIT_RF_ATK_2,		//�V�I�����O�U��
	R_VAN_WAIT_RF_ATK_3,		//�V�I�����O�U��
	R_VAN_WAIT_RF_ATK_4,		//�V�I�����O�U��
	R_VAN_WAIT_RB_ATK_1,		//�V�I�����O�U��
	R_VAN_WAIT_RB_ATK_2,		//�V�I�����O�U��
	R_VAN_WAIT_RB_ATK_3,		//�V�I�����O�U��
	R_VAN_WAIT_RB_ATK_4,		//�V�I�����O�U��

	R_RIO_WAIT_LEFTFRONT,		//���I�ҋ@(���O)
	R_RIO_WAIT_LEFTBACK,		//���I�ҋ@(����)
	R_RIO_WAIT_RIGHTFRONT,		//���I�ҋ@(�E�O)
	R_RIO_WAIT_RIGHTBACK,		//���I�ҋ@(�E��)
	R_RIO_WAIT_LF_ATK_1,		//�V�I�����O�U��
	R_RIO_WAIT_LF_ATK_2,		//�V�I�����O�U��
	R_RIO_WAIT_LF_ATK_3,		//�V�I�����O�U��
	R_RIO_WAIT_LF_ATK_4,		//�V�I�����O�U��
	R_RIO_WAIT_LB_ATK_1,		//�V�I�����O�U��
	R_RIO_WAIT_LB_ATK_2,		//�V�I�����O�U��
	R_RIO_WAIT_LB_ATK_3,		//�V�I�����O�U��
	R_RIO_WAIT_LB_ATK_4,		//�V�I�����O�U��
	R_RIO_WAIT_RF_ATK_1,		//�V�I�����O�U��
	R_RIO_WAIT_RF_ATK_2,		//�V�I�����O�U��
	R_RIO_WAIT_RF_ATK_3,		//�V�I�����O�U��
	R_RIO_WAIT_RF_ATK_4,		//�V�I�����O�U��
	R_RIO_WAIT_RB_ATK_1,		//�V�I�����O�U��
	R_RIO_WAIT_RB_ATK_2,		//�V�I�����O�U��
	R_RIO_WAIT_RB_ATK_3,		//�V�I�����O�U��
	R_RIO_WAIT_RB_ATK_4,		//�V�I�����O�U��
	//�e�ҋ@(�G)
	R_SAHAGIN1_WAIT_LEFTFRONT,		//�T�n�M��1�ҋ@(���O)
	R_SAHAGIN1_WAIT_LEFTBACK,		//�T�n�M��1�ҋ@(����)
	R_SAHAGIN1_WAIT_RIGHTFRONT,		//�T�n�M��1�ҋ@(�E�O)
	R_SAHAGIN1_WAIT_RIGHTBACK,		//�T�n�M��1�ҋ@(�E��)
	R_SAHAGIN2_WAIT_LEFTFRONT,		//�T�n�M��2�ҋ@(���O)
	R_SAHAGIN2_WAIT_LEFTBACK,		//�T�n�M��2�ҋ@(����)
	R_SAHAGIN2_WAIT_RIGHTFRONT,		//�T�n�M��2�ҋ@(�E�O)
	R_SAHAGIN2_WAIT_RIGHTBACK,		//�T�n�M��2�ҋ@(�E��)
	R_LIZARDMAN1_WAIT_LEFTFRONT,		//���U�[�h�}��1�ҋ@(���O)
	R_LIZARDMAN1_WAIT_LEFTBACK,		//���U�[�h�}��1�ҋ@(����)
	R_LIZARDMAN1_WAIT_RIGHTFRONT,		//���U�[�h�}��1�ҋ@(�E�O)
	R_LIZARDMAN1_WAIT_RIGHTBACK,		//���U�[�h�}��1�ҋ@(�E��)
	R_LIZARDMAN2_WAIT_LEFTFRONT,		//���U�[�h�}��2�ҋ@(���O)
	R_LIZARDMAN2_WAIT_LEFTBACK,		//���U�[�h�}��2�ҋ@(����)
	R_LIZARDMAN2_WAIT_RIGHTFRONT,		//���U�[�h�}��2�ҋ@(�E�O)
	R_LIZARDMAN2_WAIT_RIGHTBACK,		//���U�[�h�}��2�ҋ@(�E��)
	R_LIZARDMAN3_WAIT_LEFTFRONT,		//���U�[�h�}��3�ҋ@(���O)
	R_LIZARDMAN3_WAIT_LEFTBACK,		//���U�[�h�}��3�ҋ@(����)
	R_LIZARDMAN3_WAIT_RIGHTFRONT,		//���U�[�h�}��3�ҋ@(�E�O)
	R_LIZARDMAN3_WAIT_RIGHTBACK,		//���U�[�h�}��3�ҋ@(�E��)
	R_HOODMAN_WAIT_LEFTFRONT,		//�t�[�h�̒j�ҋ@(���O)
	R_HOODMAN_WAIT_LEFTBACK,		//�t�[�h�̒j�ҋ@(����)
	R_HOODMAN_WAIT_RIGHTFRONT,		//�t�[�h�̒j�ҋ@(�E�O)
	R_HOODMAN_WAIT_RIGHTBACK,		//�t�[�h�̒j�ҋ@(�E��)
	//�G�t�F�N�g
	R_AQUA_CURE1,
	R_AQUA_CURE2,
	R_AQUA_CURE3,
	R_AQUA_CURE4,
	R_SALAMANDER1,
	R_SALAMANDER2,
	R_SALAMANDER3,
	R_SALAMANDER4,
	R_KOUSYORAI1,
	R_KOUSYORAI2,
	R_KOUSYORAI3,
	R_KOUSYORAI4,
	R_HEELWIND1,
	R_HEELWIND2,
	R_HEELWIND3,
	R_HEELWIND4,
	//�U���G�t�F�N�g
	R_TISAIJIN1,
	R_TISAIJIN2,
	R_TISAIJIN3,
	R_TISAIJIN4,
	R_BAKUENKEN1,
	R_BAKUENKEN2,
	R_BAKUENKEN3,
	R_BAKUENKEN4,
	R_RIO_JUGEKI1,
	R_RIO_JUGEKI2,
	R_RIO_JUGEKI3,
	R_RIO_JUGEKI4,
	R_MAGUMA1,
	R_MAGUMA2,
	R_MAGUMA3,
	R_MAGUMA4,
	R_FROZEN_BULLET1,
	R_FROZEN_BULLET2,
	R_FROZEN_BULLET3,
	R_FROZEN_BULLET4,
	R_LIZARD_KAMI1,
	R_LIZARD_KAMI2,
	R_LIZARD_KAMI3,
	R_LIZARD_KAMI4,
	R_ICICLE_EDGE1,
	R_ICICLE_EDGE2,
	R_ICICLE_EDGE3,
	R_ICICLE_EDGE4,

	R_ICICLE_LEFTFLONT1,	//�V�I���A�C�V�N���G�b�W(���O)
	R_ICICLE_LEFTFLONT2,	//�V�I���A�C�V�N���G�b�W(���O)
	R_ICICLE_LEFTFLONT3,	//�V�I���A�C�V�N���G�b�W(���O)
	R_ICICLE_LEFTFLONT4,	//�V�I���A�C�V�N���G�b�W(���O)
	R_ICICLE_LEFTBACK1,		//�V�I���A�C�V�N���G�b�W(����)
	R_ICICLE_LEFTBACK2,		//�V�I���A�C�V�N���G�b�W(����)
	R_ICICLE_LEFTBACK3,		//�V�I���A�C�V�N���G�b�W(����)
	R_ICICLE_LEFTBACK4,		//�V�I���A�C�V�N���G�b�W(����)
	R_ICICLE_RIGHTFLONT1,	//�V�I���A�C�V�N���G�b�W(�E�O)
	R_ICICLE_RIGHTFLONT2,	//�V�I���A�C�V�N���G�b�W(�E�O)
	R_ICICLE_RIGHTFLONT3,	//�V�I���A�C�V�N���G�b�W(�E�O)
	R_ICICLE_RIGHTFLONT4,	//�V�I���A�C�V�N���G�b�W(�E�O)
	R_ICICLE_RIGHTBACK1,	//�V�I���A�C�V�N���G�b�W(�E��)
	R_ICICLE_RIGHTBACK2,	//�V�I���A�C�V�N���G�b�W(�E��)
	R_ICICLE_RIGHTBACK3,	//�V�I���A�C�V�N���G�b�W(�E��)
	R_ICICLE_RIGHTBACK4,	//�V�I���A�C�V�N���G�b�W(�E��)

	R_ZION_SP_BG,
	R_VAN_SP_BG,
	R_RIO_SP_BG,

	R_SP_ZION_NAME,
	R_SP_VAN_NAME,
	R_SP_RIO_NAME,

	R_TRIAN,
	R_TELOP,
	R_TELOP2,

	R_MATERIALSALAMANDER,
	R_MATERIALUNDINE,
	R_MATERIALSYLPH,
	R_MATERIALGNOME,

	R_FADE,
	R_WHITE_OUT,
	R_WHITE_OUT_VAN,

	R_EXPLODE1,
	R_EXPLODE2,
	R_EXPLODE3,
	R_EXPLODE4,

	R_CUT_EF1,
	R_CUT_EF2,
	R_CUT_EF3,
	R_CUT_EF4,

	R_CUT_EF01,
	R_CUT_EF02,
	R_CUT_EF03,
	R_CUT_EF04,

	R_CUT_EFZ01,
	R_CUT_EFZ02,
	R_CUT_EFZ03,
	R_CUT_EFZ04,

	R_CUT_EF_VAN01,
	R_CUT_EF_VAN02,
	R_CUT_EF_VAN03,
	R_CUT_EF_VAN04,

	R_SLASH,

	R_PHASE_BG,

	R_BAKUEN1,
	R_BAKUEN2,
	R_BAKUEN3,
	R_BAKUEN4,
	R_BAKUEN5,

	R_CURSOR_P,
	R_CURSOR_E,

	R_Z_V_WAIT_LF_1,		//�V�I���E���@�����O�ҋ@
	R_Z_V_WAIT_LF_2,		//�V�I���E���@�����O�ҋ@
	R_Z_V_WAIT_LF_3,		//�V�I���E���@�����O�ҋ@
	R_Z_V_WAIT_LF_4,		//�V�I���E���@�����O�ҋ@
	R_Z_V_WAIT_LB_1,		//�V�I���E���@������ҋ@
	R_Z_V_WAIT_LB_2,		//�V�I���E���@������ҋ@
	R_Z_V_WAIT_LB_3,		//�V�I���E���@������ҋ@
	R_Z_V_WAIT_LB_4,		//�V�I���E���@������ҋ@
	R_Z_V_WAIT_RF_1,		//�V�I���E���@���E�O�ҋ@
	R_Z_V_WAIT_RF_2,		//�V�I���E���@���E�O�ҋ@
	R_Z_V_WAIT_RF_3,		//�V�I���E���@���E�O�ҋ@
	R_Z_V_WAIT_RF_4,		//�V�I���E���@���E�O�ҋ@
	R_Z_V_WAIT_RB_1,		//�V�I���E���@���E��ҋ@
	R_Z_V_WAIT_RB_2,		//�V�I���E���@���E��ҋ@
	R_Z_V_WAIT_RB_3,		//�V�I���E���@���E��ҋ@
	R_Z_V_WAIT_RB_4,		//�V�I���E���@���E��ҋ@

	R_RIO_ENEMY_WAIT_LF_1,		//���I�E�t�[�h�̒j�ȊO�̓G���O�ҋ@
	R_RIO_ENEMY_WAIT_LF_2,		//���I�E�t�[�h�̒j�ȊO�̓G���O�ҋ@
	R_RIO_ENEMY_WAIT_LF_3,		//���I�E�t�[�h�̒j�ȊO�̓G���O�ҋ@
	R_RIO_ENEMY_WAIT_LF_4,		//���I�E�t�[�h�̒j�ȊO�̓G���O�ҋ@
	R_RIO_ENEMY_WAIT_LB_1,		//���I�E�t�[�h�̒j�ȊO�̓G����ҋ@
	R_RIO_ENEMY_WAIT_LB_2,		//���I�E�t�[�h�̒j�ȊO�̓G����ҋ@
	R_RIO_ENEMY_WAIT_LB_3,		//���I�E�t�[�h�̒j�ȊO�̓G����ҋ@
	R_RIO_ENEMY_WAIT_LB_4,		//���I�E�t�[�h�̒j�ȊO�̓G����ҋ@
	R_RIO_ENEMY_WAIT_RF_1,		//���I�E�t�[�h�̒j�ȊO�̓G�E�O�ҋ@
	R_RIO_ENEMY_WAIT_RF_2,		//���I�E�t�[�h�̒j�ȊO�̓G�E�O�ҋ@
	R_RIO_ENEMY_WAIT_RF_3,		//���I�E�t�[�h�̒j�ȊO�̓G�E�O�ҋ@
	R_RIO_ENEMY_WAIT_RF_4,		//���I�E�t�[�h�̒j�ȊO�̓G�E�O�ҋ@
	R_RIO_ENEMY_WAIT_RB_1,		//���I�E�t�[�h�̒j�ȊO�̓G�E��ҋ@
	R_RIO_ENEMY_WAIT_RB_2,		//���I�E�t�[�h�̒j�ȊO�̓G�E��ҋ@
	R_RIO_ENEMY_WAIT_RB_3,		//���I�E�t�[�h�̒j�ȊO�̓G�E��ҋ@
	R_RIO_ENEMY_WAIT_RB_4,		//���I�E�t�[�h�̒j�ȊO�̓G�E��ҋ@

	R_BOSS_WAIT_LF_1,		//�t�[�h�̒j���O�ҋ@
	R_BOSS_WAIT_LF_2,		//�t�[�h�̒j���O�ҋ@
	R_BOSS_WAIT_LF_3,		//�t�[�h�̒j���O�ҋ@
	R_BOSS_WAIT_LF_4,		//�t�[�h�̒j���O�ҋ@

	R_MATERIAL_SET,			//�t�H���g"�}�e���A���Z�b�g"

	R_WAIT_LF,				//�ҋ@�����
	R_WAIT_LB,
	R_WAIT_RF,
	R_WAIT_RB,	

	R_FACE_ZION,			//�V�I���G(�ȈՃX�e�[�^�X�p)
	R_FACE_VAN,				//���@���G(�ȈՃX�e�[�^�X�p)
	R_FACE_RIO,				//���I�G(�ȈՃX�e�[�^�X�p)
	R_FACE_BOSS,			//�t�[�h�̒j�G(�ȈՃX�e�[�^�X�p)
	R_FACE_SAHAGIN1,		//�T�n�M���P�G(�ȈՃX�e�[�^�X�p)
	R_FACE_SAHAGIN2,		//�T�n�M���Q�G(�ȈՃX�e�[�^�X�p)
	R_FACE_LIZARDMAN1,		//���U�[�h�}���P�G(�ȈՃX�e�[�^�X�p)
	R_FACE_LIZARDMAN2,		//���U�[�h�}���Q�G(�ȈՃX�e�[�^�X�p)

	R_STATENAME_ZION,			//�V�I���G(�ȈՃX�e�[�^�X�p)
	R_STATENAME_VAN,			//���@���G(�ȈՃX�e�[�^�X�p)
	R_STATENAME_RIO,			//���I�G(�ȈՃX�e�[�^�X�p)
	R_STATENAME_BOSS,			//�t�[�h�̒j�G(�ȈՃX�e�[�^�X�p)
	R_STATENAME_SAHAGIN1,		//�T�n�M���P�G(�ȈՃX�e�[�^�X�p)
	R_STATENAME_SAHAGIN2,		//�T�n�M���Q�G(�ȈՃX�e�[�^�X�p)
	R_STATENAME_LIZARDMAN1,		//���U�[�h�}���P�G(�ȈՃX�e�[�^�X�p)
	R_STATENAME_LIZARDMAN2,		//���U�[�h�}���Q�G(�ȈՃX�e�[�^�X�p)

	R_BG_PLAYER,	//�ȈՃX�e�[�^�XBG�v���C���[�p
	R_BG_ENEMY,		//�ȈՃX�e�[�^�XBG�G�l�~�[�p

	R_HP_FONT,
	R_AP_FONT,
	R_MG_FONT,
	R_MOV_FONT,
	R_SLASH_FONT,
	R_GAGE_WAKU,

	R_GAGE_HP,
	R_GAGE_AP,
	R_GAGE_MG,

	R_GAGE_HP_MAX,
	R_GAGE_AP_MAX,
	R_GAGE_MG_MAX,

	R_NOWLOADING,

	R_A,

	MAX_BATTLE_DATA,
};

enum BATTLE_SOUND_DATA	//�o�g���̃T�E���h�f�[�^
{
	//BGM
	S_BATTLE_BGM1,
	S_BATTLE_BGM2,
	//�K�E�Z(�V�I��)
	S_MIRAGE_EDGE,
	S_HEEL_WIND,		
	S_ICICLE_EDGE,	
	S_AQUA_CURE_Z,	
	//�K�E�Z(���@��)
	S_BAKUENKEN,		
	S_GOUSYORAI,		
	S_TISAIJIN,		
	S_KOUSYORAI,		
	//�K�E�Z(���I)
	S_BLAZE_BULLET,	
	S_BURST,			
	S_FROZEN_BULLET,	
	S_AQUA_CURE_R,	
	//�U��(�V�I��)
	S_ZION_ATTACK1,
	S_ZION_ATTACK2,
	S_ZION_ATTACK3,
	//�U��(���@��)
	S_VAN_ATTACK1,
	S_VAN_ATTACK2,
	S_VAN_ATTACK3,
	S_VAN_ATTACK4,
	S_VAN_ATTACK5,
	//�U��(���I)
	S_RIO_ATTACK1,
	S_RIO_ATTACK2,
	//���`(�V�I��)
	S_ZION_ABUSORYUTOEND,
	//S_ZION_ABUSORYUTOEND2,
	//���`(���@��)
	S_VAN_GOUVAKUREKOGEKI,

	//���ʉ�
	S_SWORDSWING1,	//�ʏ�U���V�I��
	S_SWORDSWING2,	//�ʏ�U�����@��
	S_GUN_SOUND,	//�ʏ�U�����I

	S_EF_BAKUENKEN,		//���Z������
	S_EF_ICICLE_EDGE,	//���Z�A�C�V�N���G�b�W
	S_EF_AQUACURE,		//���Z�A�N�A�L���A
	S_EF_MIRAGE_EDGE,	//���Z�~���[�W���G�b�W
	S_EF_HEEL_WIND,		//���Z�q�[���E�B���h
	S_EF_GOUSYORAI,		//���Z������
	S_EF_TISAIJIN,		//���Z�n�Ӑo
	S_EF_KOUSYORAI,		//���Z�|����
	S_EF_BLAZE_BULLET,	//���Z�u���C�Y�o���b�g
	S_EF_BURST,			//���Z�o�[�X�g
	S_EF_FROZEN_BULLET_SUCCESS,	//���Z�t���[�Y���o���b�g(����)
	S_EF_FROZEN_BULLET_MISS,	//���Z�t���[�Y���o���b�g(���s)
	S_EF_AQUA_CURE_R,	//���Z�A�N�A�L���A

	S_SWORDSWING3,	//���`�V�I�����ʉ�
	S_EXPLODE,		//���`���@�����ʉ�
	S_GAN_ACTION,	//���`���I���ʉ�

	S_OUGI_IN,
	S_CURSOR_MOVE,
	//�A�i�E���X
	S_WIN_MAN,
	S_WIN_MAN2,
	S_LOSE_MAN,
	S_LOSE_MAN2,
	S_LOSE_MAN3,

	S_WIN_GIRL,
	S_WIN_GIRL2,
	S_LOSE_GIRL,
	S_LOSE_GIRL2,
	S_LOSE_GIRL3,

	S_MATERIAL_SET_MAN,
	S_MATERIAL_SET_GIRL,
	S_AP_FALSE,

	MAX_S_BATTLE,
};

enum CHAR_MENU	//�o�g�������j���[
{
	CHAR_MOVE,		//�ړ�
	CHAR_ATTACK,	//�U��
	CHAR_SPECIAL,	//����
	CHAR_SP_EXTRA,	//���K�E�Z
	CHAR_STATE,		//�X�e�[�^�X
	CHAR_WAIT,		//�ҋ@

	COMMANDO_MAX
};

enum BATTLE_SCENE			//�o�g�����H��
{
	BATTLE_STATUS_MAKE,		//�o�g���̃X�e�[�^�X�����
	BATTLE_CONDITION,		//�o�g�����������E�s�k����(�퓬�J�n�O)
	BATTLE_MATERIAL_SET,	//�o�g���O�Ƀ}�e���A�����Z�b�g���܂�
	BATTLE_COMBAT,			//�o�g���퓬�t�B�[���h(�퓬�J�n)
	BATTLE_CLEAR,			//�o�g���I����e�`��(�퓬�I����)
};

enum DATA_NUMBER
{
	DATA_HP,	//HP
	DATA_AP,	//AP
	DATA_MG,	//MG
	DATA_MAXHP,	//MAXHP
	DATA_MAXAP,	//MAXAP
	DATA_MAXMG,	//MAXMG
	DATA_ATK,	//ATK
	DATA_DEF,	//DEF
	DATA_DEX,	//DEX
	DATA_AGL,	//AGL
	DATA_AP_R,	//AP_R
	DATA_MAG,	//MAG
	DATA_RES,	//RES
	DATA_MOV,	//MOV
	DATA_LUK,	//LUK
};

enum SIMPLE_DATA_NUMBER
{
	S_DATA_HP,		//HP
	S_DATA_AP,		//AP
	S_DATA_MG,		//MG
	S_DATA_MAXHP,	//MAXHP
	S_DATA_MAXAP,	//MAXAP
	S_DATA_MAXMG,	//MAXMG
	S_DATA_MOVE,	//MOVE
	S_DATA_ATK,		//ATK
	S_DATA_DEF,		//DEF
	S_DATA_MAG,		//MAG
	S_DATA_RES,		//RES
};

enum MAPTIP_OPERATION
{
	M_FULL,						//�S����
	M_SALAMANDER,				//�Α���
	M_UNDINE,					//������
	M_SYLPH,					//������
	M_GNOME,					//�y����
	M_NOTHING,					//�Ȃ�
};

enum SKILL_DETAIL
{
	SKILL_UP,			//�A�b�v
	SKILL_DOWN,			//�_�E��
	SKILL_DUMMY,		//�u�S�v�̕��������Ȃ�����
	SKILL_NOTHING,		//�Ȃ�
};

#define PLAYER_TURN		(1)	//�v���C���[�^�[��
#define ENEMY_TURN		(2)	//�G�l�~�[�^�[��
#define STATE_GAMEOVER	(1)	//�Q�[���I�[�o�[
#define STATE_CLEAR		(2)	//�N���A

#define RANGE_MIRAGE_EDGE	(1)	//�~���[�W���G�b�W�̍U���͈�
#define RANGE_HEEL_WIND		(3)	//�q�[���E�B���h�̍U���͈�
#define RANGE_ICICLE_EDGE	(2)	//�A�C�V�N���G�b�W�̍U���͈�
#define RANGE_AQUA_CURE_Z	(3)	//�A�N�A�L���A�̍U���͈�
#define RANGE_BAKUENKEN		(3)	//�������̍U���͈�
#define RANGE_GOUSYORAI		(2)	//�������̍U���͈�
#define RANGE_KOUSYORAI		(2)	//�|�����̍U���͈�
#define RANGE_TISAIJIN		(2)	//�n�Ӑo�̍U���͈�
#define RANGE_BLAZE_BULLET	(4)	//�u���C�Y�o���b�g�̍U���͈�
#define RANGE_BURST			(3)	//�o�[�X�g�̍U���͈�
#define RANGE_FROZEN_BULLET	(4)	//�t���[�Y���o���b�g�̍U���͈�
#define RANGE_AQUA_CURE_R	(3)	//�A�N�A�L���A�̍U���͈�

#define AP_MIRAGE_EDGE		(7)	//�~���[�W���G�b�W�̏���AP
#define AP_HEEL_WIND		(6)	//�q�[���E�B���h�̏���AP
#define AP_ICICLE_EDGE		(6)	//�A�C�V�N���G�b�W�̏���AP
#define AP_AQUA_CURE_Z		(7)	//�A�N�A�L���A�̏���AP
#define AP_BAKUENKEN		(7)	//�������̏���AP
#define AP_GOUSYORAI		(5)	//�������̏���AP
#define AP_KOUSYORAI		(5)	//�|�����̏���AP
#define AP_TISAIJIN			(7)	//�n�Ӑo�̏���AP
#define AP_BLAZE_BULLET		(5)	//�u���C�Y�o���b�g�̏���AP
#define AP_BURST			(5)	//�o�[�X�g�̏���AP
#define AP_FROZEN_BULLET	(5)	//�t���[�Y���o���b�g�̏���AP
#define AP_AQUA_CURE_R		(6)	//�A�N�A�L���A�̏���AP

#define GOUSYOURAI_EF_SIZE	(0.1)	//�������̃X�e�[�^�X�␳�l
#define KOUSYOURAI_EF_SIZE	(0.1)	//�|�����̃X�e�[�^�X�␳�l
#define BURST_EF_SIZE		(0.1)	//�o�[�X�g�̃X�e�[�^�X�␳�l

enum SKILL_TYPE
{
	ZION_SKILL_ATK = 1,		//�V�I������U��
	VAN_SKILL_ATK,		//���@������U��
	RIO_SKILL_ATK,		//���I����U��(����)
	ZION_SKILL_EFFECT,	//�V�I���������
	VAN_SKILL_EFFECT,	//���@���������
	RIO_SKILL_EFFECT,	//���I�������
};

enum CHARA_ID				//�ǂ̃L�������𔻒f����ID
{
	BLANK_ID,
	ZION_ID,		//�V�I��
	VAN_ID,			//���@��
	RIO_ID,			//���I
	SAHAGIN1_ID,		//�T�n�M��1
	SAHAGIN2_ID,		//�T�n�M��2
	LIZARD1_ID,		//���U�[�h1
	LIZARD2_ID,		//���U�[�h2
	LIZARD3_ID,		//���U�[�h3
	BOSS_ID,		//�t�[�h�̒j
};

enum DIRECTION_NO
{
	LEFT_FLONT,		//���O
	LEFT_BACK,		//����
	RIGHT_FLONT,	//�E�O
	RIGHT_BACK,		//�E��
};

#define STATE_SPASE_RANGE	(1)		//�X�e�[�^�X�ɂ���鉼�͈̔�