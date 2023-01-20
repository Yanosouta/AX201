#ifndef ___FADEMANAGER_H___
#define ___FADEMANAGER_H___

#include "FadeController.h"
#include "SceneName.h"

class FadeManager {
public:
	// コンストラクタ
	FadeManager(){}
	// デストラクタ
	~FadeManager(){}

	/**
	@brief フェードインを作成する。

	@note フェードインは透明度が高くなっていくフェードです。
	@note 既に生成済みの場合、作成しません。
	*/
	static void CreateFadeIn();
	
	/**
	@brief フェードアウトを作成する。

	@note フェードアウトは透明度が低くなっていくフェードです。
	@note 既に生成済みの場合。作成しません。
	*/
	static void CreateFadeOut(SceneName::SceneName name);
};

#endif //!___FADEMANAGER_H___