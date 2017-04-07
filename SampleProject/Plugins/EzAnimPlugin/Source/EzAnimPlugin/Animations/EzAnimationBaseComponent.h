#pragma once

#include "Components/ActorComponent.h"

#include "EzAnimationBaseComponent.generated.h"

class UEzAnimationContext;
class UEzAnimationFunctionLibrary;

UCLASS( ClassGroup=(Custom))
class EZANIMPLUGIN_API UEzAnimationBaseComponent : public UActorComponent {
friend UEzAnimationFunctionLibrary;
	GENERATED_BODY()

public:	
	UEzAnimationBaseComponent();

	void Stop();
	USceneComponent *GetTargetComponent() const;

protected:
	virtual void BeginPlay() override;

	void Finish();

public:
	UPROPERTY(BlueprintReadOnly, Category = "EzAnim")
	UEzAnimationContext *context;

private:
	UPROPERTY()
	USceneComponent *targetComponent;
};
