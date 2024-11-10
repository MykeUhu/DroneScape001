// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "UhuInventory.generated.h"

USTRUCT(BlueprintType)
struct FInventoryItem : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FGameplayTag ItemTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 Amount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	FString InventoryName;
};

UCLASS()
class DRONESCAPE_API UUhuInventory : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItemToInventory(FGameplayTag ItemTag, int32 Amount, FString InventoryName);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FInventoryItem* FindItemInInventory(FGameplayTag ItemTag, bool bLogNotFound = true);

private:
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TArray<FInventoryItem> InventoryItems;
};
