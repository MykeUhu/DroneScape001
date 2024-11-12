#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Abilities/Data/UhuAttributeInfo.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/DataTable.h"
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
    UPROPERTY(Replicated)
    bool bIsThirdPersonView;  // Flag für die aktuelle Kameraperspektive
    
    // Development only!!!
    UPROPERTY(EditDefaultsOnly, Category = "Development")
    UAttributeInfo* AttributeInfo;

    UFUNCTION(BlueprintCallable, Category = "Development")
    void ExportAttributeInfoToCSV();

    UFUNCTION(BlueprintCallable, Category = "Development")
    void ImportAttributeInfoFromCSV();

    UPROPERTY(EditDefaultsOnly, Category = "Development")
    UItemInfo* ItemInfo;

    UFUNCTION(BlueprintCallable, Category = "Development")
    void ExportItemInfoToCSV();

    UFUNCTION(BlueprintCallable, Category = "Development")
    void ImportItemInfoFromCSV();
};
