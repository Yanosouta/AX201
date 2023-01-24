#include "LifeNumber.h"

LifeNumber::LifeNumber()
{
	m_isPlay = true;
	// ƒ‹[ƒv‚·‚é
	m_isLoop = true;

	KeyFrame LifeNumber;

	// ”š100
	LifeNumber.time = 60;
	LifeNumber.uv.uvWidth = 1.0f / 2;
	LifeNumber.uv.uvHeight = 1.0f / 2;
	LifeNumber.uv.uvTopLeftU = 0.0f;
	LifeNumber.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(LifeNumber);
	// ”š75
	LifeNumber.uv.uvTopLeftU = 0.5f;
	LifeNumber.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(LifeNumber);
	// ”š50
	LifeNumber.uv.uvTopLeftU = 0.0f;
	LifeNumber.uv.uvTopLeftV = 0.5f;
	m_keyframes.push_back(LifeNumber);
	// ”š25
	LifeNumber.uv.uvTopLeftU = 0.5f;
	LifeNumber.uv.uvTopLeftV = 0.5f;
	m_keyframes.push_back(LifeNumber);
}

LifeNumber::~LifeNumber()
{
}
