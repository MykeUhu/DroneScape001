#include "Controllers/UhuPlayerController.h"

#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Characters/UhuPlayerCharacter.h"
#include "UI/Widgets/UhuChatWindow.h"
#include "Blueprint/UserWidget.h"

AUhuPlayerController::AUhuPlayerController()
{
    bIsSprinting = false;

    // Initialize InputMappingContext
    static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputMappingContextObj(TEXT("/Game/Input/IMC_Default.IMC_Default"));
    if (InputMappingContextObj.Succeeded())
    {
        InputMappingContext = InputMappingContextObj.Object;
    }
}

void AUhuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // Log BeginPlay
    FString BeginPlayMessage = TEXT("AUhuPlayerController::BeginPlay() called.");
    UE_LOG(LogTemp, Warning, TEXT("%s"), *BeginPlayMessage);
    
    // Create and add the chat window to the viewport
    if (ChatWindowClass) // ChatWindowClass ist eine TSubclassOf<UUhuChatWindow>
    {
        UUhuChatWindow* NewChatWindow = CreateWidget<UUhuChatWindow>(this, ChatWindowClass);
        if (NewChatWindow)
        {
            NewChatWindow->AddToViewport();
            ChatWindow = NewChatWindow; // Weist die lokale Variable dem Member zu
        }
    }

    // Ensure the Input Mapping Context is added
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
    {
        if (InputMappingContext)
        {
            Subsystem->AddMappingContext(InputMappingContext, 0); 
            FString InputMappingMessage = TEXT("Input Mapping Context added.");
            UE_LOG(LogTemp, Warning, TEXT("%s"), *InputMappingMessage);
            if (ChatWindow)
            {
                ChatWindow->AddLogMessage(InputMappingMessage);
            }
        }
        else
        {
            FString ErrorMessage = TEXT("Input Mapping Context is null.");
            UE_LOG(LogTemp, Error, TEXT("%s"), *ErrorMessage);
            if (ChatWindow)
            {
                ChatWindow->AddLogMessage(ErrorMessage);
            }
        }
    }
    else
    {
        FString ErrorMessage = TEXT("Failed to get EnhancedInputLocalPlayerSubsystem.");
        UE_LOG(LogTemp, Error, TEXT("%s"), *ErrorMessage);
        if (ChatWindow)
        {
            ChatWindow->AddLogMessage(ErrorMessage);
        }
    }
}

void AUhuPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(Ia_MoveForward, ETriggerEvent::Triggered, this, &AUhuPlayerController::MoveForward);
        EnhancedInputComponent->BindAction(Ia_MoveRight, ETriggerEvent::Triggered, this, &AUhuPlayerController::MoveRight);
        EnhancedInputComponent->BindAction(Ia_Look, ETriggerEvent::Triggered, this, &AUhuPlayerController::Look);
        EnhancedInputComponent->BindAction(Ia_Jump, ETriggerEvent::Triggered, this, &AUhuPlayerController::Jump);
        EnhancedInputComponent->BindAction(Ia_Sprint, ETriggerEvent::Started, this, &AUhuPlayerController::StartSprinting);
        EnhancedInputComponent->BindAction(Ia_Sprint, ETriggerEvent::Completed, this, &AUhuPlayerController::StopSprinting);

        // Log Input Component setup
        FString SetupMessage = TEXT("InputComponent setup completed.");
        UE_LOG(LogTemp, Warning, TEXT("%s"), *SetupMessage);
        if (ChatWindow)
        {
            ChatWindow->AddLogMessage(SetupMessage);
        }
    }
    else
    {
        FString ErrorMessage = TEXT("Failed to cast InputComponent to UEnhancedInputComponent.");
        UE_LOG(LogTemp, Error, TEXT("%s"), *ErrorMessage);
        if (ChatWindow)
        {
            ChatWindow->AddLogMessage(ErrorMessage);
        }
    }
}

