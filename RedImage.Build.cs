// Copyright Epic Games, Inc. All Rights Reserved.
using System;
using System.IO;
using UnrealBuildTool;

public class RedImage: ModuleRules
{
	public RedImage(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "RedImageTool"));
        string Prefix = "Release";
        if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string LibPath = Path.Combine(ModuleDirectory,"libraries", "x64", Prefix);
			PublicAdditionalLibraries.Add(Path.Combine(LibPath, "RedImageTool" + ".lib"));
            RuntimeDependencies.Add("$(TargetOutputDir)/RedImageTool.dll",  Path.Combine(LibPath, "RedImageTool" +  ".dll"));

		} 
	}
}
