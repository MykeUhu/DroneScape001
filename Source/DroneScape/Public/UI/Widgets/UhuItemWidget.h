#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "UhuItemWidget.generated.h"

UCLASS()
class DRONESCAPE_API UUhuItemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// Setzt die Item-Daten im Widget
	UFUNCTION(BlueprintCallable, Category = "Item Widget")
	void InitializeWidget(const FGameplayTag& ItemTag, const FString& ItemName, UTexture2D* ItemIcon, int32 ItemAmount);

protected:
	virtual void NativeConstruct() override;

private:
	// Tag des Items
	FGameplayTag CurrentItemTag;

	// Item-Daten
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemNameText;

	UPROPERTY(meta = (BindWidget))
	class UImage* ItemIconImage;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemAmountText;

	// Aktualisiert die Anzeige der Menge
	void UpdateAmountDisplay();
};
