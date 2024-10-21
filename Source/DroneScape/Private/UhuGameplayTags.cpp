// Copyright by MykeUhu


#include "UhuGameplayTags.h"

FUhuGameplayTags FUhuGameplayTags::GameplayTags;

void FUhuGameplayTags::InitializeNativeGameplayTags()
{
	GameplayTags.DockingStation = FGameplayTag::RequestGameplayTag(FName("Tag.DockingStation"));
}
