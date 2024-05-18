// Copyright Abdallah Saeed


#include "UI/HUD/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if(!OverlayWidgetController)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();

	}
	return OverlayWidgetController;
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("OverlaWidgetClass uninitialized, Please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass uninitialized, Please fill out BP_AuraHUD"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget);

	const FWidgetControllerParams WCParams(PC, PS, ASC, AS);
	UOverlayWidgetController* OverlayWC = GetOverlayWidgetController(WCParams);

	OverlayWidget->SetWidgetController(OverlayWC);
	OverlayWC->BroadcastInitialValues();
	
	Widget->AddToViewport();
}
