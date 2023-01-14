#include "SpriteRenderer.h"
#include "Shader.h"
#include "ObjectBase.h"
#include "Transform.h"

VertexShader* SpriteRenderer::m_pDefVS = nullptr;
PixelShader* SpriteRenderer::m_pDefPS = nullptr;
unsigned int SpriteRenderer::m_shaderRef = 0;
SamplerState* SpriteRenderer::m_pSamplerState;
BlendState* SpriteRenderer::m_pAlphaBlend;
ConstantBuffer* SpriteRenderer::m_pConst[2];
std::list<std::pair<std::string, ID3D11ShaderResourceView*>> SpriteRenderer::m_TextureList;

// コンストラクタ
SpriteRenderer::SpriteRenderer()
{
	if (m_shaderRef == 0)
	{
		//ブレンドステート作成
		m_pAlphaBlend = new BlendState();
		// サンプラーステート作成
		m_pSamplerState = new SamplerState();
		// VertexShaderを作成
		m_pDefVS = new VertexShader();
		if (FAILED(m_pDefVS->Load("Assets/Shader/UIVS.cso"))) {
			MessageBox(nullptr, "UIVS.cso", "Error", MB_OK);
		}
		// PixelShaderを作成
		m_pDefPS = new PixelShader();
		if (FAILED(m_pDefPS->Load("Assets/Shader/UIPS.cso"))) {
			MessageBox(nullptr, "UIPS.cso", "Error", MB_OK);
		}

		// Transform用ConstantBufferを作成
		m_pConst[0] = new ConstantBuffer;
		m_pConst[0]->Create(sizeof(m_SpriteInfo.m_Mat));
		// Anime用ConstantBufferを作成
		m_pConst[1] = new ConstantBuffer;
		m_pConst[1]->Create(sizeof(m_SpriteInfo.m_Param));
	}
	++m_shaderRef;

}

// デストラクタ
SpriteRenderer::~SpriteRenderer()
{
	if(m_SpriteInfo.pVtxBuf)
		delete m_SpriteInfo.pVtxBuf;
}

// テクスチャ読み込み
ID3D11ShaderResourceView* SpriteRenderer::LoadTexture(std::string file)
{
	// 登録済みのテクスチャが見つかったら
	// ロードせずに登録済みのテクスチャデータを返す。
	for (auto it = m_TextureList.begin(); it != m_TextureList.end(); it++)
		if (it->first == file) {
			m_SpriteInfo.pTexture = it->second;
			return it->second;
		}

	// 見つからなかったらテクスチャを新しくロードし、
	// ファイルネームと共にテクスチャ情報を保存しておく。
	ID3D11ShaderResourceView* texture;
	LoadTextureFromFile(file.c_str(), &texture);
	m_TextureList.push_back(std::pair<std::string, ID3D11ShaderResourceView*>(file, texture));
	m_SpriteInfo.pTexture = texture;
	return texture;
}

void SpriteRenderer::Start()
{
	// AnimeUVの初期化
	m_SpriteInfo.animeUV.uvHeight = 1.0f;
	m_SpriteInfo.animeUV.uvWidth = 1.0f;
	m_SpriteInfo.animeUV.uvTopLeftU = 0.0f;
	m_SpriteInfo.animeUV.uvTopLeftV = 0.0f;
	// パラメーター
	m_SpriteInfo.m_Param[0] = DirectX::XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	m_SpriteInfo.m_Param[1] = DirectX::XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);
	m_SpriteInfo.m_Param[2] = DirectX::XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	DirectX::XMStoreFloat4x4(&m_SpriteInfo.m_Mat[0], DirectX::XMMatrixIdentity());
	DirectX::XMStoreFloat4x4(&m_SpriteInfo.m_Mat[1], DirectX::XMMatrixIdentity());
	DirectX::XMStoreFloat4x4(&m_SpriteInfo.m_Mat[2], DirectX::XMMatrixIdentity());
}

