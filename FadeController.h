#ifndef ___FADE_CONTROLLER_H___
#define ___FADE_CONTROLLER_H___

#include "ComponentBase.h"
#include <DirectXMath.h>
#include "SceneName.h"

class FadeController : public ComponentBase
{
public:
	// フェードの色
	constexpr static DirectX::XMFLOAT3 mc_FadeColor = { 0.0f, 0.0f, 0.0f };
	// フェードの時間
	constexpr static float mc_FadeTime = 100.0f;
public:
	// フェードタイプ
	enum FadeType {
		Fade_In,	// フェードイン		だんだん画面が見えるようになる
		Fade_Out};	// フェードアウト　 だんだん画面が見えなくなる

	// コンストラクタ
	FadeController();
	// デストラクタ
	~FadeController(){}

	void Update() override final;

	//--- セット関数
	void SetFadeType(FadeType type) { m_Type = type; }
	void SetFadeColor(DirectX::XMFLOAT4 color) { m_Color = color; }
	void SetFadeTime(float time) { m_TotalTime = time; }
	void SetLoadScene(SceneName::SceneName name) { m_eName = name; }

	//--- ゲット関数
	DirectX::XMFLOAT4 GetColor() noexcept { return m_Color; }
	bool IsEnd() noexcept { return m_TotalTime < m_time; }

private:
	// フェードのタイプ
	FadeType m_Type;
	// フェードの色
	DirectX::XMFLOAT4 m_Color;
	// フェードの時間
	float m_TotalTime;

	// 経過時間
	float m_time;

	// 切り替えたいシーン名
	SceneName::SceneName m_eName;
};

#endif //!___FADE_CONTROLLER_H___