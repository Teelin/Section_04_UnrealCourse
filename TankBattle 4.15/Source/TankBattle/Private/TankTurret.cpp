// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "TankTurret.h"


void UTankTurret::TurretRotate(float RelativeSpeed)
{

	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);

	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}

