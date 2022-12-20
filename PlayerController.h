#ifndef ___PLAYER_CONTROLLER_H___
#define ___PLAYER_CONTROLLER_H__

#include "ComponentBase.h"
#include "ObjectBase.h"
#include <memory>
#include <DirectXMath.h>

class PlayerController : public ComponentBase
{
private:
	//--- 射撃用
	// 長押しによる溜め攻撃を使用可能になる時間
	float m_ChargeTime;
	float m_tic; // フレームカウント
	std::shared_ptr<ObjectBase> m_haveArrow; // 現在プレイヤーが持っている矢のポインタ
	DirectX::XMFLOAT3 m_prevPos;	// ひとつ前の座標
public:
	// コンストラクタ
	PlayerController()
		: m_ChargeTime(30.0f) // 60 fps の場合 0.5 秒
	{}
	// デストラクタ
	~PlayerController() {}
	// 初期化
	void Start() override;
	// 更新
	void Update()override;


	// 当たり判定
	void OnCollisionEnter(ObjectBase* object);
	void OnCollisionStay(ObjectBase* object);
	void OnCollisionExit(ObjectBase* object);
	
	//--- ゲット関数
	std::shared_ptr<ObjectBase> GetHaveArrow() { return m_haveArrow; }
};

#endif //!___PLAYER_CONTROLLER_H___
