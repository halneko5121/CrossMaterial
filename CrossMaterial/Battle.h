#pragma once

/************************************************************************************
 *																					*
 *	�����FBATTLE�p�[�g���Ǘ����܂�													*
 *																					*
 *	�����FBATTLE�p�[�g��Control��Render������܂�									*
 *																					*
 *	�쐬���F2008�N 11��21��															*
 *																					*
 *	�X�V���F2008�N ����																*
 *													by	����@�w					*
 *																					*
 ************************************************************************************/

/*================================
	
		INCLUDE

=================================*/
#include<math.h>

#include "Scene.h"
#include "Stage.h"

#include "D_Battle.h"
#include "Define.h"

#include "DirectGraphics.h"

#include "Calculate.h"	//�_���[�W�v�Z�N���X�ǉ�2/12(nisii)

#include "CharaData_Zion.h"
#include "CharaData_Van.h"
#include "CharaData_Rio.h"
#include "CharaData_Enemy1.h"
#include "CharaData_Enemy2.h"
#include "CharaData_Enemy3.h"
#include "CharaData_Enemy4.h"
#include "CharaData_Boss.h"

#include <cstdlib>
#include <new>
#include <memory>

using namespace std;

#include <crtdbg.h>
// crtdbg.h ���C���N���[�h�������Ƃ� _CRTDBG_MAP_ALLOC ���`���Ă��
#define _CRTDBG_MAP_ALLOC
#define new  ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

/*================================
	
		Define

=================================*/
#define MAX_TEXTURE_BATTLE	(20)		//�e�N�X�`���[�̐�
#define TEXTURE_SIZE		(1024.f)	//�e�N�X�`���̃T�C�Y
#define TEXTURE_SIZE2		(512.f)		//�e�N�X�`���̃T�C�Y�A

#define SIMPLEMAPTIP_X	(460.f)	//�ȈՃX�e�[�^�XX���S
#define SIMPLEMAPTIP_Y	(510.f)	//�ȈՃX�e�[�^�XY���S

#define SIMPLE_HAM_X	(138.f)	//�ȈՃX�e�[�^�X�HP���AP���MG��̂w�̒��S
#define SIMPLE_HAM_Y	(482.f)	//�ȈՃX�e�[�^�X�HP���AP���MG��̂x�̒��S

#define SIMPLE_AD_X	(280.f)	//�ȈՃX�e�[�^�X�ATK���DEF��̂w�̒��S
#define SIMPLE_AD_Y	(530.f)	//�ȈՃX�e�[�^�X�ATK���DEF��̂x�̒��S

#define SIMPLE_MR_X	(430.f)	//�ȈՃX�e�[�^�X�MAG���RES��̂w�̒��S
#define SIMPLE_MR_Y	(530.f)	//�ȈՃX�e�[�^�X�MAG���RES��̂x�̒��S

#define SIMPLE_INCREASE_Y	(22.5f)	//�ȈՃX�e�[�^�X�DEF���RES��̑�����

#define SIMPLE_CHARA_X		( 77.f)		//�ȈՃX�e�[�^�X�̃L�����G��X���S
#define SIMPLE_CHARA_Y		(526.f)		//�ȈՃX�e�[�^�X�̃L�����G��Y���S

typedef struct _GetBattleData{	//�퓬�p�ɕK�v�ȃf�[�^
	CharaData_status status;	//�v�Z�p�X�e�[�^�X
	int direction;				//����
}GetBattleData;

typedef struct _GetBattleDataVan{	//�퓬�p�ɕK�v�ȃf�[�^(���@���d�l)
	CharaData_status status;
	int direction;
	double hitDamagevan;
}GetBattleDataVan;

typedef struct _DrawBattleData{
	int damage;
	int move;
	bool act;
	float posX;
	float posY;
}DrawBattleData;
class C_Battle :	public C_Scene
{
private:
	C_Control *key;
	C_Stage *stage;

	GetBattleData getPlData;			//�v���C���[�̃f�[�^
	GetBattleData getEnemyData;			//�G�̃f�[�^

