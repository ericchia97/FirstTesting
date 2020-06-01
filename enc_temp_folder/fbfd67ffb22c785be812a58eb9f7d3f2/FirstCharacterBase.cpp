// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstCharacterBase.h"

// Sets default values
AFirstCharacterBase::AFirstCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = 100.f;

}

// Called when the game starts or when spawned
void AFirstCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AFirstCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

