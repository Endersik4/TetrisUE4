// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestroyActor.generated.h"

class UBoxComponent;
class ATetrisPawn;

UCLASS()
class TETRIS_API ADestroyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestroyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int LevelsDestroy = 1;

	UPROPERTY(EditAnywhere)
		class USoundCue* LineClear;
	bool CzyWykonacDestroy;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool CzyDestroy;
	bool CzyDestroy2;
	int IleDestroy = 1;

	int DestroyBlocks;
	TArray<ATetrisPawn*> Pawns;
	void UnoMomento();

	UPROPERTY(EditAnywhere)
		int JakiRodzaj;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* Box_Main;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* Box_1;

	UFUNCTION()
		void Box_1_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* Box_2;

	UFUNCTION()
		void Box_2_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hitr);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* Box_3;

	UFUNCTION()
		void Box_3_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* Box_4;

	UFUNCTION()
		void Box_4_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* Box_5;

	UFUNCTION()
		void Box_5_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* Box_6;

	UFUNCTION()
		void Box_6_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hitr);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* Box_7;

	UFUNCTION()
		void Box_7_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* Box_8;

	UFUNCTION()
		void Box_8_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* Box_9;

	UFUNCTION()
		void Box_9_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* Box_10;

	UFUNCTION()
		void Box_10_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hit);

};
