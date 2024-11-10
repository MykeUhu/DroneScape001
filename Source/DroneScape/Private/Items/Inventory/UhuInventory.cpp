// Copyright by MykeUhu

#include "Items/Inventory/UhuInventory.h"

void UUhuInventory::AddItemToInventory(FGameplayTag ItemTag, int32 Amount, FString InventoryName)
{
	if (FInventoryItem* ExistingItem = FindItemInInventory(ItemTag, false))
	{
		ExistingItem->Amount += Amount;
	}
	else
	{
		FInventoryItem NewItem;
		NewItem.ItemTag = ItemTag;
		NewItem.Amount = Amount;
		NewItem.InventoryName = InventoryName;
		InventoryItems.Add(NewItem);
	}
}

FInventoryItem* UUhuInventory::FindItemInInventory(FGameplayTag ItemTag, bool bLogNotFound)
{
	for (FInventoryItem& Item : InventoryItems)
	{
		if (Item.ItemTag.MatchesTagExact(ItemTag))
		{
			return &Item;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find Item for ItemTag [%s] in Inventory."), *ItemTag.ToString());
	}

	return nullptr;
}
