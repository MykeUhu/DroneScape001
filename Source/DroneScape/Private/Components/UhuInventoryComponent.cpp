#include "Components/UhuInventoryComponent.h"

#include "Actor/Inventory/UhuInventorySystem.h"

UUhuInventoryComponent::UUhuInventoryComponent(): InventorySystem(nullptr)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UUhuInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// Verweise auf das zentrale Inventarsystem abrufen
	InventorySystem = GetOwner()->FindComponentByClass<UUhuInventorySystem>();
}

// Fügt ein Item hinzu, falls es in den erlaubten Tags ist
bool UUhuInventoryComponent::AddItem(const FGameplayTag& ItemTag, const int32 Amount) const
{
	if (IsItemAllowed(ItemTag) && InventorySystem)
	{
		InventorySystem->AddItem(ItemTag, Amount);
		return true;
	}
	return false;
}

// Entfernt ein Item, falls es in den erlaubten Tags ist
bool UUhuInventoryComponent::RemoveItem(const FGameplayTag& ItemTag, const int32 Amount) const
{
	if (IsItemAllowed(ItemTag) && InventorySystem)
	{
		return InventorySystem->RemoveItem(ItemTag, Amount);
	}
	return false;
}

// Gibt die Menge eines Items im Inventar zurück
int32 UUhuInventoryComponent::GetItemAmount(const FGameplayTag& ItemTag) const
{
	if (InventorySystem)
	{
		return InventorySystem->GetItemAmount(ItemTag);
	}
	return 0; // Gibt 0 zurück, wenn das Inventarsystem nicht vorhanden ist
}

// Übergibt Items an ein anderes Inventar
bool UUhuInventoryComponent::TransferItemTo(UUhuInventoryComponent* TargetInventory, const FGameplayTag& ItemTag, int32 Amount)
{
	if (TargetInventory && RemoveItem(ItemTag, Amount))
	{
		TargetInventory->AddItem(ItemTag, Amount);
		return true;
	}
	return false;
}

// Hilfsfunktion, um die Erlaubnis zu überprüfen
bool UUhuInventoryComponent::IsItemAllowed(const FGameplayTag& ItemTag) const
{
	return AllowedItemTags.Num() == 0 || AllowedItemTags.Contains(ItemTag);
}
