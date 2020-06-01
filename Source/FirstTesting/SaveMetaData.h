#pragma once

#include "Runtime/CoreUObject/Public/UObject/Class.h"
#include "Runtime/Core/Public/Misc/DateTime.h"
#include "SaveMetaData.generated.h"


USTRUCT(BlueprintType)
struct FSaveMetaData
{
	GENERATED_BODY()

	//Name of the Slot
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	FString SlotName;

	//Date of the slot created
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Default")
	FDateTime Date;
};