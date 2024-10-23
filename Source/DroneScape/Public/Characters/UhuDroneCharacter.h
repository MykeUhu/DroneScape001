// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UhuDroneCharacter.generated.h"

// Vorwärtsdeklaration
class UCapsuleComponent;
class UStaticMeshComponent;
class ADockingStation;
class UBehaviorTree;
class AUhuAIController;
class UDroneTaskManager;
class AUhuAIController;

// Drohnen-Charakter-Klasse
UCLASS()
class DRONESCAPE_API AUhuDroneCharacter : public APawn
{
    GENERATED_BODY()

public:
    // Standardkonstruktor
    AUhuDroneCharacter();
    
    // Override for possession by a controller
    virtual void PossessedBy(AController* NewController) override;

protected:
    // Wird aufgerufen, wenn das Spiel startet oder die Instanz erstellt wird
    virtual void BeginPlay() override;

    // AI Behavior Tree
    UPROPERTY(EditAnywhere, Category = "AI")
    TObjectPtr<UBehaviorTree> BehaviorTree;

    // Reference to the AI Controller
    UPROPERTY()
    TObjectPtr<AUhuAIController> UhuAIController;

public:
    // Wird jeden Frame aufgerufen
    virtual void Tick(float DeltaTime) override;
    
    // Components
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCapsuleComponent* CapsuleComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* DroneMesh;
    
    // Notfallmodus aktivieren
    UFUNCTION(BlueprintCallable, Category="Drone")
    void SetEmergencyModeOn();

    // Notfallmodus deaktivieren
    UFUNCTION(BlueprintCallable, Category="Drone")
    void SetEmergencyModeOff();

    // Setze den Status der Drohne
    UFUNCTION(BlueprintCallable, Category="Drone")
    void SetDroneState(bool bIdle, bool bFlying, bool bDocked, bool bFuelSufficient);
    
    // Führt die Aufgabe mit der höchsten Priorität aus
    UFUNCTION(BlueprintCallable, Category="Drone.Task")
    void ExecuteHighestPriorityTask();

private:
    // Handle für das Task-Management
    UPROPERTY(VisibleAnywhere, Category="Drone")
    UDroneTaskManager* DroneTaskManager;
    
    // Notfall-Modus-Flag
    bool bEmergencyReturnMode = false;

    // Status der Drohne
    bool bIsIdle = false;
    bool bIsFlying = false;
    bool bIsDocked = false;
    bool bIsFuelSufficient = false;


};
