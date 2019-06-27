// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	auto AimigComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(AimigComponent))
	{
		FoundAimingComponent(AimigComponent);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("no AIMING"));
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetPawn()) { return; }
	auto AimigComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimigComponent)) { return; }
	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{
		AimigComponent->AimAt(HitLocation);
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 VierPortSizex = 0, VierPortSizey = 0; 
	
	GetViewportSize(VierPortSizex, VierPortSizey);
	FVector2D ScreenLocation = FVector2D(CrossHairXlocation*VierPortSizex, CrossHairYlocation*VierPortSizey);
	FVector  LookDirection;
	if ( GetLookDirection(ScreenLocation, LookDirection))
	{
		return GetLookVecttorHitLocation(LookDirection,OutHitLocation);
		
	}

	
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D  ScreenLocation, FVector & LookDirection) const
{
	FVector  wordlocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, wordlocation, LookDirection);
}

bool ATankPlayerController::GetLookVecttorHitLocation(FVector lookDirection,FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StarLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StarLocation + lookDirection * LineTraceRange;
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StarLocation, EndLocation,ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	else
	{
		return false;
	}

}




