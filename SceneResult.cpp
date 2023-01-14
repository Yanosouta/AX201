//----------------------------------------------
// 1/14  竹下
//       リザルト用シーン作成
//----------------------------------------------
#include "SceneResult.h"
#include "MeshRenderer.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "ObjectManager.h"
#include "Ui.h"

SceneResult::SceneResult()
{
	//--- 変更用ポインタ
	std::shared_ptr<MeshRenderer> pMeshRenderer;	// 3Dオブジェクト用レンダラー
	std::shared_ptr<SpriteRenderer> pSpriteRenderer;// 2Dオブジェクト用レンダラー
	std::shared_ptr<Transform> pTransform;			// 位置情報
	std::shared_ptr<Rigidbody> pRigidbody;			// 物理挙動

	ObjectManager::CreateObject<UI>("UI.1");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.1")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.1")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/GameOver.png");
	pSpriteRenderer->SetSize(1280, 720);
	ObjectManager::FindObjectWithName("UI.1")->SetLayerNum(2);
	pTransform->SetPosition({ 0.0f, 0.0f, 0.0f });
}

SceneResult::~SceneResult()
{
}
