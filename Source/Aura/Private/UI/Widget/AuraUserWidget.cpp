// No-Copyright


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetWidgetController(UObject* InwidgetController)
{
	WidgetController = InwidgetController;
	WidgetControllerSet();
}
