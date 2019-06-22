//---------------------------------------------
//
//      文字の設定
//      作成開始日:3月5日
//      更新日:12月22日
//      作成者:西井
//		更新者:三上	　void DrawFont(LPSTR str ,RECT rect,DWORD option)の追加
//
//---------------------------------------------

#ifndef _DIRECTFONT_H_
#define _DIRECTFONT_H_

#define DEFAULT_FONT_SIZE_X (13/*16*/)	//基本のフォントサイズ
#define DEFAULT_FONT_SIZE_Y (40)		//基本のフォントサイズ
enum DRAWTEXT_OPTION					//オプション設定
{
	OP_LEFT,							//文字列を左揃えに
	OP_RIGHT,							//文字列を左揃えに
	OP_CENTER,							//文字列を左揃えに	
	OP_BOTTOM,							//文字列を左揃えに
	OP_VCENTER,							//文字列をy軸の中央に
	OP_BREAK,							//改行してくれる
	OP_TAB,
};

#include "DirectGraphics.h"

class DFont
{
private:
    LPDIRECT3DDEVICE9   fontDevice; //文字描画専用で使うデバイス
    LPD3DXFONT          pFont;      //DirectFontのインターフェース
    D3DXFONT_DESC		fontDesc;   //フォント
    D3DCOLOR            fontColor;  //フォントの色
    D3DXVECTOR2         fontSize;   //フォントサイズ
public:
    //////////////////////////////////////////////////////////
    //
    //      説明　：初期化を行う(メンバ初期化)
    //      引数　：LPDIRECT3DDEVICE9   pDevice    デバイス
    //　　　戻り値：HRESULT S_OK:成功   E_FAIL:失敗
    //
    //////////////////////////////////////////////////////////
    HRESULT InitDFont(LPDIRECT3DDEVICE9 pDevice);

    //////////////////////////////////////////////////////////
    //
    //      説明　：フォントの色変更
    //      引数　：D3DCOLOR    alpha   アルファ値
    //              D3DCOLOR    red     赤の値
    //              D3DCOLOR    green   緑の値
    //              D3DCOLOR    blue    青の値
    //　　　戻り値：なし
    //
    //////////////////////////////////////////////////////////
    void ChangeFontColor(D3DCOLOR alpha , D3DCOLOR red , D3DCOLOR green , D3DCOLOR blue);

    //////////////////////////////////////////////////////////
    //
    //      説明　：フォントサイズ変更
    //      引数　：D3DXVECTOR2 size    大きさ指定(幅・高さ)
    //　　　戻り値：なし
    //
    //////////////////////////////////////////////////////////
    void ChangeFontSize(D3DXVECTOR2 size);

	//////////////////////////////////////////////////////////
    //
    //      説明　：フォントサイズ変更
    //      引数　：LPCSTR fontname    フォント名
    //　　　戻り値：なし
    //		作成者：三上
    //////////////////////////////////////////////////////////
	void ChangeFontName(LPSTR fontname);

    //////////////////////////////////////////////////////////
    //
    //      説明　：文字の描画
    //      引数　：LPSTR   str     文字列
    //              long    posX    X座標
    //              long    posY    Y座標
    //　　　戻り値：なし
    //
    //////////////////////////////////////////////////////////
    void DrawFont(LPSTR str , long posX , long posY);

	//////////////////////////////////////////////////////////
	//
	//      説明　：文字の描画(uFormatの設定をしたい場合)
	//      引数　：LPSTR   str     文字列
	//              RECRT	rect	矩形座標
	//				DWORD	option	DrawTextのuFormatオプション
	//　　　戻り値：なし
	//		作成者：三上
	//////////////////////////////////////////////////////////
	void DrawFont(LPSTR str ,RECT rect,DWORD option);

};

#endif //_DIRECTFONT_H_