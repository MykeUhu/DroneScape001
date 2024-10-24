// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UhuWidgetController.generated.h"

class UUserWidget;

UCLASS()
class DRONESCAPE_API UUhuWidgetController : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void ShowPlayerHUD();

	UFUNCTION(BlueprintCallable)
	void ShowDroneHUD();

protected:
	// Verwende TWeakObjectPtr, um stale Pointer zu vermeiden
	TWeakObjectPtr<UUserWidget> PlayerHUD;
	TWeakObjectPtr<UUserWidget> DroneHUD;
	UUserWidget* CurrentHUD = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	TSubclassOf<UUserWidget> PlayerHUDClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	TSubclassOf<UUserWidget> DroneHUDClass;
};
