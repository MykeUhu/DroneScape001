#include "Components/UhuItemDataComponent.h"

UUhuItemDataComponent::UUhuItemDataComponent(): ItemData()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UUhuItemDataComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UUhuItemDataComponent::SetItemData(const FUhuItemData& NewItemData)
{
	ItemData = NewItemData;
}

FUhuItemData* UUhuItemDataComponent::GetItemData()
{
	return &ItemData;
}
