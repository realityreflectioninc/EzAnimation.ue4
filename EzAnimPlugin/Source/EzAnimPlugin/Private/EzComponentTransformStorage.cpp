#include "EzAnimPlugin.h"

#include <map>

#include "EzComponentTransformStorage.h"

using namespace std;

struct ComponentData {
	FString name;
	FTransform transform;
};

static map<UClass*, TArray<ComponentData>> _storage;

void UEzComponentTransformStorage::SetupEz(AActor *target) {
	auto components = target->GetComponentsByClass(USceneComponent::StaticClass());

	auto klass = target->GetClass();

	for (auto _comp : components) {
		auto comp = (USceneComponent*)_comp;

		ComponentData cd;
		cd.name = comp->GetName();
		cd.transform = comp->GetRelativeTransform();

		_storage[klass].Add(cd);
	}
}

bool UEzComponentTransformStorage::GetEditorTransform(AActor *target,
	USceneComponent *comp, FTransform &transform,
	bool warn) {

	auto klass = target->GetClass();
	if (_storage.find(klass) == _storage.end()) {
		if (warn) {
			UE_LOG(LogTemp, Error, TEXT("You must call `SetupEz` method in `BeginPlay` first."));
		}
		return false;
	}

	auto compData = _storage[klass];
	for (auto cd : compData) {
		if (cd.name == comp->GetName()) {
			transform = cd.transform;
			return true;
		}
	}

	return false;
}

bool UEzComponentTransformStorage::GetEditorScale3D(AActor *target,
	USceneComponent *comp, FVector &scale,
	bool warn) {

	FTransform transform;
	if (GetEditorTransform(target, comp, transform, warn)) {
		scale = transform.GetScale3D();
		return true;
	}
	return false;
}
bool UEzComponentTransformStorage::GetEditorRotation(AActor *target,
	USceneComponent *comp, FVector &rotation,
	bool warn) {

	FTransform transform;
	if (GetEditorTransform(target, comp, transform, warn)) {
		rotation = transform.GetRotation().Vector();
		return true;
	}
	return false;
}