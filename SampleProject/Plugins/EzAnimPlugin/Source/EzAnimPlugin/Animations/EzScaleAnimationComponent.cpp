#include "EzAnimPlugin.h"

#include "Kismet/KismetMathLibrary.h"
#include "EzEase.h"

#include "EzScaleAnimationComponent.h"

UEzScaleAnimationComponent::UEzScaleAnimationComponent() :
	scaleTo(1.0f) {
}

void UEzScaleAnimationComponent::BeginPlay() {
	Super::BeginPlay();
	
	if (IsValid(targetComponent)) {
		SetStartAndEndValue(targetComponent->RelativeScale3D.X, scaleTo);
	}
}

void UEzScaleAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float scale = GetEaseValue();
	GetTargetComponent()->SetRelativeScale3D(FVector(scale, scale, scale));
}

