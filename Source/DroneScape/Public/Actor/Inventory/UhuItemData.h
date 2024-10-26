#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "UhuItemData.generated.h"

USTRUCT(BlueprintType)
struct DRONESCAPE_API FUhuItemData : public FTableRowBase
{
	GENERATED_BODY()

public:
	// Allgemeine Item-Daten
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Allgemein")
	int32 ItemID = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Allgemein")
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Allgemein")
	FGameplayTag ItemTag;  // Tag zur Identifikation der Item-Kategorie (z.B. Nahrung, Baumaterial)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Allgemein")
	UTexture2D* ItemIcon = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Allgemein")
	FString ItemDescription;

	// Nahrungsspezifische Daten (können ignoriert werden, wenn Item kein Nahrungsmittel ist)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Nahrung")
	float StomachFillValue = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Nahrung")
	float HungerReductionPercent = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Nahrung")
	float SaturationDuration = 0.0f;

	// Baumaterial-spezifische Daten (optional hinzufügbar)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Baumaterial")
	int32 Durability = 0;

	// Gameplay-Effekte
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effekte")
	TArray<TSubclassOf<class UGameplayEffect>> Effects;  // Mehrere Effekte möglich
};
