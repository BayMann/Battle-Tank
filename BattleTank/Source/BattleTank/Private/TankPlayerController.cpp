// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank(); //Get Player's Pawn
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank()) {return;}
	FVector HitLocation;
	GetSightRayHitLocation(HitLocation);
}
	

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation)
{
	int ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto CrosshairLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);
	
	FVector LookDirection;
	if (GetLookDirection(CrosshairLocation, LookDirection)) { UE_LOG(LogTemp, Warning, TEXT("Look Direction is at: %s"), *(LookDirection.ToString())) }
	else { UE_LOG(LogTemp, Warning, TEXT("Can't Find Look Direction")); }
	
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection*LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		UE_LOG(LogTemp, Warning, TEXT("Hit Location is at: %s"), *(HitLocation.ToString()))
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Cant find Hit Location"));
		return false;
	}

	
}


bool ATankPlayerController::GetLookDirection(FVector2D CrosshairLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation;
	if (DeprojectScreenPositionToWorld(CrosshairLocation.X, CrosshairLocation.Y, CameraWorldLocation, LookDirection)) { return true; }
	else { return false; }
}

