// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"

void UFoodItem::Use(class AFirstCharacterBase* Character)
{
	if (Character)
	{
		Character->Health += 10.f;
	}
}