#include "EzAnimPlugin.h"
#include "EzPeriodicAnimationComponent.h"

UEzPeriodicAnimationComponent::UEzPeriodicAnimationComponent() :
	duration(1.0f), time(0.0f) {
	PrimaryComponentTick.bCanEverTick = true;
}

void UEzPeriodicAnimationComponent::BeginPlay() {
	Super::BeginPlay();
	
}

void UEzPeriodicAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	time += DeltaTime;

    if (duration <= time) {
        if (loop == true)
            time = 0.0f;
        else
            Finish();
    }
}

float UEzPeriodicAnimationComponent::GetNormalizedTime() const {
	return FMath::Max(0.0f, FMath::Min(1.0f, time / duration));
}
bool UEzPeriodicAnimationComponent::IsLastTick(float dt) const {
    if (loop) return false;
    return (time + dt) >= duration;
}