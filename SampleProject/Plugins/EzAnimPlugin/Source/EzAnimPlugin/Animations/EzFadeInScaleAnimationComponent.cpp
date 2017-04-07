#include "EzAnimPlugin.h"

#include "EzComponentTransformStorage.h"

#include "EzFadeInScaleAnimationComponent.h"

UEzFadeInScaleAnimationComponent::UEzFadeInScaleAnimationComponent() {

}

void UEzFadeInScaleAnimationComponent::BeginPlay() {
	Super::BeginPlay();

    UEzComponentTransformStorage::SetupEz(GetOwner());

    if (IsValid(GetTargetComponent())) {
        SetStartAndEndValue(FVector(0,0,0), GetTargetComponent()->RelativeScale3D);
    }
}


