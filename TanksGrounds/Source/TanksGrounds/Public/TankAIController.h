// Fill out your copyright notice in the Description page of Project Settings.
#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/PlayerController.h"
#include "TankAIController.generated.h"



UCLASS()
class TANKSGROUNDS_API ATankAIController : public AAIController
{
	GENERATED_BODY()



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere,Category="Setup")
	float AcceptaincRaidus = 80000.0;
};
