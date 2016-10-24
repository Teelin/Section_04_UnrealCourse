// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "Tank.h"
#include "TankAiController.h"



void ATankAiController::BeginPlay()
{
	Super::BeginPlay();

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Not possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("The Player Tank is: %s"), *PlayerTank->GetName());
	}

}
void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		AimAtPlAyer();
	}
}


ATank* ATankAiController::GetAiTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAiController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}

void ATankAiController::AimAtPlAyer() const
{
	GetAiTank()->AimAt(GetPlayerTank()->GetActorLocation());
}