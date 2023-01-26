//-----------------------------------
//1/14 竹下
//     UIControllerを作成
//1/17 Game01.hだけに使用
//     UIControllerから01Controllerに名前犯行
//-----------------------------------
#include "01Controller.h"
#include "Input.h"
#include "SceneManager.h"
#include "SBotton.h"
#include "ObjectManager.h"
#include "FadeManager.h"
#include "EButton.h"
#include "WinUtil.h"

void Game01Controller::Start()
{
	m_NextScene = false;
	m_EndWnd = false;
	m_nSelect = 0;
}

void Game01Controller::Update()
{
	//エンターを押すとゲームシーンに移動
	if (m_NextScene)	
	{
		//SceneManager::LoadScene(SceneName::SceneTitle);
		FadeManager::CreateFadeOut(SceneName::SceneTitle);
	}
	if (m_EndWnd)
	{
		EndWindow();
	}
	if (IsKeyTrigger(VK_UP))
	{
		m_nSelect++;
	}
	else if (IsKeyTrigger(VK_DOWN))
	{
		m_nSelect++;
	}
	// 奇数なら選択中
	if (m_nSelect % 2 == 1)
	{
		ObjectManager::FindObjectWithName("UI.3")->GetComponent<SBtton>()->Swapframe(1);
		ObjectManager::FindObjectWithName("UI.3")->GetComponent<SBtton>()->Play();
		ObjectManager::FindObjectWithName("UI.4")->GetComponent<SBtton>()->Swapframe(0);
		ObjectManager::FindObjectWithName("UI.4")->GetComponent<SBtton>()->Play();
	}
	// 偶数なら未選択
	if (m_nSelect % 2 == 0)
	{
		ObjectManager::FindObjectWithName("UI.3")->GetComponent<SBtton>()->Swapframe(0);
		ObjectManager::FindObjectWithName("UI.3")->GetComponent<SBtton>()->Play();
		ObjectManager::FindObjectWithName("UI.4")->GetComponent<SBtton>()->Swapframe(1);
		ObjectManager::FindObjectWithName("UI.4")->GetComponent<SBtton>()->Play();
	}
	// エンターキーでUI切り替え
	if (IsKeyTrigger(VK_RETURN))
	{
		if (m_nSelect % 2 == 1)
		{
			m_NextScene = true;
			ObjectManager::FindObjectWithName("UI.3")->GetComponent<SBtton>()->Swapframe(2);
			ObjectManager::FindObjectWithName("UI.3")->GetComponent<SBtton>()->Play();
		}
		if (m_nSelect % 2 == 0)
		{
			m_EndWnd = true;
			ObjectManager::FindObjectWithName("UI.4")->GetComponent<SBtton>()->Swapframe(2);
			ObjectManager::FindObjectWithName("UI.4")->GetComponent<SBtton>()->Play();
		}
	}
}
