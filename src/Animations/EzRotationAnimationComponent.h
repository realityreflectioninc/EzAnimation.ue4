#pragma once

#include "Components/ActorComponent.h"

#include "EzEaseVectorAnimationComponent.h"

#include "EzRotationAnimationComponent.generated.h"

class UEzAnimationFunctionLibrary;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EZANIMPLUGIN_API UEzRotationAnimationComponent : public UEzEaseVectorAnimationComponent {
friend UEzAnimationFunctionLibrary;
	GENERATED_BODY()

public:	
	UEzRotationAnimationComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere, Category = "EzAnim")
	FVector rotateTo;
};
