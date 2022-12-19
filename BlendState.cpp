#include "BlendState.h"

BlendState::BlendState()
	: m_pState(nullptr)
{
	HRESULT hr;	// 実行結果

	D3D11_BLEND_DESC blendDesc;
	ZeroMemory(&blendDesc, sizeof(blendDesc));
	blendDesc.RenderTarget[0].BlendEnable = TRUE;
	blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
	
	// αブレンド
	// 今から描画する色 * α値
	// + もともと描画されている色 * (1-α値)
	blendDesc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
	blendDesc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;

	blendDesc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
	blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
	blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
	blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	hr = GetDevice()->CreateBlendState(&blendDesc, &m_pState);
}
BlendState::~BlendState()
{
	if (m_pState)
	{
		m_pState->Release();
		m_pState = nullptr;
	}
}

void BlendState::Bind()
{
	float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GetContext()->OMSetBlendState(m_pState, blendFactor, 0xffffffff);
}
