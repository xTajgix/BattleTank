// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATankAIController::ATankAIController() {
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!GetControlledTank()) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("No tank to controlled"));
		return; 
	}

	//TODO Move towards the Player

	//Aim towards the Player
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

	//TODO Fire if ready
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;
	auto AIControlledTank = GetControlledTank();
	if (AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possesing %s"), *(AIControlledTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller NOT possesing a Tank"));
	}
	auto PlayerControlledTank = GetPlayerTank();
	if (PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Tank found %s"), *(PlayerControlledTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Tank NOT found a Tank"));
	}
}
ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


