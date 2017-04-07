#include "EzAnimPlugin.h"
#include "EzForwardMovementComponent.h"

UEzForwardMovementComponent::UEzForwardMovementComponent() :
    speed(100),
    sweep(false),
    reverseOnHit(false) {

    PrimaryComponentTick.bCanEverTick = true;
}

void UEzForwardMovementComponent::BeginPlay() {
    Super::BeginPlay();

}

void UEzForwardMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    FHitResult hit;
    GetOwner()->SetActorLocation(
        GetOwner()->GetActorLocation() + 
        GetOwner()->GetActorForwardVector() * speed * DeltaTime,
        sweep, &hit);

    if (sweep && hit.bBlockingHit)
        speed *= -1;
}

void UEzForwardMovementComponent::SetSpeed(float _speed) {
    speed = _speed;
}
float UEzForwardMovementComponent::GetSpeed() const {
    return speed;
}