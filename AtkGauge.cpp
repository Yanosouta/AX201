//--------------------------------------
// 2022/12/19 竹下雄太郎
// 残機の数字部分のアニメーションを作成
//
//--------------------------------------
#include "AtkGauge.h"
AtkGauge::AtkGauge()
{
	m_isPlay = true;
	// ループする
	m_isLoop = true;

	KeyFrame AtkGauge;

	// ためてない状態
	AtkGauge.time = 60;
	AtkGauge.uv.uvWidth = 1.0f / 4;
	AtkGauge.uv.uvHeight = 1.0f / 5;
	AtkGauge.uv.uvTopLeftU = 0.0f;
	AtkGauge.uv.uvTopLeftV = 1.0f / 5.0f * 4.0f;
	m_keyframes.push_back(AtkGauge);
	//1
	AtkGauge.uv.uvTopLeftU = 0.0f;
	AtkGauge.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(AtkGauge);
	//2
	AtkGauge.uv.uvTopLeftU = 1.0f / 4.0f;
	AtkGauge.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(AtkGauge);
	//3
	AtkGauge.uv.uvTopLeftU = 1.0f / 4.0f * 2;
	AtkGauge.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(AtkGauge);
	//4
	AtkGauge.uv.uvTopLeftU = 1.0f / 4.0f * 3;
	AtkGauge.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(AtkGauge);
	//5
	AtkGauge.uv.uvTopLeftU = 0.0f;
	AtkGauge.uv.uvTopLeftV = 1.0f / 5.0f;
	m_keyframes.push_back(AtkGauge);
	//6
	AtkGauge.uv.uvTopLeftU = 1.0f / 4.0f;
	AtkGauge.uv.uvTopLeftV = 1.0f / 5.0f;
	m_keyframes.push_back(AtkGauge);
	//7
	AtkGauge.uv.uvTopLeftU = 1.0f / 4.0f * 2;
	AtkGauge.uv.uvTopLeftV = 1.0f / 5.0f;
	m_keyframes.push_back(AtkGauge);
	//8
	AtkGauge.uv.uvTopLeftU = 1.0f / 4.0f * 3;
	AtkGauge.uv.uvTopLeftV = 1.0f / 5.0f;
	m_keyframes.push_back(AtkGauge);
	//9
	AtkGauge.uv.uvTopLeftU = 0.0f;
	AtkGauge.uv.uvTopLeftV = 1.0f / 5.0f * 2;
	m_keyframes.push_back(AtkGauge);
	//10
	AtkGauge.uv.uvTopLeftU = 1.0f / 4.0f;
	AtkGauge.uv.uvTopLeftV = 1.0f / 5.0f * 2;
	m_keyframes.push_back(AtkGauge);
	//11
	AtkGauge.uv.uvTopLeftU = 1.0f / 4.0f * 2;
	AtkGauge.uv.uvTopLeftV = 1.0f / 5.0f * 2;
	m_keyframes.push_back(AtkGauge);
	//12
	AtkGauge.uv.uvTopLeftU = 1.0f / 4.0f * 3;
	AtkGauge.uv.uvTopLeftV = 1.0f / 5.0f * 2;
	m_keyframes.push_back(AtkGauge);
	//13
	AtkGauge.uv.uvTopLeftU = 0.0f;
	AtkGauge.uv.uvTopLeftV = 1.0f / 5.0f * 3;
	m_keyframes.push_back(AtkGauge);
	//14
	AtkGauge.uv.uvTopLeftU = 1.0f / 4.0f;
	AtkGauge.uv.uvTopLeftV = 1.0f / 5.0f * 3;
	m_keyframes.push_back(AtkGauge);
	//15
	AtkGauge.uv.uvTopLeftU = 1.0f / 4.0f * 2;
	AtkGauge.uv.uvTopLeftV = 1.0f / 5.0f * 3;
	m_keyframes.push_back(AtkGauge);
	//16
	AtkGauge.uv.uvTopLeftU = 1.0f / 4.0f * 3;
	AtkGauge.uv.uvTopLeftV = 1.0f / 5.0f * 3;
	m_keyframes.push_back(AtkGauge);

	

}

AtkGauge::~AtkGauge()
{
}



