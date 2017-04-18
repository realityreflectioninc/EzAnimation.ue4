#pragma once

#include "Components/ActorComponent.h"

#include "EzMovementTarget.h"

#include "EzFloatingComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EZANIMPLUGIN_API UEzFloatingComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UEzFloatingComponent();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

#if WITH_EDITOR
private:
    virtual bool CanEditChange(const UProperty* prop) const override;
#endif

private:
    UPROPERTY(EditAnywhere, Category = "EzAnim_MovementTarget")
    TEnumAsByte<EzMovementTarget> targetType;

    UPROPERTY(EditAnywhere, Category = "EzAnim_MovementTarget")
    int playerIndex;

    UPROPERTY(EditAnywhere, Category = "EzAnim_MovementTarget")
    AActor *target;

    UPROPERTY(EditAnywhere, Category = "EzAnim")
    bool syncRotation;

    UPROPERTY(EditAnywhere, Category = "EzAnim")
    float distance;

    UPROPERTY(EditAnywhere, Category = "EzAnim")
    float angle;

    UPROPERTY(EditAnywhere, Category = "EzAnim")
    FVector axis;
};
