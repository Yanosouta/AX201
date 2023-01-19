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
		std::shared_ptr<ObjectBase> pObj = ObjectManager::FindObjectWithTag(TagName::Player);

		//プレイヤーが持っている矢でないときに処理する
		if (pObj->GetComponent<PlayerController>()->GetHaveArrow()
			!= object->GetThisPtr())
		{
			//アイテムの種類によって効果を変える
			switch (m_eItemKind)
			{
				//体力回復
			case ItemController::E_LIFE_UP: pObj->GetComponent<PlayerController>()->AddLife(1);
				break;

				//スペシャルアップ
			case ItemController::E_SPECIAL_UP: pObj->GetComponent<PlayerController>()->SetEnableSpecial();
				break;
			
			default:
				break;
			}

			//自身の削除
			ObjectManager::RemoveObject(GetOwner()->GetThisPtr());
		}
	}
}



//=======================
//アイテムの種類を決める
//=======================
void ItemController::SetItemKind(int kind)
{
	//体力回復
	if (kind == 0) m_eItemKind = E_LIFE_UP;
	//スペシャル
	if (kind == 1) m_eItemKind = E_SPECIAL_UP;
}
