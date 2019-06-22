#pragma once

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

/*================================
	
		INCLUDE


=================================*/
#include<stdio.h>
#include<string.h>

#include"Define.h"

/*================================
	
		Define

=================================*/

enum TEXT_FOLDER
{
	FOLDER_GRAPHIC,			//絵のフォルダ
	FOLDER_SOUND,			//音のフォルダ
	FOLDER_SCRIPT,			//スクリプトのフォルダ
	FOLDER_RECT,			//矩形情報のフォルダ

	MAX_FOLDER,
};

class C_FileControl
{
private:
	FILE *fp;
	errno_t err;
	int		string_section[MAX_FOLDER];			//テキストファイルの行数を判断する。
	char	l_talk_no[MAX_STRING];				//読み込む為の文字列格納用
	char	text_buffer[MAX_STRING];			//会話ウィンドウ1行あたりの最大文字数

public:
	C_FileControl(void);

	//初期化関数
	void Init();
	void Init(int folder_num);

	/*********************************************************************************
	テキストデータの読み込み
	関数名	:char** SetText(char* filefolder,char* filename, char** file_string, int kind_folder)
	引数	:char*	filefolder			ファイルのあるフォルダ名を指定
			:char*	filename			ファイル名を指定
			:char** file_string			ファイルの中にある文字データを格納する
			:int	kind_folder			フォルダの種類を指定
	戻り値	:成功	char**	file_string	文字列を取得
			 失敗	0					ファイルがない場合
	作成者	:三上
	更新日	:  年  月  日
	更新内容:なし
	*********************************************************************************/
	char** SetText(char* filefolder,char* filename, char** file_string, int kind_folder);

	/*********************************************************************************
	読み込んだテキストの行数を取得
	関数名	:int　GetSectionint kind_folder) { return string_section[kind_folder]; }
	引数	:int　kind_folder		フォルダの種類
	戻り値	:string_section[kindfolder]		指定したフォルダの文字列の行数を取得
	作成者	:三上
	更新日	:  年  月  日	更新内容:なし
	*********************************************************************************/
	int GetSection(int kind_folder){ return string_section[kind_folder]; }	//テキストの行数を返します

	~C_FileControl(void);
};
