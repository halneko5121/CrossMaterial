#include "FileControl.h"

/************************************************************************************
 *																					*
 *	役割：ファイルの読み込みをします												*
 *																					*
 *	説明：テキストファイルから文字や値を読み込みセットします						*
 *																					*
 *	作成日：2009年 2 月15日															*
 *																					*
 *	更新日：年 月 日																*
 *													by	三上　亘					*
 *																					*
 ************************************************************************************/

C_FileControl::C_FileControl(void)
{
}

C_FileControl::~C_FileControl(void)
{
}

void C_FileControl::Init()
{
	for(int i = 0;i < MAX_FOLDER;i++) string_section[i] = 0;
}

void C_FileControl::Init(int folder_num)
{
	string_section[folder_num] = 0;
}

/************************************************************************************
 *	説明	：テキスト読み込み														*
 *	引数	：char*  filefolder		ファイルのフォルダ名へのポインタ				*
 *		    ：char*  filename		ファイル名へのポインタ							*
 *			：char** file_string	ファイル内の文章へのポインタ					*
 *			：int	 kind_folder 	フォルダの種類(今回	0:CG 1:SD 2:Script 3:Rect)  *
 *	戻り値	：char** file_string	ファイル本文が格納されたcharポインタへのポインタ*
 *													by	三上　亘					*
 ************************************************************************************/
char** C_FileControl::SetText(char* filefolder,char* filename, char** file_string, int kind_folder)
{
	memset(text_buffer,'\0', sizeof(char)	* MAX_STRING);
	memset(l_talk_no,  '\0', sizeof(char)	* MAX_STRING);

	sprintf_s(l_talk_no,"%s%s.txt",filefolder,filename);		//読み込むフォルダを指定

	err = fopen_s(&fp,l_talk_no,"r");							//ファイルを読み込む

	if(err != NULL)	perror("ファイルオープンエラー");

	while(fscanf(fp,"%s",text_buffer) != EOF){					//ファイルの終端でなければ
		string_section[kind_folder]++;							//行数をカウントする。
		memset(text_buffer,'\0', sizeof(char) * MAX_STRING);
	}

	fseek(fp,0L,SEEK_SET);										//ファイルの先頭にアドレスを戻す

	file_string = new char * [string_section[kind_folder]];//文の数だけメモリを確保する。

	for(int i = 0;i < string_section[kind_folder];i++){
		file_string[i] = new char[MAX_STRING];			//1行分のメモリを確保する。
	}
	for(int i = 0;i < string_section[kind_folder];i++){
		fscanf(fp,"%s",file_string[i]);
	}

	fclose(fp);	  //ファイルを閉じる。

	return file_string;
}