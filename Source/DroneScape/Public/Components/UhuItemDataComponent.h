#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Actor/Inventory/UhuItemData.h"
#include "UhuItemDataComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DRONESCAPE_API UUhuItemDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UUhuItemDataComponent();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FUhuItemData ItemData;

	void SetItemData(const FUhuItemData& NewItemData);
	FUhuItemData* GetItemData();
};
