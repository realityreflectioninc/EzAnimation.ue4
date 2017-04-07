#include "EzAnimPlugin.h"
#include "EzEaseFloatComponent.h"

UEzEaseFloatComponent::UEzEaseFloatComponent() :
	value(0.0f), time(0.0f),
	startValue(0.0f), endValue(1.0f), duration(1.0f), 
	easeType(EzEaseType::EaseLinear) {

	PrimaryComponentTick.bCanEverTick = true;
}

void UEzEaseFloatComponent::BeginPlay() {
	Super::BeginPlay();

	value = startValue;
	deltaValue = endValue - startValue;
}

void UEzEaseFloatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	time += DeltaTime;

	if (time >= duration) {
		value = endValue;
		return;
	}

	auto normalized = FMath::Max(0.0f, FMath::Min(1.0f, time / duration));

	value = startValue + EzEase::Ease(time, easeType) * deltaValue;
}

float UEzEaseFloatComponent::GetValue() const {
	return value;
}