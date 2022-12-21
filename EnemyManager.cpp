#include "EnemyManager.h"
#include"Enemy.h"
#include"ObjectBase.h"
#include"ObjectManager.h"

#include"Transform.h"

EnemyManager::EnemyManager()
	: m_RepopTime(240.0f)
	, m_tick(0.0f)
{
	//リポップする場所
	m_RepopPosList.push_back(DirectX::XMFLOAT3{10.0f, 0.0f, 0.0f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{ 5.0f, 0.0f, 0.0f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{ 0.0f, 0.0f, 0.0f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{-5.0f, 0.0f, 0.0f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{-10.0f,0.0f, 0.0f });
}

void EnemyManager::Update()
{
	//カウント
	m_tick++;

	//リポップするか判定
	if (m_RepopTime < m_tick&&mc_EnemyMaxNum > ObjectManager::FindObjectListWithTag(TagName::Enemy).size())
	{
		std::shared_ptr<ObjectBase> pEnemy;
		std::shared_ptr<Transform> pTrans;
		pEnemy = ObjectManager::CreateObject<Enemy>("RepopEnemy", TagName::Enemy);
		pTrans = pEnemy->GetComponent<Transform>();
		pTrans->SetPosition(m_RepopPosList[rand() % m_RepopPosList.size()]);
		pTrans->SetScale({ 1.0f,1.0f,1.0f });

		m_tick = 0.0f;
	}
}
