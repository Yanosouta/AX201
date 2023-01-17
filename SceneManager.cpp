#include "SceneManager.h"
#include "ObjectManager.h"
#include "SceneTitle.h"
#include "SceneGame01.h"
#include "SceneResult.h"

bool SceneManager::m_bLoad = false;
SceneName::SceneName SceneManager::m_loadScene = SceneName::SceneGame01; // スタートをタイトル画面からに変更

void SceneManager::LoadUpdate() {
	if (m_bLoad) {
		m_bLoad = false;
		// オブジェクトを全削除
		ObjectManager::DestroyAllObject();

		// ロードシーンで分岐
		switch (m_loadScene) {
		case SceneName::SceneGame01:
			SceneGame01();
			break;
		case SceneName::SceneTitle:
			SceneTitle();
			break;
		case SceneName::SceneResult:
			SceneResult();
			break;
		}
	}
}

void SceneManager::LoadScene(SceneName::SceneName scene) {
	m_loadScene = scene;
	m_bLoad = true;
}

int SceneManager::GetScene()
{
	return m_loadScene;
}
