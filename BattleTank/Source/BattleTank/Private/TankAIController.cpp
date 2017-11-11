// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay ()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) { UE_LOG(LogTemp, Warning, TEXT("Cant get a tank pawn for this AI")); }
	else { UE_LOG(LogTemp, Warning, TEXT("This AI's tank is: %s"), *(ControlledTank->GetName())); }
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (GetPlayerTank()) { GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation()); }
}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr;}
	else { return Cast<ATank>(PlayerPawn); }
}