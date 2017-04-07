#pragma once

#include "Components/ActorComponent.h"
#include "EzUniformMovementComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EZANIMPLUGIN_API UEzUniformMovementComponent : public UActorComponent {
	GENERATED_BODY()

public:	
	UEzUniformMovementComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UFUNCTION(BlueprintCallable, Category="EzAnim")
    void SetSpeed(const FVector speed);
    UFUNCTION(BlueprintPure, Category = "EzAnim")
    FVector GetSpeed() const;

private:
    UPROPERTY(EditAnywhere, Category = "EzAnim")
    FVector speed;

    UPROPERTY(EditAnywhere, Category = "EzAnim")
    bool sweep;

    UPROPERTY(EditAnywhere, Category = "EzAnim", meta = (EditCondition = "sweep"))
    bool reverseOnHit;
};
