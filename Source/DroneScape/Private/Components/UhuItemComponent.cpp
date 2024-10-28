// Copyright by MykeUhu
#include "Components/UhuItemComponent.h"
#include "Engine/DataTable.h"
#include "Inventory/UhuInventoryItemData.h"

UUhuItemComponent::UUhuItemComponent()
    : InventoryDataTable(nullptr)
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UUhuItemComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UUhuItemComponent::SetInventoryDataTable(UDataTable* NewInventoryDataTable)
{
    InventoryDataTable = NewInventoryDataTable;
    UE_LOG(LogTemp, Warning, TEXT("InventoryDataTable set to: %s"), *InventoryDataTable->GetName());
}

FInventoryItemData UUhuItemComponent::InitializeItem(const FName RowName) const
{
    FInventoryItemData ItemData = {};

    if (!InventoryDataTable)
    {
        UE_LOG(LogTemp, Error, TEXT("InventoryDataTable is not set"));
        return ItemData;
    }

    UE_LOG(LogTemp, Warning, TEXT("Initializing item with RowName: %s"), *RowName.ToString());

    if (const FInventoryItemData* FoundItemData = InventoryDataTable->FindRow<FInventoryItemData>(RowName, TEXT("")))
    {
        ItemData = *FoundItemData;
        UE_LOG(LogTemp, Warning, TEXT("Item found: %s"), *ItemData.ItemName.ToString());
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Item not found in DataTable: %s"), *RowName.ToString());
    }

    return ItemData;
}
