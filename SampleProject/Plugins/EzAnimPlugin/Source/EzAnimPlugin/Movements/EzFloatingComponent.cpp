#include "EzAnimPlugin.h"
#include "EzFloatingComponent.h"

UEzFloatingComponent::UEzFloatingComponent() :
    targetType(EzMovementTarget::MT_Actor),
    playerIndex(0),
    target(nullptr),
    syncRotation(true),
    distance(100), angle(0) {

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

    if (targetType == EzMovementTarget::MT_Actor) {
        if (IsValid(target)) {
            targetLocation = target->GetActorLocation();
            forwardVector = target->GetActorForwardVector();
            targetRotation = target->GetActorRotation();
        }
    }
    else if (targetType == EzMovementTarget::MT_PlayerCamera) {
        auto camManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), playerIndex);
        if (IsValid(camManager)) {
            targetLocation = camManager->GetCameraLocation();
            forwardVector = camManager->GetActorForwardVector();
            targetRotation = camManager->GetCameraRotation();
        }
    }
    else if (targetType == EzMovementTarget::MT_PlayerPawn) {
        auto pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), playerIndex);
        if (IsValid(pawn)) {
            targetLocation = pawn->GetActorLocation();
            forwardVector = pawn->GetActorForwardVector();
            targetRotation = target->GetActorRotation();
        }
    }
     
    auto floating = forwardVector;
    floating = forwardVector.RotateAngleAxis(angle, FVector(1,1,0)) * distance;
    GetOwner()->SetActorLocation(targetLocation + floating);

    if (syncRotation) {
        GetOwner()->SetActorRotation(targetRotation);
    }
}

bool UEzFloatingComponent::CanEditChange(const UProperty* prop) const {
    auto name = prop->GetFName();

    if (name == GET_MEMBER_NAME_CHECKED(UEzFloatingComponent, playerIndex)) {
        return
            targetType == EzMovementTarget::MT_PlayerCamera ||
            targetType == EzMovementTarget::MT_PlayerPawn;
    }
    else if (name == GET_MEMBER_NAME_CHECKED(UEzFloatingComponent, target))
        return targetType == EzMovementTarget::MT_Actor;

    return Super::CanEditChange(prop);
}