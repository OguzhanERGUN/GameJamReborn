// Fill out your copyright notice in the Description page of Project Settings.


#include "GameJam/Enemies/Enemy.h"
#include "Components/DecalComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	StartingLocation = GetActorLocation();

}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


FVector AEnemy::GetNextPatrolLocation()
{
	if (!TargetPatrolLocations.Num()) 
		return StartingLocation;

	FVector NextLocation = TargetPatrolLocations[LastPatrolIndex++];
	LastPatrolIndex = LastPatrolIndex % TargetPatrolLocations.Num();
	return NextLocation;
}
