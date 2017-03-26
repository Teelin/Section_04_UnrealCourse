// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{

	
	auto AiForwardIntention = MoveVelocity.GetSafeNormal();
	auto TankForwardVector = GetOwner()->GetActorForwardVector().GetSafeNormal();

	auto AiForwardThrow = FVector::DotProduct(TankForwardVector, AiForwardIntention);
	IntendMoveForward(AiForwardThrow);

	auto AiRightVector = FVector::CrossProduct(TankForwardVector, AiForwardIntention).Z;
	IntendTurnRight(AiRightVector);

}

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}
void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}


