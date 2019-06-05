// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class TANKSGROUNDS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


public:


	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:
   UFUNCTION(BlueprintCallable,Category = "Setup" )
     ATank* GetControlledTank() const;
   UFUNCTION(BlueprintImplementableEvent, Category = "SetUp")
	   void FoundAimingComponent(UTankAimingComponent* aimComRef);
private:

	UPROPERTY(EditDefaultsOnly)
		float CrossHairXlocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
		float CrossHairYlocation = 0.3333;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVecttorHitLocation(FVector lookDirection,FVector& HitLocation) const;
};
