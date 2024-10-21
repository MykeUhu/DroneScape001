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

UCLASS()
class DRONESCAPE_API AUhuDroneCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AUhuDroneCharacter();

	// Posses override
	virtual void PossessedBy(AController* NewController) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

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

	// Reference to the Docking Station
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Docking")
	ADockingStation* DockingStationReference = nullptr; // Initialized as nullptr

	// Indicates if the Docking Station has been found
	UPROPERTY(BlueprintReadOnly, Category = "Docking")
	bool bIsDockingStationFound = false;

	// Sends a ping to the Docking Station until it responds
	UFUNCTION(BlueprintCallable, Category = "Docking")
	void PingDockingStation();

	// PlayTest
	UFUNCTION(BlueprintCallable, Category = "Emergency")
	void SetEmergencyReturnMode(bool bEmergencyMode);
	
	UPROPERTY(BlueprintReadWrite, Category = "PlayTest")
	bool bEmergencyReturnMode;

private:
	// Timer handle for pinging
	FTimerHandle PingTimerHandle;

	// Responds to the Docking Station's location request
	FVector RequestDockingStationLocation();


};
