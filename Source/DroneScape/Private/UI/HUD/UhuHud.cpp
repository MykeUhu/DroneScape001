// Copyright by MykeUhu

#include "UI/HUD/UhuHud.h"

#include "UI/WidgetController/UhuInventoryWidgetController.h"
#include "UI/Widgets/UhuUserWidget.h"
#include "UI/WidgetController/UhuOverlayWidgetController.h"

UUhuOverlayWidgetController* AUhuHud::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UUhuOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}

UUhuInventoryWidgetController* AUhuHud::GetInventoryMenuWidgetController(const FWidgetControllerParams& WCParams)
{
	if (UhuInventoryMenuWidgetController == nullptr)
	{
		UhuInventoryMenuWidgetController = NewObject<UUhuInventoryWidgetController>(this, InventoryMenuWidgetControllerClass);
		UhuInventoryMenuWidgetController->SetWidgetControllerParams(WCParams);
		UhuInventoryMenuWidgetController->BindCallbacksToDependencies();
	}
	return  UhuInventoryMenuWidgetController;
}

void AUhuHud::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_UhuHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_UhuHUD"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UUhuUserWidget>(Widget);
	
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UUhuOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	Widget->AddToViewport();
}

