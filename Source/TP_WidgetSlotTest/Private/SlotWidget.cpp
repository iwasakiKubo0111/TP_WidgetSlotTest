// Fill out your copyright notice in the Description page of Project Settings.


#include "SlotWidget.h"
#include "Components/Button.h"
#include <Kismet/KismetSystemLibrary.h>
#include "Kismet/GameplayStatics.h"
#include "MainWidget.h"
#include <Blueprint/WidgetBlueprintLibrary.h>
#include "Tasks/Task.h"
#include "Engine/LevelStreamingDynamic.h"

using namespace UE::Tasks;

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

	//読み込みボタンを表示
	m_throbber->SetVisibility(ESlateVisibility::Visible);

	Async(EAsyncExecution::Thread, [this]()
		{
			float inTime = 4;
			float time = 0;

			m_throbber->SetVisibility(ESlateVisibility::Visible);

			while (inTime > time)
			{
				FPlatformProcess::Sleep(1.f);
				UE_LOG(LogTemp, Log, TEXT("wait"));
				time = time + 1;
			}
			

			AsyncTask(ENamedThreads::GameThread, [this]()
				{

					if (m_throbber)
					{
						// m_throbberのプロパティにアクセス
						m_throbber->SetVisibility(ESlateVisibility::Hidden);
					}

				});
		});



}

void USlotWidget::ShowThrobber()
{
	float inTime = 4;
	float time = 0;

	while (inTime > time)
	{
		FPlatformProcess::Sleep(1.f);
		UE_LOG(LogTemp, Log, TEXT("wait"));
		time = time + 1;
	}
	m_throbber->SetVisibility(ESlateVisibility::Hidden);
	UE_LOG(LogTemp, Log, TEXT("end"));

}


