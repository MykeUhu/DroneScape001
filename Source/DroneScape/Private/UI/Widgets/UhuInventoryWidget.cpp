#include "UI/Widgets/UhuInventoryWidget.h"
#include "UI/Widgets/UhuItemWidget.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "Engine/DataTable.h"

void UUhuInventoryWidget::InitializeInventoryWidget()
{
	OnInitializeInventoryWidget();
}

void UUhuInventoryWidget::UpdateInventoryDisplay()
{
	OnUpdateInventoryDisplay();

	if (!InventoryContainer || !ItemWidgetClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("InventoryContainer oder ItemWidgetClass ist nicht gesetzt!"));
		return;
	}

	// Beispiel: Füge ein Item-Widget für jedes Item hinzu
	for (int32 i = 0; i < 10; ++i) // Beispielhaft 10 Items
	{
		UUhuItemWidget* ItemWidget = CreateWidget<UUhuItemWidget>(this, ItemWidgetClass);
		if (ItemWidget)
		{
			FGameplayTag ItemTag; // Setze den tatsächlichen ItemTag
			UDataTable* DataTable = nullptr; // Setze die tatsächliche DataTable
			ItemWidget->InitializeWidget(ItemTag, DataTable);
			InventoryContainer->AddChild(ItemWidget);
		}
	}
}
