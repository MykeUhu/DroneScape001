// Copyright by MykeUhu

#include "Characters/UhuDroneCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "AI/UhuAIController.h"
#include "Actor/Drone/Tasks/DroneTaskManager.h"
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
    if (UhuAIController && BehaviorTree)
    {
        UhuAIController->GetBlackboardComponent()->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
        UhuAIController->RunBehaviorTree(BehaviorTree);
        UhuAIController->GetBlackboardComponent()->SetValueAsBool(FName("bEmergencyReturnMode"), false);
    }
}

// Called when the game starts or when spawned
void AUhuDroneCharacter::BeginPlay()
{
    Super::BeginPlay();
    
    // Task-Manager initialisieren
    DroneTaskManager = NewObject<UDroneTaskManager>(this);
    if (!DroneTaskManager)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create DroneTaskManager!"));
        return; // Abbrechen, wenn die Initialisierung fehlschlägt
    }

    // Füge anfängliche Aufgaben hinzu
    DroneTaskManager->AddTask(TEXT("Inspect Area"), 1, 5.0f); // Dauer in Sekunden
    DroneTaskManager->AddTask(TEXT("Build Base"), 2, 10.0f);
    DroneTaskManager->AddTask(TEXT("Resource Management"), 3, 3.0f);
}

// Called every frame
void AUhuDroneCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Aktualisiere die Aufgabenliste
    if (DroneTaskManager)
    {
        DroneTaskManager->UpdateTaskList(); // Aktualisiere die Aufgaben

        // Überprüfen und Ausführen der höchsten Prioritätsaufgabe
        ExecuteHighestPriorityTask();
    }
}

void AUhuDroneCharacter::SetEmergencyModeOn()
{
    bEmergencyReturnMode = true; // Setze die Instanzvariable
    if (UhuAIController)
    {
        UhuAIController->GetBlackboardComponent()->SetValueAsBool(FName("bEmergencyReturnMode"), bEmergencyReturnMode); // Setze den Wert im Blackboard
    }
}

void AUhuDroneCharacter::SetEmergencyModeOff()
{
    bEmergencyReturnMode = false; // Setze die Instanzvariable
    if (UhuAIController)
    {
        UhuAIController->GetBlackboardComponent()->SetValueAsBool(FName("bEmergencyReturnMode"), bEmergencyReturnMode); // Setze den Wert im Blackboard
    }
}

void AUhuDroneCharacter::SetDroneState(bool bIdle, bool bFlying, bool bDocked, bool bFuelSufficient)
{
    this->bIsIdle = bIdle;
    this->bIsFlying = bFlying;
    this->bIsDocked = bDocked;
    this->bIsFuelSufficient = bFuelSufficient;

    // Blackboard
    if (UhuAIController)
    {
        UhuAIController->GetBlackboardComponent()->SetValueAsBool(FName("bIsIdle"), this->bIsIdle);
        UhuAIController->GetBlackboardComponent()->SetValueAsBool(FName("bIsFlying"), this->bIsFlying);
        UhuAIController->GetBlackboardComponent()->SetValueAsBool(FName("bIsDocked"), this->bIsDocked);
        UhuAIController->GetBlackboardComponent()->SetValueAsBool(FName("bIsFuelSufficient"), this->bIsFuelSufficient);
    }
}

void AUhuDroneCharacter::ExecuteHighestPriorityTask()
{
    if (DroneTaskManager)
    {
        // Get the task list from the Task Manager
        const TArray<FDroneTask>& TaskList = DroneTaskManager->GetTaskList();

        // Logik für das Ausführen der höchsten Prioritätsaufgabe hier implementieren
        // Beispiel: Finde die Aufgabe mit der höchsten Priorität und führe sie aus.
        int32 HighestPriorityIndex = -1;
        int32 HighestPriority = -1;

        for (int32 i = 0; i < TaskList.Num(); ++i)
        {
            if (TaskList[i].bIsActive && TaskList[i].Priority > HighestPriority)
            {
                HighestPriority = TaskList[i].Priority;
                HighestPriorityIndex = i;
            }
        }

        // Führe die höchste Prioritätsaufgabe aus
        if (HighestPriorityIndex != -1)
        {
            // Hier kann die Logik zur Ausführung der Aufgabe hinzugefügt werden
            UE_LOG(LogTemp, Log, TEXT("Executing Task: %s"), *TaskList[HighestPriorityIndex].TaskName);
            // Beispiel: Aufgabe ausführen (deaktiviere oder ändere sie, je nach Logik)
            DroneTaskManager->ChangeTaskPriority(TaskList[HighestPriorityIndex].TaskName, 0); // Deaktivieren
        }
    }
}
