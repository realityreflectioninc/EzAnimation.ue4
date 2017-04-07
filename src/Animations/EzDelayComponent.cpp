#include "EzAnimPlugin.h"
#include "EzDelayComponent.h"

UEzDelayComponent::UEzDelayComponent() :
	delay(1.0f) {

	PrimaryComponentTick.bCanEverTick = false;
}

void UEzDelayComponent::BeginPlay() {
	Super::BeginPlay();

	GetWorld()->GetTimerManager()
		.SetTimer(timerHandle, this, &UEzDelayComponent::OnDelayTimer, delay, false);
}

void UEzDelayComponent::OnDelayTimer() {
	Finish();
}