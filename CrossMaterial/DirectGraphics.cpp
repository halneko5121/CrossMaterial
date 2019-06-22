/************************************************************************************
 *																					*
 *	役割：グラフィックのライブラリ。											    *
 *																					*
 *	説明：これがあるだけで描画は完璧なすぐれもの！									*
 *																					*
 *	作成日：2008年 8月 6日															*
 *																					*
 *	更新日：2009年 1月20日															*
 *													by	早瀬　公彦					*
 *													更新三上　亘					*
 ************************************************************************************/


#include "DirectGraphics.h"


void C_DGraphics::SetDevice(IDirect3DDevice9 *pDevice)//デバイスのセット
{
	pD3Device = pDevice;
}

void C_DGraphics::InitData(int max_data)//初期化
{
	color = new DWORD[max_data];	//メモリの確保（右側は型名！）
	angle = new float[max_data];	//メモリの確保（右側は型名！）
	size_x = new float[max_data];	//メモリの確保（右側は型名！）
	size_y = new float[max_data];	//メモリの確保（右側は型名！）
	position = new F_RECT[max_data];//メモリの確保（右側は型名！）
	color2 = new DWORD[4];			//2月28日追加

	for(int i = 0; i < max_data; i++)//使用する画像の枚数分for文でまわす
	{
		color[i] = 0xFFFFFFFF;
		angle[i] = 0.f;
		size_x[i] = 1.f;
		size_y[i] = 1.f;
		if(i < 4){
			color2[i] = 0xFFFFFFFF;
		}
	}
}

void C_DGraphics::SetTextureNum(int texture_num)//統合ファイルの枚数分まわす
{
	num = texture_num;

	height = new float[num];	//画像の高さ
	width = new float[num];		//画像の幅

	for(int i = 0; i < num; i++)//初期化
	{
		height[i] = 0.f;
		width[i] = 0.f;
	}
}


void C_DGraphics::LoadTexture(char* pFileName, LPDIRECT3DTEXTURE9 &pTexture)//テクスチャーの読み込み
{	
	if(FAILED(D3DXCreateTextureFromFileExA(pD3Device,
		pFileName,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT_NONPOW2,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_FILTER_NONE,
		D3DX_FILTER_NONE,
		D3DCOLOR_ARGB(255,0,255,0),
		NULL,NULL,&pTexture))){
			MessageBox(NULL,TEXT("pTextureの生成に失敗しましゅた"),NULL,MB_OK);
			return ;
	}

//	float height,width;
	D3DSURFACE_DESC desc;
	pTexture->GetLevelDesc(0,&desc);

	for(int i = 0; i < num; i++)
	{
		if(height[i] == 0.f)
		{
			height[i] = (float)desc.Height;
			width[i]  = (float)desc.Width;
			break;
		}
	}
}

void C_DGraphics::SetPostion(F_RECT rect, int no)							//座標をセットする
{
	position[no] = rect;
}

void C_DGraphics::SetSize(float texture_size_x, float texture_size_y, int no)//大きさをセットする
{
	size_x[no] = texture_size_x;
	size_y[no] = texture_size_y;
}

void C_DGraphics::SetPostion(float t, float l, float b, float r, int no)	//矩形情報のリセット
{
	position[no].top = t;
	position[no].left = l;
	position[no].right = r;
	position[no].bottom = b;
}

void C_DGraphics::SetColor(DWORD texture_color, int no)	//カラーをセットする
{
	color[no] = texture_color;
}

void C_DGraphics::SetColor2(DWORD texture_color,int no)
{
	color2[no] = texture_color;
}

void C_DGraphics::SetAngle(float texture_angle, int no)//角度をセットする
{
	angle[no] = texture_angle;
}

/************************************************************************************
 *	説明	：フェードイン処理														*
 *	引数	：int fade_speed	int texture_alpha:テクスチャのalpha値				*
 *	戻り値	：int alpha																*
 *													by	三上　亘					*
 ************************************************************************************/