void AUhuPlayerController::MoveForward(const FInputActionValue& InputActionValue)
{
    if (AUhuPlayerCharacter* PlayerCharacter = Cast<AUhuPlayerCharacter>(GetPawn()))
    {
        const float Value = InputActionValue.Get<float>();

        // Vorwärtsrichtung basierend auf der Steuerung des Charakters ermitteln
        FRotator PlayerControlRotation = PlayerCharacter->GetControlRotation(); // Umbenannt in PlayerControlRotation
        FVector Direction = FRotationMatrix(PlayerControlRotation).GetScaledAxis(EAxis::X); // Vorwärtsrichtung

        // Hier fügen wir die WASD-Steuerung hinzu
        if (Value != 0.0f)
        {
            PlayerCharacter->AddMovementInput(Direction, Value);
        }

        // Log movement input
        FString MovementMessage = FString::Printf(TEXT("MoveForward called with value: %f"), Value);
        UE_LOG(LogTemp, Warning, TEXT("%s"), *MovementMessage);
        if (ChatWindow)
        {
            ChatWindow->AddLogMessage(MovementMessage);
        }
    }
    else
    {
        FString ErrorMessage = TEXT("Failed to cast Pawn to AUhuPlayerCharacter.");
        UE_LOG(LogTemp, Error, TEXT("%s"), *ErrorMessage);
        if (ChatWindow)
        {
            ChatWindow->AddLogMessage(ErrorMessage);
        }
    }
}


void AUhuPlayerController::MoveRight(const FInputActionValue& InputActionValue)
{
    if (AUhuPlayerCharacter* PlayerCharacter = Cast<AUhuPlayerCharacter>(GetPawn()))
    {
        const float Value = InputActionValue.Get<float>();
        PlayerCharacter->MoveRight(Value);

        // Log movement input
        FString MovementMessage = FString::Printf(TEXT("MoveRight called with value: %f"), Value);
        UE_LOG(LogTemp, Warning, TEXT("%s"), *MovementMessage);
        if (ChatWindow)
        {
            ChatWindow->AddLogMessage(MovementMessage);
        }
    }
    else
    {
        FString ErrorMessage = TEXT("Failed to cast Pawn to AUhuPlayerCharacter.");
        UE_LOG(LogTemp, Error, TEXT("%s"), *ErrorMessage);
        if (ChatWindow)
        {
            ChatWindow->AddLogMessage(ErrorMessage);
        }
    }
}

void AUhuPlayerController::Look(const FInputActionValue& Value)
{
    // Holen Sie sich den LookAxis-Wert
    const FVector2D LookAxis = Value.Get<FVector2D>();

    // Überprüfen, ob der Wert gültig ist, indem wir sicherstellen, dass er nicht NaN ist
    if (!FMath::IsNaN(LookAxis.X) && !FMath::IsNaN(LookAxis.Y))
    {
        // Yaw und Pitch nur bei rechtem Mausklick anpassen
        AddYawInput(LookAxis.X);
        AddPitchInput(LookAxis.Y);

        // Log look input
        FString LookMessage = FString::Printf(TEXT("Look called with value: %s"), *LookAxis.ToString());
        UE_LOG(LogTemp, Warning, TEXT("%s"), *LookMessage);
        if (ChatWindow)
        {
            ChatWindow->AddLogMessage(LookMessage);
        }
    }
    else
    {
        // Log invalid look input
        UE_LOG(LogTemp, Error, TEXT("Look axis value is invalid (NaN)."));
        if (ChatWindow)
        {
            ChatWindow->AddLogMessage(TEXT("Look axis value is invalid (NaN)."));
        }
    }
}

void AUhuPlayerController::Jump()
{
    if (ACharacter* ControlledCharacter = Cast<ACharacter>(GetPawn()))
    {
        ControlledCharacter->Jump();

        // Log jump input
        FString JumpMessage = TEXT("Jump called.");
        UE_LOG(LogTemp, Warning, TEXT("%s"), *JumpMessage);
        if (ChatWindow)
        {
            ChatWindow->AddLogMessage(JumpMessage);
        }
    }
}

void AUhuPlayerController::StartSprinting()
{
    bIsSprinting = true;
    if (AUhuPlayerCharacter* PlayerCharacter = Cast<AUhuPlayerCharacter>(GetPawn()))
    {
        PlayerCharacter->StartSprinting();

        // Log start sprinting
        FString SprintStartMessage = TEXT("StartSprinting called.");
        UE_LOG(LogTemp, Warning, TEXT("%s"), *SprintStartMessage);
        if (ChatWindow)
        {
            ChatWindow->AddLogMessage(SprintStartMessage);
        }
    }
}

void AUhuPlayerController::StopSprinting()
{
    bIsSprinting = false;
    if (AUhuPlayerCharacter* PlayerCharacter = Cast<AUhuPlayerCharacter>(GetPawn()))
    {
        PlayerCharacter->StopSprinting();

        // Log stop sprinting
        FString SprintStopMessage = TEXT("StopSprinting called.");
        UE_LOG(LogTemp, Warning, TEXT("%s"), *SprintStopMessage);
        if (ChatWindow)
        {
            ChatWindow->AddLogMessage(SprintStopMessage);
        }
    }
}
