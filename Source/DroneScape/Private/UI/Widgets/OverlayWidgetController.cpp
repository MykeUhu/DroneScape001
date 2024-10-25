// Copyright by MykeUhu


#include "UI/Widgets/OverlayWidgetController.h"

#include "Abilities/UhuAbilitySystemComponent.h"
#include "Abilities/UhuAttributeSet.h"

class UUhuAttributeSet;

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UUhuAttributeSet* UhuAttributeSet = CastChecked<UUhuAttributeSet>(AttributeSet);
	
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UUhuAttributeSet* UhuAttributeSet = CastChecked<UUhuAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UhuAttributeSet->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);

	
	Cast<UUhuAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				// For example, say that Tag = Message.HealthPotion
				// "Message.HealthPotion".MatchesTag("Message") will return True, "Message".MatchesTag("Message.HealthPotion") will return False
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
}