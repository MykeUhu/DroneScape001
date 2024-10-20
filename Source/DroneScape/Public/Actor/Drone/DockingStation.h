#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DockingStation.generated.h"

UCLASS()
class DRONESCAPE_API ADockingStation : public AActor
{
	GENERATED_BODY()

public:
	// Konstruktor
	ADockingStation();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Funktion, um die Drohne zu pingen
	UFUNCTION(BlueprintCallable, Category = "Drone")
	FVector PingDrone();

	// Gibt die aktuelle Position der Docking-Station zurück
	UFUNCTION(BlueprintCallable, Category = "Docking")
	FVector GetCurrentLocation() const;

private:
	// Scene Component als Root
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;

	// Mesh für die Docking-Station
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DockingMesh;
};
