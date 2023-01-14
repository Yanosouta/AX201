#pragma once

#include "ComponentBase.h"
#include "ObjectBase.h"
#include <DirectXMath.h>


class ItemController :
	public ComponentBase
{
public:
	enum ItemKind
	{
		LIFE_UP = 0,

		SPECIAL_UP,

		MAX_KIND
	};

public:
	ItemController()
		:m_rotSpeed(DirectX::XMConvertToRadians(10.0f)),
		m_bExist(true)
	{}
	~ItemController()
	{}

	void Start() override final;
	void Update() override final;

	// 当たり判定
	void OnCollisionEnter(ObjectBase* object) override final;

private:
	//アイテムの回転速度
	float m_rotSpeed;
	//アイテムの生存フラグ
	bool m_bExist;

};

