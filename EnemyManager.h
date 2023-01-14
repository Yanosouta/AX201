#ifndef ___ENEMYMANAGER_H___
#define ___ENEMYMANAGER_H___
#include"ComponentBase.h"

#include<vector>
#include<DirectXMath.h>
class EnemyManager : public ComponentBase
{
public:
	//コンストラクタ
	EnemyManager();
	//デストラクタ
	~EnemyManager()
	{}

	//更新
	void Update() override;

	//敵の最大数
	constexpr static int mc_EnemyMaxNum = 10;
	
private:
	//リポップする間隔
	float m_RepopTime;
	//フレームカウント
	float m_tick;
	//ラスボスが出るまでの敵の撃退数
	int m_AppearCount;
	std::vector<DirectX::XMFLOAT3> m_RepopPosList;
	//最初だけリポップするフラグ
	bool m_FirstOnlyFlg;
	//ボスが出てくるまでのカウント
	int m_MBCount;
};


#endif // !___ENEMYMANAGER_H___
