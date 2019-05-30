// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialize(UTankTrack* leftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!leftTrackToSet || !RightTrackToSet) { return; }
	leftTrack = leftTrackToSet;
	RightTrack = RightTrackToSet;
}



void UTankMovementComponent::IntendMoveForward(float Throw)
{
	
	leftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}
void UTankMovementComponent::IntendTurnRight(float Throw)
{
	leftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AiForwardIntention = MoveVelocity.GetSafeNormal();
	float ForwardThrow = FVector::DotProduct(TankForward, AiForwardIntention);
	auto TurndThrow = FVector::CrossProduct(TankForward, AiForwardIntention);

	IntendTurnRight(TurndThrow.Z);
	IntendMoveForward(ForwardThrow);
}
