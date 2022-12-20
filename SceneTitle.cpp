#include "SceneTitle.h"
#include "CameraObjBase.h"
#include "MeshRenderer.h"
#include "SpriteRenderer.h"
#include "Rigidbody.h"
#include "ObjectManager.h"
#include "Object3D.h"
#include "Cube.h"
#include "AABBCollider.h"
#include "TestAnimation.h" // (仮)

#include "Transform.h"
#include "CameraObjPlayer.h"
#include "Player.h"
#include "Enemy.h"
#include "Field.h"
#include "UI.h"

SceneTitle::SceneTitle()
{
	//--- 変更用ポインタ
	std::shared_ptr<ObjectBase> pObj;
	std::shared_ptr<MeshRenderer> pMeshRenderer;	// 3Dオブジェクト用レンダラー
	std::shared_ptr<SpriteRenderer> pSpriteRenderer;// 2Dオブジェクト用レンダラー
	std::shared_ptr<Transform> pTransform;			// 位置情報
	std::shared_ptr<Rigidbody> pRigidbody;			// 物理挙動
	std::shared_ptr<AABBCollider> pAABBCollider;	// AABB当たり判定用
	std::shared_ptr<CameraPlayer> pCameraPlayer;

	//2022/12/16　小栗大輝
	//UIの描画が最後に来るようにクリエイトの位置を最初に持ってきた
	//UI部分--------------------------------------------------------------------------------
	//ObjectManager::CreateObject<UI>("UI.2");
	//pSpriteRenderer = ObjectManager::FindObjectWithName("UI.2")->GetComponent<SpriteRenderer>();
	//pTransform = ObjectManager::FindObjectWithName("UI.2")->GetComponent<Transform>();
	//pSpriteRenderer->LoadTexture("Assets/Texture/karizanki.png");	//2022/12/14 小栗大輝　テクスチャを変更
	//pSpriteRenderer->SetSize(300, 80);
	//ObjectManager::FindObjectWithName("UI.2")->SetLayerNum(1);
	//pTransform->SetPosition({ 450.0f, 300.0f, 0.0f });

	//------------------------------------------------------------------------------------
	
	// 仮(あにめーしょんUI)
	//pObj = ObjectManager::CreateObject<UI>("UI.3");
	//pObj->SetLayerNum(2);
	//pObj->AddComponent<TestAnimation>();
	//pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	//pSpriteRenderer->LoadTexture("Assets/Texture/Test.png");
	//pSpriteRenderer->SetSize(80, 80);
	//pTransform = pObj->GetComponent<Transform>();
	//pTransform->SetPosition({ -450.0f, 300.0f, 0.0f });
	//----------------------------------------------------------------------------------------
	// 2022/12/19 竹下雄太郎 
	// UIをいい感じに配置だぜ
	//----------------------------------------------------------------------------------------
	// 中央真ん中HPの枠
	ObjectManager::CreateObject<UI>("UI.4");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.4")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.4")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/HP_Waku.png");	
	pSpriteRenderer->SetSize(450, 130);
	ObjectManager::FindObjectWithName("UI.4")->SetLayerNum(3);
	pTransform->SetPosition({ 0.0f, -280.0f, 0.0f });

	// 中央真ん中HPの中身(まだ配置しかしてないのでアニメーションの追加をする)
	ObjectManager::CreateObject<UI>("UI.5");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.5")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.5")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/HP_MAX.png");
	pSpriteRenderer->SetSize(200, 110);
	ObjectManager::FindObjectWithName("UI.5")->SetLayerNum(4);
	pTransform->SetPosition({ 0.0f, -280.0f, 0.0f });

	// 画面左端 必殺技アイコン
	ObjectManager::CreateObject<UI>("UI.6");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.6")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.6")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/SP.png");
	pSpriteRenderer->SetSize(120, 120);
	ObjectManager::FindObjectWithName("UI.6")->SetLayerNum(5);
	pTransform->SetPosition({ -530.0f, -180.0f, 0.0f });

	// 必殺技ゲージ(後ろ透過されちゃうので後から場所は後からいじる)
	ObjectManager::CreateObject<UI>("UI.7");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.7")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.7")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/SP_gage.png");
	pSpriteRenderer->SetSize(120, 120);
	ObjectManager::FindObjectWithName("UI.7")->SetLayerNum(6);
	pTransform->SetPosition({ -530.0f, -40.0f, 0.0f });

	// 攻撃アイコン
	ObjectManager::CreateObject<UI>("UI.8");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.8")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.8")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/ATK.png");
	pSpriteRenderer->SetSize(150, 150);
	ObjectManager::FindObjectWithName("UI.8")->SetLayerNum(7);
	pTransform->SetPosition({ -400.0f, -230.0f, 0.0f });

	// 画面左上 残機枠
	ObjectManager::CreateObject<UI>("UI.9");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.9")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.9")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/Zanki.png");
	pSpriteRenderer->SetSize(400, 150);
	ObjectManager::FindObjectWithName("UI.9")->SetLayerNum(8);
	pTransform->SetPosition({ -500.0f, 330.0f, 0.0f });

	// 残機の数字(1枚1枚の画像なので、まとめる必要あり)
	ObjectManager::CreateObject<UI>("UI.10");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.10")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.10")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/ZankiNum.png");
	pSpriteRenderer->SetSize(50, 50);
	ObjectManager::FindObjectWithName("UI.10")->SetLayerNum(9);
	pTransform->SetPosition({ -320.0f, 300.0f, 0.0f });
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

	for (int i = 0; i < 1; i++) {
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
		//   型　：Enemy
		//  名前 ：Enemy
		// タグ名：MiddleBoss
	std::shared_ptr<ObjectBase> pMBObj = ObjectManager::CreateObject<Enemy>("Enemy", TagName::MiddleBoss);
	// Transformのポインタを取得する
	pTransform = pMBObj->GetComponent<Transform>();
	// 座標を設定する
	pTransform->SetPosition({ 2.0f, 0.0f, -2.0f });
	//サイズを変更
	pTransform->SetScale({ 2.0f, 2.0f, 2.0f });

	//--- オブジェクト作成
	//   型　：Field
	//  名前 ：Field
	// タグ名：Ground
	ObjectManager::CreateObject<Field>("Field", TagName::Ground);
	// Transformのポインタを取得する
	pTransform = ObjectManager::FindObjectWithName("Field")->GetComponent<Transform>();
	// 座標を設定
	pTransform->SetPosition({ 0.0f, -5.0f, 0.0f });

	//--- オブジェクト作成
	//   型　：Field
	//  名前 ：Field
	// タグ名：Wall
	pObj = ObjectManager::CreateObject<Field>("Field", TagName::Wall);
	// Transformのポインタを取得する
	pTransform = pObj->GetComponent<Transform>();
	// 座標を設定
	pTransform->SetPosition({ 0.0f, -4.0f, 4.0f });
	// オブジェクトの辺の長さをセット
	pTransform->SetScale({ 2.0f, 5.0f, 5.0f });
	pTransform->SetAngle({ 0.0f, 70.0f, 0.0f });
	// 当たり判定の辺の長さをセット
	pObj->GetComponent<AABBCollider>()->SetLen({ 2.0f, 5.0f, 5.0f });

}

SceneTitle::~SceneTitle()
{

}