	double hitDamage;					//�󂯂��_���[�W
	DrawBattleData drawBattleData[3];	//�`��p�f�[�^
	DrawBattleData drawBattleVanData[12][3];//���@������U�����̕`��p�f�[�^
	DrawBattleData drawSpZionData[17][3];	//�V�I�����K�E�Z�̕`��p�f�[�^
	bool hitInit;						//�_���[�W�Z�b�g�p�t���O
	bool battleDrawEnd;					//���ׂĂ̕`�悪�I�������

	double recovery_point;

	COORDINATE keep_skillarea[12];

	bool AtkEfStart;

	GetBattleDataVan getEnemydatavan[12];
	GetBattleDataVan getenemydatazion[17];

	//�ǉ�2/13(nisii)
	bool charaAttack;			//�L�����A�^�b�N��
	int  charaAttackCnt;		//�L�����A�^�b�N�J�E���g
	int  keepAttackCnt;			//�ŏ��̃J�E���g��ۑ�
	int atkDeray;
	static const int  deray[8][4];			//�U���̃f�B���C
	//�ǉ������܂�
	bool charaSkillatk;			//�L�����X�L���U����
	bool SkillEfStart;

	static const int deray_skill[4];	//����U��(�n�Ӑo�̃f�B���C)
	static const int deray_wait[8][4];

	int charaAttackEfCnt;

	bool flag_battle_status_draw;
	int cnt_draw;

	C_Calculate *damegeCulc;	//�_���[�W�v�Z�N���X�ǉ�2/12(nisii)
	C_CharaData_Zion	*zion;
	C_CharaData_Van		*van;
	C_CharaData_Rio		*rio;
	C_CharaData_Enemy1	*enemy1;
	C_CharaData_Enemy2	*enemy2;
	C_CharaData_Enemy3	*enemy3;
	C_CharaData_Enemy4	*enemy4;
	C_CharaData_Boss	*boss;

	CharaData_status *status;
	CharaData_battle *status_battle;

	bool flag_zion_num_end;

	bool flag_sp_draw_off;

	int use_texture;			//�g�p����摜�̖������i�[����B

	int time_cnt;				//���ԑ�������鎞�g�p
	int flag_turn;				//PLAYER PHASE�EENEMY PHASE���Ǘ�

	int phase_shift;			//PLAYER PHASE�EENEMY PHASE��`�悷�鎞��`�̐؂�ւ�������
	int flag_turn_player;		//PLAYER TURN���L�����@�V�I���E���@���E���I���Ǘ�
	int flag_turn_enemy;		//ENEMY  TURN���@�G						   ���Ǘ�

	int flag_any_end;			//�ȒP�Ȓi�K��m�点��t���O(��:�o�g���ł̃J�[�\���ړ��E�R�}���h�ړ��Ȃ�)
	int battle_change;			//�o�g���@�J�n�O�E�퓬���E�I������Ǘ�
	int flag_char_commando;		//�R�}���h��I�����Ă��邩���f(�ړ����悤�Ƃy�������ĂȂ�)

	DWORD area_shift;			//�G���A�̐؂�ւ�(�ړ��G���A�̏ꍇ�ƍU���G���A�̏ꍇ�̐F��������)

	int x_temporarily;			//��
	int y_temporarily;			//��
	int locate_cursor_commando;	//�J�[�\���̈ʒu(�R�}���h)
	float fade;					//PLAYER TURN��\�����Ɏg�p
	int flag_change_keep;		//���݂ǂ̃V�[���̃J�[�\�����������Ă��邩��ۑ�����

	int flag_char_selected[3];
	int keep_field_id[10];		//43�Ȃǃt�B�[���h��ł�ID��ۑ�����(�L������)

	COORDINATE locate_cursor_field;	//�J�[�\���̈ʒu(�t�B�[���h)
	COORDINATE keep_posi;
	COORDINATE deleat_posi;

	int material_set[3];

	int cnt_death;

	int cursor_color;

	int direction;

	int keep_char_select;		//�L������ID�ۑ�(�V�I���Ȃ̂����@���Ȃ̂��T�n�M���Ȃ̂�)
	int keep_id;				//�L������ID�ۑ�(�T�n�M���̂P�̖ڂȂ̂��V�I���Ȃ̂����U�[�h�}���̂Q�̖ڂȂ̂��Ȃ�)

