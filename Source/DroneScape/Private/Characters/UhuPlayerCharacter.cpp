#include "Characters/UhuPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AUhuPlayerCharacter::AUhuPlayerCharacter()
{
	// Kamerarotation wird von der Controller-Eingabe gesteuert
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = false;

	// SpringArm erstellen und auf Länge 0 für First-Person setzen
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 0.0f;  // Länge 0 für First-Person
	SpringArm->bUsePawnControlRotation = true;  // Kamera dreht sich mit dem Controller

	// Kamera an den SpringArm anhängen
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(SpringArm);  // An den SpringArm heften
	FirstPersonCamera->bUsePawnControlRotation = true;  // Kamera dreht sich mit dem Controller

	// Initial in First-Person-Ansicht
	bIsThirdPersonView = false;
}

void AUhuPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Starten in der First-Person-Ansicht
	SpringArm->TargetArmLength = 0.0f;
}

void AUhuPlayerCharacter::SwitchCamera()
{
	if (SpringArm)
	{
		if (bIsThirdPersonView)
		{
			// Wechsel zur First-Person-Ansicht
			SpringArm->TargetArmLength = 0.0f;  // Kamera nah am Charakter
			bIsThirdPersonView = false;
		}
		else
		{
			// Wechsel zur Third-Person-Ansicht
			SpringArm->TargetArmLength = 300.0f;  // Setze eine sinnvolle Länge für Third-Person
			bIsThirdPersonView = true;
		}
	}
}
