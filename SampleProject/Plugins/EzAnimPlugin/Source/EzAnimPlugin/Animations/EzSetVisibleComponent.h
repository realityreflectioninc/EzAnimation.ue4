#pragma once

#include "Components/ActorComponent.h"

#include "EzAnimationBaseComponent.h"

#include "EzSetVisibleComponent.generated.h"

class UEzAnimationFunctionLibrary;

UCLASS( ClassGroup=(Custom) )
class EZANIMPLUGIN_API UEzSetVisibleComponent : public UEzAnimationBaseComponent
{
friend UEzAnimationFunctionLibrary;
	GENERATED_BODY()

public:	
	UEzSetVisibleComponent();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="EzAnim")
	bool visible;
};
