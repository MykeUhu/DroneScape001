#include "UI/Widgets/UhuChatWindow.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"

void UUhuChatWindow::NativeConstruct()
{
	Super::NativeConstruct();

}

void UUhuChatWindow::AddLogMessage(const FString& Message)
{
	if (LogText)
	{
		FString CurrentText = LogText->GetText().ToString();
		CurrentText.Append(Message + "\n");
		LogText->SetText(FText::FromString(CurrentText));

		// Scroll to the bottom
		if (LogScrollBox)
		{
			LogScrollBox->ScrollToEnd();
		}
	}
}
