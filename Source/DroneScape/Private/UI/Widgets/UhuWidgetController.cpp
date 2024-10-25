#include "UI/Widgets/UhuWidgetController.h"

void UUhuWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	// Setzen der Parameter für den Widget Controller (PlayerController, PlayerState, AbilitySystemComponent, AttributeSet)
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UUhuWidgetController::BroadcastInitialValues()
{
	// Hier können die initialen Werte der Attribute (falls benötigt) an das UI übertragen werden
	// Momentan leer, da keine speziellen Attribute oder Funktionen implementiert sind
}

void UUhuWidgetController::BindCallbacksToDependencies()
{
	// Hier werden die Callbacks an die Änderungen der Attribute gebunden
	// Momentan leer, da keine speziellen Attribute oder Abhängigkeiten implementiert sind
}
