// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "UhuAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/*
 * BoilerPlate für neue Attribute
 * hier einfügen,
 * in UhuGameplayTags
 * dann in GE_VitalAttributes in BP die Attribute hinzufügen
 * DA_AttributeInfo
 * Broadcast Initial Values in Overlay WidgetController!
 */

// TODO: remove Hardcoded Values of Max in GE_Atributes

USTRUCT()

struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

// typedef is specific to the FGameplayAttribute() signature, but TStaticFunPtr is generic to any signature chosen
//typedef TBaseStaticDelegateInstance<FGameplayAttribute(), FDefaultDelegateUserPolicy>::FFuncPtr FAttributeFuncPtr;
template<class T>
using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;

UCLASS()
class DRONESCAPE_API UUhuAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UUhuAttributeSet();
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;

	
	/*
	 * Vital Attributes
	 */

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "Vital Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Hunger, Category = "Vital Attributes")
	FGameplayAttributeData Hunger;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Hunger);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Thirst, Category = "Vital Attributes")
	FGameplayAttributeData Thirst;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Thirst);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MentalHealth, Category = "Vital Attributes")
	FGameplayAttributeData MentalHealth;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, MentalHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_FoodPoisoningChance, Category = "Vital Attributes")
	FGameplayAttributeData FoodPoisoningChance;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, FoodPoisoningChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_StressResistance, Category = "Vital Attributes")
	FGameplayAttributeData StressResistance;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, StressResistance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Exposure, Category = "Vital Attributes")
	FGameplayAttributeData Exposure;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Exposure);

	/*
	 * Nutrients Attributes
	 */

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_VitaminA, Category = "Nutrients Attributes")
	FGameplayAttributeData VitaminA;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, VitaminA);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_VitaminB, Category = "Nutrients Attributes")
	FGameplayAttributeData VitaminB;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, VitaminB);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_VitaminC, Category = "Nutrients Attributes")
	FGameplayAttributeData VitaminC;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, VitaminC);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_VitaminD, Category = "Nutrients Attributes")
	FGameplayAttributeData VitaminD;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, VitaminD);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Omega3FattyAcids, Category = "Nutrients Attributes")
	FGameplayAttributeData Omega3FattyAcids;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Omega3FattyAcids);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_NutritionLevel, Category = "Nutrients Attributes")
	FGameplayAttributeData NutritionLevel;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, NutritionLevel);

	/*
	 * Drone Technical Attributes
	 */

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BatteryLife, Category = "Drone Attributes")
	FGameplayAttributeData BatteryLife;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, BatteryLife);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_WaterSupply, Category = "Drone Attributes")
	FGameplayAttributeData WaterSupply;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, WaterSupply);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ScanEfficiency, Category = "Drone Attributes")
	FGameplayAttributeData ScanEfficiency;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, ScanEfficiency);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_FlightSpeed, Category = "Drone Attributes")
	FGameplayAttributeData FlightSpeed;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, FlightSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BuildSpeed, Category = "Drone Attributes")
	FGameplayAttributeData BuildSpeed;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, BuildSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ProcessorSpeed, Category = "Drone Attributes")
	FGameplayAttributeData ProcessorSpeed;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, ProcessorSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Durability, Category = "Drone Attributes")
	FGameplayAttributeData Durability;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, Durability);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ResourceCapacity, Category = "Drone Attributes")
	FGameplayAttributeData ResourceCapacity;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, ResourceCapacity);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_SignalRange, Category = "Drone Attributes")
	FGameplayAttributeData SignalRange;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, SignalRange);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_NoiseLevel, Category = "Drone Attributes")
	FGameplayAttributeData NoiseLevel;
	ATTRIBUTE_ACCESSORS(UUhuAttributeSet, NoiseLevel);

protected:
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	UFUNCTION()
	void OnRep_Hunger(const FGameplayAttributeData& OldHunger) const;

	UFUNCTION()
	void OnRep_Thirst(const FGameplayAttributeData& OldThirst) const;

	UFUNCTION()
	void OnRep_MentalHealth(const FGameplayAttributeData& OldMentalHealth) const;

	UFUNCTION()
	void OnRep_FoodPoisoningChance(const FGameplayAttributeData& OldFoodPoisoningChance) const;

	UFUNCTION()
	void OnRep_StressResistance(const FGameplayAttributeData& OldStressResistance) const;

	UFUNCTION()
	void OnRep_Exposure(const FGameplayAttributeData& OldExposure) const;

	UFUNCTION()
	void OnRep_VitaminA(const FGameplayAttributeData& OldVitaminA) const;

	UFUNCTION()
	void OnRep_VitaminB(const FGameplayAttributeData& OldVitaminB) const;

	UFUNCTION()
	void OnRep_VitaminC(const FGameplayAttributeData& OldVitaminC) const;

	UFUNCTION()
	void OnRep_VitaminD(const FGameplayAttributeData& OldVitaminD) const;

	UFUNCTION()
	void OnRep_Omega3FattyAcids(const FGameplayAttributeData& OldOmega3FattyAcids) const;

	UFUNCTION()
	void OnRep_NutritionLevel(const FGameplayAttributeData& OldNutritionLevel) const;

	UFUNCTION()
	void OnRep_BatteryLife(const FGameplayAttributeData& OldBatteryLife) const;

	UFUNCTION()
	void OnRep_WaterSupply(const FGameplayAttributeData& OldWaterSupply) const;

	UFUNCTION()
	void OnRep_ScanEfficiency(const FGameplayAttributeData& OldScanEfficiency) const;

	UFUNCTION()
	void OnRep_FlightSpeed(const FGameplayAttributeData& OldFlightSpeed) const;

	UFUNCTION()
	void OnRep_BuildSpeed(const FGameplayAttributeData& OldBuildSpeed) const;

	UFUNCTION()
	void OnRep_ProcessorSpeed(const FGameplayAttributeData& OldProcessorSpeed) const;

	UFUNCTION()
	void OnRep_Durability(const FGameplayAttributeData& OldDurability) const;

	UFUNCTION()
	void OnRep_ResourceCapacity(const FGameplayAttributeData& OldResourceCapacity) const;

	UFUNCTION()
	void OnRep_SignalRange(const FGameplayAttributeData& OldSignalRange) const;

	UFUNCTION()
	void OnRep_NoiseLevel(const FGameplayAttributeData& OldNoiseLevel) const;

private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};

