#ifndef ___UI_CONTROLLER_H___
#define ___UI_CONTROLLER_H__

#include "ComponentBase.h"
#include "ObjectBase.h"
#include <memory>
#include <DirectXMath.h>

class UIController : public ComponentBase
{
private:
	
public:
	// コンストラクタ
	UIController() {};
	// デストラクタ
	~UIController() {};

	// 初期化
	void Start() override;
	// 更新
	void Update()override;
};

#endif //!___UI_CONTROLLER_H___
