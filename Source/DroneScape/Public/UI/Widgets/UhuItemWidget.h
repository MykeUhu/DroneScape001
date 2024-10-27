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
	UFUNCTION(BlueprintCallable, Category = "Item Widget")
	void InitializeWidget(const FGameplayTag& ItemTag, UDataTable* DataTable);

	UFUNCTION(BlueprintCallable, Category = "Item Widget")
	void UpdateAmountDisplay(int32 ItemAmount);

protected:
	virtual void NativeConstruct() override;

private:
	FGameplayTag CurrentItemTag;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemNameText;

	UPROPERTY(meta = (BindWidget))
	class UImage* ItemIconImage;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemAmountText;

	void LoadItemData(const FGameplayTag& ItemTag, UDataTable* DataTable);
};