	int keep_direction;

	int draw_direction;			//������ۑ�����

	int flag_atk;
	int flag_skill;

	double attribute_advantage;

	int atk_draw;
	//�X�e�[�^�X�`��Ɏg�p
	int font_center_x;	//DrawCC�̌Œ�t�H���g�̂w���W�̒��S
	int add_font_canter_y;	//DrawCC�̌Œ�t�H���g�̂x���W�̒��S�̍��v
	int font_center_y;	//DrawCC�̌Œ�t�H���g�̂x���W�̒��S	
	int font_increase_y;	//Y���W�̌Œ�t�H���g�̒��S�̋�`������
	int font_standard;	//�Œ�t�H���g�̍����鎞�̊
	int num_center_x;	//DrawCC�̐����̂w���W�̒��S
	int add_num_canter_y;	//DrawCC�̐����̂x���W�̒��S�̍��v
	int num_center_y;	//DrawCC�̐����̂x���W�̒��S	
	int num_increase_y;	//Y���W�̐����̃t�H���g�̒��S�̋�`������
	int num_standard;	//�����̍����鎞�̊
	int indicate;		//�\���L����
	int mrx_increase_left;//�}�g���N�Xleft��`�f�[�^�̑�����
	int mrx_increase_right;//�}�g���N�Xright��`�f�[�^�̑�����
	int mrx_center_x;	//�����̑傫���ɂ���Ē��S�����킹��
	int mrl_increase_left;//�}�e���A����left��`�f�[�^�̑�����
	int mrl_increase_right;//�}�e���A����right��`�f�[�^�̑�����
	int mrl_center_x;	//�����̑傫���ɂ���Ē��S�����킹��
	int set_material;	//�Z�b�g���Ă���}�e���A��
	int mrl_magic_1;	//�}�e���A���Z���P
	int magic1_center_x;//�Z��x���S���W
	int mrl_detail_1;	//�}�e���A���Z�P�̏ڍ�
	int mrl_detail1_center_x;	//�}�e���A���ڍ׋Z1�̒��S���W
	int mrl_magic_2;	//�}�e���A���Z���Q
	int magic2_center_x;//�Z��x���S���W
	int mrl_detail_2;	//�}�e���A���Z�Q�̏ڍ�
	int mrl_detail2_center_x;	//�}�e���A���ڍ׋Z1�̒��S���W
	int chara_no;		//�L�����N�^�[No.
	int flag_status_draw;

	int flag_geme_end;
	double fade2;
	int fade3;
	int cursor_locate_x;
	double cursor_locate_y;

	//int topography_effect;
	int flag_simple_chara;		//�ȈՃL�����N�^�[�X�e�[�^�X�`��
	int chara_id;				//�L�����N�^�[��id
	int landform;				//�n�`�̏��
	int simple_num_x;		//�ȈՃX�e�[�^�Xx�̐����̈ʒu
	int simple_num_y;		//�ȈՃX�e�[�^�Xy�̐����̈ʒu
	int sim_num_standard;	//�
	int simple_chara_name;
	int chara_now_area;		//�L�����N�^�[������}�b�v�`�b�v���
	double test_point;		//�l���A���Ă邩�m�F�e�X�g

	int locate_cursor_skill;
	int cut_out;
	int flag_skill_ef[3];
	int keep_skill_ef_id[3];
	int charaRecoveryCnt;
	int charaSkillCnt;

	int sound_in;

	int flag_field_show;	//�o�g���J�n�O�Ƀt�B�[���h�S�̂�������

	float status_enemy;

	int charaWaitZion;		//�V�I���̑ҋ@�`��؂�ւ�������
	int charaWaitVan;		//���@���̑ҋ@�`��؂�ւ�������
	int charaWaitRio;		//���I�̑ҋ@�`��؂�ւ�������
	int charaWaitSahagin1;	//�T�n�M���P�̑ҋ@�`��؂�ւ�������
	int charaWaitSahagin2;	//�T�n�M���Q�̑ҋ@�`��؂�ւ�������
	int charaWaitLizardman1;//���U�[�h�}���P�̑ҋ@�`��؂�ւ�������
	int charaWaitLizardman2;//���U�[�h�}���Q�̑ҋ@�`��؂�ւ�������
	int charaWaitBoss;		//�t�[�h�̒j�̑ҋ@�`��؂�ւ�������

