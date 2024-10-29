// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Abilities/Data/UhuAttributeInfo.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Items/Data/UhuItemInfo.h"
#include "UhuBaseCharacter.generated.h"

struct FUhuItemInformation;
class UGameplayEffect;
class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class DRONESCAPE_API AUhuBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AUhuBaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	virtual void BeginPlay() override;

	// Kameraperspektive wechseln
	void SwitchCamera();

protected:
	// Replikation für die Kameraperspektive
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	virtual void InitAbilityActorInfo();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultNutrientAttributes;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultDroneAttributes;

	void ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& GameplayEffectClass, float Level) const;
	void InitializeDefaultAttributes() const;

private:
	// Kamera-Komponenten
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> FirstPersonCamera;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArm;  // SpringArm für Third-Person

	// ViewSettings
	UPROPERTY(Replicated)  // Damit diese Variable repliziert wird
	bool bIsThirdPersonView;  // Flag für die aktuelle Kameraperspektive

	// Developement only!!!
	UPROPERTY(EditDefaultsOnly, Category = "Developement")
	UAttributeInfo* AttributeInfo; // Referenz zur UAttributeInfo

	UFUNCTION(BlueprintCallable, Category = "Developement")
	void ExportAttributeInfoToCSV();

	UFUNCTION(BlueprintCallable, Category = "Developement")
	void ImportAttributeInfoFromCSV();

	UPROPERTY(EditDefaultsOnly, Category = "Developement")
	UItemInfo* ItemInfo;
	
	UFUNCTION(BlueprintCallable, Category = "Developement")
	void ExportItemInfoToCSV();

	UFUNCTION(BlueprintCallable, Category = "Developement")
	void ImportItemInfoFromCSV();
		
};
