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
public:
	//敵の状態
	enum ENEMY_MOTION_TYPE {
		NORMAL,		//通常
		ATTACK,		//アタック
		DEAD		//死んだ
	};
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
	
	//--- ノックバック用
	float m_KnockbackPower;	// 押される力
	bool m_bKnockBackFlg; //ノックバック中にフラグを立てる
	float m_FlgCount;	//フラグを立てている時にカウント
	float m_StanCount;	//スタンするまでに必要な攻撃数
	//---敵のパラメータ
	float m_EAttackErea;//エネミーの攻撃範囲
	int m_Hp;		//EnemyのHP
	int m_StrHp;	//強化エネミーのHP
	int m_BossHP;	//BossのHP
	int m_StrBossHP;//強化ボスのHP
	int m_BigBossHp;//大ボスのHP
	int m_ChargeTime;	//エネミーの攻撃時間

	float m_MoveStopCount;	//Enemyの止める時間のカウント

	//エネミーの状態種類
	ENEMY_MOTION_TYPE m_EnemyMotionType;
	// 攻撃用
	std::shared_ptr<ObjectBase> m_haveShockWave; // 現在敵が持っている矢のポインタ
	//死んだ後に行く場所
	DirectX::XMFLOAT3 m_DeadPos;
	//死んだ後に行く場所(右)
	DirectX::XMFLOAT3 m_RDeadPos;

	//--- 生成時に壁に埋もれないためのフラグ
	bool m_isOnCollision;
	
public:
	// コンストラクタ
	EnemyController()
		: m_MoveSpeed(0.05f)
		, m_ChangeTargetTime(50.0f)
		, m_tic(m_ChangeTargetTime)
		, m_TargetRotY(0.0f)
		, m_lateRotY(0.0f)
		, m_Hp(1)
		, m_StrHp(5)
		, m_BossHP(50)
		, m_StrBossHP(50)
		, m_BigBossHp(150)
		, m_bKnockBackFlg(false)
		, m_FlgCount(100.0f)
		, m_KnockbackPower(0.7f)
		, m_EAttackErea(1.5f)
		, m_EnemyMotionType(NORMAL)
		, m_DeadPos(-44.0f, -5.4, -9.0f)
		, m_MoveStopCount(0.0f)
		, m_StanCount(3.0f)
		, m_RDeadPos(44.0f, -5.4, -9.0f)
		, m_ChargeTime(120)
		, m_isOnCollision(false)
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

	//--- ゲット関数
	int GetStrBossHp();
	int GetBigBossHp();
};

#endif //!___ENEMY_CONTROLLER_H___
