#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UhuInventoryWidget.generated.h"

class UDataTable;
struct FInventoryItemData;

UCLASS()
class DRONESCAPE_API UUhuInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void InitializeInventory(UDataTable* DataTable);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UpdateInventory();

private:
	UPROPERTY(meta = (BindWidget))
	class UUniformGridPanel* InventoryGrid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	UDataTable* InventoryDataTable;

	TArray<FInventoryItemData> GetInventoryItems() const;
	void PopulateInventoryGrid(const TArray<FInventoryItemData>& InventoryItems);

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 Columns = 4;
};
