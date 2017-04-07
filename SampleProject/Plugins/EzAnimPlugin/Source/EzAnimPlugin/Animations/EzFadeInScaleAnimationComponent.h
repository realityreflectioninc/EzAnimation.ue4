#pragma once

#include "Components/ActorComponent.h"

#include "EzScale3DAnimationComponent.h"

#include "EzFadeInScaleAnimationComponent.generated.h"

class UEzAnimationFunctionLibrary;

UCLASS( HideCategories = ("EzAnim"), ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EZANIMPLUGIN_API UEzFadeInScaleAnimationComponent : public UEzScale3DAnimationComponent {
friend UEzAnimationFunctionLibrary;
	GENERATED_BODY()

public:	
	UEzFadeInScaleAnimationComponent();

protected:
	virtual void BeginPlay() override;

};
