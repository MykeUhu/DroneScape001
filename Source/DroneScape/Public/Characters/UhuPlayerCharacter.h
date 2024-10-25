#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h" 
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
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;


private:
	// Hier definierst du die Input Actions
	UPROPERTY(EditAnywhere, Category = "Input Actions")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input Actions")
	TObjectPtr<UInputAction> LookAction;


	virtual void InitAbilityActorInfo() override;
};
