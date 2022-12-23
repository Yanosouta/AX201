#ifndef ___ARROW_CONTROLLER_H___
#define ___ARROW_CONTROLLER_H__

#include "ComponentBase.h"
#include "ObjectBase.h"

class ArrowController : public ComponentBase
{
public:
	// 矢の種類
	enum ARROW_TYPE {
		NORMAL,	// 通常
		SUPER
	};	// 溜め撃ち
private:
	// 矢の種類
	ARROW_TYPE m_ArrowType;
public:
	// コンストラクタ
	ArrowController() {}
	// デストラクタ
	~ArrowController() {}
	// 初期化
	void Start()override;
	// 更新
	void Update()override;


	// 当たり判定
	void OnCollisionEnter(ObjectBase* object);
	void OnCollisionStay(ObjectBase* object);
	void OnCollisionExit(ObjectBase* object);
	
	//--- セット関数
	void SetArrowType(ARROW_TYPE Type) { m_ArrowType = Type; }
	//--- ゲット関数
	ARROW_TYPE GetArrowType() { return m_ArrowType; }
};

#endif //!___ARROW_CONTROLLER_H___
