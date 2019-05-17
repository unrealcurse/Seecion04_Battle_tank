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
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}



// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation,LaunchSpeed);
}

void ATank::SetBarrelReferece(UTankBarrel * BArrelTOset)
{

	TankAimingComponent->SetBarrrerReference(BArrelTOset);
	barrels = BArrelTOset;
}

void ATank::SetTurrentReferece(UTankTurret * TurrentTOset)
{
	TankAimingComponent->SetTurrentReference(TurrentTOset);
}

void ATank::fire()
{

	
	if (!barrels)
	{
		return;
	}
		

	UE_LOG(LogTemp, Warning, TEXT("FIRE"));
	GetWorld()->SpawnActor<AProjectile>(ProjectileBluePrint, barrels->GetSocketLocation(FName("Projectile")), barrels->GetSocketRotation(FName("Projectile")));
}

