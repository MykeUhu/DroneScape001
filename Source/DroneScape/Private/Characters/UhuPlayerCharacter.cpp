#include "Characters/UhuPlayerCharacter.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/Vector2D.h"

AUhuPlayerCharacter::AUhuPlayerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    
    SpringArm->TargetArmLength = 350.0f; // Set to approximately 3.5 meters
    SpringArm->bUsePawnControlRotation = false; // SpringArm NOT follows controller rotation

    SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 150.0f)); // Offset for better visibility
    SpringArm->SetRelativeRotation(FRotator(-20.0f, 0.0f, 0.0f)); // Tilt for a better angle

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false; // Camera does not follow controller rotation

    // Set default movement settings
    GetCharacterMovement()->bOrientRotationToMovement = true; // Character rotates towards movement direction
    bUseControllerRotationYaw = false; // Disable controller rotation
}

void AUhuPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}


void AUhuPlayerCharacter::StartSprinting() const
{
    // Hier logik für Sprinting einfügen
    GetCharacterMovement()->MaxWalkSpeed *= SprintMultiplier; // Maximalgeschwindigkeit erhöhen
    UE_LOG(LogTemp, Warning, TEXT("Sprinting started."));
}

void AUhuPlayerCharacter::StopSprinting() const
{
    // Hier logik für Stop Sprinting einfügen
    GetCharacterMovement()->MaxWalkSpeed /= SprintMultiplier; // Maximalgeschwindigkeit zurücksetzen
    UE_LOG(LogTemp, Warning, TEXT("Sprinting stopped."));
}

void AUhuPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}
