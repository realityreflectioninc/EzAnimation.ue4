#pragma once

#include "Components/ActorComponent.h"

#include "EzAnimationBaseComponent.h"

#include "EzDelayComponent.generated.h"

class UEzAnimationFunctionLibrary;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EZANIMPLUGIN_API UEzDelayComponent : public UEzAnimationBaseComponent {
friend UEzAnimationFunctionLibrary;
	GENERATED_BODY()

public:	
	UEzDelayComponent();

protected:
	virtual void BeginPlay() override;

private:
	void OnDelayTimer();

private:
	UPROPERTY(EditAnywhere, Category = "EzAnim")
	float delay;

	FTimerHandle timerHandle;
};
