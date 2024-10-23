#include "Characters/UhuDroneCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
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
    bEmergencyReturnMode = false;
}

// Called every frame
void AUhuDroneCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// PlayTest
bool bEmergencyMode = false;

void AUhuDroneCharacter::SetEmergencyModeOn() const
{
    bEmergencyMode = true; // Setze die Instanzvariable
    UhuAIController->GetBlackboardComponent()->SetValueAsBool(FName("bEmergencyReturnMode"), bEmergencyMode); // Setze den Wert im Blackboard
}

void AUhuDroneCharacter::SetEmergencyModeOff() const
{
    bEmergencyMode = false; // Setze die Instanzvariable
    UhuAIController->GetBlackboardComponent()->SetValueAsBool(FName("bEmergencyReturnMode"), bEmergencyMode); // Setze den Wert im Blackboard
}

void AUhuDroneCharacter::SetDroneState(const bool bIdle, const bool bFlying, const bool bDocked, const bool bFuelSufficient)
{
    bIsIdle = bIdle;
    bIsFlying = bFlying;
    bIsDocked = bDocked;
    bIsFuelSufficient = bFuelSufficient;
}

void AUhuDroneCharacter::AddTask(FString TaskName, const int32 Priority)
{
    FDroneTask NewTask;
    NewTask.TaskName = TaskName;
    NewTask.Priority = Priority;
    NewTask.bIsActive = false;
    TaskList.Add(NewTask);
}

void AUhuDroneCharacter::UpdateTaskPriority()
{
    TaskList.Sort([](const FDroneTask& A, const FDroneTask& B)
    {
        return A.Priority < B.Priority;
    });
}

void AUhuDroneCharacter::ExecuteHighestPriorityTask()
{
    if (TaskList.Num() > 0)
    {
        auto& [TaskName, Priority, bIsActive] = TaskList[0];
        bIsActive = true;
        // Logik zum Ausführen der Aufgabe hier hinzufügen
        UE_LOG(LogTemp, Warning, TEXT("Executing Task: %s"), *TaskName);
    }
}