#include "Game3D.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Input.h"

Game3D::Game3D()
{
	// タイトルシーンへ変更
	SceneManager::LoadScene(SceneName::SceneGame01); // 最初はタイトルからスタートに変更
}
Game3D::~Game3D()
{
}
void Game3D::Update()
{

	ObjectManager::FixedUpdate();
	ObjectManager::Update();
}

void Game3D::LateUpdate()
{
	ObjectManager::LateUpdate();
}

void Game3D::Draw()
{
	ObjectManager::Draw();
}