// Copyright by MykeUhu
#include "Inventory/UhuInventorySystem.h"
#include "GameplayTagContainer.h"
#include "Components/UhuInventoryComponent.h"
#include "Engine/DataTable.h"

AUhuInventorySystem::AUhuInventorySystem()
{
    PrimaryActorTick.bCanEverTick = false;

    // Initialisiere die Inventar-Komponente
    InventoryComponent = CreateDefaultSubobject<UUhuInventoryComponent>(TEXT("InventoryComponent"));
}

void AUhuInventorySystem::BeginPlay()
{
    Super::BeginPlay();
}

void AUhuInventorySystem::AddItem(const FName RowName, const int32 Amount) const
{
    if (!InventoryDataTable) return;

    // Suche nach dem Eintrag in der DataTable
    if (FInventoryItemData* InventoryItem = InventoryDataTable->FindRow<FInventoryItemData>(RowName, TEXT("")))
    {
        // Aktualisiere die vorhandene Menge
        InventoryItem->Amount += Amount;
    }
    else
    {
        // Füge einen neuen Eintrag hinzu, wenn das Item nicht gefunden wurde
        FInventoryItemData NewItem;
        NewItem.ItemName = RowName;
        NewItem.Amount = Amount;
        InventoryDataTable->AddRow(RowName, NewItem);
    }
}

void AUhuInventorySystem::RemoveItem(const FName RowName, const int32 Amount) const
{
    if (!InventoryDataTable) return;

    // Suche nach dem Eintrag in der DataTable
    if (FInventoryItemData* InventoryItem = InventoryDataTable->FindRow<FInventoryItemData>(RowName, TEXT("")))
    {
        InventoryItem->Amount -= Amount;
        if (InventoryItem->Amount <= 0)
        {
            InventoryDataTable->RemoveRow(RowName);
        }
    }
}

bool AUhuInventorySystem::HasItem(const FName RowName, int32& OutAmount) const
{
    if (!InventoryDataTable) return false;

    // Suche nach dem Eintrag in der DataTable
    if (const FInventoryItemData* InventoryItem = InventoryDataTable->FindRow<FInventoryItemData>(RowName, TEXT("")))
    {
        OutAmount = InventoryItem->Amount;
        return true;
    }
    OutAmount = 0;
    return false;
}

FGameplayTag AUhuInventorySystem::GenerateUniqueTag()
{
    static int32 UniqueID = 0;
    UniqueID++;
    return FGameplayTag::RequestGameplayTag(FName(*FString::Printf(TEXT("UniqueTag_%d"), UniqueID)));
}
