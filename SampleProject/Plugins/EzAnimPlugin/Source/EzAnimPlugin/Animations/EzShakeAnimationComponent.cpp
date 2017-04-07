#include "EzAnimPlugin.h"
#include "EzShakeAnimationComponent.h"

UEzShakeAnimationComponent::UEzShakeAnimationComponent() :
    amplitude(5.0f), frequency(0.05f), direction(1,0,1) {
}

void UEzShakeAnimationComponent::BeginPlay() {
	Super::BeginPlay();
	
    lastChanged = 0.0f;
    positiveOrNegative = false;

    initialLocation = GetTargetComponent()->RelativeLocation;
}

void UEzShakeAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    lastChanged -= DeltaTime;

    if (lastChanged <= 0.0f) {
        lastChanged = frequency;

        auto target = GetTargetComponent();
        auto origin = target->RelativeLocation;

        target->SetRelativeLocation(
            origin +
            direction * (positiveOrNegative ? 1 : -1) * amplitude);

        positiveOrNegative ^= true;
    }

    if (IsLastTick(DeltaTime))
        GetTargetComponent()->SetRelativeLocation(initialLocation);
}

