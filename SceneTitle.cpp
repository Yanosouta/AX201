#include "SceneTitle.h"
#include "CameraObjBase.h"
#include "MeshRenderer.h"
#include "SpriteRenderer.h"
#include "Rigidbody.h"
#include "ObjectManager.h"
#include "Object3D.h"
#include "Cube.h"
#include "AABBCollider.h"

#include "Transform.h"
#include "CameraObjPlayer.h"
#include "Player.h"
#include "Enemy.h"
#include "Field.h"
#include "UI.h"

SceneTitle::SceneTitle()
{
	//--- 変更用ポインタ
	std::shared_ptr<MeshRenderer> pMeshRenderer;	// 3Dオブジェクト用レンダラー
	std::shared_ptr<SpriteRenderer> pSpriteRenderer;// 2Dオブジェクト用レンダラー
	std::shared_ptr<Transform> pTransform;			// 位置情報
	std::shared_ptr<Rigidbody> pRigidbody;			// 物理挙動
	std::shared_ptr<AABBCollider> pAABBCollider;	// AABB当たり判定用
	std::shared_ptr<CameraPlayer> pCameraPlayer;

	//2022/12/16　小栗大輝
	//UIの描画が最後に来るようにクリエイトの位置を最初に持ってきた
	//UI部分--------------------------------------------------------------------------------
	ObjectManager::CreateObject<UI>("UI.2");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.2")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.2")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/karizanki.png");	//2022/12/14 小栗大輝　テクスチャを変更
	pSpriteRenderer->SetSize(300, 80);
	ObjectManager::FindObjectWithName("UI.2")->SetLayerNum(1);
	pTransform->SetPosition({ 450.0f, 300.0f, 0.0f });

	//------------------------------------------------------------------------------------

	//--- オブジェクト作成
	//   型　：CameraPlayer
	//  名前 ：CameraPlayer
	// タグ名：CameraPlayer
	ObjectManager::CreateObject<CameraObjPlayer>("CameraPlayer", TagName::MainCamera);
	// CameraPlayerのポインタを取得する
	pCameraPlayer = ObjectManager::FindObjectWithName("CameraPlayer")->GetComponent<CameraPlayer>();
	// 角度を設定する
	pCameraPlayer->SetRadY(40);
	pCameraPlayer->SetRadXZ(0.0f);

	//--- オブジェクト作成
	//   型　：Player
	//  名前 ：Player
	// タグ名：Player
	ObjectManager::CreateObject<Player>("Player", TagName::Player);
	// Transformのポインタを取得する
	pTransform = ObjectManager::FindObjectWithName("Player")->GetComponent<Transform>();
	// 座標を設定する
	pTransform->SetPosition({ 0.0f, 0.0f, 0.0f });

	for (int i = 0; i < 3; i++) {
		//--- オブジェクト作成
		//   型　：Enemy
		//  名前 ：Enemy
		// タグ名：Enemy
		std::shared_ptr<ObjectBase> pObj = ObjectManager::CreateObject<Enemy>("Enemy", TagName::Enemy);
		// Transformのポインタを取得する
		pTransform = pObj->GetComponent<Transform>();
		// 座標を設定する
		pTransform->SetPosition({ 2.0f, 0.0f, 2.0f });
	}

	//--- オブジェクト作成
	//   型　：Field
	//  名前 ：Field
	// タグ名：Field
	ObjectManager::CreateObject<Field>("Field", TagName::Field);
	// Transformのポインタを取得する
	pTransform = ObjectManager::FindObjectWithName("Field")->GetComponent<Transform>();
	// 座標を設定
	pTransform->SetPosition({ 0.0f, -5.0f, 0.0f });


}

SceneTitle::~SceneTitle()
{

}