	int fade_in_out;

	int cnt_turn;
	bool flag_use_skill[3];

	float telop;
	float telop2;
	int flag_material_seted[3];
	int flag_sp_extra;
	bool flag_sp_extra_draw;
	int fade_color;
	bool fade_end;
	bool sp_end_extra;
	//���`�p
	int cnt_ex_alltime;	//���`���̎��Ԍo�߂��J�E���g
	int fade_black;		//�u���b�N�A�E�g���J���[����������̂Ɏg�p
	int fade_out_black;	//�u���b�N�A�E�g���̃t�F�[�h�A�E�g�ȂǂɎg�p
	bool flag_black;	//�u���b�N�A�E�g�������������Ɏg���t���O
	
	//�{�C�X���f�p
	bool flag_voice;
	int  voice_change;
	bool flag_voice_attack;
	int  voice_change_attack;
	bool flag_sound_ef;
	int  sound_ef_change_attack;
	bool flag_voice_ex;
	int  voice_change_ex;
	bool flag_sound_ex;
	int  sound_ef_change_ex;
	bool flag_sound_sp;
	int  sound_ef_change_sp;
	bool flag_sound_in;
	bool flag_sound_cursor;
	bool flag_voice_setumei;
	int  voice_change_setumei;

	//AI�p
	int selectionId;
	int flag_enemy_atk;
	int enemyAttackCnt;
	//�A�h�x���`���[
	int m_key_cnt;
public:
	C_Battle(C_DGraphics *in_graphics);
	void Control(int* key);
	void Draw();
	void Sound();						//�T�E���h�̊Ǘ�
	void Release();
	void Init();

	void AttackEffectDraw(int i,int j);	//�U�����̃G�t�F�N�g�`��


	void BattleStatusMake();			//�o�g���Ŏg���X�e�[�^�X�𐶐�
	void BattleMaterial(int* key);		//�o�g���J�n�O�}�e���A���Z�b�g
	void BattleCondition(int* key);		//�o�g���J�n�O
	void BattleCombat(int* key);		//�o�g����
	void BattleCombatSystem(int* key);	//�o�g�����̃R�}���h�Ȃǂ̏���
	void BattleClear(int* key);			//�o�g���N���A��

	void DamegeExtra();
	void DamegeExtraZion();

	//�ǉ�2/12(nisii)
	void BattleProcess(void);			//�o�g�����̏����i�퓬�Ȃǁj
	void BattleDataSet(void);			//��풆�̓G�ƃv���C���[�̃f�[�^���Z�b�g
	void BattleEndProcess(void);		//�o�g���I������
	void BattleProcessDraw(void);		//�o�g�����̕`��
	float BattleDrawConvert(int id , bool x = false);		//�o�g�����̕`��ʒu�C��
	//�ǉ������܂�
	void BattleSkill(int* key);			//����U�����X�L���I��
	void SkillProcess();				//����U���̏���
	void BattleSkillDraw();				//����U�����`��
	void SkillDetailDraw();				//����U����I�񂾍ۂ̕`��
	void BattleDataSetVan();			//���@���̓���U���̌��ʔ͈͂��Ⴄ����
	void BattleDataSetZion();
	void BattleEndProcessVan();			//���@���͔͈͂ł��ʂ���
	void CharaSkillDraw(int i,int j);				//����U���E�񕜂Ȃǂ̕`��

	//�GAI
	void EnemyAi(int* key);
	void EnemyMove();
	void EnemyAttack();
	void EnemyBattleProcess();
	void EnemyBattleDataSet();
	//
	void BattleMaterialDraw();			//�o�g���J�n�O�}�e���A���Z�b�g�`��
	void BattleConditionDraw();			//�o�g���J�n�O�`��
	void BattleCombatDraw();			//�o�g�����`��
	void BattleClearDraw();				//�o�g���N���A��`��

