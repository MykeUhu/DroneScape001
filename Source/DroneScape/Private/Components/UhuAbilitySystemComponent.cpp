// Copyright by MykeUhu


#include "Abilities/UhuAbilitySystemComponent.h"

#include "UhuGameplayTags.h"

void UUhuAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UUhuAbilitySystemComponent::EffectApplied);
	
}

void UUhuAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
												const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
}