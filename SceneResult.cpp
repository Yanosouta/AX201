//----------------------------------------------
// 1/14  竹下
//       リザルト用シーン作成
//----------------------------------------------
#include "SceneResult.h"
#include "Result.h"
#include "MeshRenderer.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "ObjectManager.h"
#include "Ui.h"
#include "ResultButton.h"
#include "FadeManager.h"

SceneResult::SceneResult()
{
	//--- 変更用ポインタ
	std::shared_ptr<ObjectBase> pObj;
	std::shared_ptr<SpriteRenderer> pSpriteRenderer;// 2Dオブジェクト用レンダラー
	std::shared_ptr<Transform> pTransform;			// 位置情報

	//--- シーン切り替え時なのでフェードインを作成
	FadeManager::CreateFadeIn();

	pObj = ObjectManager::CreateObject<Result>("UI.1");
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pTransform = pObj->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/GameOver.png");
	pSpriteRenderer->SetSize(1280, 720);
	pObj->SetLayerNum(2);
	pTransform->SetPosition({ 0.0f, 0.0f, 0.0f });

	// ボタンアニメーション用画像
	pObj = ObjectManager::CreateObject<Result>("UI.2");
	pObj->SetLayerNum(3);
	pObj->AddComponent<ResultButton>();
	pObj->AddComponent<SpriteAnimation>();
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pSpriteRenderer->LoadTexture("Assets/Texture/ResultButton.png");
	pSpriteRenderer->SetSize(600, 100);
	pTransform = pObj->GetComponent<Transform>();
	pTransform->SetPosition({ 18.0f, -202.0f, 0.0f });
}

SceneResult::~SceneResult()
{
}
