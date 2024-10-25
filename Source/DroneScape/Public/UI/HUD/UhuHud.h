// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UhuHud.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class UOverlayWidgetController;
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

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

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
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	// Blueprint class of the Overlay Widget Controller
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
