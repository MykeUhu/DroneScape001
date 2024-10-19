// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UhuHUD.generated.h"

/**
 * 
 */
UCLASS()
class DRONESCAPE_API AUhuHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class UUhuChatWindow> ChatWindowClass;

	UPROPERTY()
	UUhuChatWindow* ChatWindow;
};