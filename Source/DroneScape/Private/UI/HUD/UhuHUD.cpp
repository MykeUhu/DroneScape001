// Copyright by MykeUhu


#include "UI/HUD/UhuHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widgets/UhuChatWindow.h"

void AUhuHUD::BeginPlay()
{
	Super::BeginPlay();

	// Create and add the chat window to the viewport
	if (ChatWindowClass)
	{
		ChatWindow = CreateWidget<UUhuChatWindow>(GetWorld(), ChatWindowClass);
		if (ChatWindow)
		{
			ChatWindow->AddToViewport();
		}
	}
}
