// Copyright by MykeUhu
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Inventory/UhuInventoryItemData.h"
#include "UhuInventoryComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DRONESCAPE_API UUhuInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UUhuInventoryComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(FName RowName, int32 Amount) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(FName RowName, int32 Amount) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool HasItem(FName RowName, int32& OutAmount) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	static FGameplayTag GenerateUniqueTag();

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	UDataTable* InventoryDataTable;
};
