// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankAIController.generated.h"
/**
 *
 */
UCLASS()
class TANKSGROUNDS_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	ATank* GetPlayerTank() const;
};
