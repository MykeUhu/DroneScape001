#include "Inventory/UhuInventoryWidget.h"
#include "Engine/DataTable.h"
#include "Inventory/UhuInventoryItemData.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Inventory/UhuInventoryItemWidget.h"
#include "Kismet/KismetSystemLibrary.h" // Logging

void UUhuInventoryWidget::InitializeInventory(UDataTable* DataTable)
{
    InventoryDataTable = DataTable;
    if (!InventoryDataTable)
    {
        UE_LOG(LogTemp, Warning, TEXT("InventoryDataTable is null in InitializeInventory"));
        return;
    }

    UE_LOG(LogTemp, Log, TEXT("InitializeInventory called"));

    const TArray<FInventoryItemData> InventoryItems = GetInventoryItems();
    PopulateInventoryGrid(InventoryItems);
}

TArray<FInventoryItemData> UUhuInventoryWidget::GetInventoryItems() const
{
    TArray<FInventoryItemData*> InventoryItems;
    InventoryDataTable->GetAllRows(TEXT(""), InventoryItems);

    TArray<FInventoryItemData> ValidItems;
    for (const FInventoryItemData* ItemData : InventoryItems)
    {
        if (ItemData)
        {
            UE_LOG(LogTemp, Log, TEXT("Item found: %s, Amount: %d"), *ItemData->ItemName.ToString(), ItemData->Amount);
            if (ItemData->Amount > 0)
            {
                ValidItems.Add(*ItemData);
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("ItemData is null"));
        }
    }
    return ValidItems;
}

void UUhuInventoryWidget::PopulateInventoryGrid(const TArray<FInventoryItemData>& InventoryItems)
{
    if (!InventoryGrid)
    {
        UE_LOG(LogTemp, Warning, TEXT("InventoryGrid is null in PopulateInventoryGrid"));
        return;
    }

    InventoryGrid->ClearChildren(); // Wichtig: Vor dem Hinzufügen von Widgets leeren

    int32 Row = 0;
    int32 Column = 0;
    const int32 NumColumns = 4; // Umbenennen in NumColumns

    for (const FInventoryItemData& ItemData : InventoryItems)
    {
        UUhuInventoryItemWidget* ItemWidget = CreateWidget<UUhuInventoryItemWidget>(this, UUhuInventoryItemWidget::StaticClass());
        if (ItemWidget)
        {
            UE_LOG(LogTemp, Log, TEXT("ItemWidget created"));

            ItemWidget->InitializeItemWidget(ItemData);

            InventoryGrid->AddChildToUniformGrid(ItemWidget, Row, Column);

            Column = (Column + 1) % NumColumns; // Verwendung der umbenannten Variablen
            if (Column == 0)
            {
                ++Row;
            }
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Failed to create ItemWidget"));
        }
    }
}

void UUhuInventoryWidget::UpdateInventory()
{
    if (!InventoryDataTable)
    {
        UE_LOG(LogTemp, Warning, TEXT("InventoryDataTable is null in UpdateInventory"));
        return;
    }

    UE_LOG(LogTemp, Log, TEXT("UpdateInventory called"));

    if (InventoryGrid)
    {
        InventoryGrid->ClearChildren();
    }

    InitializeInventory(InventoryDataTable);
}
