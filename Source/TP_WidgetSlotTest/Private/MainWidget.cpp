// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidget.h"
#include "SlotWidget.h"
#include <Kismet/KismetSystemLibrary.h>

//UMainWidget::UMainWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
//{
//	/*
//	* Slotウィジェットを生成 
//	*/
//
//
//
//}

void UMainWidget::NativeConstruct()
{
	Super::NativeConstruct();

	TSubclassOf<class USlotWidget> SubClass;

	SubClass = TSoftClassPtr<USlotWidget>(FSoftObjectPath(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/WidgetSlotTest/WBP_Slot.WBP_Slot_C'"))).LoadSynchronous();
	if (SubClass)
	{
		for (size_t i = 0; i < 5; i++)
		{
			//UKismetSystemLibrary::PrintString(GetWorld(), "OK");
			USlotWidget* WidgetInstance = CreateWidget<USlotWidget>(GetWorld(), SubClass);
			if (WidgetInstance)
			{

				WidgetInstance->m_text->SetText(FText::FromString("aaa"));
				WidgetInstance->m_int = i;
				m_wrapBox->AddChildToWrapBox(WidgetInstance);

			}
		}


	}
	else
	{
		UKismetSystemLibrary::PrintString(GetWorld(), "NG");
	}
}

void UMainWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{

}
