#include "EzAnimPlugin.h"
#include "EzEaseAnimationComponent.h"

UEzEaseAnimationComponent::UEzEaseAnimationComponent() :
	easeType(EzEaseType::EaseLinear),
	startValue(1.0f), deltaValue(0.0f),
	frozen(false) {
}
void UEzEaseAnimationComponent::BeginPlay() {
	Super::BeginPlay();

	if (useCurve && IsValid(curve)) {
		float min, max;
		curve->GetTimeRange(min, max);
		duration = max;
	}
}

void UEzEaseAnimationComponent::FreezeStartValue() {
	frozen = true;
}

void UEzEaseAnimationComponent::SetStartAndEndValue(float start, float end) {
	if (useCurve)
		deltaValue = 1;
	else {
		if (frozen == false)
			startValue = start;
		deltaValue = end - startValue;
	}
}

float UEzEaseAnimationComponent::GetEaseValue() const {
	if (useCurve) {
		if (IsValid(curve))
			return startValue + curve->GetFloatValue(time) * deltaValue;
	}
	else {
		return startValue + EzEase::Ease(GetNormalizedTime(), easeType) * deltaValue;
	}

	return 1.0f;
}