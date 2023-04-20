// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OdliczanieActor.generated.h"

UCLASS()
class TETRIS_API AOdliczanieActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOdliczanieActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:

	UPROPERTY(EditAnywhere)
		class USoundCue* Start;
	UPROPERTY(EditAnywhere)
		class USoundCue* MusicInGame;

	UPROPERTY(EditAnywhere)
		class UTextRenderComponent* Text;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor>Fade;
	void StartBlack();
	FTimerHandle Black;
	bool CzyBlack;

	UAudioComponent* AudioComponent;

	int Wait = 3;
	float ocs = 0;

	float MusicVolume = 0.1f;
	void ChangeMusicVolume();
	FTimerHandle MusicVolumeHandle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void StopMusicGame();
	void PlayMusicGame();
	void Czekaj();
	void TimerCzekaj();
	FTimerHandle CzekajHandle;
	bool CzyCzekac;
	TArray<AActor*>TetrisPawns;

};
