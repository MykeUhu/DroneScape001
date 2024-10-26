// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * UhuGameplayTags
 *
 * Singleton containing native Gameplay Tags
 */
struct FUhuGameplayTags
{
public:
	static const FUhuGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();
	
	FGameplayTag DockingStation;
	
	/* Vital Attributes */
	FGameplayTag Attributes_Vital_Health;
	FGameplayTag Attributes_Vital_MaxHealth;
	FGameplayTag Attributes_Vital_Stamina;
	FGameplayTag Attributes_Vital_Hunger;
	FGameplayTag Attributes_Vital_Thirst;
	FGameplayTag Attributes_Vital_MentalHealth;
	FGameplayTag Attributes_Vital_FoodPoisoningChance;
	FGameplayTag Attributes_Vital_StressResistance;

	/* Nutrients Attributes */
	FGameplayTag Attributes_Nutrient_VitaminA;
	FGameplayTag Attributes_Nutrient_VitaminB;
	FGameplayTag Attributes_Nutrient_VitaminC;
	FGameplayTag Attributes_Nutrient_VitaminD;
	FGameplayTag Attributes_Nutrient_Omega3FattyAcids;

	/* Drone Technical Attributes */
	FGameplayTag Attributes_Drone_BatteryLife;
	FGameplayTag Attributes_Drone_WaterSupply;
	FGameplayTag Attributes_Drone_ScanEfficiency;
	FGameplayTag Attributes_Drone_FlightSpeed;
	FGameplayTag Attributes_Drone_BuildSpeed;
	FGameplayTag Attributes_Drone_ProcessorSpeed;
	FGameplayTag Attributes_Drone_Durability;
	FGameplayTag Attributes_Drone_ResourceCapacity;

	/* Food Items */
	FGameplayTag Items_Food_Maggots;

private:
	static FUhuGameplayTags GameplayTags;
};
