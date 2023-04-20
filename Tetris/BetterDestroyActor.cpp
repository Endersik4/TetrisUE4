// Fill out your copyright notice in the Description page of Project Settings.


#include "BetterDestroyActor.h"
#include "TetrisPawn.h"
#include "Components/BoxComponent.h"

// Sets default values
ABetterDestroyActor::ABetterDestroyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box_Main = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_Main"));
	RootComponent = Box_Main;
	Box_Main->SetGenerateOverlapEvents(true);
	Box_Main->OnComponentBeginOverlap.AddDynamic(this, &ABetterDestroyActor::Box_Main_OnOverlapBegin);
}

// Called when the game starts or when spawned
void ABetterDestroyActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABetterDestroyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Pawns Num = %i"), Pawns.Num());
	UE_LOG(LogTemp, Warning, TEXT("DestroyBlock = %i"), DestroyBlocks);
	if (DestroyBlocks >= 10)
	{
		for (int i = 0; i < 10; i++)
		{
			if (Pawns[i]->bBox1OverlapDestroy == true) { Pawns[i]->bBox1Destroy = true; }
			if (Pawns[i]->bBox2OverlapDestroy == true) { Pawns[i]->bBox2Destroy = true; }
			if (Pawns[i]->bBox3OverlapDestroy == true) { Pawns[i]->bBox3Destroy = true; }
			if (Pawns[i]->bBox4OverlapDestroy == true) { Pawns[i]->bBox4Destroy = true; }
			//Pawns[i]->bLocation = false;
			//Pawns[i]->bDead = false;
			//Pawns[i]->bDestroyLocation = true;
		}
		Pawns.Empty();
		DestroyBlocks = 0;
	}
	/*
	if (Pawns.Num() >= 10)
	{
		for (int i = 0; i < Pawns.Num(); i++)
		{
			if (Pawns[i]->bBox1OverlapDestroy == true) { Pawns[i]->bBox1Destroy = true; }
			if (Pawns[i]->bBox2OverlapDestroy == true) { Pawns[i]->bBox2Destroy = true; }
			if (Pawns[i]->bBox3OverlapDestroy == true) { Pawns[i]->bBox3Destroy = true; }
			if (Pawns[i]->bBox4OverlapDestroy == true) { Pawns[i]->bBox4Destroy = true; }
			//Pawns[i]->bDestroyLocation = true;
			//Pawns[i]->bLocation = false;
			//Pawns[i]->bDead = false;-
		}
		Pawns.Empty();
		DestroyBlocks = 0;
	}
	*/
}

void ABetterDestroyActor::Box_Main_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	auto MyTetrisPawn = Cast<ATetrisPawn>(OtherActor);
	if (MyTetrisPawn->bBox1OverlapDestroy == true) DestroyBlocks++;
	if (MyTetrisPawn->bBox2OverlapDestroy == true) DestroyBlocks++;
	if (MyTetrisPawn->bBox3OverlapDestroy == true) DestroyBlocks++;
	if (MyTetrisPawn->bBox4OverlapDestroy == true) DestroyBlocks++;
	Pawns.Add(MyTetrisPawn);
}


