#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Actor/Inventory/UhuInventorySystem.h"
#include "UhuInventoryComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DRONESCAPE_API UUhuInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UUhuInventoryComponent();

	// Fügt ein Item hinzu, falls es in den erlaubten Tags ist
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItem(const FGameplayTag& ItemTag, int32 Amount) const;

	// Entfernt ein Item, falls es in den erlaubten Tags ist
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItem(const FGameplayTag& ItemTag, int32 Amount) const;

	// Gibt die Menge eines Items im Inventar zurück
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int32 GetItemAmount(const FGameplayTag& ItemTag) const;

	// Übergibt Items an ein anderes Inventar
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool TransferItemTo(UUhuInventoryComponent* TargetInventory, const FGameplayTag& ItemTag, int32 Amount);

protected:
	virtual void BeginPlay() override;

private:
	// Referenz zum zentralen Inventarsystem
	UUhuInventorySystem* InventorySystem;

	// Tag zur Identifizierung des Inventartyps
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	FGameplayTag InventoryTag;

	// Liste der erlaubten Item-Tags
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TArray<FGameplayTag> AllowedItemTags;

	// Hilfsfunktion, um die Erlaubnis zu überprüfen
	bool IsItemAllowed(const FGameplayTag& ItemTag) const;
};
