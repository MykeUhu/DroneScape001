// Copyright by MykeUhu


#include "UI/Widgets/UhuUserWidget.h"

void UUhuUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
