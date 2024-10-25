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
    TagsToAttributes.Add(GameplayTags.Attributes_Vital_Hunger, GetHungerAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Vital_Thirst, GetThirstAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Vital_MentalHealth, GetMentalHealthAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Vital_FoodPoisoningChance, GetFoodPoisoningChanceAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Vital_StressResistance, GetStressResistanceAttribute);

    /* Nutrients Attributes */
    TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_VitaminA, GetVitaminAAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_VitaminB, GetVitaminBAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_VitaminC, GetVitaminCAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_VitaminD, GetVitaminDAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Nutrient_Omega3FattyAcids, GetOmega3FattyAcidsAttribute);

    /* Drone Technical Attributes */
    TagsToAttributes.Add(GameplayTags.Attributes_Drone_BatteryLife, GetBatteryLifeAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Drone_WaterSupply, GetWaterSupplyAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Drone_ScanEfficiency, GetScanEfficiencyAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Drone_FlightSpeed, GetFlightSpeedAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Drone_BuildSpeed, GetBuildSpeedAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Drone_ProcessorSpeed, GetProcessorSpeedAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Drone_Durability, GetDurabilityAttribute);
    TagsToAttributes.Add(GameplayTags.Attributes_Drone_ResourceCapacity, GetResourceCapacityAttribute);
}

void UUhuAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Vital Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Hunger, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Thirst, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, MentalHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, FoodPoisoningChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, StressResistance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Exposure, COND_None, REPNOTIFY_Always);

	// Nutrients Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, VitaminA, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, VitaminB, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, VitaminC, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, VitaminD, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Omega3FattyAcids, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, NutritionLevel, COND_None, REPNOTIFY_Always);

	// Drone Technical Attributes
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, BatteryLife, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, WaterSupply, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, ScanEfficiency, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, FlightSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, BuildSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, ProcessorSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, Durability, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, ResourceCapacity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, SignalRange, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UUhuAttributeSet, NoiseLevel, COND_None, REPNOTIFY_Always);
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

void UUhuAttributeSet::OnRep_Hunger(const FGameplayAttributeData& OldHunger) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Hunger, OldHunger);
}

void UUhuAttributeSet::OnRep_Thirst(const FGameplayAttributeData& OldThirst) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Thirst, OldThirst);
}

void UUhuAttributeSet::OnRep_MentalHealth(const FGameplayAttributeData& OldMentalHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, MentalHealth, OldMentalHealth);
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

void UUhuAttributeSet::OnRep_VitaminA(const FGameplayAttributeData& OldVitaminA) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, VitaminA, OldVitaminA);
}

void UUhuAttributeSet::OnRep_VitaminB(const FGameplayAttributeData& OldVitaminB) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, VitaminB, OldVitaminB);
}

void UUhuAttributeSet::OnRep_VitaminC(const FGameplayAttributeData& OldVitaminC) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, VitaminC, OldVitaminC);
}

void UUhuAttributeSet::OnRep_VitaminD(const FGameplayAttributeData& OldVitaminD) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, VitaminD, OldVitaminD);
}

void UUhuAttributeSet::OnRep_Omega3FattyAcids(const FGameplayAttributeData& OldOmega3FattyAcids) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Omega3FattyAcids, OldOmega3FattyAcids);
}

void UUhuAttributeSet::OnRep_NutritionLevel(const FGameplayAttributeData& OldNutritionLevel) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, NutritionLevel, OldNutritionLevel);
}

void UUhuAttributeSet::OnRep_BatteryLife(const FGameplayAttributeData& OldBatteryLife) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, BatteryLife, OldBatteryLife);
}

void UUhuAttributeSet::OnRep_WaterSupply(const FGameplayAttributeData& OldWaterSupply) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, WaterSupply, OldWaterSupply);
}

void UUhuAttributeSet::OnRep_ScanEfficiency(const FGameplayAttributeData& OldScanEfficiency) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, ScanEfficiency, OldScanEfficiency);
}

void UUhuAttributeSet::OnRep_FlightSpeed(const FGameplayAttributeData& OldFlightSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, FlightSpeed, OldFlightSpeed);
}

void UUhuAttributeSet::OnRep_BuildSpeed(const FGameplayAttributeData& OldBuildSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, BuildSpeed, OldBuildSpeed);
}

void UUhuAttributeSet::OnRep_ProcessorSpeed(const FGameplayAttributeData& OldProcessorSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, ProcessorSpeed, OldProcessorSpeed);
}

void UUhuAttributeSet::OnRep_Durability(const FGameplayAttributeData& OldDurability) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, Durability, OldDurability);
}

void UUhuAttributeSet::OnRep_ResourceCapacity(const FGameplayAttributeData& OldResourceCapacity) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, ResourceCapacity, OldResourceCapacity);
}

void UUhuAttributeSet::OnRep_SignalRange(const FGameplayAttributeData& OldSignalRange) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, SignalRange, OldSignalRange);
}

void UUhuAttributeSet::OnRep_NoiseLevel(const FGameplayAttributeData& OldNoiseLevel) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UUhuAttributeSet, NoiseLevel, OldNoiseLevel);
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
