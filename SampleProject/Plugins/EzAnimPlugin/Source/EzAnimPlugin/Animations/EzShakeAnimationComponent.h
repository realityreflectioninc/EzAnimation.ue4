#pragma once

#include "Components/ActorComponent.h"

#include "EzPeriodicAnimationComponent.h"

#include "EzShakeAnimationComponent.generated.h"

class UEzAnimationFunctionLibrary;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EZANIMPLUGIN_API UEzShakeAnimationComponent : public UEzPeriodicAnimationComponent {
friend UEzAnimationFunctionLibrary;
	GENERATED_BODY()

public:	
    UEzShakeAnimationComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    UPROPERTY(EditAnywhere, Category = "EzAnim")
    float amplitude;
	
    UPROPERTY(EditAnywhere, Category = "EzAnim")
    float frequency;

    UPROPERTY(EditAnywhere, Category = "EzAnim")
    FVector direction;

    FVector initialLocation;
    bool positiveOrNegative;
    float lastChanged;
};
