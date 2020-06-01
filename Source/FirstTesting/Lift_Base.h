// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lift_Base.generated.h"

UCLASS()
class FIRSTTESTING_API ALift_Base : public AActor
{
	GENERATED_BODY()
	
private:
	float StartingHeight = .0f;
	float EndingHeight = .0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lift_Base", Meta = (AllowPrivateAccess = "true"))
	class USceneComponent* RootSceneComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lift_Base", Meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* StaticMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Lift_Base", Meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BoxCollider = nullptr;

	
public:	
	// Sets default values for this actor's properties
	ALift_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lift_Base")
	float LiftHeight = .0f;

	UFUNCTION(BlueprintImplementableEvent, Category = "Lift_Base")
	void UpdateLiftHeight();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "Lift_Base")
		float GetStartingHeight() const { return StartingHeight; }

	UFUNCTION(BlueprintPure, Category = "Lift_Base")
		float GetEndingHeight() const { return EndingHeight; }

private:
	UFUNCTION()
		void LiftTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
