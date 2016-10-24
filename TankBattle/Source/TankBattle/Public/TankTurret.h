// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void TurretRotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, category = Setup)
		float MaxDegreesPerSecond = 20;
	
	
};
