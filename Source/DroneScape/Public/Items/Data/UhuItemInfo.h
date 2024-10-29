// Copyright by MykeUhu
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
    UTexture2D* ItemImage = nullptr; // Standardwert setzen

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    FString ItemImagePath; // Bildpfad

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    FString ItemDescription;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    float ItemWeight = 0.0f; // Standardwert setzen

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    FString ItemRarity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    int32 ItemDurability = 100; // Standardwert setzen

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    TArray<FGameplayTag> GameplayEffects;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    TMap<FGameplayTag, float> NutrientValues;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    TMap<FGameplayTag, float> VitalValues;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    TMap<FGameplayTag, float> TechnicalValues;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    FName RowName;
};

UCLASS()
class DRONESCAPE_API UItemInfo : public UDataAsset // Umbenannt von UUhuItemInfo zu UItemInfo
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    TArray<FUhuItemInfo> ItemInformation;

    // Developement only!!!
    UFUNCTION(BlueprintCallable, Category = "ItemInfo")
    void ExportItemInfoToCSV(const FString& FilePath);

    UFUNCTION(BlueprintCallable, Category = "ItemInfo")
    void ImportItemInfoFromCSV(const FString& FilePath);
};
