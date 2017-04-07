#pragma once

#include "Components/ActorComponent.h"

#include "EzAnimationBaseComponent.generated.h"

class UEzAnimationContext;

UCLASS( ClassGroup=(Custom))
class EZANIMPLUGIN_API UEzAnimationBaseComponent : public UActorComponent {
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

protected:
	UPROPERTY()
	USceneComponent *targetComponent;
};
