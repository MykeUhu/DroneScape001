#include "Controllers/UhuPlayerController.h"

#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Characters/UhuPlayerCharacter.h"
#include "UI/Widgets/UhuChatWindow.h"
//#include "Blueprint/UserWidget.h"
#include "UI/Widgets/UhuUserWidget.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "Math/Vector2D.h"


void AUhuPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (UEnhancedInputLocalPlayerSubsystem* Subsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
    {
        // Füge hier deinen Input-Mapping-Kontext hinzu
        Subsystem->AddMappingContext(InputMappingContext, 0);
    }
    
    // Log BeginPlay
    FString BeginPlayMessage = TEXT("AUhuPlayerController::BeginPlay() called.");
    UE_LOG(LogTemp, Warning, TEXT("%s"), *BeginPlayMessage);
    
    // Create and add the chat window to the viewport
    if (ChatWindowClass)
    {
        UUhuChatWindow* NewChatWindow = CreateWidget<UUhuChatWindow>(this, ChatWindowClass);
        if (NewChatWindow)
        {
            NewChatWindow->AddToViewport();
            ChatWindow = NewChatWindow;
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



AUhuPlayerController::AUhuPlayerController(): Ia_MoveForward(nullptr), Ia_MoveRight(nullptr), Ia_Jump(nullptr),
                                              Ia_Sprint(nullptr),
                                              Ia_Look(nullptr),
                                              ChatWindow(nullptr)
{
    PrimaryActorTick.bCanEverTick = true;
    bIsSprinting = false;
    bIsLooking = false;

    // Initialize InputMappingContext
    static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputMappingContextObj(
        TEXT("/Game/Input/IMC_Default.IMC_Default"));
    if (InputMappingContextObj.Succeeded())
    {
        InputMappingContext = InputMappingContextObj.Object;
    }
}

void AUhuPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    // Ändere den Namen der lokalen Variable
    FRotator CurrentControlRotation = GetControlRotation();
    CurrentControlRotation.Pitch = 0; // Setze die Pitch auf 0, um vertikales Drehen zu vermeiden
    
    // Setze die Rotation des Player Characters
    GetPawn()->SetActorRotation(CurrentControlRotation);
}



void AUhuPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    
    
    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
    {
        // Movement
        EnhancedInputComponent->BindAction(Ia_MoveForward, ETriggerEvent::Triggered, this, &AUhuPlayerController::MoveForward);
        EnhancedInputComponent->BindAction(Ia_MoveRight, ETriggerEvent::Triggered, this, &AUhuPlayerController::MoveRight);
        EnhancedInputComponent->BindAction(Ia_Jump, ETriggerEvent::Started, this, &AUhuPlayerController::Jump);
        EnhancedInputComponent->BindAction(Ia_Sprint, ETriggerEvent::Started, this, &AUhuPlayerController::StartSprinting);
        EnhancedInputComponent->BindAction(Ia_Sprint, ETriggerEvent::Completed, this, &AUhuPlayerController::StopSprinting);

        // Look action (2D Vector axis)
        EnhancedInputComponent->BindAction(Ia_Look, ETriggerEvent::Started, this, &AUhuPlayerController::StartLooking);
        EnhancedInputComponent->BindAction(Ia_Look, ETriggerEvent::Completed, this, &AUhuPlayerController::StopLooking);
        EnhancedInputComponent->BindAction(Ia_Look, ETriggerEvent::Triggered, this, &AUhuPlayerController::LookAround);
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
        const FRotator PlayerControlRotation = PlayerCharacter->GetControlRotation(); // Umbenannt in PlayerControlRotation
        const FVector Direction = FRotationMatrix(PlayerControlRotation).GetScaledAxis(EAxis::X); // Vorwärtsrichtung

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

        // Vorwärtsrichtung basierend auf der Steuerung des Charakters ermitteln
        FRotator PlayerControlRotation = PlayerCharacter->GetControlRotation(); // Umbenannt in PlayerControlRotation
        FVector Direction = FRotationMatrix(PlayerControlRotation).GetScaledAxis(EAxis::Y); // Rechtliche Richtung

        // Hier fügen wir die WASD-Steuerung hinzu
        if (Value != 0.0f)
        {
            PlayerCharacter->AddMovementInput(Direction, Value);
        }

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

// Start looking around
void AUhuPlayerController::StartLooking(const FInputActionValue& Value)
{
    bIsLooking = true;
    LookAround(Value);

    UE_LOG(LogTemp, Warning, TEXT("Started looking, bIsLooking = true"));
    
}

// Stop looking around
void AUhuPlayerController::StopLooking()
{
    bIsLooking = false;
    UE_LOG(LogTemp, Warning, TEXT("Stopped looking, bIsLooking = false"));
}

// Handle looking around
void AUhuPlayerController::LookAround(const FInputActionValue& Value)
{
    FVector2D CursorPosition;
    GetCursorPosition(CursorPosition);
    
    FVector2D LookInput = Value.Get<FVector2D>(); // Hole die Eingaben für die Mausbewegung

    if (AUhuPlayerCharacter* PlayerCharacter = Cast<AUhuPlayerCharacter>(GetPawn()))
    {
        // Überprüfen, ob wir gültige Eingaben haben
        if (LookInput.SizeSquared() > 0)
        {
            PlayerCharacter->AddControllerYawInput(LookInput.X);  // Yaw (Drehung) basierend auf der Eingabe
            PlayerCharacter->AddControllerPitchInput(LookInput.Y); // Pitch (Neigung) basierend auf der Eingabe
            
            UE_LOG(LogTemp, Warning, TEXT("LookAroundX: %f, LookAroundY: %f"), LookInput.X, LookInput.Y);
        }
    }
}

void AUhuPlayerController::GetCursorPosition(FVector2D& OutCursorPosition)
{
    float MouseX, MouseY;
    if (GetMousePosition(MouseX, MouseY))
    {
        OutCursorPosition = FVector2D(MouseX, MouseY);
        UE_LOG(LogTemp, Warning, TEXT("Cursor Position: X: %f, Y: %f"), MouseX, MouseY);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to get cursor position"));
    }
}