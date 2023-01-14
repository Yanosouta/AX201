#include "EnemyManager.h"
#include"Enemy.h"
#include"ObjectBase.h"
#include"ObjectManager.h"

#include"Transform.h"

EnemyManager::EnemyManager()
	: m_RepopTime(240.0f)
	, m_tick(0.0f)
	, m_AppearCount(0)
	, m_FirstOnlyFlg(true)
	, m_MBCount(3)
{
	//リポップする場所
	m_RepopPosList.push_back(DirectX::XMFLOAT3{ -28.0f,-5.4f, 3.1f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{ -23.0f,-5.4f, 5.0f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{ -14.5f,-5.4f, 2.2f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{   7.1f,-5.4f, 1.9f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{  14.0f,-5.4f, 2.6f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{  20.5f,-5.4f, 3.2f });
}

void EnemyManager::Update()
{
	//カウント
	m_tick++;

	//リポップするか判定
	if (m_FirstOnlyFlg)
	{
		if (m_RepopTime < m_tick&&mc_EnemyMaxNum > ObjectManager::FindObjectListWithTag(TagName::Enemy).size())
		{
			std::shared_ptr<ObjectBase> pEnemy;
			std::shared_ptr<Transform> pTrans;
			pEnemy = ObjectManager::CreateObject<Enemy>("RepopEnemy", TagName::Enemy);
			pTrans = pEnemy->GetComponent<Transform>();
			pTrans->SetPosition(m_RepopPosList[rand() % m_RepopPosList.size()]);
			pTrans->SetScale({ 1.0f,1.0f,1.0f });

			m_AppearCount++;
			//m_tick = 0.0f;
		}
		
	}
	if (0 == ObjectManager::FindObjectListWithTag(TagName::Enemy).size() + ObjectManager::FindObjectListWithTag(TagName::MiddleBoss).size())
	{
		m_FirstOnlyFlg = true;
		
	}
	//ボス出現
	if (m_AppearCount >= 10)
	{
		std::shared_ptr<ObjectBase> pFinalBoss;
		std::shared_ptr<Transform> pBossTrans;
		pFinalBoss = ObjectManager::CreateObject<Enemy>("RepopEnemy", TagName::MiddleBoss);
		pBossTrans = pFinalBoss->GetComponent<Transform>();
		pBossTrans->SetPosition({-3.0f,-4.0f,10.0f});
		pBossTrans->SetScale({ 2.0f,2.0f,2.0f });
		m_AppearCount = 0;
		m_MBCount--;
		m_FirstOnlyFlg = false;
	}
	//ボス出現
	if (m_MBCount == 0)
	{
		std::shared_ptr<ObjectBase> pFinalBoss;
		std::shared_ptr<Transform> pBossTrans;
		pFinalBoss = ObjectManager::CreateObject<Enemy>("RepopEnemy", TagName::FinalBoss);
		pBossTrans = pFinalBoss->GetComponent<Transform>();
		pBossTrans->SetPosition({ -3.0f,-4.0f,20.0f });
		pBossTrans->SetScale({ 3.0f,3.0f,3.0f });
		m_AppearCount = 0;

		m_FirstOnlyFlg = false;
		m_MBCount = 99;
	}
	//m_tick = 0.0f;
}
