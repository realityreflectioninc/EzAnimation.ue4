#pragma once

#include "Components/ActorComponent.h"

#include "EzEase.h"
#include "EzEaseAnimationComponent.h"

#include "EzScalarParamAnimationComponent.generated.h"

class UEzAnimationFunctionLibrary;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EZANIMPLUGIN_API UEzScalarParamAnimationComponent : public UEzEaseAnimationComponent
{
friend UEzAnimationFunctionLibrary;
	GENERATED_BODY()

public:	
	UEzScalarParamAnimationComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
private:
	UPROPERTY(EditAnywhere, Category = "EzAnim")
	UMaterialInstanceDynamic *material;

	UPROPERTY(EditAnywhere, Category = "EzAnim")
	FName parameterName;

	UPROPERTY(EditAnywhere, Category = "EzAnim")
	float parameterTo;
};
