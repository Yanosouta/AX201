#include "LifeNumber.h"

LifeNumber::LifeNumber()
{
	m_isPlay = true;
	// ループする
	m_isLoop = true;

	KeyFrame LifeNumber;

	// 数字100
	LifeNumber.time = 60;
	LifeNumber.uv.uvWidth = 1.0f / 2;
	LifeNumber.uv.uvHeight = 1.0f / 2;
	LifeNumber.uv.uvTopLeftU = 0.0f;
	LifeNumber.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(LifeNumber);
	// 数字75
	LifeNumber.uv.uvTopLeftU = 0.5f;
	LifeNumber.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(LifeNumber);
	// 数字50
	LifeNumber.uv.uvTopLeftU = 0.0f;
	LifeNumber.uv.uvTopLeftV = 0.5f;
	m_keyframes.push_back(LifeNumber);
	// 数字25
	LifeNumber.uv.uvTopLeftU = 0.5f;
	LifeNumber.uv.uvTopLeftV = 0.5f;
	m_keyframes.push_back(LifeNumber);
}

LifeNumber::~LifeNumber()
{
}
