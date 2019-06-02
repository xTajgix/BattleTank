// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
	//AimTowardsCrosshair
	UE_LOG(LogTemp, Warning, TEXT("It is woring!"));
}

void ATankPlayerController::BeginPlay()
{
	auto ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possesing %s"), *(ControlledTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possesing a Tank"));
	}
}


ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	//Get the world location if linetrace throught crosshair
	//If it hits the lanscape
		//Tell controlled tank to aim at this point
}


