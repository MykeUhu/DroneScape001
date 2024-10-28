// Copyright by MykeUhu
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "Inventory/UhuInventoryItemData.h"
#include "UhuItemComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DRONESCAPE_API UUhuItemComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UUhuItemComponent();

protected:
    virtual void BeginPlay() override;

public:
    UFUNCTION(BlueprintCallable, Category = "Item")
    void SetInventoryDataTable(UDataTable* NewInventoryDataTable);

    UFUNCTION(BlueprintCallable, Category = "Item")
    FInventoryItemData InitializeItem(FName RowName) const;

private:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowPrivateAccess = "true"))
    UDataTable* InventoryDataTable;
};
