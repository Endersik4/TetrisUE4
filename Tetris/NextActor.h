// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NextActor.generated.h"

UCLASS()
class TETRIS_API ANextActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANextActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Respienie();
	int PierwszyPoziom;
	int PPoziom;
	int DrugiPoziom;
	int TrzeciPoziom;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Pawn_T;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Pawn_I;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Pawn_J;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Pawn_L;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Pawn_O;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Pawn_S;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Pawn_Z;

};
