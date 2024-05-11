// Copyright Abdallah Saeed


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	if(IsValid(InWidgetController))
	{
		WidgetController = InWidgetController;
		OnWidgetControllerSet();
	}
}
