#include "Characters/UhuDroneCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "AIController.h"
#include "Engine/World.h"
#include "Actor/Drone/DockingStation.h"

// Sets default values
AUhuDroneCharacter::AUhuDroneCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Initialize components
    CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
    RootComponent = CapsuleComponent;

    DroneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DroneMesh"));
    DroneMesh->SetupAttachment(RootComponent);

    // Initialize variables
    FuelConsumptionRate = 1.0f; // Example value
    CurrentFuelLevel = 100.0f;  // Example value
    DockingStationLocation = FVector::ZeroVector; // Default location
}

// Called when the game starts or when spawned
void AUhuDroneCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AUhuDroneCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Ping Docking Station to get location
void AUhuDroneCharacter::RequestDockingStationLocation()
{
    if (DockingStationReference)
    {
        ADockingStation* DockingStation = Cast<ADockingStation>(DockingStationReference);
        if (DockingStation)
        {
            DockingStationLocation = DockingStation->PingDrone();
            UE_LOG(LogTemp, Warning, TEXT("DockingStation antwortet mit Position: %s"), *DockingStationLocation.ToString());
        }
    }
}
