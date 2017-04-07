#pragma once

UENUM(BlueprintType)
enum EzEaseType {
	EaseLinear,

	EaseQuadIn, EaseQuadOut, EaseQuadInOut,
	EaseCubeIn, EaseCubeOut, EaseCubeInOut,
	EaseSineIn, EaseSineOut, EaseSineInOut,

	EaseBounceIn, EaseBounceOut, EaseBounceInOut,
	EaseElasticIn, EaseElasticOut, EaseElasticInOut
};
 
class EZANIMPLUGIN_API EzEase
{
public:
	static float Ease(float t, EzEaseType type);

	static float Linear(float t);

	static float QuadIn(float t);
	static float QuadOut(float t);
	static float QuadInOut(float t);

	static float CubeIn(float t);
	static float CubeOut(float t);
	static float CubeInOut(float t);

	static float SineIn(float t);
	static float SineOut(float t);
	static float SineInOut(float t);

	static float BounceIn(float t);
	static float BounceOut(float t);
	static float BounceInOut(float t);

	static float ElasticIn(float t);
	static float ElasticOut(float t);
	static float ElasticInOut(float t);
};
