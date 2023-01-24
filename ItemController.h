#pragma once

#include "ComponentBase.h"
#include "ObjectBase.h"
#include <DirectXMath.h>


class ItemController :
	public ComponentBase
{
public:
	//アイテムの種類
	enum ITEMKIND
	{
		E_LIFE_UP = 0, //体力回復

		E_SPECIAL_UP,  //スペシャル回復

		MAX_KIND
	};

public:
	ItemController()
		:m_pos(0.0f, 0.0f, 0.0f),
		m_sinFram(0.0f),
		m_rotY(0.0f),
		m_collCount(0)
	{}
	~ItemController()
	{}

	void Start() override final;
	void Update() override final;

	// 当たり判定
	void OnCollisionEnter(ObjectBase* object) override final;

	//セット関数
	void SetItemKind(int kind);

private:
	//アイテムの回転
	float m_rotY;
	//アイテムの種類
	ITEMKIND m_eItemKind;
	//アイテムの座標
	DirectX::XMFLOAT3 m_pos;
	float m_sinFram;
	//当たり判定用のカウント
	int m_collCount;
};

