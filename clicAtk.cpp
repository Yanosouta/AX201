//--------------------------------------
// 2022/12/20 竹下雄太郎
// ハート内アニメーションを作成
//
//--------------------------------------
#include "clicAtk.h"
#include "Input.h"

clicAtk::clicAtk()
{
	m_isPlay = true;
	// ループする
	m_isLoop = true;

	KeyFrame clicAtk;

	clicAtk.time = 60;
	clicAtk.uv.uvWidth = 1.0f / 2;
	clicAtk.uv.uvHeight = 1.0f;
	clicAtk.uv.uvTopLeftU = 0.0f;
	clicAtk.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(clicAtk);

	clicAtk.uv.uvTopLeftU = 1.0f / 2;
	clicAtk.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(clicAtk);
}

clicAtk::~clicAtk()
{
}




