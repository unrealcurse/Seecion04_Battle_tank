// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure( TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation,LaunchSpeed);
}



void ATank::fire()
{

	if (!ensure(Barrel)) { return; }
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime )> ReloadTimeInseconds;
	if (isReloaded)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBluePrint, barrels->GetSocketLocation(FName("Projectile")),
			barrels->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}		
	
	
	
	
}

