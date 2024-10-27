#include "Actor/Inventory/UhuBaseItem.h"

#include "Actor/Inventory/UhuInventorySystem.h"
#include "Controllers/UhuPlayerController.h"
#include "Net/UnrealNetwork.h"

AUhuBaseItem::AUhuBaseItem() : DataTable(nullptr)
{
	// Set default values for ItemData
	ItemData.ItemName = "Base Item"; // Placeholder name
	ItemData.ItemID = 0; // Placeholder ID

	// Enable replication for this actor
	bReplicates = true;
}

void AUhuBaseItem::InitializeWithTag(const FGameplayTag& NewItemTag) 
{
	this->ItemTag = NewItemTag; 

	if (!DataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("DataTable is not set for %s"), *GetName());
		return;
	}

	// Search for the row in the DataTable based on the ItemTag
	for (const FName RowName : DataTable->GetRowNames())
	{
		if (const FUhuItemData* Row = DataTable->FindRow<FUhuItemData>(RowName, TEXT("")); Row && Row->ItemTag == ItemTag)
		{
			ItemData = *Row; // Copy values into ItemData
			return;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("DataTable row not found for tag: %s"), *ItemTag.GetTagName().ToString());
}

void AUhuBaseItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AUhuBaseItem, ItemData);
	DOREPLIFETIME(AUhuBaseItem, DataTable);
	DOREPLIFETIME(AUhuBaseItem, ItemTag);
	DOREPLIFETIME(AUhuBaseItem, Amount);
}