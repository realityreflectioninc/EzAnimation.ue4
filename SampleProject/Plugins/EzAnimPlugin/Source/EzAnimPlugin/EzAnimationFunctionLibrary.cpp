#include "EzAnimPlugin.h"

#include "EzComponentTransformStorage.h"

#include "EzAnimationContext.h"
#include "EzDelayComponent.h"
#include "EzDestroyAfterComponent.h"
#include "EzRotationAnimationComponent.h"
#include "EzScaleAnimationComponent.h"
#include "EzScale3DAnimationComponent.h"
#include "EzScalarParamAnimationComponent.h"
#include "EzSetVisibleComponent.h"

#include "EzAnimationFunctionLibrary.h"

#define BEGIN_FACTORY_BODY(target, typeName) \
	if (IsValid(target)) { \
		auto comp = NewObject<typeName>(target, #typeName); \
		comp->targetComponent = target; \
		if (context != nullptr) comp->context = context; \
		else { \
			comp->context = NewObject<UEzAnimationContext>(comp, "EzAnimContext"); \
			comp->context->target = comp; \
		}

#define END_FACTORY_BODY() \
		comp->RegisterComponent(); \
		target->GetOwner()->AddOwnedComponent(comp); \
		return comp->context; \
	} \
	return nullptr;

UMaterialInstanceDynamic *UEzAnimationFunctionLibrary::OverrideMaterial(UStaticMeshComponent *staticMeshComponent, int materialIdx) {
	auto originalMaterial = staticMeshComponent->GetMaterial(materialIdx);
	UMaterialInstanceDynamic *material = nullptr;

	material = Cast<UMaterialInstanceDynamic>(originalMaterial);
	if (material == nullptr) {
		material = staticMeshComponent->CreateDynamicMaterialInstance(materialIdx, material);
		staticMeshComponent->SetMaterial(materialIdx, material);
	}
	
	return material;
}

float UEzAnimationFunctionLibrary::Conv_EaseFloatToFloat(UEzEaseFloatComponent *easeFloat) {
	return easeFloat->GetValue();
}
FString UEzAnimationFunctionLibrary::Conv_EaseFloatToString(UEzEaseFloatComponent *easeFloat) {
	char buf[16];
	sprintf(buf, "%f", easeFloat->GetValue());
	return FString(buf);
}
FText UEzAnimationFunctionLibrary::Conv_EaseFloatToText(UEzEaseFloatComponent *easeFloat) {
	char buf[16];
	sprintf(buf, "%f", easeFloat->GetValue());
	return FText::FromString(buf);
}

UEzAnimationContext *UEzAnimationFunctionLibrary::FadeInWithScale(USceneComponent *target,
	float duration,
	EzEaseType easeType, 
	UEzAnimationContext *context) {

	BEGIN_FACTORY_BODY(target, UEzScale3DAnimationComponent)
		comp->duration = duration;
		comp->startValue = FVector::ZeroVector;
		if (UEzComponentTransformStorage::GetEditorScale3D(target->GetOwner(), target, comp->scaleTo, false) == false)
			comp->scaleTo = target->RelativeScale3D;
		comp->useCurve = false;
		comp->easeType = easeType;

		comp->FreezeStartValue();
	END_FACTORY_BODY()
}
UEzAnimationContext *UEzAnimationFunctionLibrary::FadeOutWithScale(USceneComponent *target,
	float duration,
	EzEaseType easeType, 
	UEzAnimationContext *context) {

	BEGIN_FACTORY_BODY(target, UEzScaleAnimationComponent)
		comp->duration = duration;
		comp->scaleTo = 0.0f;
		comp->useCurve = false;
		comp->easeType = easeType;
	END_FACTORY_BODY()
}

UEzAnimationContext *UEzAnimationFunctionLibrary::FadeInWithScalarParameter_StaticMesh(
	UStaticMeshComponent *target,
	float duration, int materialIdx,
	FName parameterName,
	EzEaseType easeType,
	UEzAnimationContext *context) {

	auto material = OverrideMaterial(target, materialIdx);

	float out = 0.0f;
	material->GetScalarParameterValue(parameterName, out);

	BEGIN_FACTORY_BODY(target, UEzScalarParamAnimationComponent)
		comp->material = material;
		comp->parameterName = parameterName;
		comp->duration = duration;
		comp->startValue = 0.0f;
		comp->parameterTo = out;
		comp->useCurve = false;
		comp->easeType = easeType;

		comp->FreezeStartValue();
	END_FACTORY_BODY()
}
UEzAnimationContext *UEzAnimationFunctionLibrary::FadeOutWithScalarParameter_StaticMesh(
	UStaticMeshComponent *target,
	float duration, int materialIdx,
	FName parameterName,
	EzEaseType easeType,
	UEzAnimationContext *context) {

	auto material = OverrideMaterial(target, materialIdx);

	BEGIN_FACTORY_BODY(target, UEzScalarParamAnimationComponent)
		comp->material = material;
		comp->parameterName = parameterName;
		comp->duration = duration;
		comp->parameterTo = 0.0f;
		comp->useCurve = false;
		comp->easeType = easeType;
	END_FACTORY_BODY()
}

UEzAnimationContext *UEzAnimationFunctionLibrary::ScaleTo(USceneComponent *target,
	float duration, float scaleTo, EzEaseType easeType, 
	UEzAnimationContext *context) {

	BEGIN_FACTORY_BODY(target, UEzScaleAnimationComponent)
		comp->duration = duration;
		comp->scaleTo = scaleTo;
		comp->useCurve = false;
		comp->easeType = easeType;
	END_FACTORY_BODY()
}
UEzAnimationContext *UEzAnimationFunctionLibrary::ScaleTo3D(USceneComponent *target,
	float duration, const FVector scaleTo, EzEaseType easeType,
	UEzAnimationContext *context) {

	BEGIN_FACTORY_BODY(target, UEzScale3DAnimationComponent)
		comp->duration = duration;
		comp->scaleTo = scaleTo;
		comp->useCurve = false;
		comp->easeType = easeType;
	END_FACTORY_BODY()
}
UEzAnimationContext *UEzAnimationFunctionLibrary::ScaleToWithCurve(USceneComponent *target,
	UCurveFloat *curve,
	UEzAnimationContext *context) {

	BEGIN_FACTORY_BODY(target, UEzScaleAnimationComponent)
		comp->useCurve = true;
		comp->curve = curve;
	END_FACTORY_BODY() 
}

UEzAnimationContext *UEzAnimationFunctionLibrary::ScaleTo3DWithCurve(USceneComponent *target,
	UCurveVector *curve,
	UEzAnimationContext *context) {

	BEGIN_FACTORY_BODY(target, UEzScale3DAnimationComponent)
		comp->useCurve = true;
		comp->curve = curve;
	END_FACTORY_BODY()
}

UEzAnimationContext *UEzAnimationFunctionLibrary::RotateTo(USceneComponent *target,
	float duration, const FVector rotateTo, EzEaseType easeType,
	UEzAnimationContext *context) {

	BEGIN_FACTORY_BODY(target, UEzRotationAnimationComponent)
		comp->duration = duration;
		comp->rotateTo = rotateTo;
		comp->useCurve = false;
		comp->easeType = easeType;
	END_FACTORY_BODY()
}

UEzAnimationContext *UEzAnimationFunctionLibrary::RotateToWithCurve(USceneComponent *target,
	UCurveVector *curve,
	UEzAnimationContext *context) {

	BEGIN_FACTORY_BODY(target, UEzRotationAnimationComponent)
		comp->curve = curve;
		comp->useCurve = true;
	END_FACTORY_BODY()
}

UEzAnimationContext *UEzAnimationFunctionLibrary::SetVisible(USceneComponent *target,
	bool visible,
	UEzAnimationContext *context) {

	BEGIN_FACTORY_BODY(target, UEzSetVisibleComponent)
		comp->visible = visible;
	END_FACTORY_BODY()
}

UEzAnimationContext *UEzAnimationFunctionLibrary::Delay(USceneComponent *target,
	float delay,
	UEzAnimationContext *context) {

	BEGIN_FACTORY_BODY(target, UEzDelayComponent)
		comp->delay = delay;
	END_FACTORY_BODY()
}

UEzAnimationContext *UEzAnimationFunctionLibrary::DestroyAfter(USceneComponent *target,
	float delay, 
	UEzAnimationContext *context) {

	BEGIN_FACTORY_BODY(target, UEzDestroyAfterComponent)
		comp->delay = delay;
	END_FACTORY_BODY()
} 

UEzAnimationContext *UEzAnimationFunctionLibrary::DestroyActorAfter(USceneComponent *target,
	float delay,
	UEzAnimationContext *context) {

	BEGIN_FACTORY_BODY(target, UEzDestroyAfterComponent)
		comp->destroyActor = true;
		comp->delay = delay;
	END_FACTORY_BODY()
}
