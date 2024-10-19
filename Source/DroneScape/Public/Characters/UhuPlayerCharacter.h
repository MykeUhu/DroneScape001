#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "UhuPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class DRONESCAPE_API AUhuPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AUhuPlayerCharacter();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	// Movement
	void StartSprinting() const;
	void StopSprinting() const;

protected:
	virtual void BeginPlay() override;


private:
	float SprintMultiplier = 1.5f; // Beispielwert für Sprintgeschwindigkeit

	// Camera components
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	UCameraComponent* Camera;
	
};
