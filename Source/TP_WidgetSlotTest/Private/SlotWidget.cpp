// Fill out your copyright notice in the Description page of Project Settings.


#include "SlotWidget.h"
#include "Components/Button.h"
#include <Kismet/KismetSystemLibrary.h>
#include "Kismet/GameplayStatics.h"
#include "MainWidget.h"
#include <Blueprint/WidgetBlueprintLibrary.h>
#include "Engine/LevelStreamingDynamic.h"



void USlotWidget::NativeConstruct()
{
	Super::NativeConstruct();

	m_button->OnClicked.AddDynamic(this,&USlotWidget::OnButtonClick);
}

void USlotWidget::OnButtonClick()
{
	UKismetSystemLibrary::PrintString(GetWorld(), FString::FromInt(m_int));

	TArray<UUserWidget*> foundWidgets;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(),foundWidgets,UMainWidget::StaticClass(),false);

	for (UUserWidget* Widget : foundWidgets)
	{
		UKismetSystemLibrary::PrintString(GetWorld(), *Widget->GetName());

		UMainWidget* mainWidget = Cast<UMainWidget>(Widget);
		if (mainWidget)
		{
			UKismetSystemLibrary::PrintString(GetWorld(), mainWidget->m_widgetName);
			///Script/Engine.World'/Game/WidgetSlotTest/Level2.Level2'

			FString LevelPath = TEXT("/Game/WidgetSlotTest/Level2.Level2");

		
		}
	}
}
