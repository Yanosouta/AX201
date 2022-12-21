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
	pObj = ObjectManager::CreateObject<Cube>("Ground", TagName::Ground);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ -8.0f, -6.4f, -0.0f });
	pTrans->SetScale({ 88.0f,1.0f,41.5f });
	pCol->SetLen({ 88.0f,1.0f,41.5f });
}

Stage::~Stage()
{

}