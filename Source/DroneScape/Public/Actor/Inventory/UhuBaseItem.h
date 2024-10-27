#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UhuGameplayTags.h"
#include "GameplayTagContainer.h"
#include "UhuItemData.h"
#include "UhuBaseItem.generated.h"

UCLASS(Abstract)
class DRONESCAPE_API AUhuBaseItem : public AActor
{
    GENERATED_BODY()
    
public:
    AUhuBaseItem();

    UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Item")
    FUhuItemData ItemData;

    UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Item")
    UDataTable* DataTable;

    UPROPERTY(Replicated, EditDefaultsOnly, Category = "Item")
    FGameplayTag ItemTag;

    UPROPERTY(Replicated, EditDefaultsOnly, Category = "Item")
    int32 Amount = 1;

    UFUNCTION(BlueprintCallable, Category = "Item")
    void InitializeWithTag(const FGameplayTag& NewItemTag);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
    static FUhuGameplayTags GameplayTags;
};
