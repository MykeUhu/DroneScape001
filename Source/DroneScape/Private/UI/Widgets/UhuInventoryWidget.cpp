#include "UI/Widgets/UhuInventoryWidget.h"
#include "UI/Widgets/UhuItemWidget.h"
#include "Components/VerticalBox.h"

void UUhuInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Hier könntest du das Inventar initialisieren oder die bestehenden Items laden
}

void UUhuInventoryWidget::AddItemWidget(const FGameplayTag& ItemTag, const FString& ItemName, UTexture2D* ItemIcon, int32 ItemAmount)
{
	if (ItemList)
	{
		UUhuItemWidget* NewItemWidget = CreateWidget<UUhuItemWidget>(GetWorld(), UUhuItemWidget::StaticClass());
		if (NewItemWidget)
		{
			NewItemWidget->InitializeWidget(ItemTag, ItemName, ItemIcon, ItemAmount);
			ItemList->AddChild(NewItemWidget);
		}
	}
}
