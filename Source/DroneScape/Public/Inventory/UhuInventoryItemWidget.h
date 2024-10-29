#pragma once

#include "CoreMinimal.h"
#include "UhuInventoryItemData.h"
#include "Blueprint/UserWidget.h"
#include "UhuInventoryItemWidget.generated.h"

UCLASS()
class DRONESCAPE_API UUhuInventoryItemWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetItemImage(UTexture2D* Image);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetItemName(FText Name);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetItemAmount(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void InitializeItemWidget(const FInventoryItemData& ItemData);

private:
	UPROPERTY(meta = (BindWidget))
	class UImage* ItemImage;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemName;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemAmount;
};
