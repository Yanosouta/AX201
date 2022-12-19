#ifndef __SAMPLER_STATE_H__
#define __SAMPLER_STATE_H__

#include "DirectX.h"

class SamplerState
{
public:
	SamplerState();
	~SamplerState();

	void Bind();

private:
	ID3D11SamplerState* m_pState;
};

#endif // __SAMPLER_STATE_H__
