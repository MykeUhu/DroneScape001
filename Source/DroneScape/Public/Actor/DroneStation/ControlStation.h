#pragma once

#include "CoreMinimal.h"
#include "BaseStation.h"
#include "ControlStation.generated.h"

class UStaticMeshComponent;

UCLASS()
class DRONESCAPE_API AControlStation : public ABaseStation
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AControlStation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Control Panel Mesh Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ControlPanelMesh;
};
