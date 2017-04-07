#include "EzAnimPlugin.h"
#include "EzEaseVectorAnimationComponent.h"

UEzEaseVectorAnimationComponent::UEzEaseVectorAnimationComponent() :
	useCurve(false), curve(nullptr),
	easeType(EzEaseType::EaseLinear),
	startValue(0,0,0), deltaValue(1,1,1),
	frozen(false) {
}

void UEzEaseVectorAnimationComponent::BeginPlay() {
	Super::BeginPlay();
}

void UEzEaseVectorAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (useCurve && IsValid(curve)) {
		float min, max;
		curve->GetTimeRange(min, max);
		duration = max;
	}
}

void UEzEaseVectorAnimationComponent::FreezeStartValue() {
	frozen = true;
}

void UEzEaseVectorAnimationComponent::SetStartAndEndValue(
	const FVector &start, const FVector &end) {

	if (useCurve) deltaValue = FVector(1, 1, 1);
	else {
		if (frozen == false)
			startValue = start;
		deltaValue = end - startValue;
	}
}

FVector UEzEaseVectorAnimationComponent::GetEaseValue() const {
	if (useCurve) {
		if (IsValid(curve))
			return startValue + curve->GetVectorValue(time) * deltaValue;

		UE_LOG(LogTemp, Warning, TEXT("InvalidCurve"));
	}
	else {
		return FVector(
			startValue.X + EzEase::Ease(GetNormalizedTime(), easeType) * deltaValue.X,
			startValue.Y + EzEase::Ease(GetNormalizedTime(), easeType) * deltaValue.Y,
			startValue.Z + EzEase::Ease(GetNormalizedTime(), easeType) * deltaValue.Z);
	}

	return FVector(1,1,1);
}