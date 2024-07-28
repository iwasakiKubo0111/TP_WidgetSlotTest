// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TP_WidgetSlotTest : ModuleRules
{
	public TP_WidgetSlotTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
