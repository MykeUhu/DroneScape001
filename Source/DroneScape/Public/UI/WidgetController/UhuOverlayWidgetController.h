// UhuOverlayWidgetController.h
#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/UhuWidgetController.h"
#include "UhuOverlayWidgetController.generated.h"

USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag MessageTag = FGameplayTag();

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Message = FText();

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<class UUhuUserWidget> MessageWidget;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UTexture2D* Image = nullptr;
};

class UUhuUserWidget;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMessageWidgetRowSignature, FUIWidgetRow, Row);

UCLASS(BlueprintType, Blueprintable)
class DRONESCAPE_API UUhuOverlayWidgetController : public UUhuWidgetController
{
    GENERATED_BODY()

public:
    virtual void BroadcastInitialValues() override;
    virtual void BindCallbacksToDependencies() override;

    UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
    FOnAttributeChangedSignature OnHealthChanged;

    UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
    FOnAttributeChangedSignature OnMaxHealthChanged;

    UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
    FOnAttributeChangedSignature OnStaminaChanged;

    UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
    FOnAttributeChangedSignature OnMaxStaminaChanged;

    UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
    FOnAttributeChangedSignature OnHungerChanged;

    UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
    FOnAttributeChangedSignature OnMaxHungerChanged;

    UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
    FOnAttributeChangedSignature OnThirstChanged;

    UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
    FOnAttributeChangedSignature OnMaxThirstChanged;

    UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
    FOnAttributeChangedSignature OnMentalHealthChanged;

    UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
    FOnAttributeChangedSignature OnMaxMentalHealthChanged;

    UPROPERTY(BlueprintAssignable, Category="GAS|Messages")
    FMessageWidgetRowSignature MessageWidgetRowDelegate;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget Data")
    TObjectPtr<UDataTable> MessageWidgetDataTable;

    template<typename T>
    T* GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag);
};

template <typename T>
T* UUhuOverlayWidgetController::GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag)
{
    return DataTable->FindRow<T>(Tag.GetTagName(), TEXT(""));
}
