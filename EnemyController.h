///////////////////////
//編集履歴
//2022年12月19日 矢野　Hpの変数を追加
//
//
//
//
#ifndef ___ENEMY_CONTROLLER_H___
#define ___ENEMY_CONTROLLER_H__

#include "ComponentBase.h"
#include "ObjectBase.h"
#include <DirectXMath.h>

class EnemyController : public ComponentBase
{
private:

	//--- 移動用
	// 移動スピード（１フレームに進む距離）
	float m_MoveSpeed;
	// ターゲットまでのベクトル
	DirectX::XMFLOAT3 m_TargetVector;
	// ターゲットの場所をランダムで変える時間(ミリ秒)
	float m_ChangeTargetTime;
	float m_tic; // フレームカウント
	float m_TargetRotY;	// ターゲットまでのベクトルのY角度
	float m_lateRotY;	// 遅れてついてくるY角度
	DirectX::XMFLOAT3 m_prevPos;	// ひとつ前の座標
	int m_Hp;	//Enemyの体力
	
	//--- ノックバック用
	float m_KnockbackPower;	// 押される力
	bool m_bKnockBackFlg; //ノックバック中にフラグを立てる
	float m_FlgCount;	//フラグを立てている時にカウント
public:
	// コンストラクタ
	EnemyController()
		: m_MoveSpeed(0.05f)
		, m_ChangeTargetTime(50.0f)
		, m_tic(m_ChangeTargetTime)
		, m_TargetRotY(0.0f)
		, m_lateRotY(0.0f)
		, m_Hp(2)
		, m_bKnockBackFlg(false)
		, m_FlgCount(5.0f)
		, m_KnockbackPower(0.7f)
	{}
	// デストラクタ
	~EnemyController() {}
	// 初期化
	void Start() override;
	// 更新
	void Update()override;

	// 当たり判定
	void OnCollisionEnter(ObjectBase* object);
	void OnCollisionStay(ObjectBase* object);
	void OnCollisionExit(ObjectBase* object);

	//--- セット関数
	void SetMoveSpeed(float speed) { m_MoveSpeed = speed; }
};

#endif //!___ENEMY_CONTROLLER_H___
