#pragma once
#include <DirectXMath.h>
#include "ComponentBase.h"
#include "ConstantBuffer.h"

using namespace DirectX;

class light : public ComponentBase
{
public:
	//float pad  HLSL側の定数バッファであるfloat3型変数は16の倍数のアドレスに配置されるけど、
	//           C++は4の倍数のアドレスに配置されるからパディングを埋めておかないとデータの受け渡しでずれたデータが渡されちゃう
	//          ※XMVECTORはx,y,z,wで出来ているからパディング書かなくてもちゃんと受け渡しされるから書かないように！
	struct Light
	{
		//XMVECTOR dirDirection;    //ディレクションライトの方向      00  x,y,z,w
		XMFLOAT4 dirDirection;    //ディレクションライトの方向      00  x,y,z,w
		XMFLOAT3 dirColor;        //ディレクションライトのカラー    16  x,y,z
		float pad;                //パディング                      28  w

		XMFLOAT3 ptPosition;      //ポイントライトの位置            32  x,y,z
		float pad0;               //パディング                      44  w
		XMFLOAT3 ptColor;         //ポイントライトの色              48  x,y,z
		float ptRange;            //ポイントライトの範囲            60  w

		XMFLOAT3 spPosition;      //スポットライトの位置            64  x,y,z
		float spRange;            //スポットライトの範囲            76  w
		XMFLOAT3 spColor;         //スポットライトの色              80  x,y,z
		float spAngle;            //スポットライトの角度            92  w
		//XMVECTOR spDirection;     //スポットライトの方向            96  x,y,z,w
		XMFLOAT4 spDirection;     //スポットライトの方向            96  x,y,z,w

		XMFLOAT3 groundColor;     //地面の色
		float pad1;               //パディング
		XMFLOAT3 skyColor;        //空の色
		float pad2;               //パディング
		//XMVECTOR groundNormal;    //地面の法線
		XMFLOAT4 groundNormal;    //地面の法線

		XMFLOAT3 eyePos;          //視点の位置                     
		float pad3;               //パディング                     
		XMFLOAT3 ambientLIght;    //アンビエントライト(環境光)      
		float pad4;               //パディング
	};

public:
	light();
	~light();
	void Update() override;
	void SetLight();

private:
	Light m_Light;
	ConstantBuffer* m_pWVP;
};

