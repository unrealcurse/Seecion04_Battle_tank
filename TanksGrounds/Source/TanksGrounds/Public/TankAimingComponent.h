#pragma once
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"
UENUM()
enum class EFiringState :uint8
{	
	Reloading,
	Aiming,
	Lock,
	OutofAmo
};
class AProjectile;
class UTankTurret;
class UTankBarrel;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKSGROUNDS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	UFUNCTION(BlueprintCallable, Category = action)
	void fire();

	EFiringState GetFiringState() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Reloading;
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialize(UTankBarrel * barrel, UTankTurret * turrent);



public:	
	void AimAt(FVector WordSpaceAim);
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 10000;

	
	UFUNCTION(BlueprintCallable, Category = Setup)
		int32 GetRoundLeft() const;
	

private:
	FVector  AimDirection;
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turrent = nullptr;
	void MoveBarrel(FVector AimDirrection);
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	virtual void BeginPlay() override;
	bool IsBarrelMoving();


	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBluePrint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInseconds = 3;

	double LastFireTime = 0;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	int32 RoundsLeft = 3;
};

