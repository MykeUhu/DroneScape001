// Copyright by MykeUhu

using UnrealBuildTool;
using System.Collections.Generic;

public class DroneScapeTarget : TargetRules
{
	public DroneScapeTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "DroneScape" } );
	}
}