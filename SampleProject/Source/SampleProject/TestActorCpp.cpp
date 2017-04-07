#include "SampleProject.h"
#include "TestActorCpp.h"

ATestActorCpp::ATestActorCpp() {
	PrimaryActorTick.bCanEverTick = true;

}

void ATestActorCpp::BeginPlay() {
	Super::BeginPlay();
	
}

void ATestActorCpp::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

