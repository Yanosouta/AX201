#include "FadeManager.h"
#include "ObjectManager.h"
#include "ObjectBase.h"
#include "FadeController.h"
#include "SceneManager.h"
#include "FadeObj.h"

SceneName::SceneName mName = SceneName::SceneName::SceneMax;

void FadeManager::CreateFadeIn()
{
	// フェードインのフェードが存在するかチェック
	if (ObjectManager::FindObjectWithTag(TagName::FadeIn)) return;

	// フェードを作成する
	std::shared_ptr<ObjectBase> pObj;
	pObj = ObjectManager::CreateObject<FadeObj>("FadeIn", TagName::FadeIn);

	// タイプをセットする
	pObj->GetComponent<FadeController>()->SetFadeType(FadeController::FadeType::Fade_In);
}

void FadeManager::CreateFadeOut(SceneName::SceneName name)
{
	// フェードアウトのフェードが存在するかチェック
	if (ObjectManager::FindObjectWithTag(TagName::FadeOut)) return;

	// フェードを作成する
	std::shared_ptr<ObjectBase> pObj;
	pObj = ObjectManager::CreateObject<FadeObj>("FadeOut", TagName::FadeOut);

	// フェードが終わったときにロードするシーンをセットする
	pObj->GetComponent<FadeController>()->SetLoadScene(name);

	// タイプをセットする
	pObj->GetComponent<FadeController>()->SetFadeType(FadeController::FadeType::Fade_Out);
}