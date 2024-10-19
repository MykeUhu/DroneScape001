// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UhuNPCCharacter.generated.h"

UCLASS()
class DRONESCAPE_API AUhuNPCCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AUhuNPCCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
