// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
	ATank * GetControlledTank() const;
	
	void AimTowardCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation);
	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333;

	bool GetLookDirection(FVector2D CrosshairLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	UPROPERTY(EditAnywhere)
		int LineTraceRange = 1000000;
};
