// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrrerReference(UTankBarrel * BarrelToset)
{

	Barrel = BarrelToset;
}

void UTankAimingComponent::SetTurrentReference(UTankTurret * TurretToSet)
{
	Turrent = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float launchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StarLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StarLocation,
		HitLocation,
		launchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace	);
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
		
	}

}

void UTankAimingComponent::MoveBarrel(FVector AimDirrection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirrection.Rotation();
	auto DeltaRotator = AimRotator - BarrelRotator;


	Barrel->Elevate(DeltaRotator.Pitch);
	Turrent->Rotate(DeltaRotator.Yaw);
}

