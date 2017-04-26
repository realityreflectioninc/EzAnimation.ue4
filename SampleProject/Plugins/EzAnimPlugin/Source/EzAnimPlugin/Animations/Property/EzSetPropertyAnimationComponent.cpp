#include "EzAnimPlugin.h"
#include "EzSetPropertyAnimationComponent.h"

UEzSetPropertyAnimationComponent::UEzSetPropertyAnimationComponent() {
    intValue = 0;
    floatValue = 0;
    boolValue = false;
}

void UEzSetPropertyAnimationComponent::BeginPlay() {
    auto owner = GetOwner();

    if (IsValid(owner) == false) {
        Finish(); return;
    }

    auto ownerClass = owner->GetClass();
    for (TFieldIterator<UProperty> prop(ownerClass); prop; ++prop) {
        if (*prop->GetName() == propertyName) {
            // SWITCH-BY-TYPE
            if (auto intProp = Cast<UIntProperty>(*prop)) {
                intProp->SetPropertyValue_InContainer(owner, intValue);
            }
            else if (auto floatProp = Cast<UFloatProperty>(*prop)) {
                floatProp->SetPropertyValue_InContainer(owner, floatValue);
            }
            else if (auto boolProp = Cast<UBoolProperty>(*prop)) {
                boolProp->SetPropertyValue_InContainer(owner, boolValue);
            }
            else if (auto vectorProp = Cast<UStructProperty>(*prop)) {
                *(vectorProp->ContainerPtrToValuePtr<FVector>(owner)) = vectorValue;
            }
            break;
        }
    }
    Finish();
}

#if WITH_EDITOR
bool UEzSetPropertyAnimationComponent::CanEditChange(const UProperty* prop) const {
    auto name = prop->GetFName();

    if (name == GET_MEMBER_NAME_CHECKED(UEzSetPropertyAnimationComponent, intValue)) {
        if (valueType == VT_Integer) return true;
        return false;
    }
    if (name == GET_MEMBER_NAME_CHECKED(UEzSetPropertyAnimationComponent, floatValue)) {
        if (valueType == VT_Float) return true;
        return false;
    }
    if (name == GET_MEMBER_NAME_CHECKED(UEzSetPropertyAnimationComponent, boolValue)) {
        if (valueType == VT_Bool) return true;
        return false;
    }
    if (name == GET_MEMBER_NAME_CHECKED(UEzSetPropertyAnimationComponent, vectorValue)) {
        if (valueType == VT_Vector) return true;
        return false;
    }

    return Super::CanEditChange(prop);
}
#endif