int C_DGraphics::FadeIn(int fade_speed ,int texture_alpha) 
{
	alpha = texture_alpha;
	alpha += fade_speed;

	if(alpha >= 255 )	alpha = 255;

	return alpha;
}

/************************************************************************************
 *	説明	：フェードイン処理(float_ver)											*
 *	引数	：float fade_speed	float texture_alpha:テクスチャのalpha値				*
 *	戻り値	：float alpha															*
 *													by	三上　亘					*
 ************************************************************************************/
float C_DGraphics::FadeIn(float fade_speed ,float texture_alpha) 
{
	alpha_f = texture_alpha;
	alpha_f += fade_speed;

	if(alpha_f >= 255 )	alpha_f = 255;

	return alpha_f;
}

/************************************************************************************
 *	説明	：フェードイン処理														*
 *	引数	：int fade_stop: フェード処理を停止する値								*
 *			：int fade_speed:速さ			 int texture_alpha:テクスチャのalpha値	*
 *	戻り値	：int alpha																*
 *													by	三上　亘					*
 ************************************************************************************/
int C_DGraphics::FadeIn(int fade_speed ,int texture_alpha, int fade_stop) 
{
	alpha = texture_alpha;
	alpha += fade_speed;

	if(alpha >= fade_stop )	alpha = fade_stop;

	return alpha;
}

/************************************************************************************
 *	説明	：フェードアウト処理													*
 *	引数	：int fade_speed	int texture_alpha:テクスチャのalpha値				*
 *	戻り値	：int alpha																*
 *													by	三上　亘					*
 ************************************************************************************/
int C_DGraphics::FadeOut(int fade_speed ,int texture_alpha) 
{
	alpha = texture_alpha;
	alpha -= fade_speed;

	if(alpha <= 0 )	alpha = 0;

	return alpha;
}

/************************************************************************************
 *	説明	：フェードアウト処理(float_ver)											*					
 *	引数	：float fade_speed	float texture_alpha:テクスチャのalpha値				*
 *	戻り値	：float alpha															*
 *													by	三上　亘					*
 ************************************************************************************/
float C_DGraphics::FadeOut(float fade_speed ,float texture_alpha) 
{
	alpha_f = texture_alpha;
	alpha_f -= fade_speed;

	if(alpha_f <= 0 )	alpha_f = 0;

	return alpha_f;
}

/************************************************************************************
 *	説明	：フェードアウト処理													*
 *	引数	：int fade_stop: フェード処理を停止する値								*
 *			：int fade_speed:速さ			 int texture_alpha:テクスチャのalpha値	*
 *	戻り値	：int alpha																*
 *													by	三上　亘					*
 ************************************************************************************/
int C_DGraphics::FadeOut(int fade_speed ,int texture_alpha, int fade_stop) 
{
	alpha = texture_alpha;
	alpha -= fade_speed;

	if(alpha <= fade_stop )	alpha = fade_stop;

	return alpha;
}

void C_DGraphics::Draw(float x, float y, LPDIRECT3DTEXTURE9 &pTexture, int no, int no2)//ヴァーテックスをいじる
{
	float texture_sin,texture_cos;
	float u1,u2,v1,v2;
	float texture_size_x, texture_size_y;

	texture_size_x = abs((int)(position[no2].right - position[no2].left));
	texture_size_y = abs((int)(position[no2].bottom - position[no2].top));

	texture_sin = sinf(D3DXToRadian(angle[no2]));
	texture_cos = cosf(D3DXToRadian(angle[no2]));

	D3DXVECTOR2 vector[] = //回転する絵を作るときに使う
	{
		D3DXVECTOR2(0.f,0.f),
		D3DXVECTOR2(texture_size_x * size_x[no2],0.f),
		D3DXVECTOR2(texture_size_x * size_x[no2],texture_size_y * size_y[no2]),
		D3DXVECTOR2(0.f,texture_size_y * size_y[no2]),
	};

	v1 = position[no2].top		/ height[no];//u、v値の求めかた　矩形 / 全体の高さ
	v2 = position[no2].bottom	/ height[no];
	u1 = position[no2].left		/ width[no];
	u2 = position[no2].right	/ width[no];

	
	CUSTOMVERTEX ver[4] =
	{
		{	0.f	,   0 , 0.5f,1.0f,color[no2],u1,v1}, //左上
		{	0.f ,   0 , 0.5f,1.0f,color[no2],u2,v1}, //右上
		{	0.f ,	0 , 0.5f,1.0f,color[no2],u2,v2}, //右下
		{	0.f	,	0 , 0.5f,1.0f,color[no2],u1,v2}, //左下
	};

	for(int i = 0;i < 4; i++)
	{
		ver[i].x = (vector[i].x * texture_cos) + (vector[i].y * -texture_sin) + x;//回転の公式
		ver[i].y = (vector[i].x * texture_sin) + (vector[i].y *  texture_cos) + y;
	}

	pD3Device->SetTexture(0,pTexture);
	pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);
	pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN,2,ver,sizeof(CUSTOMVERTEX));

}

