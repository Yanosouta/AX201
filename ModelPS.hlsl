//====================================
// ModelPS  モデル用  松尾天真 
//
//-----------ライティング開始-----------
// 2022/12/02  ディレクションライト追加
// 2022/12/04  鏡面反射光を追加
// 2022/12/04  環境光追加
// 2022/12/07  ポイントライトの追加
// 2022/12/08  スポットライトの追加
// 2022/12/09  リムライト追加
// 2022/12/10  半球ライト追加
//-----------ライティング終了-----------
//
//
//
//
//
//====================================

//******************************************
//******頂点シェーダから受け取るデータ******
//******ピクセルシェーダへの入力      ******
//******************************************
struct PSIn
{
	float4 pos          : SV_POSITION;
	float3 normal       : NORMAL;
	float2 uv           : TEXCOORD0;
	float3 worldPos     : TEXCOORD1;
	float3 normalInView : TEXCOORD2;
};

//**************************************************************
//************ライトのデータを受け取るバッファを用意************
//**************************************************************
cbuffer DirectionLightCb : register(b1)
{
	//ディレクションライトの変数
	float3 dirDirection;  //向き
	float3 dirColor;      //色

	//ポイントライトの変数
	float3 ptPosition;    //位置
	float3 ptColor;       //色
	float ptRange;        //影響範囲

	//スポットライトの変数
	float3 spPosition;    //位置
	float spRange;        //影響範囲
	float3 spColor;       //色
	float spAngle;        //角度
	float3 spDirection;   //向き

	//半球ライトの変数
	float3 groundColor;   //地面の色
	float3 skyColor;      //空の色
	float3 groundNormal;  //地面の法線

	//その他の変数
	float3 eyePos;        //視点の位置
	float3 ambientLight;  //環境光
};

//****************
//****関数宣言****
//****************
//拡散反射光
float3 CalcLambertDiffuse(float3 lightDirection, float3 lightColor, float3 normal);
//鏡面反射光
float3 CalcPhongSpecular(float3 lightDirection, float3 lightColor, float3 worldPos, float3 normal);
//ディレクションライト
float3 CalcLigFromDirectionLight(PSIn psin);
//ポイントライト
float3 CalcLigFromPointLight(PSIn psin);
//スポットライト
float3 CalcLigFromSpotLight(PSIn psin);
//リムライト
float3 CalcLigFromLimLight(PSIn psin);
//半球ライト
float3 CalcLigFromHemLight(PSIn psin);

//**************************
//*****モデルテクスチャ*****
//**************************
texture2D<float4> g_texture : register(t0);

//**************************
//****サンプラーステート****
//**************************
sampler g_sampler : register(s0);

//**********************************************************
//******モデル用のピクセルシェーダのエントリーポイント******
//**********************************************************
float4 main(PSIn psin) : SV_Target0
{
	//========================
	//==ディレクションライト==
	//========================
	float3 directionLig = CalcLigFromDirectionLight(psin);

	//==================
	//==ポイントライト==
	//==================
	float3 pointLig = CalcLigFromPointLight(psin);

	//==================
	//==スポットライト==
	//==================
	float3 spotLig = CalcLigFromSpotLight(psin);

	//==============
	//==リムライト==
	//==============
	float3 limColor = CalcLigFromLimLight(psin);

	//==============
	//==半球ライト==
	//==============
	float3 hemLight = CalcLigFromHemLight(psin);

	//最終的な反射光を求める
	//全てのライトを加算する
	float3 finalLig = directionLig + limColor + hemLight + spotLig + pointLig + ambientLight; //ambientLight ライトの効果を一律で底上げする (環境光はこれだけ)  
	float4 finalColor = g_texture.Sample(g_sampler, psin.uv);//テクスチャからカラーをフェッチする

	//最終的な色に光を乗算する
	finalColor.xyz *= finalLig;

	return finalColor;
}


//************************
//****拡散反射光の計算****
//************************
float3 CalcLambertDiffuse(float3 lightDirection, float3 lightColor, float3 normal)
{
	//ピクセルの法線とライトの方向の内積を計算
	float t = dot(normal, lightDirection);
	t *= -1.0f; //反転

	//内積の値を0以上にする
	t = max(0.0f, t);

	//拡散反射光を求める
	float3 diffuse = lightColor * t;

	//エネルギー保存の法則を適用
	diffuse /= 3.1415926;

	return diffuse;
}


