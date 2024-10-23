// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardData.h"
#include "GameFramework/Pawn.h"
#include "UhuDroneCharacter.generated.h"

class UCapsuleComponent;
class UStaticMeshComponent;
class ADockingStation;
class UBehaviorTree;
class AUhuAIController;

USTRUCT(BlueprintType)
struct FDroneTask
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category="Task")
    FString TaskName;

    UPROPERTY(BlueprintReadWrite, Category="Task")
    int32 Priority = 0;

    UPROPERTY(BlueprintReadWrite, Category="Task")
    bool bIsActive = false;
};

UCLASS()
class DRONESCAPE_API AUhuDroneCharacter : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    AUhuDroneCharacter();

    // Override for possession by a controller
    virtual void PossessedBy(AController* NewController) override;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // AI Behavior Tree
    UPROPERTY(EditAnywhere, Category = "AI")
    TObjectPtr<UBehaviorTree> BehaviorTree;

    // Reference to the AI Controller
    UPROPERTY()
    TObjectPtr<AUhuAIController> UhuAIController;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Components
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCapsuleComponent* CapsuleComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* DroneMesh;

    // Emergency Mode
    UFUNCTION(BlueprintCallable, Category = "Emergency")
    void SetEmergencyModeOff() const;

    UPROPERTY(BlueprintReadWrite, Category = "PlayTest")
    bool bEmergencyReturnMode;

    UFUNCTION(BlueprintCallable, Category = "Emergency")
    void SetEmergencyModeOn() const;

    // Drone State
    UPROPERTY(BlueprintReadWrite, Category="State")
    bool bIsIdle;

    UPROPERTY(BlueprintReadWrite, Category="State")
    bool bIsFlying;

    UPROPERTY(BlueprintReadWrite, Category="State")
    bool bIsDocked;

    UPROPERTY(BlueprintReadWrite, Category="State")
    bool bIsFuelSufficient;

    // Function to set the drone's state
    UFUNCTION(BlueprintCallable, Category="State")
    void SetDroneState(bool bIdle, bool bFlying, bool bDocked, bool bFuelSufficient);

    // Task Management
    UPROPERTY(BlueprintReadWrite, Category="Tasks")
    TArray<FDroneTask> TaskList;

    // Function to add a task
    UFUNCTION(BlueprintCallable, Category="Tasks")
    void AddTask(FString TaskName, int32 Priority);

    // Function to update task priorities
    UFUNCTION(BlueprintCallable, Category="Tasks")
    void UpdateTaskPriority();

    // Function to execute the highest priority task
    UFUNCTION(BlueprintCallable, Category="Tasks")
    void ExecuteHighestPriorityTask();
};
