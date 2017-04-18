#include "EzAnimPlugin.h"
#include "EzFloatingComponent.h"

UEzFloatingComponent::UEzFloatingComponent() :
    targetType(EzMovementTarget::EZMT_Actor),
    playerIndex(0),
    target(nullptr),
    syncRotation(true),
    distance(100), angle(0), axis(1, 1, 0) {

    PrimaryComponentTick.TickGroup = ETickingGroup::TG_PostUpdateWork;
    PrimaryComponentTick.bCanEverTick = true;
}

void UEzFloatingComponent::BeginPlay() {
    Super::BeginPlay();

}

void UEzFloatingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    FVector targetLocation;
    FRotator targetRotation;
    FVector forwardVector;

    if (targetType == EzMovementTarget::EZMT_Actor) {
        if (IsValid(target)) {
            targetLocation = target->GetActorLocation();
            forwardVector = target->GetActorForwardVector();
            targetRotation = target->GetActorRotation();
        }
    }
    else if (targetType == EzMovementTarget::EZMT_PlayerCamera) {
        auto camManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), playerIndex);
        if (IsValid(camManager)) {
            targetLocation = camManager->GetCameraLocation();
            forwardVector = camManager->GetActorForwardVector();
            targetRotation = camManager->GetCameraRotation();
        }
    }
    else if (targetType == EzMovementTarget::EZMT_PlayerPawn) {
        auto pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), playerIndex);
        if (IsValid(pawn)) {
            targetLocation = pawn->GetActorLocation();
            forwardVector = pawn->GetActorForwardVector();
            targetRotation = pawn->GetActorRotation();
        }
    }
     
    auto floating = forwardVector;
    floating = forwardVector.RotateAngleAxis(angle, axis) * distance;
    GetOwner()->SetActorLocation(targetLocation + floating);

    if (syncRotation) {
        GetOwner()->SetActorRotation(targetRotation);
    }
}

#if WITH_EDITOR
bool UEzFloatingComponent::CanEditChange(const UProperty* prop) const {
    auto name = prop->GetFName();

    if (name == GET_MEMBER_NAME_CHECKED(UEzFloatingComponent, playerIndex)) {
        return
            targetType == EzMovementTarget::EZMT_PlayerCamera ||
            targetType == EzMovementTarget::EZMT_PlayerPawn;
    }
    else if (name == GET_MEMBER_NAME_CHECKED(UEzFloatingComponent, target))
        return targetType == EzMovementTarget::EZMT_Actor;

    return Super::CanEditChange(prop);
}
#endif