#ifndef ___CLEARMANAGER_H___
#define ___CLEARMANAGER_H___
#include"ComponentBase.h"

#include<vector>
#include<DirectXMath.h>

class ClearManager : public ComponentBase
{
public:
	//コンストラクタ
	ClearManager();
	//デストラクタ
	~ClearManager()
	{}

	//更新
	void Update() override;
	// クリア条件の敵を倒した数
	constexpr static int mc_nClearEnemyNum = 11;
private:
	int m_BreakEnemy;
	float m_alpha;
	DirectX::XMFLOAT4  m_color;
	
	// 経過時間
	float m_time;
	float m_TotalTime;
};
#endif // __CLEARMANAGER_H__
