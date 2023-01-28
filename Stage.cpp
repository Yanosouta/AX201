#include "Stage.h"
#include "ObjectBase.h"
#include "ObjectManager.h"
#include <memory>
#include "Transform.h"
#include "AABBCollider.h"

#include "Field.h"
#include "Cube.h"

Stage::Stage()
{
	// 変更用ポインタ
	std::shared_ptr<ObjectBase> pObj;
	std::shared_ptr<Transform> pTrans;
	std::shared_ptr<AABBCollider> pCol;

	//--- Fieldのモデルを生成
	// 名前 : Field
	// タグ : 未設定 (Untagged)
	pObj = ObjectManager::CreateObject<Field>("Field");
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetScale({ 20.0f, 20.0f, 20.0f });
	pTrans->SetAngle({ 0.0f, 180.0f, 0.0f });

	//--- 当たり判定用モデルを生成
	//--- 床
	// 名前 : Ground
	// タグ : Ground
	pObj = ObjectManager::CreateObject<ObjectBase>("Ground", TagName::Ground);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ -8.0f, -6.4f, -0.0f });
	pTrans->SetScale({ 88.0f,1.0f,41.5f });
	pCol->SetLen({ 88.0f,1.0f,41.5f });

	pObj = ObjectManager::CreateObject<ObjectBase>("Wall", TagName::Wall);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ -35.6f, 0.0f, -18.0f });
	pTrans->SetScale({ 2.4f, 10.0f, 10.0f });
	pCol->SetLen({ 2.4f, 10.0f, 10.0f });

	pObj = ObjectManager::CreateObject<ObjectBase>("Wall", TagName::Wall);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ -35.6f, 0.0f, 0.0f });
	pTrans->SetScale({ 2.4f, 10.0f, 10.0f });
	pCol->SetLen({ 2.4f, 10.0f, 10.0f });

	pObj = ObjectManager::CreateObject<ObjectBase>("Wall", TagName::Wall);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ 25.2f, 0.0f, 0.0f });
	pTrans->SetScale({ 1.4f, 10.0f, 10.0f });
	pCol->SetLen({ 1.4f, 10.0f, 10.0f });

	pObj = ObjectManager::CreateObject<ObjectBase>("Wall", TagName::Wall);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ 25.2f, 0.0f, -18.0f });
	pTrans->SetScale({ 1.4f, 10.0f, 10.0f });
	pCol->SetLen({ 1.4f, 10.0f, 10.0f });

	pObj = ObjectManager::CreateObject<ObjectBase>("Wall", TagName::Wall);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ 25.2f, 0.0f, 4.0f });
	pTrans->SetScale({ 50.0f, 10.0f, 1.0f });
	pCol->SetLen({ 50.0f, 10.0f, 1.0f });

	pObj = ObjectManager::CreateObject<ObjectBase>("Wall", TagName::Wall);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ -33.2f, 0.0f, 4.0f });
	pTrans->SetScale({ 50.0f, 10.0f, 1.0f });
	pCol->SetLen({ 50.0f, 10.0f, 1.0f });

	pObj = ObjectManager::CreateObject<ObjectBase>("Wall", TagName::Wall);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ -5.0f, 0.0f, 21.0f });
	pTrans->SetScale({ 10.0f, 10.0f, 1.0f });
	pCol->SetLen({ 10.0f, 10.0f, 1.0f });

	pObj = ObjectManager::CreateObject<ObjectBase>("Wall", TagName::Wall);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ 0.0f, 0.0f, 16.0f });
	pTrans->SetScale({ 1.0f, 10.0f, 25.0f });
	pCol->SetLen({ 1.0f, 10.0f, 25.0f });

	pObj = ObjectManager::CreateObject<ObjectBase>("Wall", TagName::Wall);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ -8.0f, 0.0f, 16.0f });
	pTrans->SetScale({ 1.0f, 10.0f, 25.0f });
	pCol->SetLen({ 1.0f, 10.0f, 25.0f });


	pObj = ObjectManager::CreateObject<ObjectBase>("Wall", TagName::Wall);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ 36.5f, -5.0f, 0.0f });
	pTrans->SetScale({ 1.0f, 10.0f, 50.0f });
	pCol->SetLen({ 1.0f, 10.0f, 50.0f });

	pObj = ObjectManager::CreateObject<ObjectBase>("Wall", TagName::Wall);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ -52.0f, -5.0f, 0.0f });
	pTrans->SetScale({ 1.0f, 10.0f, 50.0f });
	pCol->SetLen({ 1.0f, 10.0f, 50.0f });

	pObj = ObjectManager::CreateObject<ObjectBase>("Wall", TagName::Wall);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ 0.0f, -5.0f, -22.0f });
	pTrans->SetScale({ 130.0f, 10.0f, 1.0f });
	pCol->SetLen({ 130.0f, 10.0f, 1.0f });
}

Stage::~Stage()
{

}