void C_DGraphics::DrawCC(float x, float y, LPDIRECT3DTEXTURE9 &pTexture, int no, int no2)//ヴァーテックスをいじる,中心点を真ん中にとる
{
	float texture_sin,texture_cos;
	float u1,u2,v1,v2;
	float texture_size_x, texture_size_y;

	texture_size_x = (abs((int)(position[no2].right - position[no2].left)) * size_x[no2]);
	texture_size_y = (abs((int)(position[no2].bottom - position[no2].top)) * size_y[no2]);

	texture_sin = sinf(D3DXToRadian(angle[no2]));
	texture_cos = cosf(D3DXToRadian(angle[no2]));

	D3DXVECTOR2 vector[] = //回転する絵を作るときに使う
	{
		D3DXVECTOR2(-texture_size_x / 2.0f,-texture_size_y / 2.0f),
		D3DXVECTOR2( texture_size_x / 2.0f,-texture_size_y / 2.0f),
		D3DXVECTOR2( texture_size_x / 2.0f, texture_size_y / 2.0f),
		D3DXVECTOR2(-texture_size_x / 2.0f, texture_size_y / 2.0f),
	};

	v1 = position[no2].top		/ height[no];//u、v値の求めかた　全体の高さ÷矩形のTOP
	v2 = position[no2].bottom	/ height[no];
	u1 = position[no2].left		/ width[no];
	u2 = position[no2].right	/ width[no];

	
	CUSTOMVERTEX ver[4] =
	{
		{	0.f	,   0 , 0.5f,1.0f,color[no2],u1,v1}, //左上
		{	0.f ,   0 , 0.5f,1.0f,color[no2],u2,v1}, //右上
		{	0.f ,	0 , 0.5f,1.0f,color[no2],u2,v2}, //右下
		{	0.f	,	0 , 0.5f,1.0f,color[no2],u1,v2}, //左下
	};

	for(int i = 0;i < 4; i++)
	{
		ver[i].x = (vector[i].x * texture_cos) + (vector[i].y * -texture_sin) + x;//回転の公式
		ver[i].y = (vector[i].x * texture_sin) + (vector[i].y *  texture_cos) + y;
	}

	pD3Device->SetTexture(0,pTexture);
	pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);
	pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN,2,ver,sizeof(CUSTOMVERTEX));

}

