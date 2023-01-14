#include "ItemController.h"
#include "Transform.h"
#include "ObjectBase.h"
#include "Primitive.h"
#include "Vector3.h"
#include "Float3.h"
#include "ObjectManager.h"
#include "Arrow.h"
#include "PlayerController.h"
#include"EnemyRepop.h"
#include "AABBCollider.h"



//============
//  下準備？
//============
void ItemController::Start()
{
	GetOwner()->GetComponent<AABBCollider>()->SetTouchOBB(TagName::Arrow);
}


//==========
// 更新
//==========
void ItemController::Update()
{
	//アイテムの回転

	//アイテムのy座標をsin波

}



//==================================
// オブジェクトとの当たり判定
//==================================
void ItemController::OnCollisionEnter(ObjectBase* object)
{
	//矢との当たり判定
	if (object->GetTag() == TagName::Arrow)
	{
		//プレイヤーが持っている矢でないときに処理する
		if (ObjectManager::FindObjectWithTag(TagName::Player)->GetComponent<PlayerController>()->GetHaveArrow()
			!= object->GetThisPtr())
		{
			m_bExist = false;

			//プレイヤーの体力回復、スペシャルゲージの回復の処理
			ObjectManager::FindObjectWithTag(TagName::Player)->GetComponent<PlayerController>()->AddZanki(1);
			ObjectManager::RemoveObject(GetOwner()->GetThisPtr());
		}
	}
}
