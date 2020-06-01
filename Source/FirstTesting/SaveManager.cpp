// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveManager.h"
#include "Kismet/GameplayStatics.h"
#include "SaveGameMetaData.h"
#include "SaveGameData.h"
#include "Engine/Engine.h"

static const FString kSavedMetaData = "SaveGameMetaData";
static const int32 num_MaxSavedSlots = 100;
FString USaveManager::CurrentSaveSlot;
TArray<TScriptInterface<ISaveInterface>> USaveManager::SaveInterfaces;

void USaveManager::Init()
{
	CurrentSaveSlot = "Default";

	//Make sure the metadata file exists in case the game has never ran
	USaveGame* saveGame_MetaData = UGameplayStatics::LoadGameFromSlot(kSavedMetaData, 0);

	if (saveGame_MetaData == nullptr)
	{
		//The metadata doesn't exists at the beginning, thus we need to create one
		USaveGame* saveGameSlot = UGameplayStatics::CreateSaveGameObject(USaveGameMetaData::StaticClass());

		UGameplayStatics::SaveGameToSlot(saveGameSlot, kSavedMetaData, 0);
	}
}


void USaveManager::QueryAllSaveInterface()
{
	//Clear the old entries
	SaveInterfaces.Empty();

	//Get all actors to implement the save interface
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsWithInterface(GWorld, USaveInterface::StaticClass(), actors);

	//Vectors for storing all the actors
	for (AActor* Actor : actors)
	{
		SaveInterfaces.Add(Actor);
	}
}

void USaveManager::SaveGame()
{
	//Create new save game data instance
	USaveGameData* saveGameData = Cast<USaveGameData>(UGameplayStatics::CreateSaveGameObject(USaveGameData::StaticClass()));

	//Go over all the actors that need to save and save them
	for (auto& saveInterface : SaveInterfaces)
	{
		if (saveInterface.GetObject() == nullptr)
		{
			continue;
		}

		//Let the actors know it will be saved
		saveInterface->Execute_OnBeforeSave(saveInterface.GetObject());

		//Find the objects saved data using its unique name (add a new entry and serialize the object)
		FString uniqueSavedName = saveInterface->Execute_GetUniqueSaveName(saveInterface.GetObject());
		FSaveData& saveData = saveGameData->SerializeData.Add(uniqueSavedName);

		FMemoryWriter memoryWriter = FMemoryWriter(saveData.Data);
		memoryWriter.ArIsSaveGame = true;

		saveInterface.GetObject()->Serialize(memoryWriter);
	}

	//Save game to current slot
	UGameplayStatics::SaveGameToSlot(saveGameData, CurrentSaveSlot, 0);

	//Update the metadata to a new slot
	USaveGameMetaData* saveGame_Metadata = Cast<USaveGameMetaData>(UGameplayStatics::LoadGameFromSlot(kSavedMetaData, 0));

	FSaveMetaData& SlotDetail = saveGame_Metadata->SavedMetaData.FindOrAdd(CurrentSaveSlot);
	SlotDetail.SlotName = CurrentSaveSlot;
	SlotDetail.Date = FDateTime::Now();

	//Save the changes to the metadata file
	UGameplayStatics::SaveGameToSlot(saveGame_Metadata, kSavedMetaData, 0);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Saved: " + CurrentSaveSlot);
	}
}

void USaveManager::LoadGame()
{
	USaveGameData* LoadSavedGameData = Cast<USaveGameData>(UGameplayStatics::LoadGameFromSlot(CurrentSaveSlot, 0));

	if (LoadSavedGameData == nullptr)
	{
		//No save file exist yet, save the default one
		SaveGame();
		LoadSavedGameData = Cast<USaveGameData>(UGameplayStatics::LoadGameFromSlot(CurrentSaveSlot, 0));
	}

	//Loop over all the actors that need to load
	for (auto& saveInterface : SaveInterfaces)
	{
		if (saveInterface.GetObject() == nullptr)
		{
			continue;
		}

		//Find the objects saved data using its unique name (add a new entry and serialize the object)
		FString uniqueSavedName = saveInterface->Execute_GetUniqueSaveName(saveInterface.GetObject());
		FSaveData* saveData = LoadSavedGameData->SerializeData.Find(uniqueSavedName);

		if (saveData == nullptr)
		{
			continue;
		}

		//Deserialize the object save data
		FMemoryReader memoryReader(saveData->Data);
		memoryReader.ArIsSaveGame = false;

		saveInterface.GetObject()->Serialize(memoryReader);
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, "Loaded: " + CurrentSaveSlot);
	}

}

void USaveManager::DeleteSlot(const FString & slot)
{
	//Delete the slot (Information data (Player's Health or etc))
	UGameplayStatics::DeleteGameInSlot(slot, 0);

	//Loading the metadata file 
	USaveGameMetaData* saveGame_Metadata = Cast<USaveGameMetaData>(UGameplayStatics::LoadGameFromSlot(kSavedMetaData, 0));
	//Remove metadata file
	saveGame_Metadata->SavedMetaData.Remove(slot);

	//Re-Saving the metadata file
	UGameplayStatics::SaveGameToSlot(saveGame_Metadata, kSavedMetaData, 0);
}

UPARAM(DisplayName = "Slot")FString USaveManager::GetNewGameSlot(bool & slot_found)
{
	slot_found = false;

	//Loading the metadata file 
	USaveGameMetaData* saveGame_Metadata = Cast<USaveGameMetaData>(UGameplayStatics::LoadGameFromSlot(kSavedMetaData, 0));

	for (int32 i = 0; i < num_MaxSavedSlots; ++i)
	{
		//Create slot name, started from SaveSlot 1
		FString SavedSlotName = "SaveSlot " + FString::FromInt(i);

		if (saveGame_Metadata->SavedMetaData.Contains(SavedSlotName) == false)
		{
			slot_found = true;
			return SavedSlotName;
		}
	}

	return FString();
}

void USaveManager::SetCurrentSaveSlot(const FString & currentSlot)
{
	CurrentSaveSlot = currentSlot;
}

FString USaveManager::GetCurrentSaveSlot()
{
	return CurrentSaveSlot;
}

TArray<FSaveMetaData> USaveManager::GetsAllSaveMetaData()
{
	TArray<FSaveMetaData> metadata;

	//Loading the metadata file 
	USaveGameMetaData* saveGame_Metadata = Cast<USaveGameMetaData>(UGameplayStatics::LoadGameFromSlot(kSavedMetaData, 0));
	
	metadata.Reserve(saveGame_Metadata->SavedMetaData.Num());

	//Add each saved game metadata to the return array
	for (const auto& saved_game : saveGame_Metadata->SavedMetaData)
	{
		metadata.Push(saved_game.Value);
	}

	return metadata;
}
