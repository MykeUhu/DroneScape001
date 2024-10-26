#include "Actor/Inventory/UhuChest.h"

#include "Engine/DataTable.h"
#include "Components/UhuItemDataComponent.h"
#include "GameplayTagContainer.h"

AUhuChest::AUhuChest()
{
	PrimaryActorTick.bCanEverTick = false;

	// Initialisiere die Inventar-Komponente
	InventoryComponent = CreateDefaultSubobject<UUhuInventoryComponent>(TEXT("InventoryComponent"));

	// Initialisiere die Mesh-Komponente
	ChestMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ChestMesh"));
	RootComponent = ChestMesh;
}

void AUhuChest::BeginPlay()
{
	Super::BeginPlay();
	AddItemsToInventory();
}

FUhuItemData AUhuChest::GetItemDataByTag(FGameplayTag ItemTag)
{
	FUhuItemData ItemData;
	ItemData.ItemID = -1; // Setze einen Standardwert, um anzuzeigen, dass das Item nicht gefunden wurde

	if (ItemDataTable)
	{
		static const FString ContextString(TEXT("GENERAL"));
		TArray<FUhuItemData*> AllItems;
		ItemDataTable->GetAllRows(ContextString, AllItems);

		for (const FUhuItemData* Item : AllItems)
		{
			if (Item->ItemTag.MatchesTagExact(ItemTag))
			{
				ItemData = *Item; // Item-Daten setzen
				break; // Nimm nur das erste gefundene Item
			}
		}
	}

	// Überprüfen, ob das Item gefunden wurde
	if (ItemData.ItemID == -1)
	{
		// Log ein Fehler, wenn das Item nicht gefunden wurde
		UE_LOG(LogTemp, Warning, TEXT("Item with tag %s was not found in the Item Data Table."), *ItemTag.GetTagName().ToString());
	}

	return ItemData; // Rückgabe des gefundenen Items
}

void AUhuChest::AddItemsToInventory()
{
	// Beispiel: Füge spezifische Nahrungsmittel hinzu
	FGameplayTag FoodTag = FGameplayTag::RequestGameplayTag(FName("Items.Food"));

	// Hole die Item-Daten für das Nahrungsmittel
	FUhuItemData ItemData = GetItemDataByTag(FoodTag);

	// Überprüfen, ob das Item gültig ist
	if (ItemData.ItemID != 0) // Angenommen, ItemID 0 bedeutet "ungültig"
	{
		int32 Quantity = 1; // Die Menge, die hinzugefügt werden soll
		InventoryComponent->AddItem(ItemData, Quantity);
	}
}
