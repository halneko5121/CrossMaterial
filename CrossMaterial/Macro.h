/*-------------------------------------------------

		マクロの管理
		説明　：Macroのヘッダー
		作成者：兼武
		作成日：10月22日
		更新日：10月22日

---------------------------------------------------*/
#ifndef _MACRO_H_
#define _MACRO_H_

//メモリの解放（NULL を判定して、開放されていない Object Class などを開放します）
#define SAFE_DELETE(p) {if(p){delete(p); (p) = NULL;}}
//参照カウンタのデクリメント
#define SAFE_RELEASE(p) {if(p){(p)->Release();(p) = NULL;}}

//デリートマクロ
#define SAFE_DELETE_ARRYY(x) {if(x){delete[](x);(x) = NULL;}}

#endif	//_MACRO_H_