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
//---12/20 竹下------
#include "Zanki.h"//仮
#include "Life.h"
#include "LifeNumber.h" // 1/24 竹下 追加
#include "clicAtk.h"
#include "AtkGauge.h"


#include "Transform.h"
#include "CameraObjPlayer.h"
#include "Player.h"
#include "Enemy.h"
#include "Field.h"
#include "UI.h"
#include"EnemyManager.h"
#include "Stage.h"
#include "LightObj.h"
#include "FadeManager.h"
#include "ClearManager.h"

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

	ObjectManager::CreateObject<LightObj>("MainLight", TagName::Light);
	//--- シーン切り替え時なのでフェードインを作成
	FadeManager::CreateFadeIn();

	//----------------------------------------------------------------------------------------
	// 2022/12/19 竹下雄太郎 
	// UIをいい感じに配置
	// 12/20
	// UIアニメーションを追加
	//----------------------------------------------------------------------------------------
	// 中央真ん中HPの枠
	pObj = ObjectManager::CreateObject<UI>("UI.4");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.4")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.4")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/HP_Waku.png");
	pSpriteRenderer->SetSize(450, 130);
	ObjectManager::FindObjectWithName("UI.4")->SetLayerNum(5);
	pTransform->SetPosition({ 0.0f, -280.0f, 0.0f });

	// 中央真ん中HPの中身(まだ配置しかしてないのでアニメーションの追加をする)
	pObj = ObjectManager::CreateObject<UI>("UI.5");
	pObj->SetLayerNum(4);
	pObj->AddComponent<Life>(); //LifeのUpdateって指定しても
	pObj->AddComponent<SpriteAnimation>();
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pSpriteRenderer->LoadTexture("Assets/Texture/Life.png");
	pSpriteRenderer->SetSize(220, 145);
	pTransform = pObj->GetComponent<Transform>();
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
	//ObjectManager::CreateObject<UI>("UI.7");
	//pSpriteRenderer = ObjectManager::FindObjectWithName("UI.7")->GetComponent<SpriteRenderer>();
	//pTransform = ObjectManager::FindObjectWithName("UI.7")->GetComponent<Transform>();
	//pSpriteRenderer->LoadTexture("Assets/Texture/1.png");
	//pSpriteRenderer->SetSize(150, 150);
	//ObjectManager::FindObjectWithName("UI.7")->SetLayerNum(6);
	//pTransform->SetPosition({ -400.0f, -230.0f, 0.0f });

	//pObj = ObjectManager::CreateObject<UI>("UI.7");
	//pObj->SetLayerNum(6);
	//pObj->AddComponent<AtkGauge>();
	//pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	//pSpriteRenderer->LoadTexture("Assets/Texture/16.png");
	//pSpriteRenderer->SetSize(154, 154);
	//pTransform = pObj->GetComponent<Transform>();
	//pTransform->SetPosition({ -398.0f, -232.0f, 0.0f });
	pObj = ObjectManager::CreateObject<UI>("UI.7");
	pObj->SetLayerNum(6);
	pObj->AddComponent<AtkGauge>();
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pSpriteRenderer->LoadTexture("Assets/Texture/mystery16.png");
	pSpriteRenderer->SetSize(150, 150);
	pTransform = pObj->GetComponent<Transform>();
	pTransform->SetPosition({ -400.0f, -230.0f, 0.0f });

	// 攻撃アイコン
	pObj = ObjectManager::CreateObject<UI>("UI.8");
	pObj->SetLayerNum(7);
	pObj->AddComponent<clicAtk>();
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pSpriteRenderer->LoadTexture("Assets/Texture/normalAtk.png");	
	pSpriteRenderer->SetSize(150, 150);
	pTransform = pObj->GetComponent<Transform>();
	pTransform->SetPosition({ -400.0f, -230.0f, 0.0f });

	// 残機数
	// カウントダウンするようにした。
	// 時間じゃなくHPが減ったらに変えたい
	pObj = ObjectManager::CreateObject<UI>("UI.9");
	pObj->SetLayerNum(10);
	pObj->AddComponent<Zanki>();
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pSpriteRenderer->LoadTexture("Assets/Texture/number.png");
	pSpriteRenderer->SetSize(50, 50);
	pTransform = pObj->GetComponent<Transform>();
	pTransform->SetPosition({ -430.0f, 285.0f, 0.0f });

	// 画面左上 残機枠
	ObjectManager::CreateObject<UI>("UI.10");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.10")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.10")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/Zanki.png");
	pSpriteRenderer->SetSize(400, 150);
	ObjectManager::FindObjectWithName("UI.10")->SetLayerNum(9);
	pTransform->SetPosition({ -500.0f, 330.0f, 0.0f });

	// ライフ%の数字
	pObj = ObjectManager::CreateObject<UI>("UI.11");
	pObj->SetLayerNum(11);
	pObj->AddComponent<LifeNumber>();
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pSpriteRenderer->LoadTexture("Assets/Texture/Number2.png");
	pSpriteRenderer->SetSize(50, 50);
	pTransform = pObj->GetComponent<Transform>();
	pTransform->SetPosition({ 130.0f, -310.0f, 0.0f });

	pObj = ObjectManager::CreateObject<UI>("UI.12");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.12")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.12")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/clear.png");
	pSpriteRenderer->SetSize(700, 490);
	ObjectManager::FindObjectWithName("UI.12")->SetLayerNum(13);
	pTransform->SetPosition({ 0.0f, 0.0f, 0.0f });
	pObj->AddComponent<ClearManager>();
		
	
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

	//for (int i = 0; i < 1; i++) {
	//	//--- オブジェクト作成
	//	//   型　：Enemy
	//	//  名前 ：Enemy
	//	// タグ名：Enemy
	//	std::shared_ptr<ObjectBase> pObj = ObjectManager::CreateObject<Enemy>("Enemy", TagName::Enemy);
	//	// Transformのポインタを取得する
	//	pTransform = pObj->GetComponent<Transform>();
	//	// 座標を設定する
	//	pTransform->SetPosition({ 2.0f, 0.0f, 2.0f });
	//}
	////--- オブジェクト作成
	//	//   型　：Enemy
	//	//  名前 ：Enemy
	//	// タグ名：MiddleBoss
	//std::shared_ptr<ObjectBase> pMBObj = ObjectManager::CreateObject<Enemy>("Enemy", TagName::MiddleBoss);
	//// Transformのポインタを取得する
	//pTransform = pMBObj->GetComponent<Transform>();
	//// 座標を設定する
	//pTransform->SetPosition({ 2.0f, 0.0f, -2.0f });
	////サイズを変更
	//pTransform->SetScale({ 2.0f, 2.0f, 2.0f });
	//
	////--- オブジェクト作成
	////   型　：Enemy
	////  名前 ：Enemy
	//// タグ名：FinalBoss
	//std::shared_ptr<ObjectBase> pFBObj = ObjectManager::CreateObject<Enemy>("Enemy", TagName::FinalBoss);
	//// Transformのポインタを取得する
	//pTransform = pFBObj->GetComponent<Transform>();
	//// 座標を設定する
	//pTransform->SetPosition({ 2.0f, 0.0f, -2.0f });
	////サイズを変更
	//pTransform->SetScale({ 3.0f, 3.0f, 3.0f });
	
	//--- ステージ作成
	// Stage* pStage = new Stage(); のスマートポインタバージョン。
	std::shared_ptr<Stage> pStage = std::make_shared<Stage>();

	pObj = ObjectManager::CreateObject<ObjectBase>("EnemyManager");
	pObj->AddComponent<EnemyManager>();

}

SceneTitle::~SceneTitle()
{

}
