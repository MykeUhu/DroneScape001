#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "UhuPlayerController.generated.h"

class UUhuWidgetController;
class UInputMappingContext;
class UUhuChatWindow;
class UEnhancedInputComponent;
class UInputAction;
struct FInputActionValue;

UCLASS()
class DRONESCAPE_API AUhuPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AUhuPlayerController();

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

private:
    // Input Actions Begin
    UPROPERTY(EditAnywhere, Category = "Input Actions")
    TObjectPtr<UInputMappingContext> InputMappingContext;

    UPROPERTY(EditAnywhere, Category = "Input Actions")
    TObjectPtr<UInputAction> MoveAction;

    UPROPERTY(EditAnywhere, Category = "Input Actions")
    TObjectPtr<UInputAction> LookAction;

    UPROPERTY(EditAnywhere, Category = "Input Actions")
    TObjectPtr<UInputAction> SwitchCameraAction;

    void Move(const FInputActionValue& InputActionValue);
    void Look(const FInputActionValue& InputActionValue);
    
    void SwitchCamera();
};
