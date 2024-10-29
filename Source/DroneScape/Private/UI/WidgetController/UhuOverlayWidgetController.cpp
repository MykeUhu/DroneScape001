// Copyright by MykeUhu
#include "UI/WidgetController/UhuOverlayWidgetController.h"
#include "Abilities/UhuAbilitySystemComponent.h"
#include "Abilities/UhuAttributeSet.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Kismet/KismetSystemLibrary.h"

void UUhuOverlayWidgetController::BroadcastInitialValues()
{
    const UUhuAttributeSet* UhuAttributeSet = CastChecked<UUhuAttributeSet>(AttributeSet);
    if (!UhuAttributeSet)
    {
        UKismetSystemLibrary::PrintString(this, TEXT("AttributeSet is null in BroadcastInitialValues"));
        return;
    }

    OnHealthChanged.Broadcast(UhuAttributeSet->GetHealth());
    OnMaxHealthChanged.Broadcast(UhuAttributeSet->GetMaxHealth());
    OnStaminaChanged.Broadcast(UhuAttributeSet->GetStamina());
    OnMaxStaminaChanged.Broadcast(UhuAttributeSet->GetMaxStamina());
    OnHungerChanged.Broadcast(UhuAttributeSet->GetHunger());
    OnMaxHungerChanged.Broadcast(UhuAttributeSet->GetMaxHunger());
    OnThirstChanged.Broadcast(UhuAttributeSet->GetThirst());
    OnMaxThirstChanged.Broadcast(UhuAttributeSet->GetMaxThirst());
    OnMentalHealthChanged.Broadcast(UhuAttributeSet->GetMentalHealth());
    OnMaxMentalHealthChanged.Broadcast(UhuAttributeSet->GetMaxMentalHealth());
}

void UUhuOverlayWidgetController::BindCallbacksToDependencies()
{
    const UUhuAttributeSet* UhuAttributeSet = CastChecked<UUhuAttributeSet>(AttributeSet);
    if (!UhuAttributeSet)
    {
        UKismetSystemLibrary::PrintString(this, TEXT("AttributeSet is null in BindCallbacksToDependencies"));
        return;
    }

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UhuAttributeSet->GetHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnHealthChanged.Broadcast(Data.NewValue);
    });
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UhuAttributeSet->GetMaxHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnMaxHealthChanged.Broadcast(Data.NewValue);
    });
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UhuAttributeSet->GetStaminaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnStaminaChanged.Broadcast(Data.NewValue);
    });
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UhuAttributeSet->GetMaxStaminaAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnMaxStaminaChanged.Broadcast(Data.NewValue);
    });
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UhuAttributeSet->GetHungerAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnHungerChanged.Broadcast(Data.NewValue);
    });
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UhuAttributeSet->GetMaxHungerAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnMaxHungerChanged.Broadcast(Data.NewValue);
    });
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UhuAttributeSet->GetThirstAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnThirstChanged.Broadcast(Data.NewValue);
    });
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UhuAttributeSet->GetMaxThirstAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnMaxThirstChanged.Broadcast(Data.NewValue);
    });
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UhuAttributeSet->GetMentalHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnMentalHealthChanged.Broadcast(Data.NewValue);
    });
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(UhuAttributeSet->GetMaxMentalHealthAttribute()).AddLambda([this](const FOnAttributeChangeData& Data)
    {
        OnMaxMentalHealthChanged.Broadcast(Data.NewValue);
    });
}
