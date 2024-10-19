#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "UhuPlayerController.generated.h"

UCLASS()
class DRONESCAPE_API AUhuPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AUhuPlayerController();

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

    // Umbenennen von ControlRotation zu CustomControlRotation
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera")
    FRotator CustomControlRotation; 

private:
    // Input actions
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
    UInputAction* Ia_MoveForward;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
    UInputAction* Ia_MoveRight;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
    UInputAction* Ia_Look;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
    UInputAction* Ia_Jump;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
    UInputAction* Ia_Sprint;

    // Input mapping context
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
    UInputMappingContext* InputMappingContext;

    // Sprinting state
    bool bIsSprinting;

    // Chat window reference
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
    TSubclassOf<class UUhuChatWindow> ChatWindowClass;

    UPROPERTY()
    UUhuChatWindow* ChatWindow;

    // Input handling functions
    void MoveForward(const FInputActionValue& InputActionValue);
    void MoveRight(const FInputActionValue& InputActionValue);
    void Look(const FInputActionValue& Value);
    void Jump();
    void StartSprinting();
    void StopSprinting();
};
