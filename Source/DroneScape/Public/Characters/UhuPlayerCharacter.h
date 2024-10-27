#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "UhuBaseCharacter.h"
#include "Components/UhuInventoryComponent.h"
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
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	// Variable für die InventoryComponent als TSubclassOf
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
	TSubclassOf<UUhuInventoryComponent> InventoryComponentClass;

	// Pointer auf das InventoryComponent
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	UUhuInventoryComponent* InventoryComponent;

private:
	// Input Actions
	UPROPERTY(EditAnywhere, Category = "Input Actions")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input Actions")
	TObjectPtr<UInputAction> LookAction;

	virtual void InitAbilityActorInfo() override;
};
