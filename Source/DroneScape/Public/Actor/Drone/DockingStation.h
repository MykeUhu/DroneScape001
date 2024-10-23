#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DockingStation.generated.h"

class UStaticMeshComponent;
class USceneComponent;
class AUhuDroneCharacter;

UCLASS()
class DRONESCAPE_API ADockingStation : public AActor
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
	// Scene Root Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneRoot;

	// Docking Mesh Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* DockingMesh;
};
