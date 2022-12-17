// CPUから受け取った頂点データ
struct VS_IN
{
	float3 pos : POSITION0;
	float2 uv : TEXCOORD0;
};

// ピクセルシェーダーに渡すデータ
// ※SV_POSITIONはラスタライズに渡される
struct VS_OUT
{
	float4 pos : SV_POSITION;
	float2 uv : TEXCOORD0;
	float4 wPos : TEXCOORD1;
};

// 定数バッファ定義
cbuffer AnimeUV : register(b0)
{
	float uvWidth;
	float uvHeight;
	float uvTopLeftU;
	float uvTopLeftV;
};

cbuffer WVP : register(b1) {
	float4x4 world;
	float4x4 view;
	float4x4 proj;
};

VS_OUT main(VS_IN vin)
{
	VS_OUT vout;
	vout.uv = vin.uv;	// ピクセルシェーダへ受け渡し

	// 分割したサイズにスケールダウン
	vout.uv.x *= uvWidth;
	vout.uv.y *= uvHeight;
	// 左上まで移動
	vout.uv.x += uvTopLeftU;
	vout.uv.y += uvTopLeftV;

	vout.pos = float4(vin.pos, 1.0f);

	vout.pos = mul(vout.pos, world);
	vout.wPos = vout.pos;
	vout.pos = mul(vout.pos, view);
	vout.pos = mul(vout.pos, proj);
	return vout;
}
