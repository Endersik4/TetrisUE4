// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Napis_Actor.generated.h"

UCLASS()
class TETRIS_API ANapis_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANapis_Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
		class USoundCue* Walniecie;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Main_1;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Main_2;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Main_3;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Main_4;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Main_5;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Main_6;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Main_7;

	TArray<AActor*> Main1, Main2, Main3, Main4, Main5, Main6, Main7;

	void SetLocation();

	int int_Main1, int_Main2, int_Main3, int_Main4, int_Main5, int_Main6, int_Main7;
	FTimerHandle Czas;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
