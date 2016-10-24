// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
class ATank;

UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	void AimTowrdsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrossHairX = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossHairY = 0.33333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	FVector GetLookVectorHitLocation(FVector LookDirection) const;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0f;

	FVector GetLineEnd(FVector LookDirection) const;
	FVector GetLineStart() const;
	

};
