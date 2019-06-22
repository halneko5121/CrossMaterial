#include "Script.h"

/************************************************************************************
 *																					*
 *	役割：スクリプトの管理をします													*
 *																					*
 *	説明：ADVパートにおける会話などなどをテキストで管理できる						*
 *																					*
 *	作成日：2008年 11月 24日														*
 *																					*
 *	更新日：2009年 2月	27日														*
 *													by	三上　亘					*
 *																					*
 ************************************************************************************/

char *p_placename[] ={
	{"寝室"},{"リビング昼"},{"リビング夜"},	{"リビング血"},	{"教室"},
	{"中庭"},{"荒野"},		{"BLOOD"},		{"FLASH"},		{"\0"},
};

char *p_charaname[] ={
	{"クリス"},	{"ヴァン"},	{"クララ"},	{"ロゼッタ"},{"？？？"},
	{"父"},		{"母"},		{"シオン"},	{"リオ"},	 {"マグナ"},
	{"\0"},
};

char *p_charafile[] ={
	{"ヴァン"},	{"クララ"},	{"ロゼッタ"},{"？？？"},{"シオン"},
	{"シオン"},	{"リオ"},	{"リオ"},	 {"マグナ"},{"マグナ"},
	{"\0"},
};

char* p_text_folder[] = {
	{"Graphic\\"}, {"Sound\\"},	{"ScriptData\\"}, {"RectData\\"}, {"\0"}
};

//サウンドファイル名が入っているテキストの名前
char* p_text_soundfile[] = {
	{"PROLOGUE"},	 {"STORY3_1"},{"STORY3_2"}, {"STORY3_3"},
	{"BATTLEBEFORE"},{"EPILOGUE"},{"ENDING"},	{"\0"},
};

char *p_text_story[] ={
	{"Prologue"},	 {"Story3_1"},{"Story3_2"},{"Story3_3"},
	{"BattleBefore"},{"Epilogue"},{"ending_1"},{"\0"}
};

char* p_text_graphicfile = {"ADV"};

char* p_scriptkeyword[] = {
	{"PLACE"},						//これがあった場合現在地変更
	{"PLACE"},						//これがあった場合現在地変更
	{"CHARANAME"},					//これがあった場合キャラ名変更
	{"CHARADATA"},					//これがあった場合キャラ位置変更
	{"CHARADATA"},					//これがあった場合キャラ位置変更
};

char* p_subword_fade[] = {
	{"TOP_"},						//これがあった場合RectのTopをいじる
	{"BOTTOM_"},					//これがあった場合RectのBottomをいじる
	{"L_"},							//これがあった場合RectのLeftをいじる
	{"R_"},							//これがあった場合RectのRightをいじる
	{"IN"},							//フェードイン
	{"OUT"},						//フェードアウト
	{"\0"},
};

char* p_subword_pos[] = {
	{"LEFT"},{"RIGHT"},{"\0"},
};

char* p_subword_action[] = {
	{"FLASH"},{"QUAKE"},{"POWER"},{"\0"},
};

char* check_auto[] = {
	{"FADE"},{"FLASH"},{"SLIDE"},{"QUAKE"},{"\0"}
};

int p_maxname[] = {
	{T_MAX_BG},								//背景の種類
	{T_MAX_BG},								//現在地の名前
	{(R_MAX_CHARANAME - MAX_KINDFACE)},		//キャラの名前
	{(R_MAX_CHARANAME - MAX_KINDFACE)},		//キャラ(統合)の種類左側〃
	{(R_MAX_CHARANAME - MAX_KINDFACE)},		//キャラ(統合)の種類右側〃
};

char** p_searchname[] = {
	p_placename, p_placename, p_charaname, p_charafile, p_placename, p_placename,
};

