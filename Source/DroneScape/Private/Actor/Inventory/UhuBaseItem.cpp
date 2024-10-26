#include "Actor/Inventory/UhuBaseItem.h"
#include "Actor/Inventory/UhuInventorySystem.h"
#include "Controllers/UhuPlayerController.h"

AUhuBaseItem::AUhuBaseItem() : DataTable(nullptr)
{
	// Setze Standardwerte für ItemData, falls gewünscht
	ItemData.ItemName = "Base Item"; // Platzhalter-Name
	ItemData.ItemID = 0; // Platzhalter-ID
}

// Initialisiert das Item basierend auf dem GameplayTag
void AUhuBaseItem::InitializeWithTag(const FGameplayTag& NewItemTag) 
{
	// Beispiel für die Verwendung des Klassenfelds
	this->ItemTag = NewItemTag; 

	if (!DataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("DataTable is not set for %s"), *GetName());
		return;
	}

	// Sucht die Zeile in der DataTable anhand des ItemTag
	for (const FName RowName : DataTable->GetRowNames())
	{
		if (const FUhuItemData* Row = DataTable->FindRow<FUhuItemData>(RowName, TEXT("")); Row && Row->ItemTag == ItemTag)
		{
			ItemData = *Row; // Werte werden in ItemData kopiert
			return;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("DataTable row not found for tag: %s"), *ItemTag.GetTagName().ToString());
}

void AUhuBaseItem::OnInteract()
{
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		if (UUhuInventorySystem* InventorySystem = PC->FindComponentByClass<UUhuInventorySystem>())
		{
			// Fügt das Item zum Inventar hinzu, basierend auf den ItemTag und Amount-Variablen
			InventorySystem->AddItem(ItemTag, Amount);
		}
	}
	Destroy();  
}