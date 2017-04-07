#pragma once

#include "Components/ActorComponent.h"

#include "EzEase.h"

#include "EzEaseFloatComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EZANIMPLUGIN_API UEzEaseFloatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEzEaseFloatComponent();

	UFUNCTION(BlueprintPure, Category="EzAnim")
	float GetValue() const;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float value;

	UPROPERTY(EditAnywhere, Category = "EzAnim")
	float startValue;
	UPROPERTY(EditAnywhere, Category = "EzAnim")
	float endValue;
	UPROPERTY(EditAnywhere, Category = "EzAnim")
	float duration;
	UPROPERTY(EditAnywhere, Category = "EzAnim")
	TEnumAsByte<EzEaseType> easeType;

	float deltaValue;
	float time;
};
