// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "UhuWidgetController.h"
#include "UI/Widgets/UhuUserWidget.h"
#include "UhuInventoryWidgetController.generated.h"

/**
 * 
 */
UCLASS()
class DRONESCAPE_API UUhuInventoryWidgetController : public UUhuWidgetController
{
	GENERATED_BODY()

public:
	void BindCallbacksToDependencies();
	void BroadcastInitialValues();

private:
	UPROPERTY()
	UDataTable* InventoryDataTable;
};