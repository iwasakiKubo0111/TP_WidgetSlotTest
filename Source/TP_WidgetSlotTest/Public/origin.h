// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "origin.generated.h"

/**
 * 
 */
UCLASS()
class TP_WIDGETSLOTTEST_API Uorigin : public UUserWidget
{
	GENERATED_BODY()

public:
	Uorigin(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
private:
	APlayerController* m_playerController;
	FVector m_location;
	FVector2D m_screenPosition;

};
