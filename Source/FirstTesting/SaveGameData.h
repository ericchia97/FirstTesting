// Fill out your copyright notice in the Description page of Project Settings.
// Saving the information of the data (example: Player's Health) (Data inside of the slots)
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveGameData.generated.h"


USTRUCT()
struct FSaveData
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	TArray<uint8> Data;
};
/**
 * 
 */
UCLASS()
class FIRSTTESTING_API USaveGameData : public USaveGame
{
	GENERATED_BODY()
	
public:

	//Maps the unique name to its data (exp: player's name, car's name) 
	UPROPERTY(VisibleAnywhere)
	TMap<FString, FSaveData> SerializeData;
};
