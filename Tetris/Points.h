// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Points.generated.h"

UCLASS()
class TETRIS_API APoints : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APoints();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool CzyInterpto;
	bool PierwszyRazControls;
	TArray<AActor*> CameraActors;
	FRotator RotacjaKamery;
	FRotator KoncowaRotacja;

	UPROPERTY(EditAnywhere)
		FString JakiButton;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material_1;

	UPROPERTY(EditAnywhere)
		UMaterialInterface* Material_2;

	UPROPERTY(EditAnywhere)
		bool CzyLiczby;

	UPROPERTY(EditAnywhere)
		class UTextRenderComponent* Text;

	UPROPERTY(EditAnywhere)
		int Points;

};
