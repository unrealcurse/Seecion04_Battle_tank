// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::Initialize(UTankBarrel * barrel, UTankTurret * turrent)
{
	Barrel = barrel;
	Turrent = turrent;
}

void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	LastFireTime = FPlatformTime::Seconds();
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	if (RoundsLeft<=0)
	{
		FiringState = EFiringState::OutofAmo;
	}
	else if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInseconds)
	{
		FiringState = EFiringState::Reloading;
	}
	else if (IsBarrelMoving())
	{
		FiringState = EFiringState::Aiming;
	}
	else
	{
		FiringState = EFiringState::Lock;
	}
}

bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }

	auto BarrerForwar = Barrel->GetForwardVector();

	return !BarrerForwar.Equals(AimDirection,0.1f);
}



void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure( Barrel)) { return; }

	FVector OutLaunchVelocity;
	FVector StarLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StarLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace	);
	if (bHaveAimSolution)
	{
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
		
	}

}

int32 UTankAimingComponent::GetRoundLeft() const
{
	return RoundsLeft;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirrection)
{
	if (!ensure( Barrel || Turrent)) { return; }
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimRotator = AimDirrection.Rotation();
	auto DeltaRotator = AimRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
	if (FMath::Abs(DeltaRotator.Yaw )< 180)
	{
		Turrent->Rotate(DeltaRotator.Yaw);
	}
	else
	{
		Turrent->Rotate(-DeltaRotator.Yaw);
	}
	
}







void UTankAimingComponent::fire()
{

	if (!ensure(Barrel && ProjectileBluePrint)) { return; }
	
	if (FiringState == EFiringState::Lock || FiringState == EFiringState::Aiming)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBluePrint, Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
		RoundsLeft--;
	}




}

EFiringState UTankAimingComponent::GetFiringState() const
{
	return FiringState;
}

