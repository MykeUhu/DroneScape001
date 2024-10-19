// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UhuDialogManager.generated.h"

UCLASS()
class DRONESCAPE_API AUhuDialogManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUhuDialogManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
