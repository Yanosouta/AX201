#include "Debug.h"
#include <Windows.h>
#include <string>

/*・機能：デバッガに文字列を出力
　　デバッグ出力ウィンドウに文字列を直接送信する							*/
void Debug::Log(const char* format, ...)
{
#ifdef _DEBUG

	//--- 変数宣言
	char buf[1024];		//バッファ
	va_list ap;			//可変長を操作する為の構造体
	int resultNum = 0;	//処理結果の数値を格納

	va_start(ap, format);	//可変長引数の操作を開始

	resultNum = vsprintf_s(buf, format, ap);

	//--- エラー検出処理
	if (resultNum < 0)
	{
		OutputDebugString("\nLog output failed");	//エラーメッセージを出力

		//--- 終了処理
		va_end(ap);		//可変長引数の操作を終了
		return;			//強制終了
	}

	OutputDebugString(buf);		//指定された文字列を出力

	va_end(ap);	//可変長引数の操作を終了
#endif //_DEBUG
}