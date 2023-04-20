// Fill out your copyright notice in the Description page of Project Settings.


#include "OdliczanieActor.h"
#include "Components/TextRenderComponent.h"
#include "TetrisPawn.h"
#include "Kismet/GameplayStatics.h"
#include "ChangeCamera.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"

// Sets default values
AOdliczanieActor::AOdliczanieActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Czas"));
	Text->SetTextRenderColor(FColor::Black);
	Text->SetText(FText::AsNumber(Wait));
}

// Called when the game starts or when spawned
void AOdliczanieActor::BeginPlay()
{
	Super::BeginPlay();
	AudioComponent = UGameplayStatics::SpawnSound2D(this, MusicInGame, MusicVolume);
	AudioComponent->SetPaused(true);
	//GetWorldTimerManager().SetTimer()

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector SpawnLoc(-170.f, 2900.f, 1810.f);
	FRotator SpawnRot(0.f, 90.f, 0.f);
	GetWorld()->SpawnActor<AActor>(Fade, SpawnLoc, SpawnRot, SpawnParameters);

	GetWorldTimerManager().SetTimer(Black, this, &AOdliczanieActor::StartBlack, 0.1f, false, 1.5f);
}

// Called every frame
void AOdliczanieActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (CzyBlack == true)
	{
		ocs += DeltaTime;

		if (ocs > 1.0f && Wait == 3) Wait--;
		else if (ocs > 2.0f && Wait == 2) Wait--;
		else if (ocs > 3.0f && Wait == 1) Wait--;
		else if (ocs > 3.7f && Wait == 0)
		{
			UGameplayStatics::PlaySound2D(this, Start);
			if (MusicVolume == 0.10f) GetWorldTimerManager().SetTimer(MusicVolumeHandle, this, &AOdliczanieActor::ChangeMusicVolume, 0.04f, true, 0.04f);
			PlayMusicGame();

			Text->SetVisibility(false);
			if (CzyCzekac == true)
			{
				UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATetrisPawn::StaticClass(), TetrisPawns);
				for (int i = 0; i != TetrisPawns.Num(); i++)
				{
					auto Tetris = Cast<ATetrisPawn>(TetrisPawns[i]);
					if (Tetris->bRespienie == false)
					{
						Tetris->bLocation = false;
						Tetris->bDead = false;

						TArray<AActor*> Change;
						UGameplayStatics::GetAllActorsOfClass(GetWorld(), AChangeCamera::StaticClass(), Change);
						auto cos = Cast<AChangeCamera>(Change[0]);
						cos->CzyInterpto = false;

						break;
					}
				}
				CzyCzekac = false;

			}
			Wait = 99;
		}
		Text->SetText(FText::AsNumber(Wait));
	}
}

void AOdliczanieActor::ChangeMusicVolume()
{
	MusicVolume += 0.01f;
	AudioComponent->SetVolumeMultiplier(MusicVolume);
	if (MusicVolume >= 1.00f) GetWorldTimerManager().ClearTimer(MusicVolumeHandle);
}

void AOdliczanieActor::StartBlack()
{
	CzyBlack = true;
}

void AOdliczanieActor::Czekaj()
{
	Text->SetVisibility(true);
	ocs = 0;
	Wait = 3;
	CzyCzekac = true;
}

void AOdliczanieActor::TimerCzekaj()
{
	GetWorldTimerManager().SetTimer(CzekajHandle, this, &AOdliczanieActor::Czekaj, 0.1f, false, 1.5f);
}

void AOdliczanieActor::StopMusicGame()
{
	//AudioComponent->SetActive(false);
	AudioComponent->SetPaused(true);
}

void AOdliczanieActor::PlayMusicGame()
{
	//AudioComponent->SetActive(true);
	AudioComponent->SetPaused(false);
}
