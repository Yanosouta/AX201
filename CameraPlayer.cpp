#include "CameraPlayer.h"
#include "Transform.h"
#include "ObjectManager.h"

void CameraPlayer::Update()
{
	// Playerタグのついたオブジェクトの座標を取得し、注視点にする。
	m_LookPoint = ObjectManager::FindObjectWithTag(TagName::Player)->GetComponent<Transform>()->GetPosition();

	// 角度と距離、注視点からカメラの位置を計算
	GetOwner()->GetComponent<Transform>()->SetPosition({
	cosf(m_radY) * sinf(m_radXZ) * m_radius + m_LookPoint.x,
	sinf(m_radY) * m_radius + m_LookPoint.y,
	cosf(m_radY) * cosf(m_radXZ) * m_radius + m_LookPoint.z
		});

	/* 画面揺れ判定 */
	if (m_bScreenShake)
	{
		m_tick++;
		m_radius = (mc_radius - sinf(m_tick * 100 / mc_screenShakeTime));
		m_radY = (m_StopRadY - sinf(m_tick*100 / mc_screenShakeTime)) * -0.02f + 3;
		m_radXZ = (m_StopRadXZ - sinf(m_tick * 100 / mc_screenShakeTime)) * -0.02f + 6.27;
		if (mc_screenShakeTime < m_tick) m_bScreenShake = false;
	}
}