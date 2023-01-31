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
	m_rotY += 0.5f;
	GetOwner()->GetComponent<Transform>()->SetAngle(DirectX::XMFLOAT3(0.0f, m_rotY, 0.0f));

	//アイテムのy座標をsin波
	m_pos = GetOwner()->GetComponent<Transform>()->GetPosition();
	m_pos.y = sin(m_sinFram * 360 / 60 * 3.14f / 180) * 0.03f + m_pos.y;
	GetOwner()->GetComponent<Transform>()->SetPosition(m_pos);

	m_sinFram++;
	m_collCount++;
}



//==================================
// オブジェクトとの当たり判定
//==================================
void ItemController::OnCollisionEnter(ObjectBase* object)
{
	//矢との当たり判定
	if (object->GetTag() == TagName::Arrow && m_collCount > 30)
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
			case ItemController::E_LIFE_UP: pObj->GetComponent<PlayerController>()->AddLife(MAX_LIFE);
				break;

				//スペシャルアップ
			case ItemController::E_SPECIAL_UP: pObj->GetComponent<PlayerController>()->SetEnableSpecial(true);
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
