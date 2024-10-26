#include "UI/Widgets/UhuItemWidget.h"

#include "Components/TextBlock.h"
#include "Components/Image.h"

void UUhuItemWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Initialisierung oder UI Setup kann hier erfolgen
}

void UUhuItemWidget::InitializeWidget(const FGameplayTag& ItemTag, const FString& ItemName, UTexture2D* ItemIcon, int32 ItemAmount)
{
	CurrentItemTag = ItemTag;

	// Setze den Namen des Items
	if (ItemNameText)
	{
		ItemNameText->SetText(FText::FromString(ItemName));
	}

	// Setze das Icon des Items
	if (ItemIconImage)
	{
		ItemIconImage->SetBrushFromTexture(ItemIcon);
	}

	// Setze die Menge des Items
	if (ItemAmountText)
	{
		ItemAmountText->SetText(FText::FromString(FString::Printf(TEXT("Menge: %d"), ItemAmount)));
	}
}

void UUhuItemWidget::UpdateAmountDisplay()
{
	if (ItemAmountText)
	{
		// Hier könntest du die Logik hinzufügen, um die Menge basierend auf dem Inventarsystem zu aktualisieren
		// Zum Beispiel könntest du den aktuellen Betrag abrufen und die Anzeige entsprechend aktualisieren
	}
}
