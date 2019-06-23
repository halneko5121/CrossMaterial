#include "Stage.h"

/************************************************************************************
 *																					*
 *	�����F�X�e�[�W�̊Ǘ������܂�													*
 *																					*
 *	�����FMAPTIP�Efield�֌W�̊Ǘ�													*
 *																					*
 *	�쐬���F2008�N 11�� 24��														*
 *																					*
 *	�X�V���F2008�N ����																*
 *													by	����@�w					*
 *																					*
 ************************************************************************************/

C_Stage::C_Stage(void)
{
	char_max = 0;
	player_max = 0;
	enemy_max = 0;
	
	Init();
	SetMaptip();
	//2/12�ǉ�(nisii)
	keep_id = 0;
	//2/12�ǉ�(nisii)
	keep_cmd = -1;
}

C_Stage::~C_Stage(void)
{
}

void C_Stage::Control(int * key)
{

}

void C_Stage::Draw()
{
}

void C_Stage::Release()
{
}

void C_Stage::Sound()
{
}

void C_Stage::FieldControl(int x,int y)		//�}�b�v�`�b�v�̕\���ʒu��ς���
{
	//MAPTIP�̕`��ʒu���_�ł���[0][0]�̈ʒu�������߂�
	field[0][0].x = CENTER_POSITION_X - ((x - y) * SLIDE_X);
	field[0][0].y = CENTER_POSITION_Y - ((x + y) * SLIDE_Y);
	//MAPTIP�̕`��ʒu�����_[0][0]�̈ʒu���猈�߂�
	for(int j = 0;j < MAX_MAPTIP_WIDE;j++){
		for(int i = 0;i < MAX_MAPTIP_LENGTE;i++){
			if(i == 0 && j == 0);
			else{	//[0][0]�͂������܂��Ă���̂Ł��ŏ��O
				field[i][j].x = field[0][0].x + ((i - j) * SLIDE_X);
				field[i][j].y = field[0][0].y + ((i + j) * SLIDE_Y);
			}
		}
	}
}

/************************************************************************************
 *	����	�FMAPTIP�̔z��̐���b���ɉ����Č��߂�									*
 *	����	�F�Ȃ�																	*
 *	�߂�l	�F�Ȃ�																	*
 *													by	�O��@�j					*
 ************************************************************************************/
void C_Stage::Init()	//���݂��ǂ̃X�g�[���[�Ȃ̂��ɂ���ă}�b�v�`�b�v�̗ʂ�������
{
	flag_story = STORY_LAST;

	//���ꂪ�Ăяo�����Ƃ������Ƃ͐퓬�V�[���ɓ������̂ŁA���b�ڂ��Ń}�b�v�`�b�v�̗ʂ�ς���(�o�g��field�̍L����ς���)
	switch(flag_story){
		case STORY_FIRST:
			maptip_x = 10;						//���b��10�}�X(��)
			maptip_y = 10;						//���b��10�}�X(�c)
			break;
		case STORY_SECOND:
			maptip_x = 20;						//��b��20�}�X(��)
			maptip_y = 20;						//��b��20�}�X(�c)
			break;
		case STORY_LAST:
			maptip_x = 15;						//�ŏI�b��20�}�X(��)
			maptip_y = 20;						//�ŏI�b��20�}�X(�c)
			break;
	}
	//���̘b���ɂ������}�b�v�`�b�v�ʂ�����������B
	memset(&field_maptip[0],0,sizeof(int) * (int)maptip_y * (int)maptip_x);	//MAPTIP�̔z���������

}

/************************************************************************************
 *	����	�F//MAPTIP��z���SET����B�}�b�v�`�b�v�Ȃǂ�TEXT����ǂݍ���			*
 *	����	�F�Ȃ�																	*
 *	�߂�l	�F�Ȃ�																	*
 *													by	�O��@�j					*
 ************************************************************************************/
