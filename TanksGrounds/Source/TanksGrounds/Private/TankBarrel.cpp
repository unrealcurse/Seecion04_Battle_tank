// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegresPerSecond)
{

	DegresPerSecond = FMath::Clamp(DegresPerSecond, -1.0f, 1.0f);
	auto ElevationChange = DegresPerSecond * MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto ClampNewElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegress, MaxDegreesPerSecond);

	SetRelativeRotation(FRotator(ClampNewElevation, 0,0 ));
}