#ifdef CHARAFONT				//キャラ固有のフォント指定・・・します？
LPCSTR fontname[] = {
	{"小塚ゴシックStd H Bold"},				//クリス
	{"小塚ゴシックStd H Bold"},				//ヴァン
	{"ＤＦＰまるもじ体"},					//クララ　2
	{"小塚ゴシックStd H Bold"},				//ロゼッタ
	{"CRＣ＆Ｇ半古印"},						//？？？  4
	{"小塚ゴシックStd H Bold"},				//父
	{"小塚ゴシックStd H Bold"},				//母
	{"小塚ゴシックStd H Bold"},				//シオン
	{"小塚ゴシックStd H Bold"},				//リオ
	{"小塚ゴシックStd H Bold"},				//マグナ
	{"\0"},									
#else
//ふたりだけ変えよう
LPSTR fontname[] = {
	{"HG創英角ﾎﾟｯﾌﾟ体"},					//クララ
	{"白舟古印体教漢"},						//？？？
	{"\0"},
};
#endif

C_Script::C_Script(C_DGraphics* graphic) : setline(0)
{
	//いつもの↓
	graphics = graphic;	

	use_texture = keep_soundnum = roop_soundnum = 0;

	pFcontrol = new C_FileControl();

	for(int i = 0;i < MAX_FOLDER;i++)string_section[i] = 0;

	pFcontrol->Init();

	string_graphic = pFcontrol->SetText(p_text_folder[FOLDER_GRAPHIC],p_text_graphicfile,string_graphic,FOLDER_GRAPHIC);

	for(int i = 0;!strstr(string_graphic[i],"end"); i++){	//使う絵の枚数を知らせる
		use_texture++;	
	}

	graphics->SetTextureNum(use_texture);					//テクスチャの枚数をセットする

	graphics->InitData(R_MAX_ADV);							//矩形の数だけメモリを確保する。

	pTexture = new LPDIRECT3DTEXTURE9[use_texture];			//画像データの数だけメモリを確保する。

	for(int i = 0; i < use_texture; i++){					//テクスチャの読み込みを行う。
		graphics->LoadTexture(string_graphic[i],pTexture[i]); 
	}

	string_cg_rect = pFcontrol->SetText(p_text_folder[FOLDER_RECT],p_text_graphicfile,string_cg_rect,FOLDER_RECT);

	for(int i = 0; i < R_MAX_ADV; i++){						//矩形のセットを行う。
		rect_adventure[i].top	 = (float)atof(string_cg_rect[(i * 4)]);
		rect_adventure[i].bottom = (float)atof(string_cg_rect[(i * 4) + 1]);
		rect_adventure[i].left   = (float)atof(string_cg_rect[(i * 4) + 2]);
		rect_adventure[i].right  = (float)atof(string_cg_rect[(i * 4) + 3]);

		graphics->SetPostion(rect_adventure[i],i);			//矩形情報をセットする
	}

	//ここからscript系
	pFont = new DFont();									//pFontのオブジェクトを生成する。
		
	pFont->InitDFont(graphic->GetDevice());					//フォントの初期化

	string_talk	= new char * [MAX_TEXTNAME];				//会話場面数に応じたメモリを確保

	for(int i = 0;i < MAX_TEXTNAME;i++){					//会話場面の個数を数える。
		string_talk[i]  = new char[MAX_STRING];				//各要素の文字のメモリ確保
	}
}

C_Script::~C_Script(void)
{
	for(int i = 0;i < (string_section[FOLDER_GRAPHIC]-1);i++) pTexture[i]->Release();
}

void C_Script::Init(int text_num)
{
	flag_talkend = FLAG_CONTINUE;							//会話の終了を判断する。

	flag_stopline = flag_window_msg = flag_quake_x = flag_quake_y 
		= flag_flash = flag_pendant  =  flag_auto = flag_skip = false;
	
	slide_char_x = slide_char2_x = convert_rev = 0.f;

	drawline  = setline  = count_fla = count_quake = quake_x = quake_y = next_icon_y =
	kind_quake = flag_quake_continue = alpha_pendant = auto_wait  = 0;

	alpha = alpha_fla = 1;

	for(int i = 0;i < 2;i++){
		fade_t[i]		= T_HEIGHT;
		fade_l[i]		= T_WIDE;
		fade_b[i]		= fade_r[i] = 0;
		chara_height[i] = 0.f;
	}

	graphics->SetColor(D3DCOLOR_ARGB(150,100,100,100),R_BLACK);
	graphics->SetColor(D3DCOLOR_ARGB(0,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_BG_ADV);
	graphics->SetColor(D3DCOLOR_ARGB(150,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_CONSOR_MSGWINDOW);

	memset(&draw_string[0],'\0',sizeof(char) * TALK_MAXLINE * MAX_STRING);	//draw_stringの配列を初期化する。
	memset(&word_copy[0],'\0',sizeof(char) * KIND_MAX * MAX_STRING);		//word_copyの配列を初期化する。

	pFcontrol->Init(FOLDER_SCRIPT);
	pFcontrol->Init(FOLDER_SOUND);

	string_talk = pFcontrol->SetText(p_text_folder[FOLDER_SCRIPT],p_text_story[text_num],string_talk,FOLDER_SCRIPT);
	string_sound = pFcontrol->SetText(p_text_folder[FOLDER_SOUND],p_text_soundfile[text_num],string_sound,FOLDER_SOUND);

	for(int i = 0;i < MAX_FOLDER;i++) string_section[i] = pFcontrol->GetSection(i);

	for(int i = 0;!strstr(string_sound[i],"end");i++) LoadSound(string_sound[i],i);
}

void C_Script::Control(int *key)
{
#ifdef _AFTER
	if(setline != 0){
		if(strstr(string_talk[setline],STOP)){									
			flag_skip = flag_auto = false;
			flag_stopline = true;
			setline++;
		}
	}
#endif

	AutoTalk(key);
	SkipTalk(key);

	TalkEnd(key);																			//会話の終了or続行の判断

	IventCheck(key);																		//特殊な処理のチェック

	if( (!flag_stopline) && (flag_talkend == FLAG_CONTINUE) ){
		flag_nexticon = false;
		WordCheck(key);
	}
	else if(!flag_auto) NextIcon();
}

void C_Script::Draw()
{
	DrawScript(T_MAX_BG,p_placename,S_KIND_BG);												//背景
	DrawScript(MAX_CHARANAME,p_charafile,S_KIND_CHARA_LEFT);								//キャラ(左側)
	DrawScript(MAX_CHARANAME,p_charafile,S_KIND_CHARA_RIGHT);								//キャラ(右側)

	if(flag_pendant){
		graphics->SetColor(D3DCOLOR_ARGB(alpha_pendant,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_BG_ADV);
		graphics->DrawCC(POS_BG_ADVETURE_X,POS_BG_ADVETURE_Y,pTexture[T_POWER],T_POWER,R_BG_ADV);
	}
	if(flag_flash){
		graphics->SetColor(D3DCOLOR_ARGB(alpha_fla,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_BG_ADV);
		graphics->DrawCC(POS_BG_ADVETURE_X,POS_BG_ADVETURE_Y,pTexture[T_BG_FLASH],T_BG_FLASH,R_BG_ADV);
	}

	if(flag_window_msg){
		graphics->DrawCC(POS_MSGWINDOW_X,POS_MSGWINDOW_Y,pTexture[T_CONSOR_ADV],T_CONSOR_ADV,R_CONSOR_MSGWINDOW);//MSGウィンドウ
		graphics->DrawCC(POS_BLACK_X,POS_BLACK_Y,pTexture[T_BLACK],T_BLACK,R_BLACK);		//文字を見やすくする用
	}

	DrawScript((T_MAX_BG - 2),p_placename,S_KIND_NOWPLACE);									//現在地名
	DrawScript(MAX_CHARANAME,p_charaname,S_KIND_CHARANAME);									//キャラ名

	DrawTalk();																				//セリフ
	
	if(flag_nexticon) graphics->Draw(NEXTICON_X,NEXTICON_Y,pTexture[T_CONSOR_ADV],T_CONSOR_ADV,next_icon_y);
}

void C_Script::TalkEnd(int *key)
{
	if( (setline >= (string_section[FOLDER_SCRIPT]-1)) && (flag_stopline == true) ){
		for(int i = 0;p_text_story[i] != "\0";i++){
			if(strstr(string_talk[0],p_text_story[i])){
				flag_talkend = i; break;
			}
		}
		setline = 0;
		Release();
	}
	else if(key[Z_PUSH-1] == Z_PUSH){
		if(flag_stopline == true){											//ページの文字が全て表示されたら
			flag_stopline = false;											//キーが入力されたら、次のページへ進む。
			memset(&draw_string[0],'\0',sizeof(char) * TALK_MAXLINE * MAX_STRING);	//draw_stringの配列を初期化する。
		}
		if(setline > string_section[FOLDER_SCRIPT]){						//テキストファイルの最大行数に達するとカンストをかける。
			setline = string_section[FOLDER_SCRIPT];		
		}
	}	
}

void C_Script::StringAdvanced()																//文字の検索
{
	while(1){
		int j = 0;
		if(strstr(string_talk[setline],TALK_WORD)){											//『TALK』があった場合はセリフを進める
			for(int i = 0;(unsigned)i < strlen(string_talk[setline]);i++){					//文字の長さ分回す
				if(i > STRING_TALK){ draw_string[drawline][j] = string_talk[setline][i]; j++;	}
									//draw_stringにstring_talkの中身を渡す。//draw_stringを１文字移動
			}
			drawline++;
		}
		setline++;
		if(drawline == TALK_MAXLINE){ drawline = NULL; flag_stopline = true; break; }
		//3行目に来たら				  //行数を元に戻す//キー入力が行われるまで文字送りをストップする
	}

	if(!flag_skip)SetCharaFont();
}

void C_Script::DrawTalk()
{
	for(int i = 0; i < TALK_MAXLINE; i++){												//文字列を画面に出力する(3行分)
		//ｙは行の数に文字サイズ分下へ
		pFont->DrawFont(draw_string[i],TALK_POS_X,TALK_POS_Y + i * (TALK_FONTSIZE + TALK_SPACE) );
	}
}

void C_Script::SetScript(int max_data, char* text_data[],int scriptnum, int* key)
{
	for(int i = 0;i < max_data;i++){
		if(strstr(string_talk[setline],text_data[i])){									//スクリプト発動の単語があればコピーする
			if( (scriptnum == S_KIND_CHARA_LEFT) || (scriptnum == S_KIND_CHARA_RIGHT) ){		
				strcpy(word_copy[scriptnum],string_talk[setline]);
			}
			else{ strcpy(word_copy[scriptnum],text_data[i]); }							//scriptnumは、対応するスクリプトの種類
			break;																		//コピーした時点で抜ける
		}
		else memset(&word_copy[scriptnum],'\0',sizeof(char) * MAX_STRING);
	}	
	if( (scriptnum == S_KIND_CHARA_LEFT) || (scriptnum == S_KIND_CHARA_RIGHT) ){
		if(strstr(string_talk[setline + 1],"CHARADATA")){ flag_stopline = true; }
	}
}

void C_Script::DrawScript(int max_data, char* text_data[], int scriptnum)				//text_dataの中の文字列によって絵を。scriptnumの中身によって種類を。変更
{
	for(int i = 0;i < max_data;i++){
		if(strstr(word_copy[scriptnum],text_data[i])){
			switch(scriptnum){
				case S_KIND_BG:															//背景
					graphics->SetColor(D3DCOLOR_ARGB(alpha,255,255,255),R_BG_ADV);
					graphics->DrawCC((POS_BG_ADVETURE_X + quake_x),(POS_BG_ADVETURE_Y + quake_y),pTexture[i],i,R_BG_ADV);				
					break;
				case S_KIND_NOWPLACE:													//現在地枠 + 現在地名
					if( (!strstr(word_copy[scriptnum],"荒野")) && (!strstr(word_copy[scriptnum],"BLOOD")) ){
						graphics->Draw(POS_CONSOR_X,POS_CONSOR_Y,pTexture[T_CONSOR_ADV],T_CONSOR_ADV,R_CONSOR_PLACE);				//現在地枠
					}
					graphics->DrawCC(POS_NOWPLACE_X,POS_NOWPLACE_Y,pTexture[T_CONSOR_ADV],T_CONSOR_ADV,(i + R_CONVERT_PLACE));		//矩形番号に合わせるため
					break;
				case S_KIND_CHARANAME:													//キャラ名
					graphics->Draw(POS_CHARANAME_X,POS_CHARANAME_Y,pTexture[T_CONSOR_ADV],T_CONSOR_ADV,(i + R_CONVERT_CHARANAME));//矩形番号に合わせるため
					break;	
				case S_KIND_CHARA_LEFT:													//左側のキャラ
				case S_KIND_CHARA_RIGHT:												//右側のキャラ
					DrawChara(scriptnum, i);
					break;
			}
			break;
		}
	}
}

void C_Script::DrawChara(int scriptnum, int i)
{
	int rect	  = 0;
	int convert_x = 0;
	int plus_i	  = 0;
	char *search  = new char[2];
	char *check   = new char[2];
	char *check_name = new char;

	for(int j = 0;p_charaname[j] != "\0";j++){
		if(strstr(word_copy[scriptnum],p_charaname[j])){
			check_name = p_charaname[j];
			for(int k = 0;k < 2;k++) check[k] = word_copy[scriptnum][10 + k + strlen(check_name)];  
			break;
		}
	}

	for(int j = 1;j <= (char)MAX_CHARAFACE;j++){												//キャラ("誰"か"と、"どの表情"か)
		ConvertNum(j,search);
		if(strcmp(check,search) == 0){															//数字のチェック
			if(j > 5){																			//五枚目以上なら
				rect	= ((int)j % 5 == 0) ? (5):((int)j % 5);
				plus_i	= (T_MAX_BG + 1);														//矩形あわせ
			}
			else{ rect	= (int)j; plus_i = T_MAX_BG; }

			if(strstr(word_copy[scriptnum],"ロゼッタ")) { rect += (R_ROZE1 - 1); convert_x = 60; }					//ロゼッタだけ矩形サイズが違うので
			LineUpHeight(scriptnum);

			if(strstr(word_copy[scriptnum],"FADE")){
				if( (strstr(word_copy[scriptnum],"TOP_UP")) || (strstr(word_copy[scriptnum],"TOP_DOWN")) ){
					graphics->SetPostion(fade_t[scriptnum - CONVERT_FADE],rect_adventure[rect].left,rect_adventure[rect].bottom,rect_adventure[rect].right,rect);
					if(strstr(word_copy[scriptnum],TALK_CHARA_RIGHT)){
						if(strstr(word_copy[scriptnum],TALK_REVERSE)) graphics->RectReverse(rect); 
						graphics->Draw((POS_CHARA2_X - convert_x),(fade_t[scriptnum - CONVERT_FADE] + 100 + chara_height[scriptnum - 3]),pTexture[i + plus_i],(i + plus_i),rect);
					}
					else{
						if(!strstr(word_copy[scriptnum],TALK_REVERSE)) graphics->RectReverse(rect); 
						graphics->Draw((POS_CHARA_X + convert_x),(fade_t[scriptnum - CONVERT_FADE] + 100 + chara_height[scriptnum - 3]),pTexture[i + plus_i],(i + plus_i),rect);
						graphics->RectReverse(rect);
					}
				}
				else if( (strstr(word_copy[scriptnum],"R_UP")) || (strstr(word_copy[scriptnum],"R_DOWN")) ){
					graphics->SetPostion(rect_adventure[rect].top,rect_adventure[rect].left,rect_adventure[rect].bottom,(rect_adventure[rect].left + fade_r[scriptnum - CONVERT_FADE]),rect);
					if(strstr(word_copy[scriptnum],TALK_CHARA_RIGHT)){
						if(strstr(word_copy[scriptnum],TALK_REVERSE)){
							graphics->RectReverse(rect);
							graphics->SetPostion(rect_adventure[rect].top,rect_adventure[rect].right,rect_adventure[rect].bottom,(rect_adventure[rect].right + fade_r[scriptnum - CONVERT_FADE]),rect);
						}
						graphics->Draw((POS_CHARA2_X - convert_x),POS_CHARA2_Y + chara_height[scriptnum - 3],pTexture[i + plus_i],(i + plus_i),rect);
					}
					else{
						if(!strstr(word_copy[scriptnum],TALK_REVERSE)){
							graphics->RectReverse(rect);
							graphics->SetPostion(rect_adventure[rect].top,rect_adventure[rect].right,rect_adventure[rect].bottom,(rect_adventure[rect].right - fade_r[scriptnum - CONVERT_FADE]),rect);
						}
						graphics->Draw((POS_CHARA_X + convert_x),POS_CHARA_Y + chara_height[scriptnum - 3],pTexture[i + plus_i],(i + plus_i),rect);							
						graphics->RectReverse(rect);
					}
				}
				else if( (strstr(word_copy[scriptnum],"L_UP")) || (strstr(word_copy[scriptnum],"L_DOWN")) ){
					if(strstr(word_copy[scriptnum],TALK_CHARA_RIGHT)){
						graphics->SetPostion(rect_adventure[rect].top,(rect_adventure[rect].right + fade_l[scriptnum - 3]),rect_adventure[rect].bottom,rect_adventure[rect].right,rect);
						
						if(strstr(word_copy[scriptnum],TALK_REVERSE)) graphics->RectReverse(rect);
						graphics->Draw((POS_CHARA2_X - convert_x),POS_CHARA2_Y + chara_height[scriptnum - 3],pTexture[i + plus_i],(i + plus_i),rect);
						graphics->RectReverse(rect);
					}
					else{
						graphics->SetPostion(rect_adventure[rect].top,rect_adventure[rect].left,rect_adventure[rect].bottom,(rect_adventure[rect].left + fade_l[scriptnum - CONVERT_FADE]),rect);
						if(!strstr(word_copy[scriptnum],TALK_REVERSE)){
							graphics->RectReverse(rect);
							graphics->SetPostion(rect_adventure[rect].top,rect_adventure[rect].right,rect_adventure[rect].bottom,(rect_adventure[rect].right - fade_l[scriptnum - CONVERT_FADE]),rect);
						}
						graphics->Draw((POS_CHARA_X + convert_x),POS_CHARA_Y + chara_height[scriptnum - 3],pTexture[i + plus_i],(i + plus_i),rect);
						graphics->RectReverse(rect);
					}
				}
				else if( (strstr(word_copy[scriptnum],"BOTTOM_UP")) || (strstr(word_copy[scriptnum],"BOTTOM_DOWN")) ){
					graphics->SetPostion(rect_adventure[rect].top,rect_adventure[rect].left,fade_b[scriptnum - CONVERT_FADE],rect_adventure[rect].right,rect);
					if(strstr(word_copy[scriptnum],TALK_CHARA_RIGHT)){
						if(strstr(word_copy[scriptnum],TALK_REVERSE)) graphics->RectReverse(rect); 
						graphics->Draw((POS_CHARA2_X - convert_x),POS_CHARA2_Y + chara_height[scriptnum - 3],pTexture[i + plus_i],(i + plus_i),rect);
					}
					else{
						if(!strstr(word_copy[scriptnum],TALK_REVERSE)) graphics->RectReverse(rect); 
						graphics->Draw((POS_CHARA_X + convert_x),POS_CHARA_Y + chara_height[scriptnum - 3],pTexture[i + plus_i],(i + plus_i),rect);
						graphics->RectReverse(rect);
					}
				}
				break;
			}
			else{
				ConvertRev(scriptnum);
				graphics->SetPostion(rect_adventure[rect],rect);

				if(strstr(word_copy[scriptnum],TALK_CHARA_RIGHT)){
					if(strstr(word_copy[scriptnum],TALK_REVERSE)){ graphics->RectReverse(rect);	}
					graphics->Draw( (POS_CHARA2_X + slide_char2_x + convert_rev - convert_x),(POS_CHARA2_Y + chara_height[scriptnum - 3]),pTexture[i + plus_i],(i + plus_i),rect);
				}
				else{
					if(!strstr(word_copy[scriptnum],TALK_REVERSE)){ graphics->RectReverse(rect); }
					graphics->Draw((POS_CHARA_X + slide_char_x + convert_rev + convert_x),(POS_CHARA_Y + chara_height[scriptnum - 3]),pTexture[i + plus_i],(i + plus_i),rect);
					graphics->RectReverse(rect);
				}
				break;
			}
		}
	}
}

void C_Script::IventCheck(int *key)
{
	if(!(setline >= (string_section[FOLDER_SCRIPT]-1)) && (setline != 0) ){
		if(strstr(string_talk[setline],"AUTO")){									//自動で次の処理へ
			if(!SoundCheck(keep_soundnum)){
				memset(&draw_string[0],'\0',sizeof(char) * TALK_MAXLINE * MAX_STRING);	//draw_stringの配列を初期化する。
				setline++; flag_stopline = false; 
			}
		}
		else if(strstr(string_talk[setline + 1],"IVENT")){							//音の連続再生
			flag_stopline = true;
			if(!SoundCheck(keep_soundnum)) flag_stopline = false;
		}
		else{
			if( (strstr(string_talk[setline],"LEFT")) && (strstr(string_talk[setline + 1],"RIGHT")) || 
				(strstr(string_talk[setline + 1],"LEFT")) && (strstr(string_talk[setline],"RIGHT")) ){
				if(strstr(string_talk[setline],"SLIDE")){
					for(int i = 0;i < 2;i++){
						if(strstr(string_talk[setline + i],"IN")){
							if(i == 2) flag_stopline = false;							//自動スライドイン
							else break;
						}
					}
					for(int i = 0;i < 2;i++){
						if(strstr(string_talk[setline + i],"OUT")){ 
							if(i == 2) flag_stopline = false;							//自動スライドアウト
							else break;
						}
					}
				}
			}
		}

		if(key[8] == Z_PUSH){ SoundStop(true,keep_soundnum); keep_soundnum = 0; }
		if(flag_quake_continue) ActionQuake(kind_quake);							//Quakeのまま進める
		if(flag_pendant)		ActionPendant();
	}
}

void C_Script::WordCheck(int* key)
{
	if(strstr(string_talk[setline],TALK_TEXTNAME)) setline++;
	else if(strstr(string_talk[setline],"ENDTALK")){
		memset(&word_copy[0],'\0',sizeof(char) * KIND_MAX * MAX_STRING);	//word_copyの配列を初期化する
		flag_window_msg = false;
		flag_stopline	= true;
	}
	else if(strstr(string_talk[setline],"SOUND")){
		WordCheckSound();													//サウンド関係のチェック
	}
	else if(strstr(string_talk[setline],TALK_MSGWINDOW)){
		WordCheckWindow();													//ウィンドウ関係のチェック
	}
	else if(strstr(string_talk[setline],"ACTION")){
		for(int i = 0;p_subword_action[i] != "\0";i++){
			if(strstr(string_talk[setline],p_subword_action[i])){ 
				ScreenAction(i); break;
			}
		}
	}
	else if(strstr(string_talk[setline],TALK_WORD)){
		StringAdvanced();													//会話文の文字送り処理を行う
	}
	else WordCheckDraw(key);												//描画関係のチェック
}

void C_Script::WordCheckDraw(int *key)
{
	for(int i = 0;i < KIND_MAX;i++){
		if(strstr(string_talk[setline],p_scriptkeyword[i])){
			if(i != S_KIND_BG){
				if(strstr(string_talk[setline],"RIGHT")) SetScript(p_maxname[4],p_searchname[3],4,key);
				else SetScript(p_maxname[i],p_searchname[i],i,key);
			}
			else{
				SetScript(p_maxname[i],p_searchname[i],i,key);
				SetScript(p_maxname[i+1],p_searchname[i+1],i+1,key);
			}

			if(strstr(string_talk[setline],"SLIDE")){
				CharaSlide(); break;
			}
			else if(strstr(string_talk[setline],"FADE")){
				for(int i = 0;p_subword_fade[i] != "\0";i++){
					if(strstr(string_talk[setline],p_subword_fade[i])){
						FadeControl(i); break;
					}
				}
				break;
			}
			else{ setline++; break;	}
		}
	}
}

void C_Script::WordCheckSound()
{
	//if(strstr(string_talk[setline],TALK_SOUNDLOAD)){
	//	S_SoundLoad();
	//	setline++;
	//}
	if( (strstr(string_talk[setline],TALK_SOUNDPLAY)) ||
		(strstr(string_talk[setline],TALK_SOUNDSTOP)) ){
			S_SoundPlay_or_Stop();
			setline++;
	}
	/*else if(strstr(string_talk[setline],TALK_SOUNDRELEASE)){
		for(int i = 0;!strstr(string_sound[i],"end");i++) SoundRelease(i);
		setline++;
	}*/
}

void C_Script::WordCheckWindow()
{
	if(strstr(string_talk[setline],TALK_MSGWINDOW)){
		if(strstr(string_talk[setline],"ON")) flag_window_msg = true;
		else flag_window_msg = false;
		setline++;
	}
}

//void C_Script::S_SoundLoad()
//{
//	//for(int i = 0;!strstr(string_sound[i],"end");i++){
//	//	LoadSound(string_sound[i],i);
//	//}
//}

void C_Script::S_SoundPlay_or_Stop()
{
	char *search = new char[2];
	char *check	 = new char[2];

	keep_soundnum = 0;

	check[0] = string_talk[setline][10];
	check[1] = string_talk[setline][11];

	for(int j = 1;j <= (string_section[FOLDER_SOUND]-1);j++){
		ConvertNum(j,search);
		if(strcmp(check,search) == 0){											//数字のチェック
			if(strstr(string_talk[setline],TALK_SOUNDSTOP)){
				SoundStop(true,(int)j);
				roop_soundnum = 0;
			}
			else if(strstr(string_talk[setline],TALK_SOUNDPLAY)){
				if(strstr(string_talk[setline],"ROOP")){
					SoundPlay(true,(int)j);
					roop_soundnum = (int)j;
					break;
				}
				else{
					SoundPlay(false,(int)j);
					if(strstr(string_talk[setline],"SE"))				  flag_stopline = true;	//キー入力があるまで待機する。

					if( !(strstr(string_talk[setline],"IVENT")) )		  keep_soundnum = (int)j;
					else if( (strstr(string_talk[setline + 1],"IVENT")) ) keep_soundnum = (int)j;
					break;
				}
			}
		}
	}
}

void C_Script::FadeIn()
{
	if(alpha == MAX_ALPHA) alpha = NULL;

	alpha = graphics->FadeIn(5,alpha);
	graphics->SetColor(D3DCOLOR_ARGB(alpha,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_BG_ADV);
	graphics->SetColor(D3DCOLOR_ARGB(alpha,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_CONSOR_PLACE);					//現在地枠
	for(int i = 0;i < 10;i++){
		if(strstr(word_copy[S_KIND_NOWPLACE],p_placename[i])){
			graphics->SetColor(D3DCOLOR_ARGB(alpha,MAX_ARGB,MAX_ARGB,MAX_ARGB),i + R_CONVERT_PLACE);	//MSGwindow
			break;
		}
	}	

	if(alpha >= 255) setline++;
	else flag_stopline = false;
}

void C_Script::FadeOut()
{
	static int	fade_stop	= 0;
	static bool flag_check	= true;
	static char *check		= new char[3];
	char *search = new char[3];
	int	checkstring			= 0;

	if(alpha == NULL) alpha = MAX_ALPHA;

	if(strstr(string_talk[setline],"STOP")){
		if(flag_check){
			for(int i = 0; p_placename[i] != "\0";i++){
				if(strstr(string_talk[setline],p_placename[i])){
					checkstring = strlen(p_placename[i]); break;
				}
			}
			for(int j = 0;j < 3;j++) check[j] = string_talk[setline][checkstring + COMAND_STRING_F_OUT + j];
			flag_check = false;
		}
		if(fade_stop == 0){
			for(int i = 1;i <= MAX_ALPHA;i++){								
				ConvertNum(i,search);			
				if(strcmp(check,search) == 0){					//数字のチェック
					fade_stop = i;
					break;
				}
			}
		}
		alpha = graphics->FadeOut(5,alpha,fade_stop);
	}
	else alpha = graphics->FadeOut(5,alpha);

	graphics->SetColor(D3DCOLOR_ARGB(alpha,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_BG_ADV);
	graphics->SetColor(D3DCOLOR_ARGB(alpha,MAX_ARGB,MAX_ARGB,MAX_ARGB),R_CONSOR_PLACE);

	for(int i = 0;i < MAX_BGNAME;i++){
		if(strstr(word_copy[S_KIND_NOWPLACE],p_placename[i])){
			graphics->SetColor(D3DCOLOR_ARGB(alpha,MAX_ARGB,MAX_ARGB,MAX_ARGB),i + R_CONVERT_PLACE);
			break;
		}
	}	

	if(strstr(string_talk[setline],"STOP")){
		if(alpha <= fade_stop){ setline++; flag_check = true; fade_stop = 0; }
		else flag_stopline = false;
	}
	else{
		if(alpha <= 0){
			setline++; fade_stop = 0; 
		}
		else flag_stopline = false;
	}
}

void C_Script::FadeRect_Bottom()
{
	for(int i = 0;p_subword_pos[i] != "\0";i++){
		if(strstr(string_talk[setline],p_subword_pos[i])){
			if(strstr(word_copy[i + 3],"UP")){
				if(fade_b[i] == 0) fade_b[i] = T_HEIGHT;
				fade_b[i] -= SPEED_UP;

				if(fade_b[i] <= 0){	fade_b[i] = 0; setline++; break; }
				else{ flag_stopline = false; break;	}
			}
			else if(strstr(word_copy[i + 3],"DOWN")){
				if(fade_b[i] == T_HEIGHT) fade_b[i] = 0;
				fade_b[i] += SPEED_DOWN;

				if(fade_b[i] >= T_HEIGHT){ fade_b[i] = T_HEIGHT; setline++; break; }
				else{ flag_stopline = false; break;	}
			}
		}
	}
}

void C_Script::FadeRect_Top()
{
	for(int i = 0;p_subword_pos[i] != "\0";i++){
		if(strstr(string_talk[setline],p_subword_pos[i])){
			if(strstr(word_copy[i + CONVERT_FADE],"UP")){
				if(fade_t[i] == 0) fade_t[i] = T_HEIGHT;
				fade_t[i] -= SPEED_UP;
				
				if(fade_t[i] <= 0){ fade_t[i] = 0; setline++; break; }
				else{ flag_stopline = false; break; }
			}
			else if(strstr(word_copy[i + CONVERT_FADE],"DOWN")){
				if(fade_t[i] == T_HEIGHT) fade_t[i] = 0;
				fade_t[i] += SPEED_DOWN;

				if(fade_t[i] >= T_HEIGHT){ fade_t[i] = T_HEIGHT; setline++; break; }
				else{ flag_stopline = false; break;	}
			}
		}
	}
}

void C_Script::FadeRect_Right()
{
	for(int i = 0;p_subword_pos[i] != "\0";i++){
		if(strstr(string_talk[setline],p_subword_pos[i])){
			if(strstr(word_copy[i + 3],"DOWN")){
				if(fade_r[i] == 0) fade_r[i] = T_WIDE;
				fade_r[i] -= SPEED_UP;

				if(fade_r[i] <= 0){ fade_r[i] = 0; setline++; break; }
				else{ flag_stopline = false; break; }
			}
			else if(strstr(word_copy[i + 3],"UP")){
				if(fade_r[i] == T_WIDE) fade_r[i] = 0;
				fade_r[i] += SPEED_DOWN;

				if(fade_r[i] >= T_WIDE){ fade_r[i] = T_WIDE; setline++; break; }
				else{ flag_stopline = false; break; }
			}
		}
	}
}

void C_Script::FadeRect_Left()
{
	for(int i = 0;p_subword_pos[i] != "\0";i++){
		if(strstr(string_talk[setline],p_subword_pos[i])){
			if(strstr(word_copy[i + 3],"UP")){
				if(fade_l[i] == 0) fade_l[i] = T_WIDE;
				fade_l[i] -= SPEED_UP;

				if(fade_l[i] <= 0){ fade_l[i] = 0; setline++; break; }
				else{ flag_stopline = false; break; }
			}
			else if(strstr(word_copy[i + 3],"DOWN")){
				if(fade_l[i] == T_WIDE) fade_l[i] = 0;
				fade_l[i] += SPEED_DOWN;

				if(fade_l[i] >= T_WIDE){ fade_l[i] = T_WIDE; setline++; break; }
				else{ flag_stopline = false; break; }
			}
		}
	}
}

void C_Script::FadeControl(int script_i)
{
	switch(script_i){
		case 0:	FadeRect_Top();		break;
		case 1: FadeRect_Bottom();	break;
		case 2:	FadeRect_Left();	break;
		case 3: FadeRect_Right();	break;
		case 4: FadeIn();			break;
		case 5: FadeOut();			break;
	}
}

void C_Script::ScreenAction(int script_i)
{
	switch(script_i){
		case 0:	ActionFlash();
			break;
		case 1:
			if(strstr(string_talk[setline],"NEXT"))		flag_quake_continue = 1;
			else if(strstr(string_talk[setline],"STOP"))flag_quake_continue = 2;  
			
			if(strstr(string_talk[setline],"X"))		 kind_quake = 1;
			else if(strstr(string_talk[setline],"Y"))	 kind_quake = 2;
			ActionQuake(kind_quake);
			break;
		case 2:
			if(strstr(string_talk[setline],"TRUE"))		 flag_pendant = true;
			else if(strstr(string_talk[setline],"FALSE"))flag_pendant = false;
			setline++;
			break;
	}
}

void C_Script::ActionPendant()
{
	static bool flag_in = false;

	if(alpha_pendant == 0)		flag_in = true;
	else if(alpha_pendant == MAX_ALPHA){
		flag_in = false;
		SoundPlay(false,35);
	}

	if(flag_in) alpha_pendant = graphics->FadeIn(8,alpha_pendant);
	else		alpha_pendant = graphics->FadeOut(8,alpha_pendant);
}

void C_Script::ActionFlash()
{
	int flash_time	= 0;
	int flash_speed	= 0;
	static int flag_one	  = 0;
	static int count_wait = 0;
	static int flash_wait = 0;

	char *search = new char[2];
	char *check  = new char[2];

	flag_flash = true;

	check[0] = string_talk[setline][12];
	check[1] = string_talk[setline][13];

	for(int i = 1;i <= 100;i++){								
		ConvertNum(i,search);
		if(strcmp(search,check) == 0){ flash_time = i; break; }	
	}

	//FADESPEED設定
	if(strstr(string_talk[setline],"SP")){								
		check[0] = string_talk[setline][17];
		check[1] = string_talk[setline][18];
		for(int i = 1;i <= 100;i++){
			ConvertNum(i,search);
			if(strcmp(search,check) == 0){ flash_speed = i; break; }
		}
	}
	else flash_speed = SPEED_FLASH;

	//WAITTIME設定
	if(strstr(string_talk[setline],"WAIT")){								
		check[0] = string_talk[setline][24];
		check[1] = string_talk[setline][25];
		for(int i = 1;i <= 100;i++){
			ConvertNum(i,search);
			if(strcmp(search,check) == 0){ flash_wait = i; break; }
		}
	}
	else flash_wait = 0;

	if(flash_time == 1){
		if(count_wait > flash_wait) flag_one = 1;
		if(flag_one == 0){
			alpha_fla = graphics->FadeIn(flash_speed,alpha_fla);
			if(alpha_fla >= MAX_ALPHA) count_wait++;
		}
		else{
			alpha_fla = graphics->FadeOut(flash_speed,alpha_fla);
			if(alpha_fla <= 0){ alpha_fla = 0; count_fla++;}
		}
	}
	else{
		alpha_fla += flash_speed;
		if(alpha_fla >= MAX_ALPHA){ alpha_fla = 0; count_fla++; }
	}
	
	if(count_fla >= flash_time){
		count_fla = count_wait = flash_wait = flag_one = 0;
		flag_flash = false; 
		setline++;
	}
	else flag_stopline = false;
}

void C_Script::ActionQuake(int kind_quake)
{
	int  quake = 0;
	int  quake_speed = 0;
	bool flag_quake = false;

	static int quake_time = 0;
	static bool flag_one = true;
	static char *search = new char[2];
	static char *check  = new char[2];

	//回数の設定
	if(flag_one){
		check[0] = string_talk[setline][12];
		check[1] = string_talk[setline][13];
		for(int i = 1;i <= 100;i++){								
			ConvertNum(i,search);
			if(strcmp(search,check) == 0){ quake_time = i; flag_one = false; break; }	
		}
	}
	//SPEED設定
	if(strstr(string_talk[setline],"SP")){								
		check[0] = string_talk[setline][17];
		check[1] = string_talk[setline][18];
		for(int i = 1;i <= 100;i++){
			ConvertNum(i,search);
			if(strcmp(search,check) == 0){ quake_speed = i; break; }
		}
	}
	else quake_speed = SPEED_QUAKE; 

	switch(kind_quake){
		case 1:	quake = quake_x; flag_quake = flag_quake_x; break;
		case 2:	quake = quake_y; flag_quake = flag_quake_y;	break;
	}
	//反復運動
	if(flag_quake) quake -= quake_speed;
	else		   quake += quake_speed;
	if(quake < (-RETURN_QUAKE_Y)){	 flag_quake = false; count_quake++; }
	else if(quake > RETURN_QUAKE_Y){ flag_quake = true;	 count_quake++;	}

	switch(flag_quake_continue){
	case 0:
		if(count_quake > quake_time){
			if(quake == 0){	quake = count_quake = quake_time = 0; flag_one = true; setline++; }
		}
		else flag_stopline = false;
		break;
	case 1://Quakeしたまま話を進める
		if(count_quake == 0) setline++;
		break;
	case 2:
		quake = count_quake = quake_time = flag_quake_continue = 0; 
		flag_one = true; setline++;
		break;
	}
	
	switch(kind_quake){
		case 1: quake_x = quake; flag_quake_x = flag_quake; break;
		case 2:	quake_y = quake; flag_quake_y = flag_quake;	break;
	}
}

#ifdef NEXTICON_SLIDE
void C_Script::NextIcon()//絵をアニメーションさせずに絵をスライドさせるパターン
{
	static float slide = 0;
	static int	 delay = 0;
	float set_icon_y = 530.f;

	if(delay++ > DELAY_TIME){ slide++; delay = 0; }

	next_icon_y = set_icon_y + slide;

	if( (!flag_nexticon) || (slide > 15) )slide = 0;

	flag_nexticon = true;
}
#else
void C_Script::NextIcon()
{
	static int	 slide = 0;
	static int	 delay = 0;

	if(delay++ > DELAY_TIME){ slide++; delay = 0; }

	if( (!flag_nexticon) || (slide > 3) )slide = 0;

	next_icon_y =  R_NEXTICON_1 + slide;

	flag_nexticon = true;
}
#endif

void C_Script::ConvertNum(int i , char* search)
{
	if( (strstr(string_talk[setline],"FADE")) && (strstr(string_talk[setline],"STOP")) ){
		if(i >= 100){
			search[0]= (i / 100)		+ TALK_CONVERT_NUM;											//100の位と他の位の文字を別々にを格納					
			search[1]= ((i / 10)  % 10)	+ TALK_CONVERT_NUM;											//10の位と1の位の文字を別々にを格納				
			search[2]= ((i % 100) % 10) + TALK_CONVERT_NUM;	
		}
		else if( (i >= 10) && (i < 100) ){
			search[0]= TALK_CONVERT_NUM;															//10の位と1の位の文字を別々にを格納				
			search[1]= (i / 10) + TALK_CONVERT_NUM;													//10の位と1の位の文字を別々にを格納				
			search[2]= (i % 10) + TALK_CONVERT_NUM;
		}
		else{
			search[0] = TALK_CONVERT_NUM;															//10の位と1の位の文字を別々にを格納				
			search[1] = TALK_CONVERT_NUM;							
			search[2] = char(i + TALK_CONVERT_NUM);
		}
	}
	else {
		if(i >= 10){
			search[0]= (i / 10) + TALK_CONVERT_NUM;													//10の位と1の位の文字を別々にを格納				
			search[1]= (i % 10) + TALK_CONVERT_NUM;
		}
		else{
			search[0] = TALK_CONVERT_NUM;							
			search[1] = char(i + TALK_CONVERT_NUM);
		}
	}
}

void C_Script::CharaSlide()
{
	if(strstr(string_talk[setline],"LEFT")){		
		if(strstr(string_talk[setline],"IN")){
			if(slide_char_x == 0) slide_char_x = POS_CHARA1_STOP;
			slide_char_x += SPEED_SLIDE;

			if(slide_char_x >= 0){ slide_char_x = 0; setline++; }
			else flag_stopline = false;
		}
		if(strstr(string_talk[setline],"OUT")){
			if(slide_char_x == POS_CHARA1_STOP) slide_char_x = 0;
			slide_char_x -= SPEED_SLIDE;

			if(slide_char_x <= POS_CHARA1_STOP){ slide_char_x = POS_CHARA1_STOP; setline++; }
			else flag_stopline = false;
		}
	}
	else if(strstr(string_talk[setline],"RIGHT")){		
		if(strstr(string_talk[setline],"IN")){
			if(slide_char2_x == 0) slide_char2_x = POS_CHARA2_STOP;
			slide_char2_x -= SPEED_SLIDE;

			if(slide_char2_x <= 0){ slide_char2_x = 0; setline++; }
			else flag_stopline = false;
		}
		else if(strstr(string_talk[setline],"OUT")){
			if(slide_char2_x == POS_CHARA2_STOP) slide_char2_x = 0;
			slide_char2_x += SPEED_SLIDE;

			if(slide_char2_x >= POS_CHARA2_STOP){ slide_char2_x = POS_CHARA2_STOP; setline++; }
			else flag_stopline = false;
		}
	}
}

void C_Script::AutoTalk(int* key)
{
	int  check_clear = 0;
	static int count_wait_rev = 0;

	if(key[C_PUSH-1] == C_PUSH){
		if(flag_auto) { flag_auto = false; flag_stopline = true; }
		else		  { flag_auto = true;  auto_wait = 0;}
	}

	if( (key[Z_PUSH-1] == Z_PUSH) || (key[S_PUSH-1] == S_PUSH) ) flag_auto = false;

	if(!(setline >= (string_section[FOLDER_SCRIPT]-1)) && (setline != 0) ){
		if(flag_auto){
			if(!strstr(string_talk[setline],"ENDTALK")){
				for(int i = 0;check_auto[i] != "\0";i++){
					if(!strstr(string_talk[setline],check_auto[i])){
						check_clear++;
						if(check_clear == 4) flag_stopline = true;
					}
				}
			}
			auto_wait++;
			if( (auto_wait > WAIT_TIME_AUTO) || (strstr(string_talk[setline],"CHARADATA:")) ){
					if( (!SoundCheck(keep_soundnum)) || (strstr(string_talk[setline],"TALK:")) ||
						(strstr(string_talk[setline],"CHARANAME:")) ){
							if( (strstr(string_talk[setline],"REV")) && (strstr(string_talk[setline-1],"CHARADATA")) ||
								(strstr(string_talk[setline],"CHARADATA")) && (strstr(string_talk[setline-1],"REV")) ){
									if(count_wait_rev++ > 120){ flag_stopline = false; count_wait_rev = 0; }
							}
							else flag_stopline = false;
							memset(&draw_string[0],'\0',sizeof(char) * TALK_MAXLINE * MAX_STRING);	//draw_stringの配列を初期化する。
							auto_wait= 0;
					}
			}
		}
	}
}

void C_Script::SkipTalk(int* key)
{
	int  check_clear = 0;

	if(key[S_PUSH-1] == S_PUSH){
		if(flag_skip) flag_skip = false;
		else		  { flag_skip = true;  auto_wait = 0;}
	}

	if( (key[Z_PUSH-1] == Z_PUSH) || (key[C_PUSH-1] == C_PUSH) ) flag_skip = false;

	if(!(setline >= (string_section[FOLDER_SCRIPT]-1)) && (setline != 0) ){
		if(flag_skip){
			if(!strstr(string_talk[setline],"ENDTALK")){
				for(int i = 0;check_auto[i] != "\0";i++){
					if(!strstr(string_talk[setline],check_auto[i])){
						check_clear++;
						if(check_clear == 4) flag_stopline = true;
					}
				}
			}
			auto_wait++;
			if(auto_wait > WAIT_TIME_SKIP){
				SoundStop(true,keep_soundnum); 
				flag_stopline = false;
				memset(&draw_string[0],'\0',sizeof(char) * TALK_MAXLINE * MAX_STRING);	//draw_stringの配列を初期化する。
				auto_wait= 0;
			}
		}
	}

}

void C_Script::SetCharaFont()
{
#ifdef CHARAFONT
	for(int i = 0;p_charaname[i] != "\0";i++){
		if(strstr(word_copy[S_KIND_CHARANAME],p_charaname[i])){
			pFont->ChangeFontName(fontname[i]);	break;
		}
	}
#else
	for(int i = 0;p_charaname[i] != "\0";i++){
		if( (i == NAME_CULALA) || (i == NAME_RIDDLE) ){
			if(strstr(word_copy[S_KIND_CHARANAME],p_charaname[i])){
				pFont->ChangeFontName(fontname[(i / 4)]);	break;		
			}
		}
		else if(i > NAME_RIDDLE){ pFont->ChangeFontName("小塚ゴシックStd H Bold"); break; }
	}
#endif
}

void C_Script::ConvertRev(int scriptnum)
{
	if(strstr(word_copy[scriptnum],TALK_REVERSE)){
		if(strstr(word_copy[scriptnum],TALK_CHARA_RIGHT)){
			if(strstr(word_copy[scriptnum],"ロゼッタ")) convert_rev = -CONVERT_REV_ROZE;
			else convert_rev  = -CONVERT_REV;
		}
		else{
			if(strstr(word_copy[scriptnum],"ロゼッタ")) convert_rev = CONVERT_REV_ROZE;
			else convert_rev  = CONVERT_REV;
		}
	}
	else convert_rev =  0.f;
}

void C_Script::LineUpHeight(int scriptnum)
{
	//ヴァンを一基準とした身長差(画像によっても数値は違います)
	float height[] = {
		{	0.f},{	0.f},{ 70.f},{ 50.f},{	 0.f},		
		{	0.f},{	0.f},{ 30.f},{ 10.f},{   0.f},
	};					

	for(int i = 0;p_charaname[i] != "\0";i++){
		if(strstr(word_copy[scriptnum],p_charaname[i])){
			chara_height[scriptnum - 3]  = height[i];
			break;
		}
		else chara_height[scriptnum - 3] = 0.f;
	}
}

void C_Script::Release()
{
	for(int i = 0;i < (string_section[FOLDER_SOUND]-1);i++)	SoundRelease(i);
}