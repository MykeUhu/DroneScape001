#include "UI/Widgets/UhuItemWidget.h"
#include "Actor/Inventory/UhuItemData.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Engine/DataTable.h"

void UUhuItemWidget::NativeConstruct()
{
	Super::NativeConstruct();

	InitializeWidget(FGameplayTag(), nullptr);
}

void UUhuItemWidget::InitializeWidget(const FGameplayTag& ItemTag, UDataTable* DataTable)
{
	CurrentItemTag = ItemTag;

	if (DataTable)
	{
		LoadItemData(ItemTag, DataTable);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DataTable is not set for %s"), *GetName());
	}
}

void UUhuItemWidget::LoadItemData(const FGameplayTag& ItemTag, UDataTable* DataTable)
{
	if (!DataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("DataTable is not set for %s"), *GetName());
		return;
	}

	for (const FName RowName : DataTable->GetRowNames())
	{
		if (const FUhuItemData* Row = DataTable->FindRow<FUhuItemData>(RowName, TEXT("")); Row && Row->ItemTag == ItemTag)
		{
			if (ItemNameText)
			{
				ItemNameText->SetText(FText::FromString(Row->ItemName));
			}

			if (ItemIconImage)
			{
				ItemIconImage->SetBrushFromTexture(Row->ItemIcon);
			}

			return;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("DataTable row not found for tag: %s"), *ItemTag.GetTagName().ToString());
}

void UUhuItemWidget::UpdateAmountDisplay(int32 ItemAmount)
{
	if (ItemAmountText)
	{
		ItemAmountText->SetText(FText::AsNumber(ItemAmount));
	}
}
