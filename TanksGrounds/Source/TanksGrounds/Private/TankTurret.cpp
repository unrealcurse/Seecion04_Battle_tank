// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float DegresPerSecond)
{

	DegresPerSecond = FMath::Clamp(DegresPerSecond, -1.0f, 1.0f);
	auto RotationChange = DegresPerSecond * MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	auto ClampNewRotation = RelativeRotation.Yaw + RotationChange;
	

	SetRelativeRotation(FRotator(0, ClampNewRotation, 0));
}