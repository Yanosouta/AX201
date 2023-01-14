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

	// 12/23 竹下　プレイヤーのライフ
	int m_Life;
	bool m_bLifeFlg;  // [EnemyControllerの見よう見まねで作ったので、いるか分かりません
	float m_FlgCount; // [cppの269行目あたりで使ってると思うので見てあんま意味なければ消してもいいです
	// 12/23 竹下　プレイヤーの残機
	unsigned int m_Zanki;
	
	//--- ノックバック用
	float m_KnockBackPower;	// 押される力
	bool  m_bKnockBackFlg; //ノックバック中にフラグを立てる
	float m_KnockBackCount;	//フラグを立てている時にカウント

	//UI強調表示用
	bool m_LivesHighlighting;		//強調表示中フラグ
	DirectX::XMFLOAT2 m_LivesIV;	//UIの初期値
	bool m_LivesHalf;				//強調表示の折り返し	

public:
	// コンストラクタ
	PlayerController()
		: m_ChargeTime(30.0f) // 60 fps の場合 0.5 秒
		, m_Life(4)
		, m_Zanki(2)
		, m_bLifeFlg(false)
		, m_FlgCount(5.0f)
		, m_bKnockBackFlg(false)
		, m_KnockBackCount(20.0f)
		, m_KnockBackPower(0.05f)
		, m_LivesHighlighting(false)
		, m_LivesHalf(false)
		,m_LivesIV(DirectX::XMFLOAT2(1.0f,1.0f))
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

	// 残機を増やす
	void AddZanki(int num) { m_Zanki += num; }

	//UI関係
	void LivesHighlight();

};

#endif //!___PLAYER_CONTROLLER_H___
