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
	default
};
class UTankAimingComponent;
class UTankTurret;
class UTankBarrel;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKSGROUNDS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Lock;
	UFUNCTION(BlueprintCallable, Category = Setup)
		void Initialize(UTankBarrel * barrel, UTankTurret * turrent);



public:	
	void AimAt(FVector WordSpaceAim);
	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float LaunchSpeed = 10000;

	

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turrent = nullptr;
	void MoveBarrel(FVector AimDirrection);
};

