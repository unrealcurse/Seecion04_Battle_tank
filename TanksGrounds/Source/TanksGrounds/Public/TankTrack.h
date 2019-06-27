// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKSGROUNDS_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UTankTrack();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetThrottle(float Throttle);

	void DriveTracks();

	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 95000000.0;

	virtual void BeginPlay() override;

	

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void ApplySideWayForce();
	float CurrentThrottle = 0;

};
