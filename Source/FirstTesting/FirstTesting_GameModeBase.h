// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FirstTesting_GameModeBase.generated.h"

/**
 * 
 */
UCLASS(minimalapi)
class AFirstTesting_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()


public:
	AFirstTesting_GameModeBase();

	virtual void InitGameState() override;
	
};
