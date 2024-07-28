// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Components/WrapBox.h>
#include "MainWidget.generated.h"


/**
 * 
 */
UCLASS()
class TP_WIDGETSLOTTEST_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	//UMainWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UWrapBox* m_wrapBox;

	FString m_widgetName = "Name : WBP_Main";
	
};
