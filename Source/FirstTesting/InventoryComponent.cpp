// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	Capacity = 20;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	for (auto& Item : DefaultItems)
	{
		AddItem(Item);
	}
	
}


bool UInventoryComponent::AddItem(class UItem* Item)
{

	if (Items.Num() >= Capacity || !Item)
	{
		return true;
	}
	Item->OwnedInventory = this;
	Item->World = GetWorld();
	Items.Add(Item);

	//Update UI
	OnInventoryUpdated.Broadcast();

	return true;
}

bool UInventoryComponent::RemoveItem(class UItem* Item)
{
	if (Item)
	{
		Item->OwnedInventory = nullptr;
		Item->World = nullptr;
		Items.RemoveSingle(Item);
		OnInventoryUpdated.Broadcast();
		return true;
	}
	return false;
}


