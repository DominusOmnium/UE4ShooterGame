// Udemy Shooter Game. All Rights Reserved

using UnrealBuildTool;

public class UdemyShooter : ModuleRules
{
	public UdemyShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[] { 
			"UdemyShooter/Public/Player",
			"UdemyShooter/Public/Components",
			"UdemyShooter/Public/Dev",
			"UdemyShooter/Public/Weapon",
			"UdemyShooter/Public/UI",
			"UdemyShooter/Public/Animations",
			"UdemyShooter/Public/Pickups"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
