// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/TextBlock.h>
#include <Components/Throbber.h>
#include "SlotWidget.generated.h"

/**
 * 
 */
UCLASS()
class TP_WIDGETSLOTTEST_API USlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	void ShowThrobber();

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* m_text;


	UPROPERTY(meta = (BindWidget))
	UThrobber* m_throbber;

	int m_int = 0;



private:

	UPROPERTY(meta = (BindWidget))
	class UButton* m_button;

	UFUNCTION()
	void OnButtonClick();

};
