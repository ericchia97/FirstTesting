// Fill out your copyright notice in the Description page of Project Settings.


#include "LiftBase.h"

// Sets default values
ALiftBase::ALiftBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StartingHeight = GetActorLocation().Z;
	EndingHeight = StartingHeight + LiftHeight;

}

// Called when the game starts or when spawned
void ALiftBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALiftBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

