#ifndef ___Game01_H___
#define ___Game01_H___
//--------------------------------------------------------------------------------
// 1/17 竹下
// ゲーム01ヘッダ(タイトル)を作成(UIControllerがすべてのシーンに適応されちゃうため)
//
//--------------------------------------------------------------------------------

#include "ObjectBase.h"
#include "SpriteRenderer.h"
#include "DirectX.h"
#include "01Controller.h"
class Game01 : public ObjectBase
{
public:
	// コンストラクタ
	Game01(std::string name, std::string tag) : ObjectBase(name, tag) {
		// デフォルトコンポーネントを追加
		this->AddComponent<SpriteRenderer>();	// 2D用表面情報
		//----1/14 竹下 UIControllerを追加
		AddComponent<Game01Controller>();

		// 全ての設定が終わったら呼び出す
		this->Start();
	}
	// デストラクタ
	~Game01() {}

	// 描画
	void Draw() override {
		this->GetComponent<SpriteRenderer>()->Draw();
	}
};
#endif //!___Game01_H___