#pragma once

#include "CoreMinimal.h"
#include "Actor/Inventory/UhuItemData.h"
#include "Components/ActorComponent.h"
#include "UhuInventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FUhuInventoryItem
{
	GENERATED_BODY()

	// Item-Daten
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FUhuItemData ItemData;

	// Menge des Items (z.B. 5 Äpfel)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Quantity = 0;
};

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
	void AddItem(FUhuItemData ItemData, int32 Quantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(int32 ItemID, int32 Quantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void ConsumeItem(int32 ItemID);

private:
	UPROPERTY()
	TArray<FUhuInventoryItem> InventoryItems;
};