void SpriteRenderer::LateUpdate()
{
	// ワールド行列で画面の表示位置を計算
	// 移動行列
	DirectX::XMMATRIX T = DirectX::XMMatrixTranslation(
		GetOwner()->GetComponent<Transform>()->GetPosition().x,
		GetOwner()->GetComponent<Transform>()->GetPosition().y,
		GetOwner()->GetLayerNum() * 1e-8f);
	// X回転行列
	DirectX::XMMATRIX Rx = DirectX::XMMatrixRotationX(
		0.0f/*GetOwner()->GetComponent<Transform>()->GetAngle().x*/);
	// Y回転行列
	DirectX::XMMATRIX Ry = DirectX::XMMatrixRotationY(
		0.0f/*GetOwner()->GetComponent<Transform>()->GetAngle().y*/);
	// Z回転行列
	DirectX::XMMATRIX Rz = DirectX::XMMatrixRotationZ(
		GetOwner()->GetComponent<Transform>()->GetAngle().z);
	// 拡大縮小行列
	DirectX::XMMATRIX S = DirectX::XMMatrixScaling(
		1.0f,/*GetOwner()->GetComponent<Transform>()->GetScale().x*/
		1.0f,/*GetOwner()->GetComponent<Transform>()->GetScale().y*/
		1.0f/*GetOwner()->GetComponent<Transform>()->GetScale().z*/);

	// 全ての行列を一つにまとめる
	DirectX::XMMATRIX mat = S * Rz * Ry * Rx * T;

	// シェーダに渡す前に実行する処理
	mat = DirectX::XMMatrixTranspose(mat);

	DirectX::XMStoreFloat4x4(&m_SpriteInfo.m_Mat[0], mat);

	// ビュー行列
	DirectX::XMFLOAT4X4 fView;
	DirectX::XMStoreFloat4x4(&fView,
		DirectX::XMMatrixIdentity());
	m_SpriteInfo.m_Mat[1] = fView;
	// プロジェクション行列
	DirectX::XMFLOAT4X4 fProj;
	DirectX::XMStoreFloat4x4(&fProj,
		DirectX::XMMatrixTranspose(
			DirectX::XMMatrixOrthographicOffCenterLH(
				-640.0f,	// 画面左端の座標
				640.0f,		// 画面右端の座標
				-360.0f,	// 画面下端の座標
				360.0f,		// 画面上端の座標
				-1.0f,		// Z値で写す範囲の最小値
				1.0f		// Z値で写す範囲の最大値
			)
		));
	m_SpriteInfo.m_Mat[2] = fProj;
}

// 描画
void SpriteRenderer::Draw()
{
	// セットする
	m_SpriteInfo.m_Param[1].x = m_SpriteInfo.animeUV.uvTopLeftU;
	m_SpriteInfo.m_Param[1].y = m_SpriteInfo.animeUV.uvTopLeftV;
	m_SpriteInfo.m_Param[1].z = m_SpriteInfo.animeUV.uvWidth;
	m_SpriteInfo.m_Param[1].w = m_SpriteInfo.animeUV.uvHeight;
	m_pDefVS->Bind();		// VertexShader設定
	m_pDefPS->Bind();		// PixelShader設定
	m_pAlphaBlend->Bind();		// αブレンド用BlendStateを設定
	m_pSamplerState->Bind();	// SamplerState設定
	// ConstantBufferを設定
	m_pConst[0]->Write(m_SpriteInfo.m_Mat);
	m_pConst[0]->BindVS(0);
	m_pConst[1]->Write(m_SpriteInfo.m_Param);
	m_pConst[1]->BindVS(1);

	// テクスチャ設定
	SetTexturePS(m_SpriteInfo.pTexture, 0);

	//深度バッファ 2D表示
	EnableDepth(false); // 12/20 竹下
	// 描画
	m_SpriteInfo.pVtxBuf->Draw();
	// 深度バッファ 3D表示
	EnableDepth(true); // 12/20 竹下
}

void SpriteRenderer::End()
{
	// テクスチャを解放
	for (auto it = m_TextureList.begin(); it != m_TextureList.end(); it++)
		it->second->Release();
	m_TextureList.clear();
	delete m_pDefPS;
	delete m_pDefVS;
	delete m_pConst[0];
	delete m_pConst[1];
	delete m_pSamplerState;
}

void SpriteRenderer::SetSize(float width, float height)
{
	Vertex vtx[4] = {
		{{-(width / 2), (height / 2), 0.0f}, {0.0f, 0.0f}},
		{{(width / 2), (height / 2), 0.0f}, {1.0f, 0.0f}},
		{{-(width / 2), -(height / 2), 0.0f}, {0.0f, 1.0f}},
		{{(width / 2),  -(height / 2), 0.0f}, {1.0f, 1.0f}} };
	m_SpriteInfo.pVtxBuf = new VertexBuffer;
	m_SpriteInfo.pVtxBuf->Create(vtx, 4);
}


void SpriteRenderer::SetOffset(DirectX::XMFLOAT2 offset)
{
	m_SpriteInfo.m_Param[0].x = offset.x;
	m_SpriteInfo.m_Param[0].y = offset.y;
}
void SpriteRenderer::SetSize(DirectX::XMFLOAT2 size)
{
	m_SpriteInfo.m_Param[0].z = size.x;
	m_SpriteInfo.m_Param[0].w = size.y;
}

void SpriteRenderer::SetUVPos(DirectX::XMFLOAT2 pos)
{
	m_SpriteInfo.m_Param[1].x = pos.x;
	m_SpriteInfo.m_Param[1].y = pos.y;
}
void SpriteRenderer::SetUVScale(DirectX::XMFLOAT2 scale)
{
	m_SpriteInfo.m_Param[1].z = scale.x;
	m_SpriteInfo.m_Param[1].w = scale.y;
}
void SpriteRenderer::SetColor(DirectX::XMFLOAT4 color)
{
	m_SpriteInfo.m_Param[2] = color;
}