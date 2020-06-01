// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstTesting_GameModeBase.h"
#include "SaveManager.h"
#include "FirstCharacterBase.h"
#include "UObject/ConstructorHelpers.h"

AFirstTesting_GameModeBase::AFirstTesting_GameModeBase()
{
	//Set default pawn class to out Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonBP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AFirstTesting_GameModeBase::InitGameState()
{
	USaveManager::QueryAllSaveInterface();
	USaveManager::LoadGame();

	Super::InitGameState();
}