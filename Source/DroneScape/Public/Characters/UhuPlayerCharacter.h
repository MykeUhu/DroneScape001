#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "UhuPlayerCharacter.generated.h"

UCLASS()
class DRONESCAPE_API AUhuPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AUhuPlayerCharacter();

	virtual void BeginPlay() override;

	// Kameraperspektive wechseln (wird von AUhuPlayerController aufgerufen)
	void SwitchCamera();

private:
	// Kamera-Komponenten
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> FirstPersonCamera;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArm;  // SpringArm für Third-Person

	// ViewSettings
	bool bIsThirdPersonView;  // Flag für die aktuelle Kameraperspektive
};