void C_DGraphics::DrawCC2(float x, float y, LPDIRECT3DTEXTURE9 &pTexture, int no, int no2)//ヴァーテックスをいじる,中心点を真ん中にとる
{
	float texture_sin,texture_cos;
	float u1,u2,v1,v2;
	float texture_size_x, texture_size_y;

	texture_size_x = (abs((int)(position[no2].right - position[no2].left)) * size_x[no2]);
	texture_size_y = (abs((int)(position[no2].bottom - position[no2].top)) * size_y[no2]);

	texture_sin = sinf(D3DXToRadian(angle[no2]));
	texture_cos = cosf(D3DXToRadian(angle[no2]));

	D3DXVECTOR2 vector[] = //回転する絵を作るときに使う
	{
		D3DXVECTOR2(-texture_size_x / 2.0f,-texture_size_y / 2.0f),
		D3DXVECTOR2( texture_size_x / 2.0f,-texture_size_y / 2.0f),
		D3DXVECTOR2( texture_size_x / 2.0f, texture_size_y / 2.0f),
		D3DXVECTOR2(-texture_size_x / 2.0f, texture_size_y / 2.0f),
	};

	v1 = position[no2].top		/ height[no];//u、v値の求めかた　全体の高さ÷矩形のTOP
	v2 = position[no2].bottom	/ height[no];
	u1 = position[no2].left		/ width[no];
	u2 = position[no2].right	/ width[no];

	
	CUSTOMVERTEX ver[4] =
	{
		{	0.f	,   0 , 0.5f,1.0f,color2[0],u1,v1}, //左上
		{	0.f ,   0 , 0.5f,1.0f,color2[1],u2,v1}, //右上
		{	0.f ,	0 , 0.5f,1.0f,color2[2],u2,v2}, //右下
		{	0.f	,	0 , 0.5f,1.0f,color2[3],u1,v2}, //左下
	};

	for(int i = 0;i < 4; i++)
	{
		ver[i].x = (vector[i].x * texture_cos) + (vector[i].y * -texture_sin) + x;//回転の公式
		ver[i].y = (vector[i].x * texture_sin) + (vector[i].y *  texture_cos) + y;
	}

	pD3Device->SetTexture(0,pTexture);
	pD3Device->SetFVF(D3DFVF_CUSTOMVERTEX);
	pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN,2,ver,sizeof(CUSTOMVERTEX));

}

void C_DGraphics::RectChange(float &rect1,float &rect2) //矩形の入れ替え　キャラの向き変更に使用
{
	float databank; 
	databank = rect1;
	rect1 = rect2;
	rect2 = databank;
}

/************************************************************************************
 *	説明	：矩形を反転させる														*
 *	引数	：int num	矩形の番号													*
 *	戻り値	：なし																	*
 *													by	三上　亘					*
 ************************************************************************************/
void C_DGraphics::RectReverse(int num)			
{
	F_RECT copy;

	copy.left	= position[num].left;
	copy.right	= position[num].right;

	position[num].left = copy.right;
	position[num].right= copy.left;

}
 
/************************************************************************************
 *	説明	：マップチップのセッティング											*
 *	引数	：int length	縦のマス幅												*	
 *			　int wide		横のマス幅												*
 *			　int rect		MAPTIPの矩形											*
 *			　int no_rect	矩形No													*
 *			　int field_x	SETする配列x軸用										*
 *			　int field_y	SETする配列y軸用										*
 *	戻り値	：なし																	*
 *													by	三上　亘					*
 ************************************************************************************/
void C_DGraphics::SetMaptip(int length,int wide,F_RECT rect[],int no_rect,float fieid_x[][20],float fieid_y[][20])
{
	float slide_x  = 0;
	float slide_y  = 0;					//スライドさせる量(x軸),(y軸)
	float maptip_x = 0;
	float maptip_y = 0;

	float maptip_over;					//スライドさせる数値の上限

	flag_field[length][wide];
	
	slide_x = (rect[no_rect].right  - rect[no_rect].left) / 2;
	slide_y = (rect[no_rect].bottom - rect[no_rect].top)  / 4;
	maptip_over = slide_x * (float)wide * (float)length / 10;
	//スライドさせる数値がこの値以上になったらまた0から

	for(int i = 0;i < length;i++){
		maptip_x += slide_x;
		maptip_y += slide_y;
		if(maptip_x > maptip_over){
			maptip_x = 0.f;
			maptip_y = 0.f;
		}
		for(int j = 0;j < wide;j++){
			field_x[i][j]	= (j + 1) * slide_x - maptip_x;			//描画を中心座標でいく場合は(j + 1)
			field_y[i][j]	= (j + 1) * slide_y + maptip_y;			//左上中心ならいらない
		}
	}

}

