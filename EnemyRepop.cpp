#include "EnemyRepop.h"
#include"ObjectManager.h"
#include"ObjectBase.h"
#include"Transform.h"
#include"Enemy.h"
#include<DirectXMath.h>
//EnemeyRepop::EnemeyRepop()
//{
//	
//}

void EnemeyRepop::SetEnemyRepop(float PosX, float PosY, float PosZ)
{
	//Enemyの生成


		//--- オブジェクト作成
		//   型　：Enemy
		//  名前 ：Enemy
		// タグ名：Enemy
	std::shared_ptr<ObjectBase> pEObj = ObjectManager::CreateObject<Enemy>("Enemy", TagName::Enemy);
	// Transformのポインタを取得する
	std::shared_ptr<Transform> pTransform = pEObj->GetComponent<Transform>();
	// 座標を設定する
	pTransform->SetPosition({ PosX, PosY, PosZ });
}
