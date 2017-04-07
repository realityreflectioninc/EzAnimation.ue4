#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"

#include "EzEase.h"
#include "EzEaseFloatComponent.h"

#include "EzAnimationFunctionLibrary.generated.h"

class UEzAnimationContext;
class UEzAnimationBaseComponent;

UCLASS()
class EZANIMPLUGIN_API UEzAnimationFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "->", BlueprintAutocast), Category = "EzFloat")
	static float Conv_EaseFloatToFloat(UEzEaseFloatComponent *easeFloat);
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "->", BlueprintAutocast), Category = "EzFloat")
	static FString Conv_EaseFloatToString(UEzEaseFloatComponent *easeFloat);
	UFUNCTION(BlueprintPure, meta = (CompactNodeTitle = "->", BlueprintAutocast), Category = "EzFloat")
	static FText Conv_EaseFloatToText(UEzEaseFloatComponent *easeFloat);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *FadeInWithScale(
		USceneComponent *target,
		float duration = 1.0f,
		EzEaseType easeType = EzEaseType::EaseLinear,
		UEzAnimationContext *context = nullptr);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *FadeOutWithScale(
		USceneComponent *target,
		float duration = 1.0f,
		EzEaseType easeType = EzEaseType::EaseLinear,
		UEzAnimationContext *context = nullptr);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *FadeInWithScalarParameter_StaticMesh(
		UStaticMeshComponent *target,
		float duration = 1.0f,
		int materialIdx = 0,
		FName parameterName = "Opacity", 
		EzEaseType easeType = EzEaseType::EaseLinear,
		UEzAnimationContext *context = nullptr);
	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *FadeOutWithScalarParameter_StaticMesh(
		UStaticMeshComponent *target,
		float duration = 1.0f,
		int materialIdx = 0,
		FName parameterName = "Opacity",
		EzEaseType easeType = EzEaseType::EaseLinear,
		UEzAnimationContext *context = nullptr);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *ScaleTo(
		USceneComponent *target,
		float duration = 1.0f,
		float scaleTo = 1.0f,
		EzEaseType easeType = EzEaseType::EaseLinear,
		UEzAnimationContext *context = nullptr);
	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *ScaleTo3D(
		USceneComponent *target,
		float duration = 1.0f,
		const FVector scaleTo = FVector(1,1,1),
		EzEaseType easeType = EzEaseType::EaseLinear,
		UEzAnimationContext *context = nullptr);
	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *ScaleToWithCurve(
		USceneComponent *target,
		UCurveFloat *curve,
		UEzAnimationContext *context = nullptr);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *ScaleTo3DWithCurve(
		USceneComponent *target,
		UCurveVector *curve,
		UEzAnimationContext *context = nullptr);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *RotateTo(
		USceneComponent *target,
		float duration = 1.0f,
		const FVector rotateTo = FVector(0,0,0),
		EzEaseType easeType = EzEaseType::EaseLinear,
		UEzAnimationContext *context = nullptr);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *RotateToWithCurve(
		USceneComponent *target,
		UCurveVector *curve = nullptr,
		UEzAnimationContext *context = nullptr);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *SetVisible(
		USceneComponent *target,
		bool visible = true,
		UEzAnimationContext *context = nullptr);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *DestroyAfter(
		USceneComponent *target,
		float delay = 1.0f,
		UEzAnimationContext *context = nullptr);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *DestroyActorAfter(
		USceneComponent *target,
		float delay = 1.0f,
		UEzAnimationContext *context = nullptr);

	UFUNCTION(BlueprintCallable, Category = "EzAnim", meta = (HidePin = "context"))
	static UEzAnimationContext *Delay(
		USceneComponent *target,
		float delay = 1.0f,
		UEzAnimationContext *context = nullptr);

private:
	static UMaterialInstanceDynamic *OverrideMaterial(UStaticMeshComponent *staticMeshComponent, int materialIdx);
}; 
