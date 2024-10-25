#include "Controllers/UhuPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "Math/Vector2D.h"
#include "Characters/UhuBaseCharacter.h" 

class AUhuBaseHud;
class AUhuDroneCharacter;

AUhuPlayerController::AUhuPlayerController() 
{
	bReplicates = true;
	bShowMouseCursor = false;  // In First-Person wird der Mauszeiger nicht angezeigt.
	DefaultMouseCursor = EMouseCursor::None;
}

void AUhuPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(InputMappingContext, 0);

	FInputModeGameOnly InputModeData;
	SetInputMode(InputModeData);
}

void AUhuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AUhuPlayerController::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AUhuPlayerController::Look);
	EnhancedInputComponent->BindAction(SwitchCameraAction, ETriggerEvent::Completed, this, &AUhuPlayerController::SwitchCamera);
}

void AUhuPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AUhuPlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	// Use AddYawInput and AddPitchInput to rotate the camera in first-person mode
	AddYawInput(LookAxisVector.X);  // Horizontal mouse movement controls Yaw
	AddPitchInput(LookAxisVector.Y);  // Vertical mouse movement controls Pitch
}

void AUhuPlayerController::SwitchCamera()
{
	// Hole den PlayerCharacter und rufe dessen SwitchCamera-Funktion auf
	if (AUhuBaseCharacter* BaseCharacter = Cast<AUhuBaseCharacter>(GetPawn()))  // Ändere den Cast hier
	{
		BaseCharacter->SwitchCamera();
	}
}
