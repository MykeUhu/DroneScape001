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

    // Name des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    FName ItemName;

    // Tag zur Identifizierung des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    FGameplayTag ItemTag;

    // Tag zur Identifizierung der Rarity
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    FGameplayTag RarityTag;

    // Bild des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    UTexture2D* ItemImage = nullptr; // Standardwert setzen

    // Beschreibung des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    FString ItemDescription = "Items with empty fields prevent the import of all items!";

    // Gewicht des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    float ItemWeight = 0.0f; // Standardwert setzen

    // Haltbarkeit des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    int32 ItemDurability = 100; // Standardwert setzen

    // Nährstoffwerte des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    TMap<FGameplayTag, float> NutrientValues;

    // Vitalwerte des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    TMap<FGameplayTag, float> VitalValues;

    // Technikwerte des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
    TMap<FGameplayTag, float> TechnicalValues;
};

UCLASS()
class DRONESCAPE_API UItemInfo : public UDataAsset 
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