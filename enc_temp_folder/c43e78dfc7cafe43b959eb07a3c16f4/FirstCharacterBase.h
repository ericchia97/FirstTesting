

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FirstCharacterBase.generated.h"

UCLASS()
class FIRSTTESTING_API AFirstCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstCharacterBase();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float Health;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
};
