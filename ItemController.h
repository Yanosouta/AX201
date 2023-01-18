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
		:m_rotSpeed(DirectX::XMConvertToRadians(10.0f))
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
	//アイテムの回転速度
	float m_rotSpeed;
	//アイテムの種類
	ITEMKIND m_eItemKind;
};

