#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "EzComponentTransformStorage.generated.h"

UCLASS()
class EZANIMPLUGIN_API UEzComponentTransformStorage : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "EzAnim")
	static void SetupEz(AActor *target);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "warn"))
	static bool GetEditorTransform(AActor *target, USceneComponent *comp, FTransform &transform, bool warn = true);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "warn"))
	static bool GetEditorScale3D(AActor *target, USceneComponent *comp, FVector &scale, bool warn = true);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "warn"))
	static bool GetEditorRotation(AActor *target, USceneComponent *comp, FVector &rotation, bool warn =true);
};
