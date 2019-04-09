// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	FString logname = "";
	if (GetPlayerTank())
	{
		logname = GetPlayerTank()->GetName();
	}
	UE_LOG(LogTemp, Warning, TEXT("Ai Controller  find player tank :  %s"), *logname);
}

ATank * ATankAIController::GetPlayerTank() const
{

	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn)
	{
		return Cast<ATank>(PlayerPawn);
	
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("UPSS"));
		return nullptr;
	}
	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
