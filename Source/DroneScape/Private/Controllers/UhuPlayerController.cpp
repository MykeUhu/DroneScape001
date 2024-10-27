#include "Controllers/UhuPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Blueprint/UserWidget.h"
#include "Characters/UhuBaseCharacter.h"
#include "UI/Widgets/UhuInventoryWidget.h"

AUhuPlayerController::AUhuPlayerController()
{
    bReplicates = true;
    bShowMouseCursor = false;
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

    if (InventoryWidgetClass)
    {
        InventoryWidget = CreateWidget<UUhuInventoryWidget>(this, InventoryWidgetClass);
        if (InventoryWidget)
        {
            InventoryWidget->AddToViewport();
            InventoryWidget->InitializeInventoryWidget();
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("InventoryWidget konnte nicht erstellt werden!"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("InventoryWidgetClass ist nicht gesetzt!"));
    }
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

    AddYawInput(LookAxisVector.X);
    AddPitchInput(LookAxisVector.Y);
}

void AUhuPlayerController::SwitchCamera()
{
    if (AUhuBaseCharacter* BaseCharacter = Cast<AUhuBaseCharacter>(GetPawn()))
    {
        BaseCharacter->SwitchCamera();
    }
}
