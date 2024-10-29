// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UhuHud.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class UUhuOverlayWidgetController;
class UUhuUserWidget;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class DRONESCAPE_API AUhuHud : public AHUD
{
	GENERATED_BODY()
public:

	UUhuOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:

private:

	// Reference to the Overlay Widget
	UPROPERTY()
	TObjectPtr<UUhuUserWidget> OverlayWidget;

	// Blueprint class of the Overlay Widget
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUhuUserWidget> OverlayWidgetClass;

	// Overlay Widget Controller reference
	UPROPERTY()
	TObjectPtr<UUhuOverlayWidgetController> OverlayWidgetController;

	// Blueprint class of the Overlay Widget Controller
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUhuOverlayWidgetController> OverlayWidgetControllerClass;
};
