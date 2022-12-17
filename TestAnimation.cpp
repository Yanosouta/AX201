#include "TestAnimation.h"

TestAnimation::TestAnimation()
{
	// テストなのでここでtrueにするが、
	// Controller系のComponentからtrueにしてもよい
	m_isPlay = true;
	// ループする
	m_isLoop = true;
	
	// キーを設定
	KeyFrame keyframe;
	// �@
	keyframe.time = 60;
	keyframe.uv.uvWidth  = 1.0f / 3;
	keyframe.uv.uvHeight = 1.0f / 3;
	keyframe.uv.uvTopLeftU = 0.0f;
	keyframe.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(keyframe);	// 追加
	// �A
	keyframe.uv.uvTopLeftU = 1.0f / 3;
	keyframe.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(keyframe);	// 追加
	// �B
	keyframe.uv.uvTopLeftU = 1.0f / 3 * 2;
	keyframe.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(keyframe);	// 追加
	// �C
	keyframe.uv.uvTopLeftU = 0.0f;
	keyframe.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(keyframe);	// 追加
	// �D
	keyframe.uv.uvTopLeftU = 1.0f / 3;
	keyframe.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(keyframe);	// 追加
	// �E
	keyframe.uv.uvTopLeftU = 1.0f / 3 * 2;
	keyframe.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(keyframe);	// 追加
}

TestAnimation::~TestAnimation()
{

}