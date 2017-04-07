#include "EzAnimPlugin.h"
#include "EzDestroyAfterComponent.h"

UEzDestroyAfterComponent::UEzDestroyAfterComponent() :
	delay(0.0f), destroyActor(false) {
}

void UEzDestroyAfterComponent::BeginPlay() {
	Super::BeginPlay();

	if (delay == 0.0f)
		OnDestroyTimer();
	else {
		GetWorld()->GetTimerManager()
			.SetTimer(timerHandle, this, &UEzDestroyAfterComponent::OnDestroyTimer, delay, false);
	}
}

void UEzDestroyAfterComponent::OnDestroyTimer() {
	auto owner = GetOwner();

	if (destroyActor && IsValid(owner))
		owner->Destroy();
	else
		GetTargetComponent()->DestroyComponent();
}