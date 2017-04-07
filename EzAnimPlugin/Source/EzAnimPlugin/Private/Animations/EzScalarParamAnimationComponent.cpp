#include "EzAnimPlugin.h"
#include "EzScalarParamAnimationComponent.h"

UEzScalarParamAnimationComponent::UEzScalarParamAnimationComponent() :
	material(nullptr), parameterName("Opacity"),
	parameterTo(1.0f) {
}

void UEzScalarParamAnimationComponent::BeginPlay() {
	Super::BeginPlay();

	if (IsValid(material)) {
		float v;
		if (material->GetScalarParameterValue(parameterName, v)) {
			SetStartAndEndValue(v, parameterTo);
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("failed to acquire scalar param : %s"), *(parameterName.ToString()));
		}
	}
}

void UEzScalarParamAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsValid(material)) {
		float value = GetEaseValue();

		material->SetScalarParameterValue(parameterName, value);
	}
}
