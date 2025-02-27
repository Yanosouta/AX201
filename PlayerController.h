#ifndef ___PLAYER_CONTROLLER_H___
#define ___PLAYER_CONTROLLER_H__

#include "ComponentBase.h"
#include "ObjectBase.h"
#include <memory>
#include <DirectXMath.h>

#define MAX_LIFE (4)

class PlayerController : public ComponentBase
{
private:
	//--- 射撃用
	// 長押しによる溜め攻撃を使用可能になる時間
	float m_ChargeTime;
	float m_tic; // フレームカウント
	std::shared_ptr<ObjectBase> m_haveArrow[3]; // 現在プレイヤーが持っている矢のポインタ
	DirectX::XMFLOAT3 m_prevPos;	// ひとつ前の座標
	bool m_isHaveArrow;	// 射撃中かどうか

	// 12/23 竹下　プレイヤーのライフ
	int m_Life;
	bool m_bLifeFlg;  // [EnemyControllerの見よう見まねで作ったので、いるか分かりません
	float m_FlgCount; // [cppの269行目あたりで使ってると思うので見てあんま意味なければ消してもいいです
	// 12/23 竹下　プレイヤーの残機
	unsigned int m_Zanki;
	bool m_EnableSpecial; //スペシャルの使用可能フラグ
	
	//--- ノックバック用
	float m_KnockBackPower;	// 押される力
	bool  m_bKnockBackFlg; //ノックバック中にフラグを立てる
	float m_KnockBackCount;	//フラグを立てている時にカウント

	//UI用
	bool m_LivesHighlighting;		//強調表示中フラグ
	DirectX::XMFLOAT2 m_LivesIV;	//UIの初期値
	bool m_LivesHalf;				//強調表示の折り返し
	int m_Specialcnt;

	int m_nEnemyNum;	// 倒した敵の数

	//矢の処理用の関数
	void IsSpecialArrow();
	void IsNormalArrow();

public:
	// コンストラクタ
	PlayerController()
		: m_ChargeTime(30.0f) // 60 fps の場合 0.5 秒
		, m_Life(MAX_LIFE)
		, m_Zanki(2)
		, m_bLifeFlg(false)
		, m_FlgCount(5.0f)
		, m_bKnockBackFlg(false)
		, m_KnockBackCount(20.0f)
		, m_KnockBackPower(0.05f)
		, m_LivesHighlighting(false)
		, m_LivesHalf(false)
		,m_LivesIV(DirectX::XMFLOAT2(1.0f,1.0f))
		, m_nEnemyNum(0)
		, m_isHaveArrow(false)
		,m_EnableSpecial(false)
		,m_Specialcnt(0)
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
	std::shared_ptr<ObjectBase> GetHaveArrow() { return *m_haveArrow; }
	bool GetIsHaveArrow() { return m_isHaveArrow; }

	//ライフの回復
	void AddLife(int add);

	//セット関数　スペシャル仕様可能
	void SetEnableSpecial(bool enable);

	// 体力を減らす
	void Reduce(int num);
	//UI関係
	void LivesHighlight();

	// 倒した数を増やす
	void AddBreakEnemy() { m_nEnemyNum++; }
	int GetBreahEnemy() { return m_nEnemyNum; }
	

};

#endif //!___PLAYER_CONTROLLER_H___