//************************
//****鏡面反射光の計算****
//************************
float3 CalcPhongSpecular(float3 lightDirection, float3 lightColor, float3 worldPos, float3 normal)
{
	//反射ベクトルを求める
	float3 refVec = reflect(lightDirection, normal);

	//光が当たったサーフェイスから視点の位置のベクトルを求める
	float3 toEye = eyePos - worldPos;
	toEye = normalize(toEye); //正規化

	//鏡面反射の強さを求める
	float t = dot(refVec, toEye);

	//内積の値を0以上にする
	t = max(0.0f, t);

	//鏡面反射の強さを絞る ※引数の値を変えると強さが変わる
	t = pow(t, 5.0f);

	//鏡面反射光を求める
	return lightColor * t;
}


//****************************************
//*****ディレクションライトの光を計算*****
//****************************************
float3 CalcLigFromDirectionLight(PSIn psin)
{
	//拡散反射光を求める
	float3 diffDirection = CalcLambertDiffuse(dirDirection, dirColor, psin.normal);
	//鏡面反射光を求める
	float3 specDirection = CalcPhongSpecular(dirDirection, dirColor, psin.worldPos, psin.normal);

	return diffDirection + specDirection;
}


//****************************************
//********ポイントライトの光を計算********
//****************************************
float3 CalcLigFromPointLight(PSIn psin)
{
	//サーフェイスに入射する光の向きを計算
	float3 ligDir = psin.worldPos - ptPosition;
	ligDir = normalize(ligDir);

	//拡散反射光を求める
	float3 diffPoint = CalcLambertDiffuse(ligDir, ptColor, psin.normal);
	//鏡面反射光を求める
	float3 specPoint = CalcPhongSpecular(ligDir, ptColor, psin.worldPos, psin.normal);

	//距離による影響率を計算
	float distance = length(psin.worldPos - ptPosition);
	float affect = 1.0f - 1.0f / ptRange * distance;
	if (affect < 0.0f) affect = 0.0f;
	affect = pow(affect, 3.0f);

	//拡散反射光と鏡面反射光に影響率を乗算して影響を弱める
	diffPoint *= affect;
	specPoint *= affect;

	return diffPoint + specPoint;
}


//****************************************
//********スポットライトの光を計算********
//****************************************
float3 CalcLigFromSpotLight(PSIn psin)
{
	//サーフェイスに入射するスポットライトの光の向きを計算
	float ligDir = psin.worldPos - spPosition;
	ligDir = normalize(ligDir);

	//拡散反射光を求める
	float3 diffSpotLight = CalcLambertDiffuse(ligDir, spColor, psin.normal);

	//鏡面反射光を求める
	float3 specSpotLight = CalcPhongSpecular(ligDir, spColor, psin.worldPos, psin.normal);

	//影響率を計算
	float3 distance = length(psin.worldPos - spPosition);
	float affect = 1.0f - 1.0f / spRange * distance;
	if (affect < 0.0f) affect = 0.0f;
	affect = pow(affect, 3.0f);

	//影響率を乗算して反射光を弱める
	diffSpotLight *= affect;

	//入射光と射出方向の角度を求める
	float angle = dot(ligDir, spDirection);
	angle = abs(acos(angle));

	//角度による影響率を求める
	affect = 1.0f - 1.0f / spAngle * angle;
	if (affect < 0.0f) affect = 0.0f;
	affect = pow(affect, 0.5f);

	//角度による影響率を反射光に乗算して弱める
	diffSpotLight *= affect;
	specSpotLight *= affect;

	return diffSpotLight + specSpotLight;
}


//****************************************
//**********リムライトの光を計算**********
//****************************************
float3 CalcLigFromLimLight(PSIn psin)
{
	//サーフェイスの法線と光の入射方向に依存するリムの強さを求める
	float power1 = 1.0f - max(0.0f, dot(dirDirection, psin.normal));

	//サーフェイスの法線と視点の方向に依存するリムの強さを求める
	float power2 = 1.0f - max(0.0f, psin.normalInView.z * -1.0f);

	//最終的なリムの強さを求める
	float limPower = power1 * power2;
	limPower = pow(limPower, 1.3f);

	//リムライトの色を計算
	return limPower * dirColor;
}


//****************************************
//**********半球ライトの光を計算**********
//****************************************
float3 CalcLigFromHemLight(PSIn psin)
{
	//サーフェイスの法線と地面の法線の内積を計算
	float t = dot(psin.normal, groundNormal);

	//内積の結果を0～1の間にする
	t = (t + 1.0f) / 2.0f;

	//地面の色と空の色を補間率tで線形補間:lerp()   groundColor * (1.0f - t) + skyColor * t
	float3 hemLight = lerp(groundColor, skyColor, t);

	return hemLight;
}