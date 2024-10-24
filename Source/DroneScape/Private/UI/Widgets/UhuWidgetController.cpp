// Copyright by MykeUhu


#include "UI/Widgets/UhuWidgetController.h"

void UUhuWidgetController::NativeConstruct()
{
	Super::NativeConstruct();

	// Hier kannst du die HUD-Klassen initialisieren
	if (PlayerHUDClass)
	{
		PlayerHUD = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDClass);
	}

	if (DroneHUDClass)
	{
		DroneHUD = CreateWidget<UUserWidget>(GetWorld(), DroneHUDClass);
	}
}

void UUhuWidgetController::ShowPlayerHUD()
{
	if (CurrentHUD)
	{
		CurrentHUD->RemoveFromParent();  
	}

	if (PlayerHUD.IsValid())
	{
		CurrentHUD = PlayerHUD.Get();
		CurrentHUD->AddToViewport();
	}
}

void UUhuWidgetController::ShowDroneHUD()
{
	if (CurrentHUD)
	{
		CurrentHUD->RemoveFromParent();  
	}

	if (DroneHUD.IsValid())
	{
		CurrentHUD = DroneHUD.Get();
		CurrentHUD->AddToViewport();
	}
}