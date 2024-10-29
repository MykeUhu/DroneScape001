// Copyright by MykeUhu
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "UhuInventoryItemData.generated.h"

// Struktur zur Darstellung eines Inventaritems in der DataTable
USTRUCT(BlueprintType)
struct FInventoryItemData : public FTableRowBase
{
    GENERATED_BODY()

    // Name des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    FName ItemName;

    // Tag zur Identifizierung des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    FGameplayTag ItemTag;

    // Anzahl der Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    int32 Amount = 0; // Standardwert setzen

    // Tag zur Identifizierung des Lagers (z.B. Spieler, Lootbox)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    FGameplayTag StorageTag;

    // Bild des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    UTexture2D* ItemImage = nullptr; // Standardwert setzen

    // Beschreibung des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    FString ItemDescription;

    // Gewicht des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    float ItemWeight = 0.0f; // Standardwert setzen

    // Seltenheit des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    FString ItemRarity;

    // Haltbarkeit des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    int32 ItemDurability = 100; // Standardwert setzen

    // Gameplay-Effekte des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TArray<FGameplayTag> GameplayEffects;

    // Nährstoffwerte des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TMap<FGameplayTag, float> NutrientValues;

    // Vitalwerte des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TMap<FGameplayTag, float> VitalValues;

    // Row Name des Items
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    FName RowName;
    
};
