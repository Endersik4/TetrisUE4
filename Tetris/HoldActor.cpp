// Fill out your copyright notice in the Description page of Project Settings.


#include "HoldActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "TetrisPawn.h"

// Sets default values
AHoldActor::AHoldActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHoldActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHoldActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHoldActor::CzyZrespic()
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (CzyHoldZajety == true)
	{
		TArray<AActor*> PierwszyActor;
		switch (PoprzedniPawn)
		{
		case 1: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_T, PierwszyActor); } break;
		case 2: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_I, PierwszyActor); } break;
		case 3: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_J, PierwszyActor); } break;
		case 4: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_L, PierwszyActor); } break;
		case 5: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_O, PierwszyActor); } break;
		case 6: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_S, PierwszyActor); } break;
		case 7: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_Z, PierwszyActor); } break;
		}
		PierwszyActor[0]->Destroy();
		PierwszyActor.Empty();
	}
	 
	if (JakiPawn == 1)
	{
		const FVector SpawnLoc(2110.f, 455.f, 2560.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_T, SpawnLoc, SpawnRot, SpawnParameters);
		PoprzedniPawn = 1;
	}
	else if (JakiPawn == 2)
	{
		const FVector SpawnLoc(2190.f, 505.f, 2630.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_I, SpawnLoc, SpawnRot, SpawnParameters);
		PoprzedniPawn = 2;
	}
	else if (JakiPawn == 3)
	{
		const FVector SpawnLoc(2110.f, 455.f, 2560.f);
		const FRotator SpawnRot(-90.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_J, SpawnLoc, SpawnRot, SpawnParameters);
		PoprzedniPawn = 3;
	}
	else if (JakiPawn == 4)
	{
		const FVector SpawnLoc(2110.f, 455.f, 2560.f);
		const FRotator SpawnRot(90.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_L, SpawnLoc, SpawnRot, SpawnParameters);
		PoprzedniPawn = 4;
	}
	else if (JakiPawn == 5)
	{
		const FVector SpawnLoc(2110.f, 455.f, 2620.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_O, SpawnLoc, SpawnRot, SpawnParameters);
		PoprzedniPawn = 5;
	}
	else if (JakiPawn == 6)
	{
		const FVector SpawnLoc(2110.f, 455.f, 2560.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_S, SpawnLoc, SpawnRot, SpawnParameters);
		PoprzedniPawn = 6;
	}
	else
	{
		const FVector SpawnLoc(2110.f, 455.f, 2560.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_Z, SpawnLoc, SpawnRot, SpawnParameters);
		PoprzedniPawn = 7;
	}
}

