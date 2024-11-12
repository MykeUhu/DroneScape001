#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "UhuItemInfo.generated.h"

// Struktur zur Darstellung eines Items in der DataTable
USTRUCT(BlueprintType)
struct FUhuItemInfo : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    FName ItemName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    FGameplayTag ItemTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    FGameplayTag RarityTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    UTexture2D* ItemImage = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    FString ItemDescription = "Items with empty fields prevent the import of all items!";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    float ItemWeight = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    int32 ItemDurability = 100;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    TMap<FGameplayTag, float> NutrientValues;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    TMap<FGameplayTag, float> VitalValues;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    TMap<FGameplayTag, float> TechnicalValues;
};

UCLASS()
class DRONESCAPE_API UItemInfo : public UDataAsset 
{
    GENERATED_BODY()

public:
    FUhuItemInfo FindAttributeForTag(const FGameplayTag& ItemTag, bool bLogNotFound) const;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    TArray<FUhuItemInfo> ItemInformation;

    UFUNCTION(BlueprintCallable, Category = "ItemInfo")
    void ExportItemInfoToCSV(const FString& FilePath);

    UFUNCTION(BlueprintCallable, Category = "ItemInfo")
    void ImportItemInfoFromCSV(const FString& FilePath);
};
