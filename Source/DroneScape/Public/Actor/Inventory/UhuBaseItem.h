// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UhuGameplayTags.h"
#include "GameplayTagContainer.h"
#include "Actor/Inventory/UhuItemData.h" // Behalte die benötigte Include-Zeile bei

#include "UhuBaseItem.generated.h"

UCLASS(Abstract)  // Diese Klasse sollte nicht direkt instanziiert werden
class DRONESCAPE_API AUhuBaseItem : public AActor
{
    GENERATED_BODY()
    
public:
    AUhuBaseItem();
    void OnInteract(); // Entferne den Klassennamen hier, da es bereits in der Klasse definiert ist

    // ItemData, das alle relevanten Informationen über das Item enthält
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    FUhuItemData ItemData;

    // Verweis auf die DataTable
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
    UDataTable* DataTable;

    UPROPERTY(EditDefaultsOnly, Category = "Item")
    FGameplayTag ItemTag;

    UPROPERTY(EditDefaultsOnly, Category = "Item")
    int32 Amount = 1;

    UFUNCTION(BlueprintCallable, Category = "Item")
    void InitializeWithTag(const FGameplayTag& NewItemTag);
};

