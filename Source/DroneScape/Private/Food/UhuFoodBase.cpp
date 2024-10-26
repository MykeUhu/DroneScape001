#include "Food/UhuFoodBase.h"
#include "Engine/DataTable.h"
#include "GameplayEffect.h"
#include "Abilities/UhuAbilitySystemComponent.h"

AUhuFoodBase::AUhuFoodBase()
{
	PrimaryActorTick.bCanEverTick = false;

	// Initialisiere die Ability System Component
	AbilitySystemComponent = CreateDefaultSubobject<UUhuAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
}

void AUhuFoodBase::BeginPlay()
{
	Super::BeginPlay();
}

bool AUhuFoodBase::LoadFoodData(FUhuItemData& OutFoodData) const
{
	if (!FoodDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("DataTable is not set for %s"), *GetName());
		return false;
	}

	// Holt die Zeile aus der DataTable anhand des Namens (z.B. "Maggots")
	if (const FUhuItemData* Row = FoodDataTable->FindRow<FUhuItemData>(FName(*FoodName), TEXT("")))
	{
		OutFoodData = *Row; // Werte werden in die Ausgabevariable kopiert
		return true;
	}

	UE_LOG(LogTemp, Warning, TEXT("DataTable row not found for %s"), *FoodName);
	return false;
}

void AUhuFoodBase::Consume()
{
	FUhuItemData FoodData;  // Hier wird die Struktur für die Nahrungsmittelwerte erstellt
	if (LoadFoodData(FoodData))
	{
		// Hier kannst du die Werte anwenden, z.B. Effekte auf den Charakter
		UE_LOG(LogTemp, Log, TEXT("Consuming %s: StomachFillValue = %f, HungerReductionPercent = %f"), 
			*FoodName, FoodData.StomachFillValue, FoodData.HungerReductionPercent);

		// Beispiel: Effekte anwenden
		for (auto& EffectClass : FoodData.Effects)
		{
			if (EffectClass)
			{
				if (const UGameplayEffect* Effect = NewObject<UGameplayEffect>(this, EffectClass); Effect && AbilitySystemComponent)
				{
					AbilitySystemComponent->ApplyGameplayEffectToSelf(Effect, 1.0f, AbilitySystemComponent->MakeEffectContext());
				}
			}
		}
	}
}