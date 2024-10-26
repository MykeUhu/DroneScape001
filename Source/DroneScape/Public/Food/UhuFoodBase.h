#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Abilities/UhuAbilitySystemComponent.h"
#include "GameFramework/Actor.h"
#include "Actor/Inventory/UhuItemData.h"
#include "UhuFoodBase.generated.h"

/* Boilerplate bei neuen Effekten
 * Datatable anpassen
 * Gameplayeffekte checken
 */

UCLASS()
class DRONESCAPE_API AUhuFoodBase : public AActor
{
	GENERATED_BODY()

public:
	AUhuFoodBase();

protected:
	virtual void BeginPlay() override;

public:
	// Name des Nahrungsmittels
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Food")
	FString FoodName;

	// Verweis auf die DataTable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Food")
	UDataTable* FoodDataTable;

	// Ability System Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	UUhuAbilitySystemComponent* AbilitySystemComponent;

	// Hilfsfunktion zum Laden der Nahrungsmitteldaten
	UFUNCTION(BlueprintCallable, Category = "Food")
	bool LoadFoodData(FUhuItemData& OutFoodData) const;

	// Konsumieren-Funktion
	UFUNCTION(BlueprintCallable, Category = "Food")
	void Consume();
};