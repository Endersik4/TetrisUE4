// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TetrisPawnController.generated.h"
class ATetrisPawn;

/**
 * 
 */
UCLASS()
class TETRIS_API ATetrisPawnController : public APlayerController
{
	GENERATED_BODY()

		ATetrisPawnController();

	UFUNCTION()
		virtual void SetupInputComponent() override;
public:

	void Respawn();
	virtual void Tick(float DeltaTime) override;
	float WaitTime = 3.3;

private:
	UPROPERTY(EditAnywhere)
		class USoundCue* MusicInGame;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ATetrisPawn> Pawn_T;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ATetrisPawn> Pawn_I;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ATetrisPawn> Pawn_J;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ATetrisPawn> Pawn_L;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ATetrisPawn> Pawn_O;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ATetrisPawn> Pawn_S;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ATetrisPawn> Pawn_Z;

protected:

	virtual void BeginPlay();
	FTimerHandle Pauza;
};
