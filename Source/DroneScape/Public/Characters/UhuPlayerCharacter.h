#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"  // Füge dies hinzu
#include "UhuBaseCharacter.h"
#include "UhuPlayerCharacter.generated.h"

class UInputAction;

UCLASS()
class DRONESCAPE_API AUhuPlayerCharacter : public AUhuBaseCharacter
{
	GENERATED_BODY()

public:
	AUhuPlayerCharacter();

protected:
	virtual void BeginPlay() override;

private:
	// Hier definierst du die Input Actions
	UPROPERTY(EditAnywhere, Category = "Input Actions")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input Actions")
	TObjectPtr<UInputAction> LookAction;

	// Weitere Membervariablen und Methoden...
};
