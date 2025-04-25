// Copyright (c) April 2025. Vitaliy Talyh. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class VehicleTouch50EditorTarget : TargetRules
{
	public VehicleTouch50EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "VehicleTouch50" } );
	}
}
