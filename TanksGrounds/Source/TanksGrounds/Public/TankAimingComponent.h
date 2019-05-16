#pragma once
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"
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


public:	


	void SetBarrrerReference(UTankBarrel* BarrelToset);

	void SetTurrentReference(UTankTurret* TurretToSet);

	void AimAt(FVector WordSpaceAim,float launchSpeed);

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turrent = nullptr;
	void MoveBarrel(FVector AimDirrection);
};
