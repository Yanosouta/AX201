#include "EnemyManager.h"
#include"Enemy.h"
#include"ObjectBase.h"
#include"ObjectManager.h"

#include"Transform.h"
#include<time.h>
#include<stdlib.h>

EnemyManager::EnemyManager()
	: m_RepopTime(240.0f)
	, m_tick(0.0f)
	, m_AppearCount(0)
	, m_FirstOnlyFlg(true)
	, m_MBCount(3)
	, m_FBBRepopTime(1200.0f)
	, m_FBBtick(0.0f)
	, m_FBBEnemyCount(6)
	, m_FinalBigBossHP(0)
	, m_StrBossHP(0)
{
	//リポップする場所
	m_RepopPosList.push_back(DirectX::XMFLOAT3{ -28.0f,-5.4f, 2.5f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{ -23.0f,-5.4f, 2.5f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{ -14.5f,-5.4f, 2.5f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{   7.1f,-5.4f, 2.5f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{  14.0f,-5.4f, 2.5f });
	m_RepopPosList.push_back(DirectX::XMFLOAT3{  20.5f,-5.4f, 2.5f });
}

void EnemyManager::Update()
{
	//カウント
	m_tick++;
	m_FBBtick++;
	if (ObjectManager::FindObjectListWithTag(TagName::FinalBigBoss).size() == 1)
	{
		m_FinalBigBossHP = ObjectManager::FindObjectWithTag(TagName::FinalBigBoss)->GetComponent<EnemyController>()->GetBigBossHp();
	}
	if (ObjectManager::FindObjectListWithTag(TagName::StrFinalBoss).size() == 1)
	{
		m_StrBossHP = ObjectManager::FindObjectWithTag(TagName::StrFinalBoss)->GetComponent<EnemyController>()->GetStrBossHp();
	}
	

	//リポップするか判定
	if (m_FirstOnlyFlg)
	{
		EnemyRepop({ m_RepopPosList[rand() % m_RepopPosList.size()] }, { 1.0f,1.0f,1.0f });
	
	}
	if (0 == ObjectManager::FindObjectListWithTag(TagName::Enemy).size() + ObjectManager::FindObjectListWithTag(TagName::MiddleBoss).size())
	{
		m_FirstOnlyFlg = true;
	}
	//強化エネミー出現
	if (m_AppearCount >= 10)
	{
		StrEnemyRepop({ -3.0f,-4.0f,10.0f }, { 1.5f,1.5f,1.5f });
		
	}
	//ボス出現
	if (m_MBCount == 0)
	{
		std::shared_ptr<ObjectBase> pFinalBoss;
		std::shared_ptr<Transform> pBossTrans;
		pFinalBoss = ObjectManager::CreateObject<Enemy>("RepopEnemy", TagName::FinalBoss);
		pBossTrans = pFinalBoss->GetComponent<Transform>();
		pBossTrans->SetPosition({ -3.0f,-4.0f,20.0f });
		pBossTrans->SetScale({ 2.0f,2.0f,2.0f });
		m_AppearCount = 0;
		m_FirstOnlyFlg = false;
		m_MBCount = 99;
	}

	//通常中ボスの敵の生成
	if (ObjectManager::FindObjectListWithTag(TagName::FinalBoss).size() == 1)
	{
		EnemyGenerate({ m_RepopPosList[rand() % m_RepopPosList.size()] }, { 1.0f,1.0f,1.0f }, m_RepopTime, m_tick, mc_RepopBossCount);
	}
	//強化中ボスの敵の生成
	if (ObjectManager::FindObjectListWithTag(TagName::StrFinalBoss).size() == 1)
	{
		StrEnemyGenerate({ m_RepopPosList[rand() % m_RepopPosList.size()] }, { 2.0f,2.0f,2.0f }, m_RepopTime, m_tick,mc_RepopStrBossCount);
		if (m_StrBossHP <= 25)
		{
			StrEnemyGenerate({ m_RepopPosList[rand() % m_RepopPosList.size()] }, { 2.0f,2.0f,2.0f }, m_RepopTime, m_tick, mc_RepopStrBossCount);
		}
	}
	//大ボスの敵の生成
	if (ObjectManager::FindObjectListWithTag(TagName::FinalBigBoss).size() == 1)
	{
		if (m_FinalBigBossHP <= 75)
		{
			m_FBBRepopTime = 800.0f;
		}
		if (m_FBBRepopTime < m_FBBtick)
		{
   			BEnemyGenerate({ m_RepopPosList[rand() % m_RepopPosList.size()] }, { 1.0f,1.0f,1.0f }, m_FBBRepopTime, m_FBBtick, mc_RepopFinalBigBossCount);
			BStrEnemyGenerate({ m_RepopPosList[rand() % m_RepopPosList.size()] }, { 1.5f,1.5f,1.5f }, m_FBBRepopTime, m_FBBtick, 1);
			m_FBBtick = 0.0f;
		}
	}
	
}
//エネミーのリスポーン
void EnemyManager::EnemyRepop(DirectX::XMFLOAT3 pos, DirectX::XMFLOAT3 Scale)
{
	if (m_RepopTime < m_tick&&mc_EnemyMaxNum > ObjectManager::FindObjectListWithTag(TagName::Enemy).size())
	{
		std::shared_ptr<ObjectBase> pEnemy;
		std::shared_ptr<Transform> pTrans;
		pEnemy = ObjectManager::CreateObject<Enemy>("RepopEnemy", TagName::Enemy);
		pTrans = pEnemy->GetComponent<Transform>();
		pTrans->SetPosition(pos);
		pTrans->SetScale({ Scale.x,Scale.y,Scale.z });
	
		m_AppearCount++;
		//m_tick = 0.0f;
	}
}
//強化エネミーのリスポーン
void EnemyManager::StrEnemyRepop(DirectX::XMFLOAT3 pos, DirectX::XMFLOAT3 Scale)
{
	if (m_RepopTime < m_tick&&mc_EnemyMaxNum > ObjectManager::FindObjectListWithTag(TagName::MiddleBoss).size())
	{
		std::shared_ptr<ObjectBase> pEnemy;
		std::shared_ptr<Transform> pTrans;
		pEnemy = ObjectManager::CreateObject<Enemy>("RepopEnemy", TagName::MiddleBoss);
		pTrans = pEnemy->GetComponent<Transform>();
		pTrans->SetPosition(pos);
		pTrans->SetScale({ Scale.x,Scale.y,Scale.z });

		m_AppearCount = 0;
		m_MBCount--;
		m_FirstOnlyFlg = false;
		
		//m_tick = 0.0f;
	}
}
//エネミーのジェネレート
void EnemyManager::EnemyGenerate(DirectX::XMFLOAT3 pos, DirectX::XMFLOAT3 Scale ,float Time,float tick,float Count)
{

	if (Time < tick&& Count > ObjectManager::FindObjectListWithTag(TagName::GenerateEnemy).size())
	{
		std::shared_ptr<ObjectBase> pEnemy;
		std::shared_ptr<Transform> pTrans;
		pEnemy = ObjectManager::CreateObject<Enemy>("RepopEnemy", TagName::GenerateEnemy);
		pTrans = pEnemy->GetComponent<Transform>();
		pTrans->SetPosition(pos);
		pTrans->SetScale(Scale);
		//m_tick = 0.0f;
	}
}
//強化エネミーのジェネレート
void EnemyManager::StrEnemyGenerate(DirectX::XMFLOAT3 pos, DirectX::XMFLOAT3 Scale, float Time, float tick,float Count)
{

	for (int i = 0; i < 3; i++)
	{
		std::shared_ptr<ObjectBase> pEnemy;
		std::shared_ptr<Transform> pTrans;
		pEnemy = ObjectManager::CreateObject<Enemy>("RepopEnemy", TagName::GenerateStrEnemy);
		pTrans = pEnemy->GetComponent<Transform>();
		pTrans->SetPosition(m_RepopPosList[rand() % m_RepopPosList.size()]);
		pTrans->SetScale(Scale);
	}
}
//大ボス用エネミー
void EnemyManager::BEnemyGenerate(DirectX::XMFLOAT3 pos, DirectX::XMFLOAT3 Scale, float Time, float tick, float Count)
{
	for (int i = 0; i < Count; i++)
	{
		std::shared_ptr<ObjectBase> pEnemy;
		std::shared_ptr<Transform> pTrans;
		pEnemy = ObjectManager::CreateObject<Enemy>("RepopEnemy", TagName::GenerateEnemy);
		pTrans = pEnemy->GetComponent<Transform>();
		pTrans->SetPosition(m_RepopPosList[rand() % m_RepopPosList.size()]);
		pTrans->SetScale(Scale);
	}
}
//大ボス用強化エネミー
void EnemyManager::BStrEnemyGenerate(DirectX::XMFLOAT3 pos, DirectX::XMFLOAT3 Scale, float Time, float tick, float Count)
{
	if (15 < ObjectManager::FindObjectListWithTag(TagName::GenerateStrEnemy).size())
	{
		for (int i = 0; i < 5; i++)
		{
			std::shared_ptr<ObjectBase> pEnemy;
			std::shared_ptr<Transform> pTrans;
			pEnemy = ObjectManager::CreateObject<Enemy>("RepopEnemy", TagName::GenerateStrEnemy);
			pTrans = pEnemy->GetComponent<Transform>();
			pTrans->SetPosition(m_RepopPosList[rand() % m_RepopPosList.size()]);
			pTrans->SetScale(Scale);
		}
	}
	
}

