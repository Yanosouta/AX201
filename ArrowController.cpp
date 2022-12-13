#include "ArrowController.h"
#include "ObjectBase.h"
#include "ObjectManager.h"
#include <DirectXMath.h>
#include "Transform.h"
#include "Rigidbody.h"

void ArrowController::Update()
{
	//--- 矢の進行方向に向きを合わせるプログラム
	// 現在の正面のベクトル
	GetOwner()->GetComponent<Transform>()->GetVectorForword();
	// モデルの正面方向のベクトル
	DirectX::XMFLOAT3 zVector = { 0.0f, 0.0f, -1.0f };
}

void ArrowController::OnCollisionEnter(ObjectBase* object)
{
	if (object->GetTag() == TagName::Enemy) {
		ObjectManager::RemoveObject(GetOwner()->GetThisPtr());
	}
}

void ArrowController::OnCollisionStay(ObjectBase* object)
{
}

void ArrowController::OnCollisionExit(ObjectBase* object)
{

}