void C_Stage::SetMaptip()	//�}�b�v�`�b�v�Ȃǂ�TEXT����ǂݍ���
{
	char pos_maptip[MAX_STRING] = {"last_stage"};		//MAPTIP�̔z�u�f�[�^
	char pos_character[MAX_STRING] = {"last_stage_char"};	//�L����(����)�̔z�u�f�[�^

	FILE *fp; 
	errno_t err;

	char l_stage_no[MAX_STRING];	//�X�e�[�W�f�[�^��ǂݍ��ވׂ̕�����i�[�p

	sprintf_s(l_stage_no,"MaptipData\\%s.txt",pos_maptip);

	if( (err = fopen_s(&fp,l_stage_no,"r") != 0) )
	{
		perror("�t�@�C���I�[�v���G���[");
	}	

	for(int i = 0; i < maptip_x;i++){
		for(int j = 0; j < maptip_y;j++){
			fscanf_s(fp,"%d,",&field_maptip[i][j]);
		}
	}
	fclose(fp);	  //�t�@�C�������B

	//�L�����z�u
	sprintf_s(l_stage_no,"MaptipData\\%s.txt",pos_character);

	if( (err = fopen_s(&fp,l_stage_no,"r") != 0) )
	{
		perror("�t�@�C���I�[�v���G���[");
	}	

	for(int i = 0; i < maptip_x;i++){
		for(int j = 0; j < maptip_y;j++){
			fscanf_s(fp,"%d,",&field_character[i][j]);
			//�ǉ�
			if(IdSeach(i,j) != 0){
				char_max++;
				if(IdSeach(i,j) < U_SAHAGIN1)	player_max++;
				else	enemy_max++;
			}
			//�ǉ�
		}
	}
	fclose(fp);	  //�t�@�C�������B
}

void C_Stage::AreaSeach(int char_position_x,int char_position_y,int unit_id,int distance,int char_commando)	//�ړ��E�U���ł���G���A���Z�o
{
	//int cnt = 0;	//�f�o�b�N�p
	//�����L�������ς���Ă�����
	if(unit_id != keep_id || char_commando != keep_cmd){	//2/12�ǉ�(nisii)
		//�ړ��ł���G���A��������
		for(int i = 0;i < maptip_x;i++){
			for(int j = 0;j < maptip_y;j++){
				area_info[i][j] = 0;
			}
		}
		area_distance = distance;	//����������
		//�ړ��ł���G���A�����߂�
		for(int i = -area_distance;i <= area_distance;i++){	//�|�ړ��͂���ړ��͂܂ŉ�(X����)
			for(int j = -area_distance;j <= area_distance;j++){	//��ɓ���(Y����)
				if(char_position_x + i >= 0 && char_position_x + i < MAX_MAPTIP_LENGTE){	//�z���[20]�ō�����ꍇ�O�`19�܂ł����Ȃ����ߗ\�h��
					if(char_position_y + j >= 0 && char_position_y + j < MAX_MAPTIP_WIDE){	//��ɓ���
						//i��j�̒l���|�̎��A-1�������Đ�Βl�ɂ��Ai��j�̍��v���ړ��������z���Ă��Ȃ��ꍇ�͂P�������(�ړ��ł���)
						if(i < 0 && j < 0){
							area_info[char_position_x + i][char_position_y + j] = -i + -j;
//							cnt++;	//�f�o�b�N�p
						}
						//i�̒l���|�̎�
						else if(i < 0){
							area_info[char_position_x + i][char_position_y + j] = -i + j;
//							cnt++;	//�f�o�b�N�p
						}
						//j�̒l���|�̎�
						else if(j < 0){
							area_info[char_position_x + i][char_position_y + j] = i + -j;
//							cnt++;	//�f�o�b�N�p
						}
						//i��j�̒l���{�̎��Ai��j�̍��v���ړ��������z���Ă��Ȃ��ꍇ�͂P�������(�ړ��ł���)
						else{
							area_info[char_position_x + i][char_position_y + j] = i + j;
//							cnt++;	//�f�o�b�N�p
						}
					}
				}
			}
		}
	}
	if(char_commando == CHAR_MOVE){
		for(int i = 0;i < maptip_x;i++){
			for(int j = 0;j < maptip_y;j++){
				if(field_character[i][j] != 0){
					if(field_character[i][j] >= U_SAHAGIN1){
						area_info[i][j] = field_character[i][j];
					}
				}
			}
		}
	}

	int min_keep = 100;

	if(char_commando == CHAR_MOVE){
		for(int k = 2;k <= area_distance;k++){
			for(int i = -area_distance;i <= area_distance;i++){
				for(int j = -area_distance;j <= area_distance;j++){
					if(area_info[char_position_x + i][char_position_y + j] == k){
						if(area_info[char_position_x + i + 1][char_position_y + j] == k - 1){
						}
						else if(area_info[char_position_x + i - 1][char_position_y + j] == k - 1){
						}
						else if(area_info[char_position_x + i][char_position_y + j + 1] == k - 1){
						}
						else if(area_info[char_position_x + i][char_position_y + j - 1] == k - 1){
						}
						else{
							if(min_keep > area_info[char_position_x + i + 1][char_position_y + j] && area_info[char_position_x + i + 1][char_position_y + j] != 0){
								min_keep = area_info[char_position_x + i + 1][char_position_y + j];
							}
							if(min_keep > area_info[char_position_x + i - 1][char_position_y + j] && area_info[char_position_x + i - 1][char_position_y + j] != 0){
								min_keep = area_info[char_position_x + i - 1][char_position_y + j];
							}
							if(min_keep > area_info[char_position_x + i][char_position_y + j + 1] && area_info[char_position_x + i][char_position_y + j + 1] != 0){
								min_keep = area_info[char_position_x + i][char_position_y + j + 1];
							}
							if(min_keep > area_info[char_position_x + i][char_position_y + j - 1] && area_info[char_position_x + i][char_position_y + j - 1] != 0){
								min_keep = area_info[char_position_x + i][char_position_y + j - 1];
							}
							area_info[char_position_x + i][char_position_y + j] = min_keep + 1;
							min_keep = 100;
						}
					}
				}
			}
		}
		for(int i = -area_distance;i <= area_distance;i++){
			for(int j = -area_distance;j <= area_distance;j++){
				if(area_info[char_position_x + i][char_position_y + j] > distance){
					area_info[char_position_x + i][char_position_y + j] = 0;
				}
				else if(area_info[char_position_x + i][char_position_y + j] > 0){
					area_info[char_position_x + i][char_position_y + j] = 1;
				}
			}
		}
	}
	else{
		for(int i = -area_distance;i <= area_distance;i++){
			for(int j = -area_distance;j <= area_distance;j++){
				if(area_info[char_position_x + i][char_position_y + j] > distance){
					area_info[char_position_x + i][char_position_y + j] = 0;
				}
				else if(area_info[char_position_x + i][char_position_y + j] > 0){
					area_info[char_position_x + i][char_position_y + j] = 1;
				}
			}
		}
	}
	area_info[char_position_x][char_position_y] = 2;

	if(unit_id == VAN_ID && char_commando == CHAR_SPECIAL && distance == 3){
		for(int i = -area_distance;i <= area_distance;i++){
			for(int j = -area_distance;j <= area_distance;j++){
				area_info[char_position_x + i][char_position_y + j] = 0;
				if(i == 0){
					area_info[char_position_x + i][char_position_y + j] = 1;
				}
				if(j == 0){
					area_info[char_position_x + i][char_position_y + j] = 1;
				}
			}
		}
		area_info[char_position_x][char_position_y] = 2;
	}

	//cnt = cnt;	//�f�o�b�N�p
	if(char_commando == 0)
	{
		for(int i = 0;i < maptip_x;i++){
			for(int j = 0;j < maptip_y;j++){
				if(char_position_x == i && char_position_y == j);
				else{
					if(field_maptip[i][j] >= 0 && field_maptip[i][j] < 4 || IdSeach(i,j) != 0){
						area_info[i][j] = 0;
					}
				}
			}
		}
	}
	keep_id = unit_id;
	keep_cmd = char_commando;	//2/12�ǉ�(nisii)
}

