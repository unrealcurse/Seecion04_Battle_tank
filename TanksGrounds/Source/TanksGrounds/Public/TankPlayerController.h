// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"
/**
 *
 */
UCLASS()
class TANKSGROUNDS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


public:

	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere)
		float CrossHairXlocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossHairYlocation = 0.3333;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVecttorHitLocation(FVector lookDirection,FVector& HitLocation) const;
};
