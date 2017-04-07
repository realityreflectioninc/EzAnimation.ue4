#include "EzAnimPlugin.h"

#include <math.h>

#include "EzEase.h"

#define M_PI 3.14

float EzEase::Ease(float t, EzEaseType type) {
	switch (type) {
	case EaseLinear: return Linear(t);

	case EaseQuadIn: return QuadIn(t);
	case EaseQuadOut: return QuadOut(t);
	case EaseQuadInOut: return QuadInOut(t);

	case EaseCubeIn: return CubeIn(t);
	case EaseCubeOut: return CubeOut(t);
	case EaseCubeInOut: return CubeInOut(t);

	case EaseSineIn: return SineIn(t);
	case EaseSineOut: return SineOut(t);
	case EaseSineInOut: return SineInOut(t);

	case EaseBounceIn: return BounceIn(t);
	case EaseBounceOut: return BounceOut(t);
	case EaseBounceInOut: return BounceInOut(t);

	case EaseElasticIn: return ElasticIn(t);
	case EaseElasticOut: return ElasticOut(t);
	case EaseElasticInOut: return ElasticInOut(t);
	}

	return t;
}

float EzEase::Linear(float t) {
	return t;
}

float EzEase::QuadIn(float t) {
	return t * t;
}
float EzEase::QuadOut(float t) {
	return t * (2 - t);
}
float EzEase::QuadInOut(float t) {
	t *= 2.0f;
	if (t < 1) return 0.5f * t * t;
	return -0.5f * (--t * (t - 2) - 1);
}

float EzEase::CubeIn(float t) {
	return t * t * t;
}
float EzEase::CubeOut(float t) {
	t -= 1;
	return t * t * t + 1;
}
float EzEase::CubeInOut(float t) {
	t *= 2;
	if (t < 1)
		return 0.5f * t * t * t;
	t -= 2;
	return 0.5f * (t * t * t + 2);
}

float EzEase::SineIn(float t) {
	return 1 - cos(t * M_PI / 2);
}
float EzEase::SineOut(float t) {
	return sin(t * M_PI / 2);
}
float EzEase::SineInOut(float t) {
	return 0.5f * (1 - cos(M_PI * t));
}

float EzEase::BounceIn(float t) {
	return 1 - BounceOut(1 - t);
}
float EzEase::BounceOut(float t) {
	if (t < (1.0f / 2.75f))
		return 7.5625f * t * t;
	if (t < (2.0f / 2.75f)) {
		t -= 1.5f / 2.75f;
		return 7.5625f * t * t + 0.75f;
	}
	if (t < (2.5f / 2.75f)) {
		t -= 2.25f / 2.75f;
		return 7.5625f * t * t + 0.9375f;
	}
	t -= 2.625f / 2.75f;
	return 7.5625f * t * t + 0.984375f;
}
float EzEase::BounceInOut(float t) {
	if (t < 0.5f)
		return BounceIn(t * 2) * 0.5f;
	else
		return BounceOut(t * 2 - 1) * 0.5f + 0.5f;
}

float EzEase::ElasticIn(float t) {
	if (t == 0) return 0;
	if (t == 1) return 1;

	float s = 0.3f / 4;
	t = t - 1;
	return -powf(2, 10 * t) * sinf((t - s) * (M_PI * 2) / 0.3f);
}
float EzEase::ElasticOut(float t) {
	if (t == 0) return 0;
	if (t == 1) return 1;

	float s = 0.3f / 4;

	return pow(2, -10 * t) * sin((t - s) * (M_PI * 2) / 0.3f) + 1;
}
float EzEase::ElasticInOut(float t) {
	if (t == 0) return 0;
	if (t == 1) return 1;

	t = t * 2;
		
	float s = 0.3f / 4;
	t = t - 1;
	if (t < 0)
		return -0.5f * pow(2, 10 * t) * sin((t - s) * (M_PI * 2) / 0.3f);
	else 
		return pow(2, -10 * t) * sin((t - s) * (M_PI * 2) / 0.3f) * 0.5f + 1;
}