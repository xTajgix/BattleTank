// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:
	ATank * GetControlledTank() const;

	//Start the tank moving the barrel so that a shot would it where the crosshair intersects the world
	void AimTowardsCrosshair();

	//Return an out parameter, it is true if hit the landscape
	bool GetSightRayHitLocation(FVector & OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector & OutHitLocation, FVector LookDirection) const;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.f;

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333f;
};
