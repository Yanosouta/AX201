#include "light.h"
#include "CameraPlayer.h"
#include "Input.h"
#include "ObjectManager.h"
#include "Transform.h"


//=====================
//   コンストラクタ
//=====================
light::light()
{
	//コンスタントバッファ
	m_pWVP = new ConstantBuffer();
	m_pWVP->Create(sizeof(Light)); //送る構造体の型

	//******************************************************
	//*****************ディレクションライト*****************
	//******************************************************
	//ディレクションライトの向きをベクトルに変換
	m_Light.dirDirection = XMFLOAT3(0.0f, -1.0f, 1.0f);

	//ディレクションライトの色
	m_Light.dirColor = XMFLOAT3(1.0f, 1.0f, 1.0f);

	//******************************************************
	//********************ポイントライト********************
	//******************************************************
	//ポイントライトの位置
	m_Light.ptPosition = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//ポイントライトの色
	m_Light.ptColor = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//ポイントライトの影響範囲
	m_Light.ptRange = 0.0f;

	//******************************************************
	//********************スポットライト********************
	//******************************************************
	//スポットライトの位置
	m_Light.spPosition = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//スポットライトの色
	m_Light.spColor = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//スポットライトの影響範囲
	m_Light.spRange = 0.0f;

	//スポットライトの向き
	m_Light.spDirection = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//スポットライトの角度
	m_Light.spAngle = XMConvertToRadians(0.0f);

	//*****************************************************
	//**********************半球ライト*********************
	//*****************************************************
	//地面の色 ※本来はプレイヤーと地面の当たり判定をとってプレイヤーが立っているブロックやステージの色を持ってくる
	m_Light.groundColor = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//空の色  ※なんかステージ色とかがいいかも 天井とか
	m_Light.skyColor = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//地面の法線　※ここもプレイヤーが立っているブロックの法線情報をもらってくる
	m_Light.groundNormal = XMFLOAT3(0.0f, 1.0f, 0.0f);

	//******************************************************
	//************************その他************************
	//******************************************************

	//環境光
	m_Light.ambientLIght = XMFLOAT3(0.3f, 0.3f, 0.3f);
}

//
//
//
light::~light()
{
	delete m_pWVP;
}


//========================
//     ライトの更新
//========================
void light::Update()
{
	//視点の位置の更新
	m_Light.eyePos = ObjectManager::FindObjectWithTag(TagName::MainCamera)->GetComponent<Transform>()->GetPosition();

	//ポイントライトの位置を更新
	if (IsKeyPress(VK_SHIFT))
	{
		if (IsKeyPress('I')) m_Light.ptPosition.z += 1.0f;
		if (IsKeyPress('K')) m_Light.ptPosition.z -= 1.0f;
		if (IsKeyPress('L')) m_Light.ptPosition.x += 1.0f;
		if (IsKeyPress('J')) m_Light.ptPosition.x -= 1.0f;
	}

	
}


//======================================
//ライトの情報をピクセルシェーダに送る
//======================================
void light::SetLight()
{
	//ライトの情報を書込みピクセルシェーダに送る
	m_pWVP->Write(&m_Light);
	m_pWVP->BindPS(1);
}