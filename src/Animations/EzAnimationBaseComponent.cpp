#include "EzAnimPlugin.h"

#include "EzAnimationContext.h"

#include "EzAnimationBaseComponent.h"

UEzAnimationBaseComponent::UEzAnimationBaseComponent() :
	targetComponent(nullptr) {

	PrimaryComponentTick.bCanEverTick = false;
}

void UEzAnimationBaseComponent::BeginPlay() {
	Super::BeginPlay();
	
}

USceneComponent *UEzAnimationBaseComponent::GetTargetComponent() const {
	return targetComponent;
}

void UEzAnimationBaseComponent::Stop() {
	DestroyComponent();
}
void UEzAnimationBaseComponent::Finish() {
	if (context == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("context is nullptr"));
	}
	else
		context->Step();

	DestroyComponent();
}

