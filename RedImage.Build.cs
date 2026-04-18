// Copyright Epic Games, Inc. All Rights Reserved.
using System;
using System.IO;
using UnrealBuildTool;

public class RedImage: ModuleRules
{
	public RedImage(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;
        string Prefix = "Release";
        if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			string LibPath = Path.Combine(ModuleDirectory,"Library", "Win64", Prefix);
			PublicAdditionalLibraries.Add(Path.Combine(LibPath, "RedImage" + ".lib"));
            RuntimeDependencies.Add("$(BinaryOutputDir)/RedImage.dll",  Path.Combine(LibPath, "RedImage.dll"));
		} 
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "RedImage"));
	}
}
