// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SaveMetaData.h"
#include "SaveInterface.h "
#include "SaveManager.generated.h"

/**
 * 
 */

UCLASS()
class FIRSTTESTING_API USaveManager : public UObject
{
	GENERATED_BODY()

private:
	//Current Save Slot
	static FString CurrentSaveSlot;

	//Array of all the actors in the game which implement the save interface
	static TArray<TScriptInterface<ISaveInterface>> SaveInterfaces;

public:
	//Initialize the class and must be called when the game starts
	static void Init();

	//Queries all actors and implements in the game interface
	static void QueryAllSaveInterface();
	
	//Save current game
	UFUNCTION(BlueprintCallable, Category = "SaveAndLoading")
	static void SaveGame();

	//Load current game
	UFUNCTION(BlueprintCallable, Category = "SaveAndLoading")
	static void LoadGame();

	//Delete game slot
	UFUNCTION(BlueprintCallable, Category = "SaveAndLoading")
	static void DeleteSlot(const FString& slot);

	//Gets a new, unused slot
	UFUNCTION(BlueprintPure, Category = "SaveAndLoading")
	static UPARAM(DisplayName = "Slot") FString GetNewGameSlot(bool& slot_found);

	//Sets current save slot to specified value
	UFUNCTION(BlueprintCallable, Category = "SaveAndLoading")
	static void SetCurrentSaveSlot(const FString& currentSlot);

	//Gets current save slot to specified value
	UFUNCTION(BlueprintPure, Category = "SaveAndLoading")
	static FString GetCurrentSaveSlot();

	//Gets all saved game
	UFUNCTION(BlueprintPure, Category = "SaveAndLoading")
	static TArray<FSaveMetaData> GetsAllSaveMetaData();
	
};
