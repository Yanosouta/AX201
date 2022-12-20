//--------------------------------------
// 2022/12/19 竹下雄太郎
// 残機の数字部分のアニメーションを作成
//
//--------------------------------------
#include "Zanki.h"
Zanki::Zanki()
{
	m_isPlay = true;
	// ループする
	m_isLoop = true;

	KeyFrame Zanki;

	// 数字9
	Zanki.time = 60;
	Zanki.uv.uvWidth = 1.0f / 4;
	Zanki.uv.uvHeight = 1.0f / 3;
	Zanki.uv.uvTopLeftU = 1.0f / 4;
	Zanki.uv.uvTopLeftV = 1.0f / 3 * 2;
	m_keyframes.push_back(Zanki);
	// 数字8
	Zanki.uv.uvTopLeftU = 0.0f;
	Zanki.uv.uvTopLeftV = 1.0f / 3 * 2;
	m_keyframes.push_back(Zanki);
	// 数字7
	Zanki.uv.uvTopLeftU = 1.0f / 4 * 3;
	Zanki.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(Zanki);
	// 数字6
	Zanki.uv.uvTopLeftU = 1.0f / 4 * 2;
	Zanki.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(Zanki);
	// 数字5
	Zanki.uv.uvTopLeftU = 1.0f / 4;
	Zanki.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(Zanki);
	// 数字4
	Zanki.uv.uvTopLeftU = 0.0f;
	Zanki.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(Zanki);
	// 数字3
	Zanki.uv.uvTopLeftU = 1.0f / 4 * 3;
	Zanki.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(Zanki);
	// 数字2
	Zanki.uv.uvTopLeftU = 1.0f / 4 * 2;
	Zanki.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(Zanki);
	// 数字1
	Zanki.uv.uvTopLeftU = 1.0f / 4;
	Zanki.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(Zanki);
	// 数字0
	Zanki.uv.uvTopLeftU = 0.0f;
	Zanki.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(Zanki);	
}

Zanki::~Zanki()
{
}



