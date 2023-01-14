struct VS_IN
{
	float3 pos    : POSITION;
	float3 normal : NORMAL;
	float2 uv     : TEXCOORD;
	float4 weight : WEIGHT;
	uint4 index   : INDEX;
};

struct VS_OUT
{
	float4 pos          : SV_POSITION;
	float3 normal       : NORMAL;
	float2 uv           : TEXCOORD0;
	float3 worldPos     : TEXCOORD1;
	float3 normalInView : TEXCOORD2;
};

cbuffer WVP : register(b0)
{
	float4x4 world;
	float4x4 view;
	float4x4 proj;
};

cbuffer Anime : register(b1)
{
	float4x4 bones[50];
};

VS_OUT main(VS_IN vin)
{
	VS_OUT vout;
	vout.pos = float4(vin.pos, 1.0f);
	float4x4 mat =
		bones[vin.index.x] * vin.weight.x +
		bones[vin.index.y] * vin.weight.y +
		bones[vin.index.z] * vin.weight.z +
		bones[vin.index.w] * vin.weight.w;
	vout.pos = mul(vout.pos, mat);

	vout.pos = mul(vout.pos, world);
	vout.worldPos = vout.pos;
	vout.pos = mul(vout.pos, view);
	vout.pos = mul(vout.pos, proj);
	vout.uv = vin.uv;

	// 頂点法線をピクセルシェーダーに渡す
	vout.normal = mul(vin.normal, world); // 法線を回転させる

	//カメラ空間の法線を求める
	vout.normalInView = mul(vin.normal, view);

	return vout;
}
