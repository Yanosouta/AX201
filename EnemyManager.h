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

	//リポップ関数
	void EnemyRepop(DirectX::XMFLOAT3,DirectX::XMFLOAT3);
	void StrEnemyRepop(DirectX::XMFLOAT3, DirectX::XMFLOAT3);
	//ジェネレート関数
	void EnemyGenerate(DirectX::XMFLOAT3, DirectX::XMFLOAT3,float,float,float);
	void StrEnemyGenerate(DirectX::XMFLOAT3, DirectX::XMFLOAT3,float,float,float);
	//大ボス用ジェネレート関数
	void BEnemyGenerate(DirectX::XMFLOAT3, DirectX::XMFLOAT3,float,float,float);
	void BStrEnemyGenerate(DirectX::XMFLOAT3, DirectX::XMFLOAT3,float,float,float);
	//敵の最大数
	constexpr static int mc_EnemyMaxNum = 10;
	//通常中ボスが召喚するエネミーの数
	constexpr static int mc_RepopBossCount = 8;
	//強化中ボスが召喚するエネミーの数
	constexpr static int mc_RepopStrBossCount = 3;
	//大ボスが召喚するエネミーの数
	constexpr static int mc_RepopFinalBigBossCount = 5;
private:
	//リポップする間隔
	float m_RepopTime;
	//フレームカウント
	float m_tick;
	//大ボス用フレームカウント
	float m_FBBtick;
	//ラスボスが出るまでの敵の撃退数
	int m_AppearCount;
	std::vector<DirectX::XMFLOAT3> m_RepopPosList;
	//最初だけリポップするフラグ
	bool m_FirstOnlyFlg;
	//ボスが出てくるまでのカウント
	int m_MBCount;
	//大ボスが生成するエネミーリポップする間隔
	float m_FBBRepopTime;
	//大ボスが生成するエネミー数
	int m_FBBEnemyCount;
};


#endif // !___ENEMYMANAGER_H___
