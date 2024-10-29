#include "Inventory/UhuInventoryItemWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Engine/DataTable.h"
#include "Inventory/UhuInventoryItemData.h"

void UUhuInventoryItemWidget::SetItemImage(UTexture2D* Image)
{
	if (ItemImage)
	{
		ItemImage->SetBrushFromTexture(Image);
	}
}

void UUhuInventoryItemWidget::SetItemName(FText Name)
{
	if (ItemName)
	{
		ItemName->SetText(Name);
	}
}

void UUhuInventoryItemWidget::SetItemAmount(int32 Amount)
{
	if (ItemAmount)
	{
		ItemAmount->SetText(FText::AsNumber(Amount));
	}
}

void UUhuInventoryItemWidget::InitializeItemWidget(const FInventoryItemData& ItemData)
{
	SetItemImage(ItemData.ItemImage);
	SetItemName(FText::FromString(ItemData.ItemName.ToString()));
	SetItemAmount(ItemData.Amount);
}
