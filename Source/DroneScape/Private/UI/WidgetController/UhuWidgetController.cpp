// Copyright by MykeUhu


#include "UI/WidgetController/UhuWidgetController.h"

void UUhuWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UUhuWidgetController::BroadcastInitialValues()
{
	// Sende Anfangswerte
}

void UUhuWidgetController::BindCallbacksToDependencies()
{
	// Binde Rückrufe an Abhängigkeiten
}
