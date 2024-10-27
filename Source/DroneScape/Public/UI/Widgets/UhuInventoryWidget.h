#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/UhuUserWidget.h"
#include "UhuInventoryWidget.generated.h"

UCLASS()
class DRONESCAPE_API UUhuInventoryWidget : public UUhuUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void InitializeInventoryWidget();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UpdateInventoryDisplay();

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void OnInitializeInventoryWidget();

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory")
	void OnUpdateInventoryDisplay();

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* InventoryContainer;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UUserWidget> ItemWidgetClass;
};
