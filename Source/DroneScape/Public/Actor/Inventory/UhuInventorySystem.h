#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "UhuInventorySystem.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DRONESCAPE_API UUhuInventorySystem : public UActorComponent
{
	GENERATED_BODY()

public:
	bool AddItem(const FGameplayTag& ItemTag, int32 Amount);
	bool RemoveItem(const FGameplayTag& ItemTag, int32 Amount);
	int32 GetItemAmount(const FGameplayTag& ItemTag) const;
	UDataTable* GetDataTable() const;

private:
	UPROPERTY()
	TMap<FGameplayTag, int32> InventoryItems;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	UDataTable* ItemDataTable;
};
