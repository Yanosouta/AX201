#include "ArrowController.h"
#include "ObjectBase.h"
#include "ObjectManager.h"
#include <DirectXMath.h>
#include "Transform.h"
#include "Rigidbody.h"
#include "AABBCollider.h"

void ArrowController::Start()
{
	GetOwner()->GetComponent<AABBCollider>()->SetTouchOBB(TagName::Enemy);
}

void ArrowController::Update()
{
}

void ArrowController::OnCollisionEnter(ObjectBase* object)
{
	if (object->GetTag() == TagName::Enemy) {
		if (m_ArrowType == ARROW_TYPE::NORMAL)
			ObjectManager::RemoveObject(GetOwner()->GetThisPtr());
	}
}

void ArrowController::OnCollisionStay(ObjectBase* object)
{
}

void ArrowController::OnCollisionExit(ObjectBase* object)
{

}
