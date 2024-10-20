#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "UhuDroneCharacter.generated.h"

class UCapsuleComponent;
class UStaticMeshComponent;
class AActor;
class ADockingStation;
class UBehaviorTree;     // Fügt die Behavior Tree Klasse hinzu
class UBlackboardData;   // Fügt die Blackboard Klasse hinzu

UCLASS()
class DRONESCAPE_API AUhuDroneCharacter : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    AUhuDroneCharacter();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Components
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UCapsuleComponent* CapsuleComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* DroneMesh;

    // Docking Station Reference
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Docking")
    AActor* DockingStationReference;

    // Docking Station Location
    UPROPERTY(BlueprintReadOnly, Category = "Docking")
    FVector DockingStationLocation;

    // Funktion zum Pingen der Dockingstation
    UFUNCTION(BlueprintCallable, Category = "Docking")
    void RequestDockingStationLocation();

    // Blackboard and Behavior Tree
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    UBehaviorTree* BehaviorTreeAsset;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    UBlackboardData* BlackboardAsset;

private:
    float FuelConsumptionRate;
    float CurrentFuelLevel;
};
