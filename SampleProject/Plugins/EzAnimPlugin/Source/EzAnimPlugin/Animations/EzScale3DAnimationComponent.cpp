#include "EzAnimPlugin.h"
#include "EzScale3DAnimationComponent.h"

UEzScale3DAnimationComponent::UEzScale3DAnimationComponent() :
	scaleTo(1,1,1) {
}

void UEzScale3DAnimationComponent::BeginPlay() {
	Super::BeginPlay();

	if (IsValid(targetComponent)) {
		SetStartAndEndValue(targetComponent->RelativeScale3D, scaleTo);
	}
}

void UEzScale3DAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto scale = GetEaseValue();
	GetTargetComponent()->SetRelativeScale3D(scale);
}

