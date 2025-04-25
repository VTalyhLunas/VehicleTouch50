// Copyright (c) April 2025. Vitaliy Talyh. All rights reserved.


#include "VAGameInstanceSubsystem.h"

UVAGameInstanceSubsystem::UVAGameInstanceSubsystem()
{
	FString CarColorName;
	if (FParse::Value(FCommandLine::Get(), TEXT("color="), CarColorName))
	{
		ECarColor InCarColor = GetEnumValueFromDisplayName<ECarColor>(CarColorName);
		CarColor = CarColors[InCarColor];
	}
}

bool UVAGameInstanceSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return Super::ShouldCreateSubsystem(Outer);
}

void UVAGameInstanceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UVAGameInstanceSubsystem::Deinitialize()
{
	Super::Deinitialize();
}
