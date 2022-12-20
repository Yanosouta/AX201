//--------------------------------------
// 2022/12/20 竹下雄太郎
// ハート内アニメーションを作成
//
//--------------------------------------
#include "Life.h"
#include "Input.h"

Life::Life()
{
	m_isPlay = true;
	// ループする
	m_isLoop = true;

	KeyFrame Life;

	Life.time = 60;
	Life.uv.uvWidth = 1.0f / 2;
	Life.uv.uvHeight = 1.0f / 3;
	Life.uv.uvTopLeftU = 0.0f;
	Life.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(Life);

	Life.uv.uvTopLeftU = 1.0f / 2;
	Life.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(Life);

	Life.uv.uvTopLeftU = 0.0f;
	Life.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(Life);

	Life.uv.uvTopLeftU = 1.0f / 2;
	Life.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(Life);

	Life.uv.uvTopLeftU = 0.0f;
	Life.uv.uvTopLeftV = 1.0f / 3 * 2;
	m_keyframes.push_back(Life);
}

Life::~Life()
{
}
