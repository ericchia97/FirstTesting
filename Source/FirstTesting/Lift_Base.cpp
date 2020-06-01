// Fill out your copyright notice in the Description page of Project Settings.


#include "Lift_Base.h"
#include "FirstCharacterBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
ALift_Base::ALift_Base()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Root Component
	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("USceneComponent"));
	SetRootComponent(RootSceneComponent); //set it to the created SceneComponent or the system will choose DefaultedSceneComponent as default

	// Create Static Mesh Component
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("UStaticMesh"));
	StaticMesh->SetupAttachment(RootSceneComponent);

	// Create BoxCollider Component
	BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("UTriggerBox"));
	BoxCollider->SetupAttachment(StaticMesh);
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ALift_Base::LiftTriggered);
}

// Called when the game starts or when spawned
void ALift_Base::BeginPlay()
{
	Super::BeginPlay();

	StartingHeight = GetActorLocation().Z;
	EndingHeight = StartingHeight + LiftHeight;
	
}

// Called every frame
void ALift_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALift_Base::LiftTriggered(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AFirstCharacterBase* CastedChracter = Cast<AFirstCharacterBase>(OtherActor);

	if (CastedChracter != nullptr)
	{
		//up or lower the lift
		UpdateLiftHeight();
	}
}