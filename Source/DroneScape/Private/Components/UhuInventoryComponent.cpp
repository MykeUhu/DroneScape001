#include "Components/UhuInventoryComponent.h"

#include "Actor/Inventory/UhuChest.h"
#include "Components/UhuItemDataComponent.h"

UUhuInventoryComponent::UUhuInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UUhuInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UUhuInventoryComponent::AddItem(FUhuItemData ItemData, int32 Quantity)
{
	// Überprüfen, ob das Item bereits existiert
	for (FUhuInventoryItem& InventoryItem : InventoryItems)
	{
		if (InventoryItem.ItemData.ItemID == ItemData.ItemID)
		{
			// Erhöhe die Menge des vorhandenen Items
			InventoryItem.Quantity += Quantity;
			return;
		}
	}

	// Falls das Item noch nicht im Inventar ist, neues Item hinzufügen
	FUhuInventoryItem NewItem;
	NewItem.ItemData = ItemData;
	NewItem.Quantity = Quantity;
	InventoryItems.Add(NewItem);
}

void UUhuInventoryComponent::RemoveItem(int32 ItemID, int32 Quantity)
{
	for (int32 i = 0; i < InventoryItems.Num(); i++)
	{
		if (InventoryItems[i].ItemData.ItemID == ItemID)
		{
			// Reduziere die Menge des Items
			InventoryItems[i].Quantity -= Quantity;
			if (InventoryItems[i].Quantity <= 0)
			{
				// Entferne das Item, falls die Menge 0 erreicht
				InventoryItems.RemoveAt(i);
			}
			return;
		}
	}
}

void UUhuInventoryComponent::ConsumeItem(int32 ItemID)
{
	RemoveItem(ItemID, 1);  // Konsumiere eine Einheit des Items
}
