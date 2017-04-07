#pragma once

#include "Components/ActorComponent.h"
#include "EzForwardMovementComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EZANIMPLUGIN_API UEzForwardMovementComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UEzForwardMovementComponent();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION(BlueprintCallable, Category = "EzAnim")
    void SetSpeed(float speed);
    UFUNCTION(BlueprintPure, Category = "EzAnim")
    float GetSpeed() const;

private:
    UPROPERTY(EditAnywhere, Category = "EzAnim")
    float speed;

    UPROPERTY(EditAnywhere, Category = "EzAnim")
    bool sweep;

    UPROPERTY(EditAnywhere, Category = "EzAnim", meta = (EditCondition = "sweep"))
    bool reverseOnHit;
};
