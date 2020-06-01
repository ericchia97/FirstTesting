// Fill out your copyright notice in the Description page of Project Settings.
// Saving the information about the slots itself (Example: the date being saved, the name of the slots)
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveMetaData.h"
#include "SaveGameMetaData.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTTESTING_API USaveGameMetaData : public USaveGame
{
	GENERATED_BODY()
	

public:
	UPROPERTY(VisibleAnywhere, Category = "Default")
	TMap<FString, FSaveMetaData> SavedMetaData;
};
