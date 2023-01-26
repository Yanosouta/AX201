#include "SceneGame01.h"
#include "MeshRenderer.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "ObjectManager.h"
#include "Ui.h"
#include "Game01.h"
#include "SBotton.h"
#include "FadeManager.h"

SceneGame01::SceneGame01()
{
	//--- 変更用ポインタ
	std::shared_ptr<MeshRenderer> pMeshRenderer;	// 3Dオブジェクト用レンダラー
	std::shared_ptr<SpriteRenderer> pSpriteRenderer;// 2Dオブジェクト用レンダラー
	std::shared_ptr<Transform> pTransform;			// 位置情報
	std::shared_ptr<Rigidbody> pRigidbody;			// 物理挙動
	std::shared_ptr<ObjectBase> pObj;               //

	//--- シーン切り替え時なのでフェードインを作成
	FadeManager::CreateFadeIn();

	//--- UI作成
	//------------------------------------
	// 1/14 竹下
	//      タイトル用の画像に差し替え
	//------------------------------------
	// UI.1 タイトル画面
	ObjectManager::CreateObject<Game01>("UI.2");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.2")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.2")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/Bg.png");
	pSpriteRenderer->SetSize(1280, 720);
	ObjectManager::FindObjectWithName("UI.2")->SetLayerNum(2);
	pTransform->SetPosition({ 0.0f, 0.0f, 0.0f });
	
	//------------------------------------
	// 1/17 竹下
	//      ボタンアニメーション用画像
	//------------------------------------
	pObj = ObjectManager::CreateObject<UI>("UI.3");
	pObj->SetLayerNum(4);
	pObj->AddComponent<SBtton>(); 
	pObj->AddComponent<SpriteAnimation>();
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pSpriteRenderer->LoadTexture("Assets/Texture/Start.png");
	pSpriteRenderer->SetSize(460, 92);
	pTransform = pObj->GetComponent<Transform>();
	pTransform->SetPosition({ 0.0f, -153.0f, 0.0f });

	pObj = ObjectManager::CreateObject<UI>("UI.4");
	pObj->SetLayerNum(4);
	pObj->AddComponent<SBtton>();
	pObj->AddComponent<SpriteAnimation>();
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pSpriteRenderer->LoadTexture("Assets/Texture/End1.png");
	pSpriteRenderer->SetSize(460, 92);
	pTransform = pObj->GetComponent<Transform>();
	pTransform->SetPosition({ 0.0f, -260.0f, 0.0f });
}

SceneGame01::~SceneGame01()
{

}