// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_WidgetSlotTestGameMode.h"
#include "TP_WidgetSlotTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATP_WidgetSlotTestGameMode::ATP_WidgetSlotTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
