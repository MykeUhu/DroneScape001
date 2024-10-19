#include "Characters/UhuPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AUhuPlayerCharacter::AUhuPlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // Create a camera boom (pulls in towards the player if there is a collision)
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    SpringArmComponent->SetupAttachment(RootComponent);
    SpringArmComponent->TargetArmLength = 300.0f; // The camera follows at this distance behind the character
    SpringArmComponent->bUsePawnControlRotation = true; // Rotate the arm based on the controller

    // Create a follow camera
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
    CameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

    // Configure character movement
    GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
    GetCharacterMovement()->JumpZVelocity = 600.f;
    GetCharacterMovement()->AirControl = 0.2f;

    bIsSprinting = false;
}

void AUhuPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AUhuPlayerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AUhuPlayerCharacter::MoveForward(const FInputActionValue& Value)
{
    if (Controller && Value.Get<float>() != 0.0f)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // Get forward vector
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value.Get<float>());
    }
}

void AUhuPlayerCharacter::MoveRight(const FInputActionValue& Value)
{
    if (Controller && Value.Get<float>() != 0.0f)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        // Get right vector
        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value.Get<float>());
    }
}

void AUhuPlayerCharacter::Look(const FInputActionValue& Value)
{
    AddControllerYawInput(Value.Get<FVector2D>().X);
    AddControllerPitchInput(Value.Get<FVector2D>().Y);
}

void AUhuPlayerCharacter::StartSprinting()
{
    bIsSprinting = true;
    GetCharacterMovement()->MaxWalkSpeed *= 2;
}

void AUhuPlayerCharacter::StopSprinting()
{
    bIsSprinting = false;
    GetCharacterMovement()->MaxWalkSpeed /= 2;
}
