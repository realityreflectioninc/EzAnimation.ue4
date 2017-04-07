#pragma once

#include "Components/ActorComponent.h"

#include "EzAnimationBaseComponent.h"

#include "EzDestroyAfterComponent.generated.h"

class UEzAnimationFunctionLibrary;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EZANIMPLUGIN_API UEzDestroyAfterComponent : public UEzAnimationBaseComponent
{
friend UEzAnimationFunctionLibrary;
	GENERATED_BODY()

public:	
	UEzDestroyAfterComponent();

protected:
	virtual void BeginPlay() override;

private:
	void OnDestroyTimer();

private:
	UPROPERTY(EditAnywhere, Category = "EzAnim")
	float delay;

	UPROPERTY(EditAnywhere, Category = "EzAnim")
	bool destroyActor;

	FTimerHandle timerHandle;
};
