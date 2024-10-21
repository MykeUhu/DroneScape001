#include "Characters/UhuDroneCharacter.h"
#include "EngineUtils.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Actor/Drone/DockingStation.h"
#include "AI/UhuAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

// Sets default values
AUhuDroneCharacter::AUhuDroneCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Initialize components
    CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
    RootComponent = CapsuleComponent;

    DroneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DroneMesh"));
    DroneMesh->SetupAttachment(RootComponent);
}

void AUhuDroneCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    if (!HasAuthority()) return;
    UhuAIController = Cast<AUhuAIController>(NewController);
    UhuAIController->GetBlackboardComponent()->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
    UhuAIController->RunBehaviorTree(BehaviorTree);

    // Blackboard !!!
    UhuAIController->GetBlackboardComponent()->SetValueAsBool(FName("bEmergencyReturnMode"), false);
}

// Called when the game starts or when spawned
void AUhuDroneCharacter::BeginPlay()
{
    Super::BeginPlay();

    // Start pinging the Docking Station
    PingDockingStation();
    bEmergencyReturnMode = false;
}

// Function to ping the Docking Station until it responds
void AUhuDroneCharacter::PingDockingStation()
{
    // Check if the Docking Station has already been found
    if (bIsDockingStationFound)
    {
        return; // Exit if already found
    }

    // Search for the Docking Station
    for (TActorIterator<ADockingStation> It(GetWorld()); It; ++It)
    {
        ADockingStation* Actor = *It;
        if (Actor)
        {
            DockingStationReference = Actor;
            bIsDockingStationFound = true; // Set flag to true
            UE_LOG(LogTemp, Warning, TEXT("Docking Station found: %s"), *DockingStationReference->GetName());

            // Request the Docking Station's location
            FVector DockingLocation = RequestDockingStationLocation();
            UE_LOG(LogTemp, Warning, TEXT("Docking Station location: %s"), *DockingLocation.ToString());

            return; // Exit after finding the Docking Station
        }
    }

    // If not found, continue pinging after a delay
    GetWorld()->GetTimerManager().SetTimer(PingTimerHandle, this, &AUhuDroneCharacter::PingDockingStation, 1.0f, false);
}

// Responds to the request for the Docking Station's location
FVector AUhuDroneCharacter::RequestDockingStationLocation()
{
    if (DockingStationReference)
    {
        return DockingStationReference->RespondToSignal(); // Call the response function in Docking Station
    }

    return FVector::ZeroVector; // Return a default value if not set
}

// Called every frame
void AUhuDroneCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// PlayTest
void AUhuDroneCharacter::SetEmergencyReturnMode(bool bEmergencyMode)
{
    bEmergencyMode = true; // Setze die Instanzvariable
    UhuAIController->GetBlackboardComponent()->SetValueAsBool(FName("bEmergencyReturnMode"), bEmergencyMode); // Setze den Wert im Blackboard
}