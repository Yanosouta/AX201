#ifndef ___STRENEMY_H___
#define ___SYRENEMY_H___
#include "Enemy.h"
//
//#include "Object3D.h"
//#include "MeshRenderer.h"
//#include "Rigidbody.h"
//#include "AABBCollider.h"
//#include "EnemyController.h"
//
class StrEnemy : public Object3D
{
public:
	// コンストラクタ
	StrEnemy(std::string name, std::string tag) : Object3D(name, tag) {
		// プレイヤーのモデルをロードする（仮でキューブのオブジェクト）
		GetComponent<MeshRenderer>()->LoadModel("Assets/Model/enemy2.fbx", 0.1f);
		//MeshRenderer::AnimeNo no = GetComponent<MeshRenderer>()->AddAnimation("Assets/Model/The_dead_Walkbone.fbx");
		//if (no == MeshRenderer::ANIME_NONE)
		//{
		//	MessageBox(nullptr, "animeerror", "ERROR", MB_OK);
		//
		//}
		//GetComponent<MeshRenderer>()->Play(no, true);
		// コンポーネントを追加
		AddComponent<EnemyController>();
		AddComponent<Rigidbody>();
		AddComponent<AABBCollider>();
		// 当たり判定の辺の長さをセット
		GetComponent<AABBCollider>()->SetLen({ 1.0f,1.0f,1.0f });
	}
	// デストラクタ
	~StrEnemy() {}
};

#endif //!___STRENEMY_H___
