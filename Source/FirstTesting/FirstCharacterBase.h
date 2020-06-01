

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Item.h"
#include "InventoryComponent.h"
#include "FirstCharacterBase.generated.h"

UCLASS()
class FIRSTTESTING_API AFirstCharacterBase : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UInventoryComponent* Inventory;
public:
	// Sets default values for this character's properties
	AFirstCharacterBase();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float Health;

	UFUNCTION(BlueprintCallable, Category = "Item")
	void UseItem(class UItem* Item);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
};
