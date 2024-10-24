#pragma once

#include "CoreMinimal.h"
#include "BaseStation.h"
#include "GameFramework/Actor.h"
#include "DockingStation.generated.h"

class UStaticMeshComponent;
class AUhuDroneCharacter;
class UStaticMeshComponent;

UCLASS()
class DRONESCAPE_API ADockingStation : public ABaseStation
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADockingStation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Docking Mesh Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* DockingMesh;
};