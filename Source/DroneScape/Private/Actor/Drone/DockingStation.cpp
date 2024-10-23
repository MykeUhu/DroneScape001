#include "Actor/Drone/DockingStation.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

// Sets default values
ADockingStation::ADockingStation()
{
	PrimaryActorTick.bCanEverTick = true;

	// Initialize components
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	DockingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DockingMesh"));
	DockingMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADockingStation::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADockingStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
