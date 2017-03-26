// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBattle.h"
#include "Tank.h"
#include "TankAiController.h"

void ATankAiController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto AiTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{

		MoveToActor(PlayerTank, AcceptanceRadius);
		AiTank->AimAt(PlayerTank->GetActorLocation());

		AiTank->Fire();
	}
}



