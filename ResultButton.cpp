#include "ResultButton.h"

ResultButton::ResultButton()
{
	m_isPlay = true;
	// ÉãÅ[ÉvÇ∑ÇÈ
	m_isLoop = true;

	KeyFrame ResultButton;

	ResultButton.time = 60;
	ResultButton.uv.uvWidth = 1.0f / 2;
	ResultButton.uv.uvHeight = 1.0f;
	ResultButton.uv.uvTopLeftU = 0.0f;
	ResultButton.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(ResultButton);

	ResultButton.uv.uvTopLeftU = 1.0f / 2;
	ResultButton.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(ResultButton);
}

ResultButton::~ResultButton()
{
}
