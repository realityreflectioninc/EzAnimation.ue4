#include "EzAnimPlugin.h"
#include "EzUniformMovementComponent.h"

UEzUniformMovementComponent::UEzUniformMovementComponent() :
    speed(1, 0, 0),
    sweep(false) {

	PrimaryComponentTick.bCanEverTick = true;
}

void UEzUniformMovementComponent::BeginPlay() {
	Super::BeginPlay();

}

void UEzUniformMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    FHitResult hit;
    GetOwner()->SetActorLocation(
        GetOwner()->GetActorLocation() + speed * DeltaTime,
        sweep, &hit);

    if (sweep && hit.bBlockingHit)
        speed *= -1;
}

void UEzUniformMovementComponent::SetSpeed(const FVector _speed) {
    speed = _speed;
}
FVector UEzUniformMovementComponent::GetSpeed() const {
    return speed;
}