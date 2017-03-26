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

protected:

	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;

private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	void AimTowrdsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairX = 0.5;
	UPROPERTY(EditDefaultsOnly)
		float CrossHairY = 0.33333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	FVector GetLookVectorHitLocation(FVector LookDirection) const;

	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.0f;

	FVector GetLineEnd(FVector LookDirection) const;
	FVector GetLineStart() const;
	

};
