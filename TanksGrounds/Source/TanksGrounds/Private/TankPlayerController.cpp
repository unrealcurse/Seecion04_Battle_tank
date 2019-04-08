// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	FString logname = "";
	if (GetControlledTank())
	{
		logname = GetControlledTank()->GetName();
	}
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin play %s"),*logname);
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


