// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SaveMetaData.h"
#include "UObject/NoExportTypes.h"
#include "SlotObject.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotDeleted, USlotObject*, slot);
/**
 * 
 */
UCLASS(BlueprintType)
class FIRSTTESTING_API USlotObject : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "SlotObject")
	FOnSlotDeleted OnSlotDeleted;

	UPROPERTY(BlueprintReadOnly, Category = "SlotObject", Meta = (ExposeOnSpawn = "true", AllowPrivateAccess = "true"))
	FSaveMetaData SaveMetaData = {};


};
