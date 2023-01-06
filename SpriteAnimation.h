#ifndef ___SPRITE_ANIMATION_H___
#define ___SPRITE_ANIMATION_H___

#include "ComponentBase.h"
#include "SpriteRenderer.h"
#include <vector>
#include <memory>
#include "SpriteRenderer.h"

class SpriteAnimation : public ComponentBase
{
protected:
	// アニメーションキー
	struct KeyFrame {
		float time;
		SpriteRenderer::AnimeUV uv;
	};
	using KeyFrames = std::vector<KeyFrame>;
public:
	// コンストラクタ
	SpriteAnimation();
	// デストラクタ
	~SpriteAnimation();

	// 初期化
	void Start() override final;
	// 更新
	void Update() override final;

	// 再生
	void Play();
	
	//フレーム切り替え
	void Swapframe(unsigned int nextframe);

protected:
	std::shared_ptr<SpriteRenderer> m_SpritePtr; // 操作するスプライトデータ
	// アニメーション情報
	float		m_time;			// 現在の再生時間
	float		m_speed;		// 再生速度
	bool		m_isLoop;		// ループ設定
	KeyFrames	m_keyframes;	// キーフレーム情報

	bool		m_isPlay;		// 再生中かどうか
	int			m_frameNum;		// 現在のフレーム番号
	bool		m_isSwap;			// uvを変更するかどうか
	int			m_NextframeNum;
};

#endif //!___SPRITE_ANIMATION_H___