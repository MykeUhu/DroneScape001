// Copyright by MykeUhu

#include "Abilities/UhuAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include "UhuGameplayTags.h"
#include "Net/UnrealNetwork.h"

UUhuAttributeSet::UUhuAttributeSet()
{
    const FUhuGameplayTags& GameplayTags = FUhuGameplayTags::Get();

	/* Vital Attributes */
	TagsToAttributes.Add(GameplayTags.Attributes_Vital_Health, GetHealthAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Vital_MaxHealth, GetMaxHealthAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Vital_Stamina, GetStaminaAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Vital_MaxStamina, GetMaxStaminaAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Vital_Hunger, GetHungerAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Vital_MaxHunger, GetMaxHungerAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Vital_Thirst, GetThirstAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Vital_MaxThirst, GetMaxThirstAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Vital_MentalHealth, GetMentalHealthAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Vital_MaxMentalHealth, GetMaxMentalHealthAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Vital_FoodPoisoningChance, GetFoodPoisoningChanceAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Vital_StressResistance, GetStressResistanceAttribute);


	/* Nutrients Attributes */
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_VitaminA, GetVitaminAAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_MaxVitaminA, GetMaxVitaminAAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_VitaminB, GetVitaminBAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_MaxVitaminB, GetMaxVitaminBAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_VitaminC, GetVitaminCAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_MaxVitaminC, GetMaxVitaminCAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_VitaminD, GetVitaminDAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_MaxVitaminD, GetMaxVitaminDAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_Omega3FattyAcids, GetOmega3FattyAcidsAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_MaxOmega3FattyAcids, GetMaxOmega3FattyAcidsAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_Proteins, GetProteinsAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_MaxProteins, GetMaxProteinsAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_Carbohydrates, GetCarbohydratesAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_MaxCarbohydrates, GetMaxCarbohydratesAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_NutritionLevel, GetNutritionLevelAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_MaxNutritionLevel, GetMaxNutritionLevelAttribute);


	/* Drone Technical Attributes */
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_BatteryLife, GetBatteryLifeAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_MaxBatteryLife, GetMaxBatteryLifeAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_WaterSupply, GetWaterSupplyAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_MaxWaterSupply, GetMaxWaterSupplyAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_ScanEfficiency, GetScanEfficiencyAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_MaxScanEfficiency, GetMaxScanEfficiencyAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_FlightSpeed, GetFlightSpeedAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_MaxFlightSpeed, GetMaxFlightSpeedAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_BuildSpeed, GetBuildSpeedAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_MaxBuildSpeed, GetMaxBuildSpeedAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_ProcessorSpeed, GetProcessorSpeedAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_MaxProcessorSpeed, GetMaxProcessorSpeedAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_Durability, GetDurabilityAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_MaxDurability, GetMaxDurabilityAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_ResourceCapacity, GetResourceCapacityAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_MaxResourceCapacity, GetMaxResourceCapacityAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_SignalRange, GetSignalRangeAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_MaxSignalRange, GetMaxSignalRangeAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_NoiseLevel, GetNoiseLevelAttribute);
	TagsToAttributes.Add(GameplayTags.Attributes_Drone_MaxNoiseLevel, GetMaxNoiseLevelAttribute);

}

void UUhuAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Vital Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Hunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxHunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Thirst, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxThirst, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MentalHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxMentalHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, FoodPoisoningChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, StressResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Exposure, COND_None, REPNOTIFY_Always);


	// Nutrients Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, VitaminA, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxVitaminA, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, VitaminB, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxVitaminB, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, VitaminC, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxVitaminC, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, VitaminD, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxVitaminD, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Omega3FattyAcids, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxOmega3FattyAcids, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Proteins, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxProteins, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Carbohydrates, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxCarbohydrates, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, NutritionLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxNutritionLevel, COND_None, REPNOTIFY_Always);

	// Drone Technical Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, BatteryLife, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxBatteryLife, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, WaterSupply, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxWaterSupply, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, ScanEfficiency, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxScanEfficiency, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, FlightSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxFlightSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, BuildSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxBuildSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, ProcessorSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxProcessorSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Durability, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxDurability, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, ResourceCapacity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxResourceCapacity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, SignalRange, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxSignalRange, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, NoiseLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxNoiseLevel, COND_None, REPNOTIFY_Always);

}

void UUhuAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);


}

void UUhuAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}

// Hier kommen die Implementierungen der OnRep-Funktionen

// Vital Attributes
void UUhuAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Health, OldHealth);
}

void UUhuAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxHealth, OldMaxHealth);
}

void UUhuAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Stamina, OldStamina);
}

void UUhuAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxStamina, OldMaxStamina);
}

void UUhuAttributeSet::OnRep_Hunger(const FGameplayAttributeData& OldHunger) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Hunger, OldHunger);
}

void UUhuAttributeSet::OnRep_MaxHunger(const FGameplayAttributeData& OldMaxHunger) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxHunger, OldMaxHunger);
}

void UUhuAttributeSet::OnRep_Thirst(const FGameplayAttributeData& OldThirst) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Thirst, OldThirst);
}

void UUhuAttributeSet::OnRep_MaxThirst(const FGameplayAttributeData& OldMaxThirst) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxThirst, OldMaxThirst);
}

void UUhuAttributeSet::OnRep_MentalHealth(const FGameplayAttributeData& OldMentalHealth) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MentalHealth, OldMentalHealth);
}

void UUhuAttributeSet::OnRep_MaxMentalHealth(const FGameplayAttributeData& OldMaxMentalHealth) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxMentalHealth, OldMaxMentalHealth);
}

void UUhuAttributeSet::OnRep_FoodPoisoningChance(const FGameplayAttributeData& OldFoodPoisoningChance) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, FoodPoisoningChance, OldFoodPoisoningChance);
}

void UUhuAttributeSet::OnRep_StressResistance(const FGameplayAttributeData& OldStressResistance) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, StressResistance, OldStressResistance);
}

void UUhuAttributeSet::OnRep_Exposure(const FGameplayAttributeData& OldExposure) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Exposure, OldExposure);
}

// Nutrients Attributes
void UUhuAttributeSet::OnRep_VitaminA(const FGameplayAttributeData& OldVitaminA) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, VitaminA, OldVitaminA);
}

void UUhuAttributeSet::OnRep_MaxVitaminA(const FGameplayAttributeData& OldMaxVitaminA) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxVitaminA, OldMaxVitaminA);
}

void UUhuAttributeSet::OnRep_VitaminB(const FGameplayAttributeData& OldVitaminB) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, VitaminB, OldVitaminB);
}

void UUhuAttributeSet::OnRep_MaxVitaminB(const FGameplayAttributeData& OldMaxVitaminB) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxVitaminB, OldMaxVitaminB);
}

void UUhuAttributeSet::OnRep_VitaminC(const FGameplayAttributeData& OldVitaminC) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, VitaminC, OldVitaminC);
}

void UUhuAttributeSet::OnRep_MaxVitaminC(const FGameplayAttributeData& OldMaxVitaminC) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxVitaminC, OldMaxVitaminC);
}

void UUhuAttributeSet::OnRep_VitaminD(const FGameplayAttributeData& OldVitaminD) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, VitaminD, OldVitaminD);
}

void UUhuAttributeSet::OnRep_MaxVitaminD(const FGameplayAttributeData& OldMaxVitaminD) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxVitaminD, OldMaxVitaminD);
}

void UUhuAttributeSet::OnRep_Omega3FattyAcids(const FGameplayAttributeData& OldOmega3FattyAcids) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Omega3FattyAcids, OldOmega3FattyAcids);
}

void UUhuAttributeSet::OnRep_MaxOmega3FattyAcids(const FGameplayAttributeData& OldMaxOmega3FattyAcids) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxOmega3FattyAcids, OldMaxOmega3FattyAcids);
}

void UUhuAttributeSet::OnRep_Proteins(const FGameplayAttributeData& OldProteins) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Proteins, OldProteins);
}

void UUhuAttributeSet::OnRep_MaxProteins(const FGameplayAttributeData& OldMaxProteins) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxProteins, OldMaxProteins);
}

void UUhuAttributeSet::OnRep_Carbohydrates(const FGameplayAttributeData& OldCarbohydrates) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Carbohydrates, OldCarbohydrates);
}

