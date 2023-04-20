// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BetterDestroyActor.generated.h"

class UBoxComponent;
class ATetrisPawn;

UCLASS()
class TETRIS_API ABetterDestroyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABetterDestroyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int DestroyBlocks;
	TArray<ATetrisPawn*> Pawns;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* Box_Main;

	UFUNCTION()
		void Box_Main_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hit);
};