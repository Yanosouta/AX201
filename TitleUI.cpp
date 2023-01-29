//--------------------------------------
// 2022/12/20 竹下雄太郎
// ハート内アニメーションを作成
//
//--------------------------------------
#include "TitleUI.h"
#include "Input.h"

TitleUI::TitleUI()
{
	m_isPlay = true;
	// ループする
	m_isLoop = true;

	KeyFrame TitleUI;

	TitleUI.time = 60;
	TitleUI.uv.uvWidth = 1.0f;
	TitleUI.uv.uvHeight = 1.0f;
	TitleUI.uv.uvTopLeftU = 0.0f;
	TitleUI.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(TitleUI);
}

TitleUI::~TitleUI()
{
}




