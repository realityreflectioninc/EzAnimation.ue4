#pragma once

#include "UObject/NoExportTypes.h"

#include "EzEase.h"
#include <queue>
#include <functional> // since we need a capture for `OnFinished` delegate.

#include "EzAnimationContext.generated.h"

class UEzAnimationBaseComponent;
class UEzAnimationFunctionLibrary;

UCLASS(BlueprintType)
class EZANIMPLUGIN_API UEzAnimationContext : public UObject
{
friend UEzAnimationFunctionLibrary;
	GENERATED_BODY()
	
public:
	UEzAnimationContext();
	~UEzAnimationContext();

	void Step();

	UFUNCTION(BlueprintCallable, Category = "EzAnim")
	void Stop();

	UFUNCTION(BlueprintCallable, Category = "EzAnim")
	void CancelAllPendingAnimations();

	UFUNCTION(BlueprintCallable, Category = "EzAnim_Append")
	UEzAnimationContext *AppendDelay(float delay = 1.0f);
	
	UFUNCTION(BlueprintCallable, Category = "EzAnim_Append")
	UEzAnimationContext *AppendDestroy();

	UFUNCTION(BlueprintCallable, Category = "EzAnim_Append")
	UEzAnimationContext *AppendDestroyActor();

	UFUNCTION(BlueprintCallable, Category = "EzAnim_Append")
	UEzAnimationContext *AppendFadeOutWithScale(
		float duration = 1.0f,
		EzEaseType easeType = EzEaseType::EaseLinear);

	UFUNCTION(BlueprintCallable, Category = "EzAnim_Append")
	UEzAnimationContext *AppendScaleTo(
		float duration = 1.0f, float scaleTo = 1.0f,
		EzEaseType easeType = EzEaseType::EaseLinear);

	UFUNCTION(BlueprintCallable, Category = "EzAnim_Append")
	UEzAnimationContext *AppendScaleTo3D(
		float duration = 1.0f, const FVector scaleTo = FVector(1,1,1),
		EzEaseType easeType = EzEaseType::EaseLinear);

	UFUNCTION(BlueprintCallable, Category = "EzAnim_Append")
	UEzAnimationContext *AppendScaleToWithCurve(
		UCurveFloat *curve = nullptr);

	UFUNCTION(BlueprintCallable, Category = "EzAnim_Append")
	UEzAnimationContext *AppendRotateTo(
		float duration = 1.0f, const FVector rotateTo = FVector(1,1,1),
		EzEaseType easeType = EzEaseType::EaseLinear);

	UFUNCTION(BlueprintCallable, Category = "EzAnim_Append")
	UEzAnimationContext *AppendRotateToWithCurve(UCurveVector *curve);

private:
	AActor *GetOwner() const;
	USceneComponent *GetTargetComponent() const;

private:
	UPROPERTY()
	UEzAnimationBaseComponent *target;

	std::queue<std::function<void()>> pendingTasks;
};
