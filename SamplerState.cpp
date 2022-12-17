#include "SamplerState.h"


SamplerState::SamplerState()
	: m_pState(nullptr)
{
	D3D11_SAMPLER_DESC desc;
	ZeroMemory(&desc, sizeof(desc));

	desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
	desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
	desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;

	desc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;

	GetDevice()->CreateSamplerState(&desc, &m_pState);
}
SamplerState::~SamplerState()
{
	if (m_pState)
	{
		m_pState->Release();
		m_pState = nullptr;
	}
}

void SamplerState::Bind()
{
	GetContext()->PSSetSamplers(0, 1, &m_pState);
}
