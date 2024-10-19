#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UhuChatWindow.generated.h"

UCLASS()
class DRONESCAPE_API UUhuChatWindow : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "Chat")
	void AddLogMessage(const FString& Message);

private:
	UPROPERTY(meta = (BindWidget))
	class UScrollBox* LogScrollBox;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* LogText;
};
