// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s is aming at %s"), *TankName, *HitLocation.ToString());
}