#ifndef ___BOSSENEMY_H___
#define ___BOSSENEMY_H___
#include"Enemy.h"
//
//#include "Object3D.h"
//#include "MeshRenderer.h"
//#include "Rigidbody.h"
//#include "AABBCollider.h"
//#include "EnemyController.h"

class BossEnemy : public Object3D
{
public:
	// コンストラクタ
	BossEnemy(std::string name, std::string tag) : Object3D(name, tag) {
		// プレイヤーのモデルをロードする（仮でキューブのオブジェクト）
		GetComponent<MeshRenderer>()->LoadModel("Assets/Model/shinikougeki.fbx", 0.3f);
		// コンポーネントを追加
		AddComponent<EnemyController>();
		AddComponent<Rigidbody>();
		AddComponent<AABBCollider>();
		// 当たり判定の辺の長さをセット
		GetComponent<AABBCollider>()->SetLen({ 1.0f,1.0f,1.0f });
	}
	// デストラクタ
	~BossEnemy() {}
};

#endif //!___BOSSENEMY_H___
