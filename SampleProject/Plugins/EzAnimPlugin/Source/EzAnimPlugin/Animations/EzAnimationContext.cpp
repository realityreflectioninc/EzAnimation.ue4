#include "EzAnimPlugin.h"

#include "EzAnimationBaseComponent.h"
#include "EzAnimationFunctionLibrary.h"

#include "EzAnimationContext.h"

UEzAnimationContext::UEzAnimationContext() :
	target(nullptr) {

}
UEzAnimationContext::~UEzAnimationContext() {
}

AActor *UEzAnimationContext::GetOwner() const {
	return target->GetOwner();
}
USceneComponent *UEzAnimationContext::GetTargetComponent() const {
	return target->GetTargetComponent();
}

void UEzAnimationContext::Step() {
	if (pendingTasks.empty()) return;

	auto &task = pendingTasks.front();
	task();
	pendingTasks.pop();
}

void UEzAnimationContext::Stop() {
	CancelAllPendingAnimations();

	if (IsValid(target))
		target->Stop();
}
void UEzAnimationContext::CancelAllPendingAnimations() {
	decltype(pendingTasks) emptyQ;
	pendingTasks.swap(emptyQ);
}

UEzAnimationContext *UEzAnimationContext::AppendShake(float delay,
    float amplitude, float frequency,
    const FVector direction) {

    pendingTasks.push([this, delay, amplitude, frequency, direction]() {
        UEzAnimationFunctionLibrary::Shake(GetTargetComponent(),
            delay, amplitude, frequency, direction, this);
    });

    return this;
}

UEzAnimationContext *UEzAnimationContext::AppendDelay(float delay) {

	pendingTasks.push([this, delay]() {
		UEzAnimationFunctionLibrary::Delay(GetTargetComponent(), delay, this);
	});

	return this;
}

UEzAnimationContext *UEzAnimationContext::AppendDestroy() {
	pendingTasks.push([this]() {
		UEzAnimationFunctionLibrary::DestroyAfter(GetTargetComponent(), 0, this);
	});

	return this; 
}
UEzAnimationContext *UEzAnimationContext::AppendDestroyActor() {
	pendingTasks.push([this]() {
		UEzAnimationFunctionLibrary::DestroyActorAfter(GetTargetComponent(), 0, this);
	});

	return this;
}

UEzAnimationContext *UEzAnimationContext::AppendFadeOutWithScale(
	float duration,
	EzEaseType easeType) {

	pendingTasks.push([this, duration, easeType]() {
		UEzAnimationFunctionLibrary::FadeOutWithScale(
			GetTargetComponent(), duration, easeType, this);
	});

	return this;
}

UEzAnimationContext *UEzAnimationContext::AppendScaleTo(
	float duration, float scaleTo, EzEaseType easeType) {

	pendingTasks.push([this, duration, scaleTo, easeType]() {
		UEzAnimationFunctionLibrary::ScaleTo(
			GetTargetComponent(), duration, scaleTo, easeType, this);
	});

	return this;
}
UEzAnimationContext *UEzAnimationContext::AppendScaleTo3D(
	float duration, const FVector scaleTo, EzEaseType easeType) {

	pendingTasks.push([this, duration, scaleTo, easeType]() {
		UEzAnimationFunctionLibrary::ScaleTo3D(
			GetTargetComponent(), duration, scaleTo, easeType, this);
	});

	return this;
}
UEzAnimationContext *UEzAnimationContext::AppendScaleToWithCurve(UCurveFloat *curve) {

	pendingTasks.push([this, curve]() {
		UEzAnimationFunctionLibrary::ScaleToWithCurve(
			GetTargetComponent(), curve, this);
	});

	return this;
}

UEzAnimationContext *UEzAnimationContext::AppendRotateTo(
	float duration, const FVector rotateTo, EzEaseType easeType) {

	pendingTasks.push([this, duration, rotateTo, easeType]() {
		UEzAnimationFunctionLibrary::RotateTo(
			GetTargetComponent(), duration, rotateTo, easeType, this);
	});

	return this;
}

UEzAnimationContext *UEzAnimationContext::AppendRotateToWithCurve(UCurveVector *curve) {

	pendingTasks.push([this, curve]() {
		UEzAnimationFunctionLibrary::RotateToWithCurve(
			GetTargetComponent(), curve, this);
	});

	return this;
}
