// Copyright by MykeUhu

#include "Characters/UhuBaseCharacter.h"

#include "Characters/UhuPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"

AUhuBaseCharacter::AUhuBaseCharacter()
{
	// Enable replication for multiplayer
	bReplicates = true;
	
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

void AUhuBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Starten in der First-Person-Ansicht
	SpringArm->TargetArmLength = 0.0f;
}

void AUhuBaseCharacter::SwitchCamera()
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

// Replikation setup
void AUhuBaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate the camera view state to other clients
	DOREPLIFETIME(AUhuBaseCharacter, bIsThirdPersonView);
}
