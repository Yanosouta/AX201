#ifndef ___DEBUG_H___
#define ___DEBUG_H___

namespace Debug
{
	/*・機能：デバッガに文字列を出力
	　　デバッグ出力ウィンドウに文字列を直接送信する							*/
	void Log(const char* format, ...);
}

#endif //!___DEBUG_H___