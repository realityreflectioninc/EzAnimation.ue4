#pragma once

#include "Components/ActorComponent.h"

#include "EzEase.h"
#include "EzEaseAnimationComponent.h"

#include "EzScaleAnimationComponent.generated.h"

class UEzAnimationFunctionLibrary;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EZANIMPLUGIN_API UEzScaleAnimationComponent : public UEzEaseAnimationComponent
{
friend UEzAnimationFunctionLibrary;
	GENERATED_BODY()

public:	 
	UEzScaleAnimationComponent();
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(EditAnywhere, Category="EzAnim")
	float scaleTo;
};
