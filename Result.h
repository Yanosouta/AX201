#pragma once
#ifndef ___Result_H___
#define ___Result_H___
//--------------------------------------------------------------------------------
// 1/17 竹下
// リザルトヘッダを作成
//
//--------------------------------------------------------------------------------
#include "ObjectBase.h"
#include "SpriteRenderer.h"
#include "DirectX.h"
#include "ResultController.h"
class Result : public ObjectBase
{
public:
	// コンストラクタ
	Result(std::string name, std::string tag) : ObjectBase(name, tag) {
		// デフォルトコンポーネントを追加
		this->AddComponent<SpriteRenderer>();	// 2D用表面情報
		//----1/14 竹下 UIControllerを追加
		AddComponent<ResultController>();

		// 全ての設定が終わったら呼び出す
		this->Start();
	}
	// デストラクタ
	~Result() {}

	// 描画
	void Draw() override {
		this->GetComponent<SpriteRenderer>()->Draw();
	}
};
#endif //!___Game01_H___
