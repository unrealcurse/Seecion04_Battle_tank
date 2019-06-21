// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto tank = (GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControllTank = (GetPawn());
	if (tank && ControllTank)
	{
		MoveToActor(tank, AcceptaincRaidus);
		auto AimingComponet = ControllTank->FindComponentByClass<UTankAimingComponent>();
		if (!ensure(AimingComponet)) { return; }
		AimingComponet->AimAt(tank->GetActorLocation());
		AimingComponet->fire(); 
	}
	
}



