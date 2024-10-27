#include "Components/UhuInventoryComponent.h"
#include "Actor/Inventory/UhuInventorySystem.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "UI/Widgets/UhuItemWidget.h"
#include "Net/UnrealNetwork.h"

UUhuInventoryComponent::UUhuInventoryComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UUhuInventoryComponent::BeginPlay()
{
    Super::BeginPlay();

    // Get reference to the central inventory system
    InventorySystem = GetOwner()->FindComponentByClass<UUhuInventorySystem>();
}

bool UUhuInventoryComponent::AddItem(const FGameplayTag& ItemTag, int32 Amount)
{
    if (IsItemAllowed(ItemTag) && InventorySystem)
    {
        InventorySystem->AddItem(ItemTag, Amount);
        return true;
    }
    return false;
}

bool UUhuInventoryComponent::RemoveItem(const FGameplayTag& ItemTag, int32 Amount)
{
    if (IsItemAllowed(ItemTag) && InventorySystem)
    {
        return InventorySystem->RemoveItem(ItemTag, Amount);
    }
    return false;
}

int32 UUhuInventoryComponent::GetItemAmount(const FGameplayTag& ItemTag) const
{
    if (InventorySystem)
    {
        return InventorySystem->GetItemAmount(ItemTag);
    }
    return 0;
}

bool UUhuInventoryComponent::TransferItemTo(UUhuInventoryComponent* TargetInventory, const FGameplayTag& ItemTag, int32 Amount)
{
    if (TargetInventory && RemoveItem(ItemTag, Amount))
    {
        TargetInventory->AddItem(ItemTag, Amount);
        return true;
    }
    return false;
}

bool UUhuInventoryComponent::IsItemAllowed(const FGameplayTag& ItemTag) const
{
    return AllowedItemTags.Num() == 0 || AllowedItemTags.HasTag(ItemTag);
}

void UUhuInventoryComponent::AddItemToGrid(UUserWidget* InventoryWidget, const FGameplayTag& ItemTag)
{
    if (!InventoryWidget) return;

    UUniformGridPanel* GridPanel = Cast<UUniformGridPanel>(InventoryWidget->GetWidgetFromName(TEXT("UniformGridPanel")));
    if (!GridPanel) return;

    int32 ItemAmount = GetItemAmount(ItemTag);

    UUhuItemWidget* ItemWidget = CreateWidget<UUhuItemWidget>(InventoryWidget->GetWorld(), UUhuItemWidget::StaticClass());
    if (ItemWidget)
    {
        UDataTable* DataTable = InventorySystem ? InventorySystem->GetDataTable() : nullptr;
        ItemWidget->InitializeWidget(ItemTag, DataTable);
        ItemWidget->UpdateAmountDisplay(ItemAmount);

        UUniformGridSlot* GridSlot = GridPanel->AddChildToUniformGrid(ItemWidget);
        if (GridSlot)
        {
            // Setze die Position im Grid, z.B. Zeile und Spalte
            GridSlot->SetRow(0); // Beispielwert, anpassen nach Bedarf
            GridSlot->SetColumn(0); // Beispielwert, anpassen nach Bedarf
        }
    }
}
