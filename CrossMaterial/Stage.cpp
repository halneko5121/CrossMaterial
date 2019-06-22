#include "Stage.h"

/************************************************************************************
 *																					*
 *	役割：ステージの管理をします													*
 *																					*
 *	説明：MAPTIP・field関係の管理													*
 *																					*
 *	作成日：2008年 11月 24日														*
 *																					*
 *	更新日：2008年 月日																*
 *													by	平野　努					*
 *																					*
 ************************************************************************************/

C_Stage::C_Stage(void)
{
	char_max = 0;
	player_max = 0;
	enemy_max = 0;
	
	Init();
	SetMaptip();
	//2/12追加(nisii)
	keep_id = 0;
	//2/12追加(nisii)
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

void C_Stage::FieldControl(int x,int y)		//マップチップの表示位置を変える
{
	//MAPTIPの描画位置原点である[0][0]の位置情報を求める
	field[0][0].x = CENTER_POSITION_X - ((x - y) * SLIDE_X);
	field[0][0].y = CENTER_POSITION_Y - ((x + y) * SLIDE_Y);
	//MAPTIPの描画位置を原点[0][0]の位置から決める
	for(int j = 0;j < MAX_MAPTIP_WIDE;j++){
		for(int i = 0;i < MAX_MAPTIP_LENGTE;i++){
			if(i == 0 && j == 0);
			else{	//[0][0]はもう決まっているので↑で除外
				field[i][j].x = field[0][0].x + ((i - j) * SLIDE_X);
				field[i][j].y = field[0][0].y + ((i + j) * SLIDE_Y);
			}
		}
	}
}

/************************************************************************************
 *	説明	：MAPTIPの配列の数を話数に応じて決める									*
 *	引数	：なし																	*
 *	戻り値	：なし																	*
 *													by	三上　亘					*
 ************************************************************************************/
void C_Stage::Init()	//現在がどのストーリーなのかによってマップチップの量を初期化
{
	flag_story = STORY_LAST;

	//これが呼び出されるということは戦闘シーンに入ったので、何話目かでマップチップの量を変える(バトルfieldの広さを変える)
	switch(flag_story){
		case STORY_FIRST:
			maptip_x = 10;						//第一話は10マス(横)
			maptip_y = 10;						//第一話は10マス(縦)
			break;
		case STORY_SECOND:
			maptip_x = 20;						//二話は20マス(横)
			maptip_y = 20;						//二話は20マス(縦)
			break;
		case STORY_LAST:
			maptip_x = 15;						//最終話も20マス(横)
			maptip_y = 20;						//最終話も20マス(縦)
			break;
	}
	//その話数にあったマップチップ量を初期化する。
	memset(&field_maptip[0],0,sizeof(int) * (int)maptip_y * (int)maptip_x);	//MAPTIPの配列を初期化

}

/************************************************************************************
 *	説明	：//MAPTIPを配列にSETする。マップチップなどをTEXTから読み込み			*
 *	引数	：なし																	*
 *	戻り値	：なし																	*
 *													by	三上　亘					*
 ************************************************************************************/
void C_Stage::SetMaptip()	//マップチップなどをTEXTから読み込み
{
	char pos_maptip[MAX_STRING] = {"last_stage"};		//MAPTIPの配置データ
	char pos_character[MAX_STRING] = {"last_stage_char"};	//キャラ(両方)の配置データ

	FILE *fp; 
	errno_t err;

	char l_stage_no[MAX_STRING];	//ステージデータを読み込む為の文字列格納用

	sprintf_s(l_stage_no,"MaptipData\\%s.txt",pos_maptip);

	if( (err = fopen_s(&fp,l_stage_no,"r") != 0) )
	{
		perror("ファイルオープンエラー");
	}	

	for(int i = 0; i < maptip_x;i++){
		for(int j = 0; j < maptip_y;j++){
			fscanf_s(fp,"%d,",&field_maptip[i][j]);
		}
	}
	fclose(fp);	  //ファイルを閉じる。

	//キャラ配置
	sprintf_s(l_stage_no,"MaptipData\\%s.txt",pos_character);

	if( (err = fopen_s(&fp,l_stage_no,"r") != 0) )
	{
		perror("ファイルオープンエラー");
	}	

	for(int i = 0; i < maptip_x;i++){
		for(int j = 0; j < maptip_y;j++){
			fscanf_s(fp,"%d,",&field_character[i][j]);
			//追加
			if(IdSeach(i,j) != 0){
				char_max++;
				if(IdSeach(i,j) < U_SAHAGIN1)	player_max++;
				else	enemy_max++;
			}
			//追加
		}
	}
	fclose(fp);	  //ファイルを閉じる。
}

void C_Stage::AreaSeach(int char_position_x,int char_position_y,int unit_id,int distance,int char_commando)	//移動・攻撃できるエリアを算出
{
	//int cnt = 0;	//デバック用
	//もしキャラが変わっていたら
	if(unit_id != keep_id || char_commando != keep_cmd){	//2/12追加(nisii)
		//移動できるエリアを初期化
		for(int i = 0;i < maptip_x;i++){
			for(int j = 0;j < maptip_y;j++){
				area_info[i][j] = 0;
			}
		}
		area_distance = distance;	//距離を入れる
		//移動できるエリアを求める
		for(int i = -area_distance;i <= area_distance;i++){	//－移動力から移動力まで回す(X方向)
			for(int j = -area_distance;j <= area_distance;j++){	//上に同じ(Y方向)
				if(char_position_x + i >= 0 && char_position_x + i < MAX_MAPTIP_LENGTE){	//配列は[20]で作った場合０～19までしかないため予防策
					if(char_position_y + j >= 0 && char_position_y + j < MAX_MAPTIP_WIDE){	//上に同じ
						//iとjの値が－の時、-1をかけて絶対値にし、iとjの合計が移動距離を越えていない場合は１をいれる(移動できる)
						if(i < 0 && j < 0){
							area_info[char_position_x + i][char_position_y + j] = -i + -j;
//							cnt++;	//デバック用
						}
						//iの値が－の時
						else if(i < 0){
							area_info[char_position_x + i][char_position_y + j] = -i + j;
//							cnt++;	//デバック用
						}
						//jの値が－の時
						else if(j < 0){
							area_info[char_position_x + i][char_position_y + j] = i + -j;
//							cnt++;	//デバック用
						}
						//iとjの値が＋の時、iとjの合計が移動距離を越えていない場合は１をいれる(移動できる)
						else{
							area_info[char_position_x + i][char_position_y + j] = i + j;
//							cnt++;	//デバック用
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

	//cnt = cnt;	//デバック用
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
	keep_cmd = char_commando;	//2/12追加(nisii)
}

void C_Stage::AreaDeleat()		//検索したエリア情報を消す
{
	for(int i = 0;i < maptip_x;i++){
		for(int j = 0;j < maptip_y;j++){
			area_info[i][j] = 0;
		}
	}
}

int C_Stage::IdSeach(int x,int y)	//どのキャラなのかを判断　例　51 = サハギン2
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

