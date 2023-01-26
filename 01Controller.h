#ifndef ___UI_CONTROLLER_H___
#define ___UI_CONTROLLER_H__

#include "ComponentBase.h"
#include "ObjectBase.h"
#include <memory>
#include <DirectXMath.h>

class Game01Controller : public ComponentBase
{
private:
	bool m_NextScene; // UI切り替え用フラグ
	int m_nSelect;    // 選択用カウンタ
	bool m_EndWnd;	  //ゲーム終了時のUI切り替えようフラグ
public:
	// コンストラクタ
	Game01Controller() {};
	// デストラクタ
	~Game01Controller() {};

	// 初期化
	void Start() override;
	// 更新
	void Update()override;
};

#endif //!___UI_CONTROLLER_H___
