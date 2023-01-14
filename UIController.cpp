//-----------------------------------
//1/14 ’|‰º
//     UIController‚ğì¬
//
//-----------------------------------
#include "UIController.h"
#include "Input.h"
#include "SceneManager.h"

void UIController::Start()
{
}

void UIController::Update()
{
	//ENTER‚ğ‰Ÿ‚·‚ÆƒQ[ƒ€ƒV[ƒ“‚ÉˆÚ“®
	if (IsKeyTrigger(VK_RETURN))
	{
		SceneManager::LoadScene(SceneName::SceneTitle);
	}
}
