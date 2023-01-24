#pragma once

#include "Object3D.h"
#include "AABBCollider.h"
#include "ItemController.h"

class ItemSpecial : public Object3D
{
public:
	// コンストラクタ
	ItemSpecial(std::string name, std::string tag) : Object3D(name, tag) {
		//アイテムのモデルをロードする（仮でキューブのオブジェクト）
		GetComponent<MeshRenderer>()->LoadModel("Assets/Model/Item/specialheart/ItemSpecial.fbx", 0.5f);
		// コンポーネントを追加
		AddComponent<AABBCollider>();
		AddComponent<ItemController>();
		// 当たり判定の辺の長さをセット
		GetComponent<AABBCollider>()->SetLen({ 0.5f,0.5f,0.5f });
	}

	// デストラクタ
	~ItemSpecial() {}
};