#include "Actor/Inventory/UhuInventorySystem.h"

#include "Engine/DataTable.h"

bool UUhuInventorySystem::AddItem(const FGameplayTag& ItemTag, int32 Amount)
{
    if (InventoryItems.Contains(ItemTag))
    {
        InventoryItems[ItemTag] += Amount;
    }
    else
    {
        InventoryItems.Add(ItemTag, Amount);
    }

    return true;
}

bool UUhuInventorySystem::RemoveItem(const FGameplayTag& ItemTag, int32 Amount)
{
    if (InventoryItems.Contains(ItemTag))
    {
        InventoryItems[ItemTag] -= Amount;
        if (InventoryItems[ItemTag] <= 0)
        {
            InventoryItems.Remove(ItemTag);
        }

        return true;
    }

    return false;
}

int32 UUhuInventorySystem::GetItemAmount(const FGameplayTag& ItemTag) const
{
    if (InventoryItems.Contains(ItemTag))
    {
        return InventoryItems[ItemTag];
    }

    return 0;
}

UDataTable* UUhuInventorySystem::GetDataTable() const
{
    return ItemDataTable;
}
