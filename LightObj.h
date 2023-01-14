#pragma once

#include "ObjectBase.h"
#include "light.h"

class LightObj : public ObjectBase
{
public:
	// コンストラクタ
	LightObj(std::string name, std::string tag) : ObjectBase(name, tag) {
		AddComponent<light>();
	}
	// デストラクタ
	~LightObj() {}
};