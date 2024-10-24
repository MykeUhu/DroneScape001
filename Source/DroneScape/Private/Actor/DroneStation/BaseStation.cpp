#include "Actor/DroneStation/BaseStation.h"

// Sets default values
ABaseStation::ABaseStation()
{
	// Create Root Component
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	// Create Base Mesh Component
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABaseStation::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
