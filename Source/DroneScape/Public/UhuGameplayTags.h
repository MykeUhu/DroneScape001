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

	/* Dangerous Tag! */
	FGameplayTag UhuStandardTag;
	
	FGameplayTag DockingStation;
	
	/* Vital Attributes */
	FGameplayTag Attributes_Vital_Health;
	FGameplayTag Attributes_Vital_MaxHealth;
	FGameplayTag Attributes_Vital_Stamina;
	FGameplayTag Attributes_Vital_MaxStamina;
	FGameplayTag Attributes_Vital_Hunger;
	FGameplayTag Attributes_Vital_MaxHunger;
	FGameplayTag Attributes_Vital_Thirst;
	FGameplayTag Attributes_Vital_MaxThirst;
	FGameplayTag Attributes_Vital_MentalHealth;
	FGameplayTag Attributes_Vital_MaxMentalHealth;
	FGameplayTag Attributes_Vital_FoodPoisoningChance;
	FGameplayTag Attributes_Vital_StressResistance;
	FGameplayTag Attributes_Vital_None;


	/* Nutrients Attributes */
	FGameplayTag Attributes_Nutrient_VitaminA;
	FGameplayTag Attributes_Nutrient_MaxVitaminA;
	FGameplayTag Attributes_Nutrient_VitaminB;
	FGameplayTag Attributes_Nutrient_MaxVitaminB;
	FGameplayTag Attributes_Nutrient_VitaminC;
	FGameplayTag Attributes_Nutrient_MaxVitaminC;
	FGameplayTag Attributes_Nutrient_VitaminD;
	FGameplayTag Attributes_Nutrient_MaxVitaminD;
	FGameplayTag Attributes_Nutrient_Omega3FattyAcids;
	FGameplayTag Attributes_Nutrient_MaxOmega3FattyAcids;
	FGameplayTag Attributes_Nutrient_Proteins;
	FGameplayTag Attributes_Nutrient_MaxProteins;
	FGameplayTag Attributes_Nutrient_Carbohydrates;
	FGameplayTag Attributes_Nutrient_MaxCarbohydrates;
	FGameplayTag Attributes_Nutrient_NutritionLevel;
	FGameplayTag Attributes_Nutrient_MaxNutritionLevel;
	FGameplayTag Attributes_Nutrient_None;


	/* Drone Technical Attributes */
	FGameplayTag Attributes_Drone_BatteryLife;
	FGameplayTag Attributes_Drone_MaxBatteryLife;
	FGameplayTag Attributes_Drone_WaterSupply;
	FGameplayTag Attributes_Drone_MaxWaterSupply;
	FGameplayTag Attributes_Drone_ScanEfficiency;
	FGameplayTag Attributes_Drone_MaxScanEfficiency;
	FGameplayTag Attributes_Drone_FlightSpeed;
	FGameplayTag Attributes_Drone_MaxFlightSpeed;
	FGameplayTag Attributes_Drone_BuildSpeed;
	FGameplayTag Attributes_Drone_MaxBuildSpeed;
	FGameplayTag Attributes_Drone_ProcessorSpeed;
	FGameplayTag Attributes_Drone_MaxProcessorSpeed;
	FGameplayTag Attributes_Drone_Durability;
	FGameplayTag Attributes_Drone_MaxDurability;
	FGameplayTag Attributes_Drone_ResourceCapacity;
	FGameplayTag Attributes_Drone_MaxResourceCapacity;
	FGameplayTag Attributes_Drone_SignalRange;
	FGameplayTag Attributes_Drone_MaxSignalRange;
	FGameplayTag Attributes_Drone_NoiseLevel;
	FGameplayTag Attributes_Drone_MaxNoiseLevel;
	FGameplayTag Attributes_Drone_None;

	/* Items */
	FGameplayTag Items_Rarity_Common;
	FGameplayTag Items_Rarity_Uncommon;
	FGameplayTag Items_Rarity_Rare;
	FGameplayTag Items_Rarity_Epic;
	FGameplayTag Items_Rarity_Legendary;

	 /* Food Items */
    FGameplayTag Items_Food_BittenApple;            // Anbissener Apfel
    FGameplayTag Items_Food_RottenFruit;            // Halb vergammeltes Obst
    FGameplayTag Items_Food_Maggots;                // Handvoll Maden
    FGameplayTag Items_Food_WildBerries;            // Wilde Beeren
    FGameplayTag Items_Food_Roots;                  // Wurzeln
    FGameplayTag Items_Food_Mushrooms;              // Pilze
    FGameplayTag Items_Food_CannedFood;             // Gefundene Konserven
    FGameplayTag Items_Food_UnfilteredWater;        // Ungefiltertes Wasser
    FGameplayTag Items_Food_RottenVegetables;       // Halb vergammeltes Gemüse
    FGameplayTag Items_Food_DriedHerbs;             // Getrocknete Kräuter
    FGameplayTag Items_Food_FreshCarrots;           // Frische Karotten
    FGameplayTag Items_Food_Oranges;                // Orangen
    FGameplayTag Items_Food_Grains;                 // Getreide
    FGameplayTag Items_Food_Legumes;                // Hülsenfrüchte
    FGameplayTag Items_Food_CaughtFish;             // Gefangene Fische
    FGameplayTag Items_Food_CookedMushrooms;        // Gekochte Pilze
    FGameplayTag Items_Food_CookedVegetables;       // Gekochtes Gemüse
    FGameplayTag Items_Food_DriedFruits;            // Getrocknete Früchte
    FGameplayTag Items_Food_Nuts;                   // Nüsse
    FGameplayTag Items_Food_Beans;                  // Bohnen
    FGameplayTag Items_Food_Rice;                   // Reis
    FGameplayTag Items_Food_Tomatoes;               // Tomaten
    FGameplayTag Items_Food_Zucchini;               // Zucchini
    FGameplayTag Items_Food_BellPeppers;            // Paprika
    FGameplayTag Items_Food_Spinach;                // Spinat
    FGameplayTag Items_Food_Cabbage;                // Kohl
    FGameplayTag Items_Food_Potatoes;               // Kartoffeln
    FGameplayTag Items_Food_Apples;                 // Äpfel
    FGameplayTag Items_Food_Pears;                  // Birnen
    FGameplayTag Items_Food_Bananas;                // Bananen
    FGameplayTag Items_Food_BakedFish;              // Gebackener Fisch
    FGameplayTag Items_Food_VegetableStew;          // Gemüseeintopf
    FGameplayTag Items_Food_FruitSalad;             // Fruchtsalat
    FGameplayTag Items_Food_NutMix;                 // Nussmischung
    FGameplayTag Items_Food_GrainPorridge;          // Getreidebrei
    FGameplayTag Items_Food_FilteredWater;          // Gefiltertes Wasser
    FGameplayTag Items_Food_SpringWater;            // Quellwasser
    FGameplayTag Items_Food_BakedPotatoes;          // Gebackene Kartoffeln
    FGameplayTag Items_Food_CookedBeans;            // Gekochte Bohnen
    FGameplayTag Items_Food_HolidayRoast;           // Festtagsbraten

private:
	static FUhuGameplayTags GameplayTags;
};
