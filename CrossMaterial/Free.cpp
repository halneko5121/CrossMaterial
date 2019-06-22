#include "Free.h"


F_RECT rect_free[] =
{	
	{0,0,0,0},	//ダミー
};

char* LaodFreeFile[] = {
	{""},
	{"\0"},
};

C_Free::C_Free(C_DGraphics *graphic)
{
	graphics = graphic;

	use_texture = 0;			

	scene_check = new int[MAX_SCENE];
	scene_check[0] = 0;
	
	for(int i = 0;LaodFreeFile[i] != "\0"; i++)		//使う絵の枚数を知らせる
	{
		use_texture++;	
	}

	graphics->SetTextureNum(use_texture);					//テクスチャの枚数をセットする

	graphics->InitData(R_FREE_MAX);						//矩形の数だけメモリを確保する。

	pTexture = new LPDIRECT3DTEXTURE9[use_texture];		//画像データの数だけメモリを確保する。

	for(int i=0; i<R_FREE_MAX; i++)
	{	
		graphics->SetPostion(rect_free[i],i);				//矩形情報をセットする
	}	

	for(int i=0; i < use_texture; i++)						//テクスチャの読み込みを行う。
	{
		graphics->LoadTexture(LaodFreeFile[i],pTexture[i]); 
	}

	//for(int i=0; i < MAX_S_END; i++){
	//	LoadSound(LoadSoundFree[i],i);					//Free部分ののBGM
	//}
}

C_Free::~C_Free()
{
}

void C_Free::Init()
{


}

void C_Free::FreeBase(){	//基本

}

void C_Free::FreeClass(){	//教室

}

void C_Free::Control(int * key)
{

}

void C_Free::Draw()
{
}
void C_Free::Sound()
{

}
void C_Free::Release()
{

}
