using UnrealBuildTool;
using System.IO;

public class EzAnimPlugin : ModuleRules
{
    public EzAnimPlugin(TargetInfo Target)
    {
        PrivateIncludePaths.AddRange(new string[] { "EzAnimPlugin/Private", });
        PublicIncludePaths.AddRange(new string[] { "EzAnimPlugin/Public" });

        PublicDependencyModuleNames.AddRange(new string[] { "Engine", "Core", "CoreUObject", "Engine", "InputCore" });
        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
    }
}