#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "Math/Vector2D.h"
#include "UhuPlayerController.generated.h"

class UInputMappingContext;
class UUhuChatWindow;

UCLASS()
class DRONESCAPE_API AUhuPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AUhuPlayerController();

    virtual void Tick(float DeltaTime) override;
    virtual void SetupInputComponent() override;

protected:
    virtual void BeginPlay() override;

    void LookAround(const FInputActionValue& Value);
    void GetCursorPosition(FVector2D& OutCursorPosition);

private:
    UFUNCTION(BlueprintCallable, Category = "Input")
    void MoveForward(const FInputActionValue& InputActionValue);

    UFUNCTION(BlueprintCallable, Category = "Input")
    void MoveRight(const FInputActionValue& InputActionValue);

    UFUNCTION(BlueprintCallable, Category = "Input")
    void Jump();

    UFUNCTION(BlueprintCallable, Category = "Input")
    void StartSprinting();

    UFUNCTION(BlueprintCallable, Category = "Input")
    void StopSprinting();
    
    UFUNCTION(BlueprintCallable, Category = "Input")
    void StartLooking(const FInputActionValue& Value);

    UFUNCTION(BlueprintCallable, Category = "Input")
    void StopLooking();
    
    // Input Mapping Context
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputMappingContext* InputMappingContext;

    // Input
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* Ia_MoveForward;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* Ia_MoveRight;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* Ia_Jump;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* Ia_Sprint;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* Ia_Look;
    
    // Chat window UI
    UPROPERTY(EditDefaultsOnly, Category = "UI")
    TSubclassOf<UUhuChatWindow> ChatWindowClass;

    UUhuChatWindow* ChatWindow;

    bool bIsSprinting; // Flag for sprinting
    bool bIsLooking; // Flag for looking

};
