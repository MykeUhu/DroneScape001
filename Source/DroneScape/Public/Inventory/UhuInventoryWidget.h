#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UhuInventoryItemData.h"
#include "UhuInventoryWidget.generated.h"

UCLASS()
class DRONESCAPE_API UUhuInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void InitializeInventory(UDataTable* DataTable);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	TArray<FInventoryItemData> GetInventoryItems();

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	UDataTable* InventoryDataTable;
};