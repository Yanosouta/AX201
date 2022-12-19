#include "SpriteAnimation.h"
#include "ObjectBase.h"

SpriteAnimation::SpriteAnimation()
	: m_time(0.0f)
	, m_isLoop(false)
	, m_speed(0.0f)
	, m_isPlay(false)
	, m_frameNum(0)
{

}

SpriteAnimation::~SpriteAnimation()
{

}

void SpriteAnimation::Start()
{
	m_SpritePtr = GetOwner()->GetComponent<SpriteRenderer>();
}

void SpriteAnimation::Update()
{
	// 再生中のみ
	if (m_isPlay) {
		// アニメーション時間を更新
		m_time++;

		// キーの時間になったら
		if (m_time >= m_keyframes[m_frameNum].time) {
			// 経過時間を補正する
			while (m_time >= m_keyframes[m_frameNum].time)
				m_time -= m_keyframes[m_frameNum].time;
			// キーフレームを次のキーフレームにする
			m_frameNum++;
			// 最後のキーフレームか判定
			if (m_frameNum == m_keyframes.size()) {
				// ループするなら
				if (m_isLoop) {
					// 最初のフレームへ
					m_frameNum = 0;
				}
				else { // しないなら
					// 再生フラグを下げる
					m_isPlay = false;
					return;
				}
			}
		}
		// 現在のキーの情報をスプライト情報に反映させる
		m_SpritePtr->GetInfo()->animeUV = m_keyframes[m_frameNum].uv;
	}
}

void SpriteAnimation::Play()
{
	m_isPlay = true;
	m_frameNum = 0;
}