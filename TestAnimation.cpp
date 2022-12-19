#include "TestAnimation.h"

TestAnimation::TestAnimation()
{
	// ÉeÉXÉgÇ»ÇÃÇ≈Ç±Ç±Ç≈trueÇ…Ç∑ÇÈÇ™ÅA
	// ControllerånÇÃComponentÇ©ÇÁtrueÇ…ÇµÇƒÇ‡ÇÊÇ¢
	m_isPlay = true;
	// ÉãÅ[ÉvÇ∑ÇÈ
	m_isLoop = true;
	
	// ÉLÅ[Çê›íË
	KeyFrame keyframe;
	// á@
	keyframe.time = 60;
	keyframe.uv.uvWidth  = 1.0f / 3;
	keyframe.uv.uvHeight = 1.0f / 3;
	keyframe.uv.uvTopLeftU = 0.0f;
	keyframe.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(keyframe);	// í«â¡
	// áA
	keyframe.uv.uvTopLeftU = 1.0f / 3;
	keyframe.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(keyframe);	// í«â¡
	// áB
	keyframe.uv.uvTopLeftU = 1.0f / 3 * 2;
	keyframe.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(keyframe);	// í«â¡
	// áC
	keyframe.uv.uvTopLeftU = 0.0f;
	keyframe.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(keyframe);	// í«â¡
	// áD
	keyframe.uv.uvTopLeftU = 1.0f / 3;
	keyframe.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(keyframe);	// í«â¡
	// áE
	keyframe.uv.uvTopLeftU = 1.0f / 3 * 2;
	keyframe.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(keyframe);	// í«â¡
}

TestAnimation::~TestAnimation()
{

}