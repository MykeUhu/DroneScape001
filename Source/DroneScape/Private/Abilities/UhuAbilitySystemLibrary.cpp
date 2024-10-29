
#include "Abilities/UhuAbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "UI/WidgetController/UhuWidgetController.h"
#include "Game/UhuPlayerState.h"
#include "UI/HUD/UhuHUD.h"

UUhuOverlayWidgetController* UUhuAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AUhuHud* UhuHUD = Cast<AUhuHud>(PC->GetHUD()))
		{
			AUhuPlayerState* PS = PC->GetPlayerState<AUhuPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return UhuHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
