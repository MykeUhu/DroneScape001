#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "UhuInventoryComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DRONESCAPE_API UUhuInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UUhuInventoryComponent();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItem(const FGameplayTag& ItemTag, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItem(const FGameplayTag& ItemTag, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int32 GetItemAmount(const FGameplayTag& ItemTag) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool TransferItemTo(UUhuInventoryComponent* TargetInventory, const FGameplayTag& ItemTag, int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItemToGrid(UUserWidget* InventoryWidget, const FGameplayTag& ItemTag);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	class UUhuInventorySystem* InventorySystem;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	FGameplayTagContainer AllowedItemTags;

	bool IsItemAllowed(const FGameplayTag& ItemTag) const;
};
