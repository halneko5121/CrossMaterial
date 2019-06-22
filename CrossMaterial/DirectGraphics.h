#pragma once

/************************************************************************************
 *																					*
 *	役割：画像ファイルを扱いやすくする。											*
 *																					*
 *	説明：画像データの4点情報を一括して扱う。										*
 *																					*
 *	作成日：2008年 8月 6日															*
 *																					*
 *	更新日：2009年 1月 20日															*
 *													by	早瀬　公彦					*
 *													更新三上　亘					*
 ************************************************************************************/
/*================================
	
		INCLUDEたち

=================================*/
#include<d3d9.h>
#include<d3dx9tex.h>

/*================================
	
		Defineたち

=================================*/
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

#define MAX_RECT			(20)			//矩形の最大量
#define MAX_MAPTIP_LENGTE	(15)			//MAPTIPの最大数(横)
#define MAX_MAPTIP_WIDE		(20)			//MAPTIPの最大数(縦)

/*================================
	
		pragma comment

=================================*/

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")

/*================================
	
		構造体たち

=================================*/

struct CUSTOMVERTEX
{
	FLOAT x,y,z,rhw;
	DWORD color;
	FLOAT tu,tv;
};

struct F_RECT//全てlong型で絵のサイズを測るのに使うと便利
{
	float top;
	float bottom;
	float left;
	float right;
};

struct FIELD_POS
{
	float x;			//フィールドの中心座標(x)
	float y;			//フィールドの中心座標(y)
};

struct COORDINATE	//座標という意味
{
	int x;
	int y;
};

class C_DGraphics//クラスの定義
{
	private:
		IDirect3DDevice9*   pD3Device;
		float *height,*width;	//幅と高さ
		F_RECT *position;		//矩形情報
		DWORD *color;			//色
		DWORD *color2;			//色
		float *angle;			//角度
		float *size_x, *size_y;	//拡大率
		int num;				//使う絵の枚数]
		int alpha;
		float alpha_f;

		////		平野君作
		////	F_RECT rect[MAX_RECT];
		int		flag_field[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];			//配列の中にMAPTIPを識別する
		float	field_x[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];			//座標を配置(x軸)
		float	field_y[MAX_MAPTIP_LENGTE][MAX_MAPTIP_WIDE];			//座標を配置(y軸)
		
	public:
		void InitData(int max_data);													//初期化

		void SetTextureNum(int texture_num);											//テクスチャーの数を決める

		void SetSize(float texture_size_x, float texture_size_y, int no);				//絵のサイズを決める

		void SetDevice(IDirect3DDevice9 *pDevice);										//デバイスのセット

		void LoadTexture(char* pFileName, LPDIRECT3DTEXTURE9 &pTexture);				//テクスチャーの読み込み
	
		void SetPostion(F_RECT rect, int no);											//矩形情報のセット

		void SetPostion(float t, float l, float b, float r, int no);					//矩形情報のセット

		void SetColor(DWORD texture_color, int no);										//カラーのセット

		void SetColor2(DWORD texture_color,int no);										//カラーのセット(各点)(2月28日追加)

		void Draw(float x, float y, LPDIRECT3DTEXTURE9 &pTexture, int no, int no2);		//ドロー関数

		void DrawCC(float x, float y, LPDIRECT3DTEXTURE9 &pTexture, int no, int no2);	//ドロー関数(中心点を真ん中に取ったバージョン)

		void DrawCC2(float x, float y, LPDIRECT3DTEXTURE9 &pTexture, int no, int no2);	//ドロー関数(中心点を真ん中に取ったバージョン)vol.2(2月28日追加)

		void SetAngle(float texture_angle, int no);										//角度のセット

		int   FadeOut(int fade_speed ,int texture_alpha);								//フェードアウト処理
		int   FadeOut(int fade_speed ,int texture_alpha ,int fade_stop);				//フェードアウト処理
		float FadeOut(float fade_speed ,float texture_alpha);							//フェードアウト処理

		int   FadeIn(int fade_speed ,int texture_alpha);								//フェード処理 
		int	  FadeIn(int fade_speed ,int texture_alpha ,int fade_stop);					//フェード処理 
		float FadeIn(float fade_speed ,float texture_alpha);							//フェード処理 

		IDirect3DDevice9* GetDevice() {return pD3Device;}								//デバイスの情報を他に渡す 

		void RectChange(float &rect1,float &rect2);										//矩形のチェンジ(キャラの向き変更)

		void RectReverse(int num);														//矩形の反転

		void SetMaptip(int length,int wide,F_RECT rect[],int no_rect,float fieid_x[][20],float fieid_y[][20]);
		//MAPTIPをSETする関数

};
