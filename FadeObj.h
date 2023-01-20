#ifndef ___FADE_OBJ_H___
#define ___FADE_OBJ_H___

#include "UI.h"
#include "FadeController.h"
#include "Transform.h"

class FadeObj : public UI
{
public:
	// コンストラクタ
	FadeObj(std::string name, std::string tag) : UI(name, tag) {
		// コンポーネントを追加
		AddComponent<FadeController>();
		// 座標を原点に
		GetComponent<Transform>()->SetPosition({ 0.0f, 0.0f, 0.0f });
		// テクスチャをセット
		GetComponent<SpriteRenderer>()->LoadTexture("Assets/Texture/WHITE.png");
		// 全画面のサイズに変更
		GetComponent<SpriteRenderer>()->SetSize(1280, 720);
		// 一番手前に描画するため、レイヤーを大きな数字に
		SetLayerNum(999);
	}
	// デストラクタ
	~FadeObj(){}

	// 描画
	void Draw() override final {
		this->GetComponent<SpriteRenderer>()->SetColor(
			this->GetComponent<FadeController>()->GetColor()
		);
		this->GetComponent<SpriteRenderer>()->Draw();
	}
};

#endif //!___FADE_OBJ_H___