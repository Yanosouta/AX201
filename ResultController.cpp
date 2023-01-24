#include "ResultController.h"
#include "Input.h"
#include "SceneManager.h"
#include "ResultButton.h"
#include "ObjectManager.h"
#include "FadeManager.h"

void ResultController::Start()
{
	m_NextScene = false;
}

void ResultController::Update()
{
	//エンターを押すとゲームシーンに移動
	if (m_NextScene)
	{
		//SceneManager::LoadScene(SceneName::SceneTitle);
		FadeManager::CreateFadeOut(SceneName::SceneTitle);
	}
	
	// エンターキーでUI切り替え
	if (IsKeyTrigger(VK_RETURN))
	{
		m_NextScene = true;
		ObjectManager::FindObjectWithName("UI.2")->GetComponent<ResultButton>()->Swapframe(1);
		ObjectManager::FindObjectWithName("UI.2")->GetComponent<ResultButton>()->Play();
	}
}
