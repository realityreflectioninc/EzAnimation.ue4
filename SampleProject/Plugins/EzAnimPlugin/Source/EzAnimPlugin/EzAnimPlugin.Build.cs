using UnrealBuildTool;
using System.IO;

public class EzAnimPlugin : ModuleRules
{
    public EzAnimPlugin(TargetInfo Target)
    {
        PrivateIncludePaths.AddRange(new string[] {
		"EzAnimPlugin" });
        PublicIncludePaths.AddRange(new string[] {
		"EzAnimPlugin",
		"EzAnimPlugin/Animations",
		"EzAnimPlugin/ValueComponents"
	});

        PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject", "InputCore" });
    }
}