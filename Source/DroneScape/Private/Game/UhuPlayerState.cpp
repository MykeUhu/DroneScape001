// Copyright by MykeUhu


#include "Game/UhuPlayerState.h"

#include "Abilities/UhuAbilitySystemComponent.h"
#include "Abilities/UhuAttributeSet.h"
#include "Net/UnrealNetwork.h"

AUhuPlayerState::AUhuPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UUhuAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UUhuAttributeSet>("AttributeSet");
	
	NetUpdateFrequency = 100.f;
}

void AUhuPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(AUhuPlayerState, Level);
}

UAbilitySystemComponent* AUhuPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AUhuPlayerState::OnRep_Level(int32 OldLevel)
{
	
}
