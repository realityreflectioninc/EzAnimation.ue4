#pragma once

#include "Components/ActorComponent.h"

#include "EzEaseVectorAnimationComponent.h"

#include "EzScale3DAnimationComponent.generated.h"

class UEzAnimationFunctionLibrary;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EZANIMPLUGIN_API UEzScale3DAnimationComponent : public UEzEaseVectorAnimationComponent
{
friend UEzAnimationFunctionLibrary;
	GENERATED_BODY()

public:	
	UEzScale3DAnimationComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(EditAnywhere, Category = "EzAnim")
	FVector scaleTo;
};
