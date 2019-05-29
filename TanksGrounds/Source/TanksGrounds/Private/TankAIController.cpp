// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto tank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControllTank = Cast<ATank>(GetPawn());
	if (tank && ControllTank)
	{
		MoveToActor(tank, AcceptaincRaidus);
		ControllTank->AimAt(tank->GetActorLocation());
		ControllTank->fire();
	}
	
}



