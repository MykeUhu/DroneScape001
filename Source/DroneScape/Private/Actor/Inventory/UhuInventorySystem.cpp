#include "Actor/Inventory/UhuInventorySystem.h"
#include "GameplayTagContainer.h"

// Überlade den == Operator für FUhuInventoryItem
bool operator==(const FUhuInventoryItem& A, const FUhuInventoryItem& B)
{
    return A.ItemTag == B.ItemTag; // Vergleich der ItemTags
}

UUhuInventorySystem::UUhuInventorySystem()
{
    PrimaryComponentTick.bCanEverTick = false;    
}

void UUhuInventorySystem::BeginPlay()
{
    Super::BeginPlay();
}

void UUhuInventorySystem::AddItem(const FGameplayTag& NewItemTag, int32 Amount)
{
    if (Amount <= 0) return;

    if (FUhuInventoryItem* ExistingItem = FindItem(NewItemTag))
    {
        ExistingItem->Amount += Amount;
    }
    else
    {
        Inventory.Add(FUhuInventoryItem{ NewItemTag, Amount });
    }
}

bool UUhuInventorySystem::RemoveItem(const FGameplayTag& ItemTag, int32 Amount)
{
    if (Amount <= 0) return false;

    if (FUhuInventoryItem* ExistingItem = FindItem(ItemTag))
    {
        if (ExistingItem->Amount >= Amount)
        {
            ExistingItem->Amount -= Amount;
            if (ExistingItem->Amount == 0)
            {
                Inventory.RemoveSingle(*ExistingItem);
            }
            return true;
        }
    }
    return false;
}

int32 UUhuInventorySystem::GetItemAmount(const FGameplayTag& ItemTag) const
{
    for (const FUhuInventoryItem& Item : Inventory)
    {
        if (Item.ItemTag == ItemTag) // Suche nach dem ItemTag
        {
            return Item.Amount; // Gibt die Menge zurück, wenn gefunden
        }
    }
    return -1; // Gibt -1 zurück, wenn das Item nicht gefunden wurde
}

const TArray<FUhuInventoryItem>& UUhuInventorySystem::GetInventory() const
{
    return Inventory;
}

FUhuInventoryItem* UUhuInventorySystem::FindItem(const FGameplayTag& ItemTag)
{
    for (FUhuInventoryItem& Item : Inventory)
    {
        if (Item.ItemTag == ItemTag)
        {
            return &Item;
        }
    }
    return nullptr;
}
