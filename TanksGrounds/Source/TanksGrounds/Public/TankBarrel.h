// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 *
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent),hidecategories=("Collision"))
class TANKSGROUNDS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere,Category = Setup)
		float MaxDegreesPerSecond = 20;
	UPROPERTY(EditAnywhere, Category = Setup)
		float  MaxElevationDegress = 40;
	UPROPERTY(EditAnywhere, Category = Setup)
		float  MinElevationDegress = 0;
	UPROPERTY(EditAnywhere, Category = Setup)
		UStaticMesh*  asset ;
};
