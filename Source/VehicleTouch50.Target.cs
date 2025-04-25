// Copyright (c) April 2025. Vitaliy Talyh. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class VehicleTouch50Target : TargetRules
{
	public VehicleTouch50Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "VehicleTouch50" } );
	}
}
