// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "UhuBaseCharacter.generated.h"

UCLASS()
class DRONESCAPE_API AUhuBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AUhuBaseCharacter();

	virtual void BeginPlay() override;

	// Kameraperspektive wechseln
	void SwitchCamera();

protected:
	// Replikation für die Kameraperspektive
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	// Kamera-Komponenten
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> FirstPersonCamera;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArm;  // SpringArm für Third-Person

	// ViewSettings
	UPROPERTY(Replicated)  // Damit diese Variable repliziert wird
	bool bIsThirdPersonView;  // Flag für die aktuelle Kameraperspektive
};
