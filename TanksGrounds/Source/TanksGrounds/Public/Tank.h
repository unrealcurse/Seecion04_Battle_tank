#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"
class AProjectile;
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


	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = action)
		void fire();

		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;


	

private:
	UStaticMeshComponent* Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 10000;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBluePrint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInseconds = 3;

	UTankBarrel* barrels = nullptr;

	double LastFireTime = 0;

};



