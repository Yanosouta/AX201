#ifndef __BLEND_STATE_H__
#define __BLEND_STATE_H__

#include "DirectX.h"

class BlendState
{
public:
	BlendState();
	~BlendState();

	void Bind();

private:
	ID3D11BlendState* m_pState;
};

#endif // __BLEND_STATE_H__
