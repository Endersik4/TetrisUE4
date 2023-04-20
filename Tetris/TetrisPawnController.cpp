// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrisPawnController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "TetrisPawn.h"
#include "NextActor.h"
#include "Sound/SoundCue.h"

ATetrisPawnController::ATetrisPawnController()
{

}

void ATetrisPawnController::BeginPlay()
{
	WaitTime = 3.3;
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);
}

void ATetrisPawnController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (WaitTime > 0 && WaitTime != 99)
	{
		WaitTime -= DeltaTime;
		return;
	}
	if (WaitTime <= 0 && WaitTime != 99)
	{
		UGameplayStatics::SetGamePaused(GetWorld(), false);
		GetWorldTimerManager().SetTimer(Pauza, this, &ATetrisPawnController::Respawn, 0.1f, false, 1.8f);
		WaitTime = 99;
	}
}

void ATetrisPawnController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
}

void ATetrisPawnController::Respawn()
{
		APlayerController* controller;
		controller = UGameplayStatics::GetPlayerController(this, 0);

		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		UWorld* World = GetWorld();
		int RandVal;// = FMath::FRandRange(1, 6);
	
		TArray<AActor*> NextActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANextActor::StaticClass(), NextActors);

		auto Next = Cast<ANextActor>(NextActors[0]);

		RandVal = Next->PierwszyPoziom;
		Next->PierwszyPoziom = Next->DrugiPoziom;
		Next->DrugiPoziom = Next->TrzeciPoziom;
		Next->Respienie();
		Next->PPoziom = Next->PierwszyPoziom;

		if (RandVal == 1)
		{
			const FVector SpawnLoc(0.f, 10.f, 3420.f);
			auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_T, FTransform(SpawnLoc), SpawnParameters);
			NewTetrisPawn->JakiPawn = RandVal;
			if (NewTetrisPawn)
			{
				controller->Possess(NewTetrisPawn);
			}
		}
		else if (RandVal == 2)
		{
			FVector SpawnLoc(0.f, 10.f, 3240.f);
			auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_I, FTransform(SpawnLoc), SpawnParameters);
			NewTetrisPawn->JakiPawn = RandVal;
			if (NewTetrisPawn)
			{
				controller->Possess(NewTetrisPawn);
			}
		}
		else if (RandVal == 3)
		{
			FVector SpawnLoc(0.f, 10.f, 3420.f);
			auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_J, FTransform(SpawnLoc), SpawnParameters);
			NewTetrisPawn->JakiPawn = RandVal;
			if (NewTetrisPawn)
			{
				controller->Possess(NewTetrisPawn);
			}
		}
		else if (RandVal == 4)
		{
			FVector SpawnLoc(0.f, 10.f, 3420.f);
			auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_L, FTransform(SpawnLoc), SpawnParameters);
			NewTetrisPawn->JakiPawn = RandVal;
			if (NewTetrisPawn)
			{
				controller->Possess(NewTetrisPawn);
			}
		}
		else if (RandVal == 5)
		{
			FVector SpawnLoc(-90.f, 10.f, 3510.f);
			auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_O, FTransform(SpawnLoc), SpawnParameters);
			NewTetrisPawn->JakiPawn = RandVal;
			if (NewTetrisPawn)
			{
				controller->Possess(NewTetrisPawn);
			}
		}
		else if (RandVal == 6)
		{
			FVector SpawnLoc(0.f, 10.f, 3420.f);
			auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_S, FTransform(SpawnLoc), SpawnParameters);
			NewTetrisPawn->JakiPawn = RandVal;
			if (NewTetrisPawn)
			{
				controller->Possess(NewTetrisPawn);
			}
		}
		else
		{
			FVector SpawnLoc(0.f, 10.f, 3420.f);
			auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_Z, FTransform(SpawnLoc), SpawnParameters);
			NewTetrisPawn->JakiPawn = RandVal;
			if (NewTetrisPawn)
			{
				controller->Possess(NewTetrisPawn);
			}
		}

}