	void PlayerTurn(int* key);					//PLAYER TURN���̏����܂Ƃ�
	void EnemyTurn(int* key);					//ENEMY TURN���̏����܂Ƃ�

	void FieldDraw();

	void CursorControlField(int* key);	//�J�[�\������(���݂̏c�C���݂̉��C�t�B�[���h���)
	void CursorControl(int* key,int max_cursor);	//�J�[�\������(��,�ǂ̃V�[���Ȃ̂�,Z�L�[�������ꂽ���ǂ����𔻒肷��ϐ�)

	void StatusBackGroundDraw();//�X�e�[�^�X�̔w�i
	void StatusFontDraw();		//�t�H���g�̕`��
	void StatusDataDraw();		//���l�̕`��(�i�ނ��Ƃɂ���ĕω�����)
	void StatusCharaDraw();		//�L�����`��i�����A�}�g���N�X�A�}�e���A���j
	void SimpleStatusDraw();	//�ȈՃX�e�[�^�X�̒n�`�`��
	void CheckField();			//�}�b�v�`�b�v�ɂ���ĕ`�揈��
	void SimpleCharaStatusDraw();	//�ȈՃX�e�[�^�X�̃L�����f�[�^�̕`��
	void SimpleDrawFlag();			//�ȈՃX�e�[�^�X�̃L�����N�^�[�̂h�c�ɂ�鏈��
	void SimpleCharaDraw();			//�ȈՃX�e�[�^�X�̃L�����`��

	void ApRecovery();	//�^�[�����I��������AP���񕜂�����

	// ���j�b�g�f�[�^
	void SetStatus();		//�e�L�����X�e�[�^�X���X�e�[�^�X�\���̔z��Ɋi�[����
	void InitStatus();		//�e�L�����X�e�[�^�X������������

	bool GetTurnEndflag();	//�s���I�����Ă��邩�̃t���O

	void ChageActEnd();		//�^�[�����ς��ۍs���I���t���O��߂�

	void SetDamageVan();

	void CursorSelectChara(int* key);
	void CharSeach(int keep_cursor_posi_id,bool select_player);

	bool SelectedCommando();

	//���`
	void BattleSpExtra();		//���`����
	void BattleSpExtradraw();	//���`�`��(���ʕ���)
	void SpExZionDraw();		//���`�`��(�V�I��)
	void SpExVanDraw();			//���`�`��(���@��)
	void SpExRioDraw();			//���`�`��(���I)

public:
	int StatusSeachPosi(int x,int y);	//���W���炻�̈ʒu�ɂ���L�����̃X�e�[�^�X��T��(�e�ʒu��
	int StatusSeachPosi(COORDINATE no);	//���W���炻�̈ʒu�ɂ���L�����̃X�e�[�^�X��T��(�\���̔�

	int StatusSeachId(int id);		//�X�e�[�^�X�o�g����ID���猟������

	double TopographyEffect();			//�n�`���ʂ̔{����Ԃ�

	int UseMoveAP();				//�L�����N�^�[�̈ړ�����AP�̒l��Ԃ�
	
	int UseNormalAttackAP();		//�L�����N�^�[�̒ʏ�U������AP�̒l��Ԃ��B

	int UseSpecialAP1();		//�L�����N�^�[�̓���U������AP�̒l��Ԃ�

	int UseSpecialAP2();		//�L�����N�^�[�̓�����ʏ���AP�̒l��Ԃ�

	int UseDefenseAP();				//�L�����N�^�[�̖h�����AP�̒l��Ԃ�

	void SahaginAITEST(int* key);			//�T�n�M����AI�e�X�g

	void SetDamage(int id, int damage) { status[ id ].m_hp -= damage; }
	void SetRecovery(int id,int recovery);
	bool DeathCheck(int id)	{ return status[ id ].m_hp <= 0; }
	void InitBattleData();

	void CursorUp();
	void CursorDown();
	void CursorLeft();
	void CursorRight();
public:
	~C_Battle();
};