void C_Stage::AreaDeleat()		//���������G���A��������
{
	for(int i = 0;i < maptip_x;i++){
		for(int j = 0;j < maptip_y;j++){
			area_info[i][j] = 0;
		}
	}
}

int C_Stage::IdSeach(int x,int y)	//�ǂ̃L�����Ȃ̂��𔻒f�@��@51 = �T�n�M��2
{
	int char_id_no = 0;
	switch(field_character[x][y] / 10)
	{
	case BLANK_ID:
		char_id_no = U_BLANK_AREA;
		break;
	case ZION_ID:
		char_id_no = U_ZION;
		break;
	case VAN_ID:
		char_id_no = U_VAN;
		break;
	case RIO_ID:
		char_id_no = U_RIO;
		break;
	case SAHAGIN1_ID:
		char_id_no = U_SAHAGIN1;
		break;
	case SAHAGIN2_ID:
		char_id_no = U_SAHAGIN2;
		break;
	case LIZARD1_ID:
		char_id_no = U_LIZARDMAN1;
		break;
	case LIZARD2_ID:
		char_id_no = U_LIZARDMAN2;
		break;
	case LIZARD3_ID:
		char_id_no = U_LIZARDMAN3;
		break;
	}
	return char_id_no;
}

int C_Stage::GameStateSeach()
{
	int flag_gamestate = 0;
	int cnt_player = 0;
	int cnt_enemy = 0;
	for(int i = 0;i < maptip_x;i++)
	{
		for(int j = 0;j < maptip_y;j++)
		{
			if(IdSeach(i,j) == U_ZION){
				cnt_player++;
			}
			else if(IdSeach(i,j) == U_LIZARDMAN3)	cnt_enemy++;
			if(j == 19){
				if(IdSeach(i,j) >= U_SAHAGIN1) return STATE_GAMEOVER;
			}
		}
	}
	if(cnt_player == 0)	flag_gamestate = STATE_GAMEOVER;
	else if(cnt_enemy == 0)	flag_gamestate = STATE_CLEAR;
	return flag_gamestate; 
}

