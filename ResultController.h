#pragma once
#ifndef ___RESULT_CONTROLLER_H___
#define ___RESULT_CONTROLLER_H__

#include "ComponentBase.h"
#include "ObjectBase.h"
#include <memory>
#include <DirectXMath.h>

class ResultController : public ComponentBase
{
private:
	bool m_NextScene; // UI切り替え用フラグ
public:
	// コンストラクタ
	ResultController() {};
	// デストラクタ
	~ResultController() {};

	// 初期化
	void Start() override;
	// 更新
	void Update()override;
};

#endif //!___RESULT_CONTROLLER_H___