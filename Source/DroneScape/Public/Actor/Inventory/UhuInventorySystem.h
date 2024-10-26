#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "UhuInventorySystem.generated.h"

// Struktur für Inventaritems
USTRUCT(BlueprintType)
struct FUhuInventoryItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FGameplayTag ItemTag; // Tag für das Item

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 Amount; // Menge des Items
	// Standardkonstruktor
	
};

// Inventar-System-Klasse
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DRONESCAPE_API UUhuInventorySystem : public UActorComponent
{
	GENERATED_BODY()

public:
	UUhuInventorySystem();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(const FGameplayTag& ItemTag, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItem(const FGameplayTag& ItemTag, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int32 GetItemAmount(const FGameplayTag& ItemTag) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	const TArray<FUhuInventoryItem>& GetInventory() const;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	TArray<FUhuInventoryItem> Inventory;

	FUhuInventoryItem* FindItem(const FGameplayTag& ItemTag);
};
