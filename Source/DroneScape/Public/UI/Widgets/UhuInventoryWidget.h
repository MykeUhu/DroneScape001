#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Blueprint/UserWidget.h"
#include "UhuInventoryWidget.generated.h"

UCLASS()
class DRONESCAPE_API UUhuInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	// Fügt ein Item-Widget hinzu
	void AddItemWidget(const FGameplayTag& ItemTag, const FString& ItemName, UTexture2D* ItemIcon, int32 ItemAmount);

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* ItemList; // Container für Item-Widgets
};
