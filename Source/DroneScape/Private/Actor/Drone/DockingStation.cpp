#include "Actor/Drone/DockingStation.h"
#include "Characters/UhuDroneCharacter.h"
#include "EngineUtils.h"
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

	// Start pinging the Drone
	PingDrone();
}

// Function to ping the Drone until it responds
void ADockingStation::PingDrone()
{
	// Check if the Drone has already been found
	if (bIsDroneFound)
	{
		return; // Exit if already found
	}

	// Search for the Drone
	for (TActorIterator<AUhuDroneCharacter> It(GetWorld()); It; ++It)
	{
		AUhuDroneCharacter* Actor = *It;
		if (Actor)
		{
			DroneReference = Actor;
			bIsDroneFound = true; // Set flag to true
			UE_LOG(LogTemp, Warning, TEXT("Drone found."));

			// Respond to the Drone's signal
			FVector DroneLocation = RespondToSignal();
			UE_LOG(LogTemp, Warning, TEXT("Drone location: %s"), *DroneLocation.ToString());

			return; // Exit after finding the Drone
		}
	}

	// If not found, continue pinging after a delay
	GetWorld()->GetTimerManager().SetTimer(PingTimerHandle, this, &ADockingStation::PingDrone, 1.0f, false);
}

// Responds to the request for the Drone's location
FVector ADockingStation::RespondToSignal() const
{
	// Return the location of the Docking Station
	return GetActorLocation(); // Or a specific location if needed
}

// Called every frame
void ADockingStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
