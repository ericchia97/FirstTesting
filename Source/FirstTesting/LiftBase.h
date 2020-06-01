// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LiftBase.generated.h"

UCLASS()
class FIRSTTESTING_API ALiftBase : public AActor
{
	GENERATED_BODY()

private:
	float StartingHeight = .0f;
	float EndingHeight = .0f;


public:	
	// Sets default values for this actor's properties
	ALiftBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, category = "LiftBase")
	float LiftHeight = .0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, category = "Testing")
		float GetStartingHeight() const { return StartingHeight; }

	UFUNCTION(BlueprintPure, category = "Testing")
		float GetEndingHeight() const { return EndingHeight; }
};
