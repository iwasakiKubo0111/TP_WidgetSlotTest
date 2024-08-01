// Fill out your copyright notice in the Description page of Project Settings.


#include "origin.h"
#include <Kismet/GameplayStatics.h>

Uorigin::Uorigin(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//bCanEverTick = true;
	//bTickEnabled = true;
}

void Uorigin::NativeConstruct()
{
	Super::NativeConstruct();
	m_playerController = GetWorld()->GetFirstPlayerController();
	m_location.X = 1330.0f;
	m_location.Y = 1230.0f;
	m_location.Z = 50.0126f;

	UKismetSystemLibrary::PrintString(GetWorld(), "Called Uorigin::NativeConstruct");
}

void Uorigin::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	UGameplayStatics::ProjectWorldToScreen(m_playerController, m_location, m_screenPosition);
	UKismetSystemLibrary::PrintString(GetWorld(), m_screenPosition.ToString());
	SetPositionInViewport(m_screenPosition);
}
