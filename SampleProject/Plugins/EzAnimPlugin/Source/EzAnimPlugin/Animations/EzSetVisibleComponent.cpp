#include "EzAnimPlugin.h"
#include "EzSetVisibleComponent.h"

UEzSetVisibleComponent::UEzSetVisibleComponent() :
	visible(true) {
}

void UEzSetVisibleComponent::BeginPlay() {
	Super::BeginPlay();

	GetTargetComponent()->SetVisibility(visible);
	Finish();
}

