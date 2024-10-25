// Copyright by MykeUhu

using UnrealBuildTool;

public class DroneScape : ModuleRules
{
	public DroneScape(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",          // Für VR/AR oder Kopfbedeckungen (VR-Headset z.B.)
			"EnhancedInput",               // Für das Enhanced Input System
			"GameplayAbilities",           // Für das Gameplay Ability System (GAS)
			"UMG",                         // Für UI und Widgets (User Interface)
			"Slate",                       // Für UI-Framework (grundlegend für UMG)
			"SlateCore",                   // Grundlegend für UMG und Slate basiertes UI
			"OnlineSubsystem",             // Falls du Multiplayer oder Online-Funktionalität hinzufügen möchtest
			"OnlineSubsystemSteam",        // Falls du Steam als Online-Subsystem verwenden willst
			"Networking",                  // Für Netzwerke (z.B. Synchronisierung und Multiplayer)
			"Sockets"                      // Für Netzwerksockets und Kommunikation
		});


		PrivateDependencyModuleNames.AddRange(new string[] {
			"AIModule",                    // Für AI und NPC Steuerung
			"NavigationSystem",            // Für NavMesh und Navigation
			"GameplayTasks",               // Für Gameplay Tasks im GAS
			"GameplayTags",                // Für Gameplay Tags im GAS
			"NavigationSystem",            // Für NavMesh und Navigation
			"Niagara",                     // Für visuelle Effekte (falls du es brauchst, z.B. für Drohnen Effekte)
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
