#include "ClearManager.h"
#include "Player.h"
#include"ObjectBase.h"
#include"ObjectManager.h"
#include "SpriteRenderer.h"
#include "Input.h"
#include "SceneManager.h"
#include "FadeManager.h"

ClearManager::ClearManager()
	:m_BreakEnemy(0)
	,m_color(1.0f,1.0f,1.0f,0.0f)
	,m_time(0.0f)
	,m_TotalTime(90.0f)
{
	ObjectManager::FindObjectWithName("UI.12")->GetComponent<SpriteRenderer>()->SetColor(m_color);
}

void ClearManager::Update()
{
	
	m_BreakEnemy = ObjectManager::FindObjectWithTag(TagName::Player)->GetComponent<PlayerController>()->GetBreahEnemy();
	if (m_BreakEnemy == mc_nClearEnemyNum)
	{
		m_time++;
		m_color.w = 0.0f + (m_time / m_TotalTime);
		ObjectManager::FindObjectWithName("UI.12")->GetComponent<SpriteRenderer>()->SetColor(m_color);
	}
	if (IsKeyTrigger(VK_RETURN))
	{
		FadeManager::CreateFadeOut(SceneName::SceneGame01);
	}
}
