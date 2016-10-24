// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "Tank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* MyTank = GetControlledTank();
	if (!MyTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Not possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("The Controlled Tank is: %s"), *MyTank->GetName());
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowrdsCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowrdsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}


}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;

	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairX, ViewportSizeY * CrossHairY);
	FVector LookDirection;
	
	
	if (GetLookDirection(ScreenLocation,LookDirection))
	{
		
		HitLocation = GetLookVectorHitLocation(LookDirection);
	}
	

	return true;
}


bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraLocation, LookDirection);
	
}

FVector ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection) const
{
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, GetLineStart(), GetLineEnd(LookDirection), ECollisionChannel::ECC_Visibility);
	FVector HitLocat = HitResult.Location;
	return HitLocat;
}


FVector ATankPlayerController::GetLineEnd(FVector LookDirection) const
{
	return GetLineStart() + LookDirection * LineTraceRange;
}
FVector ATankPlayerController::GetLineStart() const
{
	return PlayerCameraManager->GetCameraLocation();
}