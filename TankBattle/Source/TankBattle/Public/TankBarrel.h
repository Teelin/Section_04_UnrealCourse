// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, category = Setup)
		float MaxDegreesPerSecond = 10;
	UPROPERTY(EditAnywhere, category = Setup)
		float MaxElevationDegrees = 40;
	UPROPERTY(EditAnywhere, category = Setup)
		float MinElevationDegrees = 0;
	
};
