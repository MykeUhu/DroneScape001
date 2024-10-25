// Copyright by MykeUhu


#include "UhuGameplayTags.h"

#include "GameplayTagsManager.h"

FUhuGameplayTags FUhuGameplayTags::GameplayTags;

void FUhuGameplayTags::InitializeNativeGameplayTags()
{
	GameplayTags.DockingStation = FGameplayTag::RequestGameplayTag(FName("Tag.DockingStation"));
/*
	 * Vital Attributes
	 */
	GameplayTags.Attributes_Vital_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.Health"),
		FString("Represents the health of the character.")
	);

	GameplayTags.Attributes_Vital_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Attributes.Vital.MaxHealth"),
	FString("Represents the maximum health of the character.")
	);

	GameplayTags.Attributes_Vital_Stamina = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.Stamina"),
		FString("Represents the stamina of the character.")
	);

	GameplayTags.Attributes_Vital_Hunger = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.Hunger"),
		FString("Represents the hunger level of the character.")
	);

	GameplayTags.Attributes_Vital_Thirst = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.Thirst"),
		FString("Represents the thirst level of the character.")
	);

	GameplayTags.Attributes_Vital_MentalHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.MentalHealth"),
		FString("Represents the mental health of the character.")
	);

	GameplayTags.Attributes_Vital_FoodPoisoningChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.FoodPoisoningChance"),
		FString("Chance of food poisoning when consuming food.")
	);

	GameplayTags.Attributes_Vital_StressResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.StressResistance"),
		FString("Resistance to stress effects.")
	);

	/*
	 * Nutrients Attributes
	 */
	GameplayTags.Attributes_Nutrient_VitaminA = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.VitaminA"),
		FString("Represents Vitamin A level.")
	);

	GameplayTags.Attributes_Nutrient_VitaminB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.VitaminB"),
		FString("Represents Vitamin B level.")
	);

	GameplayTags.Attributes_Nutrient_VitaminC = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.VitaminC"),
		FString("Represents Vitamin C level.")
	);

	GameplayTags.Attributes_Nutrient_VitaminD = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.VitaminD"),
		FString("Represents Vitamin D level.")
	);

	GameplayTags.Attributes_Nutrient_Omega3FattyAcids = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.Omega3FattyAcids"),
		FString("Represents Omega-3 fatty acids level.")
	);

	/*
	 * Drone Technical Attributes
	 */
	GameplayTags.Attributes_Drone_BatteryLife = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Drone.BatteryLife"),
		FString("Represents the battery life of the drone.")
	);

	GameplayTags.Attributes_Drone_WaterSupply = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Drone.WaterSupply"),
		FString("Represents the water supply of the drone.")
	);

	GameplayTags.Attributes_Drone_ScanEfficiency = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Drone.ScanEfficiency"),
		FString("Represents the scanning efficiency of the drone.")
	);

	GameplayTags.Attributes_Drone_FlightSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Drone.FlightSpeed"),
		FString("Represents the flight speed of the drone.")
	);

	GameplayTags.Attributes_Drone_BuildSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Drone.BuildSpeed"),
		FString("Represents the build speed of the drone.")
	);

	GameplayTags.Attributes_Drone_ProcessorSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Drone.ProcessorSpeed"),
		FString("Represents the processing speed of the drone.")
	);

	GameplayTags.Attributes_Drone_Durability = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Drone.Durability"),
		FString("Represents the durability of the drone.")
	);

	GameplayTags.Attributes_Drone_ResourceCapacity = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Drone.ResourceCapacity"),
		FString("Represents the resource capacity of the drone.")
	);
}