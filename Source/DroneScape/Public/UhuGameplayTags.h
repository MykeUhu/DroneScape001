// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * UhuGameplayTags
 *
 * Singleton containing native Gameplay Tags
 */
struct FUhuGameplayTags
{
public:
	static const FUhuGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag DockingStation;

private:
	static FUhuGameplayTags GameplayTags;
};
