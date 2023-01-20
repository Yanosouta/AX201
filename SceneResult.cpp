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
#include "FadeManager.h"

SceneResult::SceneResult()
{
	//--- 変更用ポインタ
	std::shared_ptr<ObjectBase> pObj;
	std::shared_ptr<SpriteRenderer> pSpriteRenderer;// 2Dオブジェクト用レンダラー
	std::shared_ptr<Transform> pTransform;			// 位置情報

	FadeManager::CreateFadeIn();  //シーン生成時にフェード

	pObj = ObjectManager::CreateObject<UI>("UI.1");
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pTransform = pObj->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/GameOver.png");
	pSpriteRenderer->SetSize(1280, 720);
	pObj->SetLayerNum(2);
	pTransform->SetPosition({ 0.0f, 0.0f, 0.0f });
}

SceneResult::~SceneResult()
{
}
