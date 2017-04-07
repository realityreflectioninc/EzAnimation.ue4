#pragma once

#include "Components/ActorComponent.h"

#include "EzAnimationBaseComponent.h"

#include "EzPeriodicAnimationComponent.generated.h"

class UEzAnimationFunctionLibrary;

UCLASS( ClassGroup=(Custom))
class EZANIMPLUGIN_API UEzPeriodicAnimationComponent : public UEzAnimationBaseComponent {
	friend UEzAnimationFunctionLibrary;
	GENERATED_BODY()

public:	
	UEzPeriodicAnimationComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

	inline float GetNormalizedTime() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EzAnim")
	float duration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EzAnim")
	bool loop;

	float time;
};
