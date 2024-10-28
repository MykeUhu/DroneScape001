#pragma once

#include "CoreMinimal.h"
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
	void InitializeItem(UDataTable* DataTable, FName RowName);

private:
	UPROPERTY(meta = (BindWidget))
	class UImage* ItemImage;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemName;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ItemAmount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	UDataTable* InventoryDataTable;
};