void UUhuAttributeSet::OnRep_MaxCarbohydrates(const FGameplayAttributeData& OldMaxCarbohydrates) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxCarbohydrates, OldMaxCarbohydrates);
}

void UUhuAttributeSet::OnRep_NutritionLevel(const FGameplayAttributeData& OldNutritionLevel) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, NutritionLevel, OldNutritionLevel);
}

void UUhuAttributeSet::OnRep_MaxNutritionLevel(const FGameplayAttributeData& OldMaxNutritionLevel) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxNutritionLevel, OldMaxNutritionLevel);
}

// Drone Technical Attributes
void UUhuAttributeSet::OnRep_BatteryLife(const FGameplayAttributeData& OldBatteryLife) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, BatteryLife, OldBatteryLife);
}

void UUhuAttributeSet::OnRep_MaxBatteryLife(const FGameplayAttributeData& OldMaxBatteryLife) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxBatteryLife, OldMaxBatteryLife);
}

void UUhuAttributeSet::OnRep_WaterSupply(const FGameplayAttributeData& OldWaterSupply) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, WaterSupply, OldWaterSupply);
}

void UUhuAttributeSet::OnRep_MaxWaterSupply(const FGameplayAttributeData& OldMaxWaterSupply) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxWaterSupply, OldMaxWaterSupply);
}

void UUhuAttributeSet::OnRep_ScanEfficiency(const FGameplayAttributeData& OldScanEfficiency) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, ScanEfficiency, OldScanEfficiency);
}

void UUhuAttributeSet::OnRep_MaxScanEfficiency(const FGameplayAttributeData& OldMaxScanEfficiency) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxScanEfficiency, OldMaxScanEfficiency);
}

void UUhuAttributeSet::OnRep_FlightSpeed(const FGameplayAttributeData& OldFlightSpeed) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, FlightSpeed, OldFlightSpeed);
}

void UUhuAttributeSet::OnRep_MaxFlightSpeed(const FGameplayAttributeData& OldMaxFlightSpeed) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxFlightSpeed, OldMaxFlightSpeed);
}

void UUhuAttributeSet::OnRep_BuildSpeed(const FGameplayAttributeData& OldBuildSpeed) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, BuildSpeed, OldBuildSpeed);
}

void UUhuAttributeSet::OnRep_MaxBuildSpeed(const FGameplayAttributeData& OldMaxBuildSpeed) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxBuildSpeed, OldMaxBuildSpeed);
}

void UUhuAttributeSet::OnRep_ProcessorSpeed(const FGameplayAttributeData& OldProcessorSpeed) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, ProcessorSpeed, OldProcessorSpeed);
}

void UUhuAttributeSet::OnRep_MaxProcessorSpeed(const FGameplayAttributeData& OldMaxProcessorSpeed) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxProcessorSpeed, OldMaxProcessorSpeed);
}

void UUhuAttributeSet::OnRep_Durability(const FGameplayAttributeData& OldDurability) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Durability, OldDurability);
}

void UUhuAttributeSet::OnRep_MaxDurability(const FGameplayAttributeData& OldMaxDurability) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxDurability, OldMaxDurability);
}

void UUhuAttributeSet::OnRep_ResourceCapacity(const FGameplayAttributeData& OldResourceCapacity) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, ResourceCapacity, OldResourceCapacity);
}

void UUhuAttributeSet::OnRep_MaxResourceCapacity(const FGameplayAttributeData& OldMaxResourceCapacity) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxResourceCapacity, OldMaxResourceCapacity);
}

void UUhuAttributeSet::OnRep_SignalRange(const FGameplayAttributeData& OldSignalRange) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, SignalRange, OldSignalRange);
}

void UUhuAttributeSet::OnRep_MaxSignalRange(const FGameplayAttributeData& OldMaxSignalRange) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxSignalRange, OldMaxSignalRange);
}

void UUhuAttributeSet::OnRep_NoiseLevel(const FGameplayAttributeData& OldNoiseLevel) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, NoiseLevel, OldNoiseLevel);
}

void UUhuAttributeSet::OnRep_MaxNoiseLevel(const FGameplayAttributeData& OldMaxNoiseLevel) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MaxNoiseLevel, OldMaxNoiseLevel);
}



void UUhuAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
}
