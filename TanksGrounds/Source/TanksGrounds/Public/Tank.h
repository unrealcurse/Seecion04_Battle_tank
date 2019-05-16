// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"
class UTankTurret;
class UTankBarrel;
class UTankAimingComponent;
UCLASS()
class TANKSGROUNDS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReferece(UTankBarrel* BArrelTOset);
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurrentReferece(UTankTurret* TurrentTOset);

	UFUNCTION(BlueprintCallable, Category = action)
		void fire();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	UStaticMeshComponent* Barrel = nullptr;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 10000;

};
