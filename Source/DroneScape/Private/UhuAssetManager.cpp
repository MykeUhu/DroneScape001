#include "UhuAssetManager.h"
#include "UhuGameplayTags.h"

UUhuAssetManager& UUhuAssetManager::Get()
{
	check(GEngine);
	
	UUhuAssetManager* UhuAssetManager = Cast<UUhuAssetManager>(GEngine->AssetManager);
	return *UhuAssetManager;
}

void UUhuAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FUhuGameplayTags::InitializeNativeGameplayTags();
}
