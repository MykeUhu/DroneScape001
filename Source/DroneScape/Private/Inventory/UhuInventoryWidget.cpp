#include "Inventory/UhuInventoryWidget.h"
#include "Engine/DataTable.h"
#include "Inventory/UhuInventoryItemData.h"

void UUhuInventoryWidget::InitializeInventory(UDataTable* DataTable)
{
	InventoryDataTable = DataTable;
}

TArray<FInventoryItemData> UUhuInventoryWidget::GetInventoryItems()
{
	TArray<FInventoryItemData*> InventoryItems;
	InventoryDataTable->GetAllRows(TEXT(""), InventoryItems);

	TArray<FInventoryItemData> Result;
	for (FInventoryItemData* ItemData : InventoryItems)
	{
		if (ItemData && ItemData->Amount > 0)
		{
			Result.Add(*ItemData);
		}
	}
	return Result;
}
