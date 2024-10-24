// Copyright by MykeUhu


#include "Actor/DroneStation/ControlStation.h"

// Sets default values
AControlStation::AControlStation()
{
	// Create Control Panel Mesh Component
	ControlPanelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ControlPanelMesh"));
	ControlPanelMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AControlStation::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AControlStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
