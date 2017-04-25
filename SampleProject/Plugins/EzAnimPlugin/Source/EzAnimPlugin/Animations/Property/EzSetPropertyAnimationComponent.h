#pragma once

#include "Components/ActorComponent.h"

#include "EzAnimationBaseComponent.h"

#include "EzSetPropertyAnimationComponent.generated.h"

class UEzAnimationFunctionLibrary;

UENUM(BlueprintType)
enum EzValueType {
    VT_Integer,
    VT_Float,
    VT_Bool,
    VT_String,
    VT_Vector,
    VT_Rotator,
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EZANIMPLUGIN_API UEzSetPropertyAnimationComponent : public UEzAnimationBaseComponent
{
friend UEzAnimationFunctionLibrary;
    GENERATED_BODY()

public:
    UEzSetPropertyAnimationComponent();

protected:
    virtual void BeginPlay() override;

#if WITH_EDITOR
    virtual bool CanEditChange(const UProperty* prop) const override;
#endif

private:
    UPROPERTY(EditAnywhere)
    FString propertyName;

    UPROPERTY(EditAnywhere)
    TEnumAsByte<EzValueType> valueType;

    UPROPERTY(EditAnywhere)
    int intValue;
    UPROPERTY(EditAnywhere)
    float floatValue;
    UPROPERTY(EditAnywhere)
    bool boolValue;
    UPROPERTY(EditAnywhere)
    FVector vectorValue;
};
