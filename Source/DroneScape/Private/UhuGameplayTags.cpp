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
	
	GameplayTags.Attributes_Vital_MaxStamina = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.MaxStamina"),
		FString("Represents the maximum stamina of the character.")
		);
	
	GameplayTags.Attributes_Vital_Hunger = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.Hunger"),
		FString("Represents the hunger level of the character.")
		);
	
	GameplayTags.Attributes_Vital_MaxHunger = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.MaxHunger"),
		FString("Represents the maximum hunger level of the character.")
		);
	
	GameplayTags.Attributes_Vital_Thirst = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.Thirst"),
		FString("Represents the thirst level of the character.")
		);
	
	GameplayTags.Attributes_Vital_MaxThirst = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.MaxThirst"),
		FString("Represents the maximum thirst level of the character.")
		);
	
	GameplayTags.Attributes_Vital_MentalHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.MentalHealth"),
		FString("Represents the mental health of the character.")
		);
	
	GameplayTags.Attributes_Vital_MaxMentalHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.MaxMentalHealth"),
		FString("Represents the maximum mental health of the character.")
		);
	
	GameplayTags.Attributes_Vital_FoodPoisoningChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.FoodPoisoningChance"),
		FString("Represents the chance of food poisoning.")
		);
	
	GameplayTags.Attributes_Vital_StressResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Vital.StressResistance"),
		FString("Represents the stress resistance of the character.")
		);


	/*
	 * Nutrients Attributes
	 */
	GameplayTags.Attributes_Nutrient_VitaminA = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.VitaminA"),
		FString("Represents the amount of Vitamin A.")
		);
	
	GameplayTags.Attributes_Nutrient_MaxVitaminA = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.MaxVitaminA"),
		FString("Represents the maximum amount of Vitamin A.")
		);
	
	GameplayTags.Attributes_Nutrient_VitaminB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.VitaminB"),
		FString("Represents the amount of Vitamin B.")
		);
	
	GameplayTags.Attributes_Nutrient_MaxVitaminB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.MaxVitaminB"),
		FString("Represents the maximum amount of Vitamin B.")
		);
	
	GameplayTags.Attributes_Nutrient_VitaminC = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.VitaminC"),
		FString("Represents the amount of Vitamin C.")
		);
	
	GameplayTags.Attributes_Nutrient_MaxVitaminC = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.MaxVitaminC"),
		FString("Represents the maximum amount of Vitamin C.")
		);
	
	GameplayTags.Attributes_Nutrient_VitaminD = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.VitaminD"),
		FString("Represents the amount of Vitamin D.")
		);
	
	GameplayTags.Attributes_Nutrient_MaxVitaminD = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.MaxVitaminD"),
		FString("Represents the maximum amount of Vitamin D.")
		);
	
	GameplayTags.Attributes_Nutrient_Omega3FattyAcids = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.Omega3FattyAcids"),
		FString("Represents the amount of Omega-3 fatty acids.")
		);
	
	GameplayTags.Attributes_Nutrient_MaxOmega3FattyAcids = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.MaxOmega3FattyAcids"),
		FString("Represents the maximum amount of Omega-3 fatty acids.")
		);
	
	GameplayTags.Attributes_Nutrient_Proteins = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.Proteins"),
		FString("Represents the amount of proteins.")
		);
	
	GameplayTags.Attributes_Nutrient_MaxProteins = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.MaxProteins"),
		FString("Represents the maximum amount of proteins.")
		);
	
	GameplayTags.Attributes_Nutrient_Carbohydrates = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.Carbohydrates"),
		FString("Represents the amount of carbohydrates.")
		);
	
	GameplayTags.Attributes_Nutrient_MaxCarbohydrates = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.MaxCarbohydrates"),
		FString("Represents the maximum amount of carbohydrates.")
		);
	
	GameplayTags.Attributes_Nutrient_NutritionLevel = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.NutritionLevel"),
		FString("Represents the overall nutrition level.")
		);
	
	GameplayTags.Attributes_Nutrient_MaxNutritionLevel = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Nutrient.MaxNutritionLevel"),
		FString("Represents the maximum overall nutrition level.")
		);


	/*
	 * Drone Technical Attributes
	 */
	GameplayTags.Attributes_Drone_BatteryLife = UGameplayTagsManager::Get().AddNativeGameplayTag(
    FName("Attributes.Drone.BatteryLife"), 
    FString("Represents the battery life of the drone.")
	);

	GameplayTags.Attributes_Drone_MaxBatteryLife = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.MaxBatteryLife"), 
	    FString("Represents the maximum battery life of the drone.")
	);

	GameplayTags.Attributes_Drone_WaterSupply = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.WaterSupply"), 
	    FString("Represents the water supply of the drone.")
	);

	GameplayTags.Attributes_Drone_MaxWaterSupply = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.MaxWaterSupply"), 
	    FString("Represents the maximum water supply of the drone.")
	);

	GameplayTags.Attributes_Drone_ScanEfficiency = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.ScanEfficiency"), 
	    FString("Represents the scan efficiency of the drone.")
	);

	GameplayTags.Attributes_Drone_MaxScanEfficiency = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.MaxScanEfficiency"), 
	    FString("Represents the maximum scan efficiency of the drone.")
	);

	GameplayTags.Attributes_Drone_FlightSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.FlightSpeed"), 
	    FString("Represents the flight speed of the drone.")
	);

	GameplayTags.Attributes_Drone_MaxFlightSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.MaxFlightSpeed"), 
	    FString("Represents the maximum flight speed of the drone.")
	);

	GameplayTags.Attributes_Drone_BuildSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.BuildSpeed"), 
	    FString("Represents the build speed of the drone.")
	);

	GameplayTags.Attributes_Drone_MaxBuildSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.MaxBuildSpeed"), 
	    FString("Represents the maximum build speed of the drone.")
	);

	GameplayTags.Attributes_Drone_ProcessorSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.ProcessorSpeed"), 
	    FString("Represents the processor speed of the drone.")
	);

	GameplayTags.Attributes_Drone_MaxProcessorSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.MaxProcessorSpeed"), 
	    FString("Represents the maximum processor speed of the drone.")
	);

	GameplayTags.Attributes_Drone_Durability = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.Durability"), 
	    FString("Represents the durability of the drone.")
	);

	GameplayTags.Attributes_Drone_MaxDurability = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.MaxDurability"), 
	    FString("Represents the maximum durability of the drone.")
	);

	GameplayTags.Attributes_Drone_ResourceCapacity = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.ResourceCapacity"), 
	    FString("Represents the resource capacity of the drone.")
	);

	GameplayTags.Attributes_Drone_MaxResourceCapacity = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.MaxResourceCapacity"), 
	    FString("Represents the maximum resource capacity of the drone.")
	);

	GameplayTags.Attributes_Drone_SignalRange = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.SignalRange"), 
	    FString("Represents the signal range of the drone.")
	);

	GameplayTags.Attributes_Drone_MaxSignalRange = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.MaxSignalRange"), 
	    FString("Represents the maximum signal range of the drone.")
	);

	GameplayTags.Attributes_Drone_NoiseLevel = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.NoiseLevel"), 
	    FString("Represents the noise level of the drone.")
	);

	GameplayTags.Attributes_Drone_MaxNoiseLevel = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Attributes.Drone.MaxNoiseLevel"), 
	    FString("Represents the maximum noise level of the drone.")
	);


	/*
	 * Drone Technical Attributes
	 */
	GameplayTags.Items_Food_BittenApple = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.BittenApple"),
	    FString("Anbissener Apfel")
	);

	GameplayTags.Items_Food_RottenFruit = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.RottenFruit"),
	    FString("Halb vergammeltes Obst")
	);

	GameplayTags.Items_Food_Maggots = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Maggots"),
	    FString("Handvoll Maden")
	);

	GameplayTags.Items_Food_WildBerries = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.WildBerries"),
	    FString("Wilde Beeren")
	);

	GameplayTags.Items_Food_Roots = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Roots"),
	    FString("Wurzeln")
	);

	GameplayTags.Items_Food_Mushrooms = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Mushrooms"),
	    FString("Pilze")
	);

	GameplayTags.Items_Food_CannedFood = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.CannedFood"),
	    FString("Gefundene Konserven")
	);

	GameplayTags.Items_Food_UnfilteredWater = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.UnfilteredWater"),
	    FString("Ungefiltertes Wasser")
	);

	GameplayTags.Items_Food_RottenVegetables = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.RottenVegetables"),
	    FString("Halb vergammeltes Gemüse")
	);

	GameplayTags.Items_Food_DriedHerbs = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.DriedHerbs"),
	    FString("Getrocknete Kräuter")
	);

	GameplayTags.Items_Food_FreshCarrots = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.FreshCarrots"),
	    FString("Frische Karotten")
	);

	GameplayTags.Items_Food_Oranges = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Oranges"),
	    FString("Orangen")
	);

	GameplayTags.Items_Food_Grains = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Grains"),
	    FString("Getreide")
	);

	GameplayTags.Items_Food_Legumes = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Legumes"),
	    FString("Hülsenfrüchte")
	);

	GameplayTags.Items_Food_CaughtFish = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.CaughtFish"),
	    FString("Gefangene Fische")
	);

	GameplayTags.Items_Food_CookedMushrooms = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.CookedMushrooms"),
	    FString("Gekochte Pilze")
	);

	GameplayTags.Items_Food_CookedVegetables = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.CookedVegetables"),
	    FString("Gekochtes Gemüse")
	);

	GameplayTags.Items_Food_DriedFruits = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.DriedFruits"),
	    FString("Getrocknete Früchte")
	);

	GameplayTags.Items_Food_Nuts = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Nuts"),
	    FString("Nüsse")
	);

	GameplayTags.Items_Food_Beans = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Beans"),
	    FString("Bohnen")
	);

	GameplayTags.Items_Food_Rice = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Rice"),
	    FString("Reis")
	);

	GameplayTags.Items_Food_Tomatoes = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Tomatoes"),
	    FString("Tomaten")
	);

	GameplayTags.Items_Food_Zucchini = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Zucchini"),
	    FString("Zucchini")
	);

	GameplayTags.Items_Food_BellPeppers = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.BellPeppers"),
	    FString("Paprika")
	);

	GameplayTags.Items_Food_Spinach = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Spinach"),
	    FString("Spinat")
	);

	GameplayTags.Items_Food_Cabbage = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Cabbage"),
	    FString("Kohl")
	);

	GameplayTags.Items_Food_Potatoes = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Potatoes"),
	    FString("Kartoffeln")
	);

	GameplayTags.Items_Food_Apples = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Apples"),
	    FString("Äpfel")
	);

	GameplayTags.Items_Food_Pears = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Pears"),
	    FString("Birnen")
	);

	GameplayTags.Items_Food_Bananas = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.Bananas"),
	    FString("Bananen")
	);

	GameplayTags.Items_Food_BakedFish = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.BakedFish"),
	    FString("Gebackener Fisch")
	);

	GameplayTags.Items_Food_VegetableStew = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.VegetableStew"),
	    FString("Gemüseeintopf")
	);

	GameplayTags.Items_Food_FruitSalad = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.FruitSalad"),
	    FString("Fruchtsalat")
	);

	GameplayTags.Items_Food_NutMix = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.NutMix"),
	    FString("Nussmischung")
	);

	GameplayTags.Items_Food_GrainPorridge = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.GrainPorridge"),
	    FString("Getreidebrei")
	);

	GameplayTags.Items_Food_FilteredWater = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.FilteredWater"),
	    FString("Gefiltertes Wasser")
	);

	GameplayTags.Items_Food_SpringWater = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.SpringWater"),
	    FString("Quellwasser")
	);

	GameplayTags.Items_Food_BakedPotatoes = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.BakedPotatoes"),
	    FString("Gebackene Kartoffeln")
	);

	GameplayTags.Items_Food_CookedBeans = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.CookedBeans"),
	    FString("Gekochte Bohnen")
	);

	GameplayTags.Items_Food_HolidayRoast = UGameplayTagsManager::Get().AddNativeGameplayTag(
	    FName("Items.Food.HolidayRoast"),
	    FString("Festtagsbraten")
	);

}

