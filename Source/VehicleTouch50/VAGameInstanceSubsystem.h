// Copyright (c) April 2025. Vitaliy Talyh. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "VAGameInstanceSubsystem.generated.h"

UENUM()
enum class ECarColor : uint8
{
	White UMETA(DisplayName = "White"),
	Red UMETA(DisplayName = "Red"),
	Blue UMETA(DisplayName = "Blue"),
	Green UMETA(DisplayName = "Green"),
	Yellow UMETA(DisplayName = "Yellow"),
	Black UMETA(DisplayName = "Black"),
	Orange UMETA(DisplayName = "Orange")
};

template <typename EnumType>
static FORCEINLINE EnumType GetEnumValueFromDisplayName(const FString& DisplayName, EnumType DefaultValue = EnumType(0))
{
	static const UEnum* Enum = StaticEnum<EnumType>();
	check(Enum);

	FText SearchedDisplayName = FText::FromString(DisplayName);
	for (int32 Index = 0; Index < Enum->NumEnums(); ++Index)
	{
		if (Enum->GetDisplayNameTextByIndex(Index).EqualToCaseIgnored(SearchedDisplayName))
			return static_cast<EnumType>(Enum->GetValueByIndex(Index));
	}

	return DefaultValue;
}

/**
 * UVAGameInstanceSubsystem serves as a custom subsystem for game instances, extending functionality beyond the default
 * provided by Unreal Engine. This subsystem primarily provides support for specific features related to the Eleganza
 * system, including authentication and customization options.
 */
UCLASS()
class VEHICLETOUCH50_API UVAGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	// Declare your properties and functions here
public:
	UVAGameInstanceSubsystem();

	// Override the virtual functions of USubsystem
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category="Eleganza|Authentication")
	FLinearColor CarColor;

private:
	TMap<ECarColor, FLinearColor> CarColors {
		{ ECarColor::White, FLinearColor(1, 1, 1, 1) },
		{ECarColor::Red, FLinearColor(1, 0, 0, 1)},
		{ECarColor::Blue, FLinearColor(0, 0, 1, 1)},
		{ECarColor::Green, FLinearColor(0, 1, 0, 1)},
		{ECarColor::Yellow, FLinearColor(1, 1, 0, 1)},
		{ECarColor::Black, FLinearColor(0, 0, 0, 1)},
		{ECarColor::Orange, FLinearColor(1, 0.6470588235294118, 0, 1)}
	};
};
