// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TetrisPawn.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class TETRIS_API ATetrisPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATetrisPawn();
	TArray<AActor*> Change;
	TArray<AActor*> CameraActors;

private:
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Fade;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> Fade2;

	UPROPERTY(EditAnywhere)
		class USoundCue* GameOver;
	UPROPERTY(EditAnywhere)
		class USoundCue* walniecie;

	float Time_Level = 1.f;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class UFloatingPawnMovement* FloatingMovement;

	FTimerHandle LeftTimer;
	FTimerHandle RightTimer;
	FTimerHandle DownTimer;
	FTimerHandle LocationTimer;
	FTimerHandle RightTimer_One;
	FTimerHandle LeftTimer_One;

	void PauseMenu();
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<class UUserWidget> PauseMenuWidgetClass;

	void GameOverMenu();
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<class UUserWidget> GameOverWidgetClass;

	void Hold();
	bool InnyRespawn;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int JakiPawn;

	int SoftPoints = 1;
	int HardPoints = 40;
	void AddPoints();
	int WhichPoints;

	UPROPERTY(EditAnywhere, Category = "StaticMesh")
		UStaticMeshComponent* Block1;

	UPROPERTY(EditAnywhere, Category = "Box Collision")
		UBoxComponent* BoxMain;

	UPROPERTY(EditAnywhere, Category = "Box Collision")
		UBoxComponent* Box1;

	UPROPERTY(EditAnywhere, Category = "StaticMesh")
		UStaticMeshComponent* Block2;

	UPROPERTY(EditAnywhere, Category = "Box Collision")
		UBoxComponent* Box2;

	UPROPERTY(EditAnywhere, Category = "StaticMesh")
		UStaticMeshComponent* Block3;

	UPROPERTY(EditAnywhere, Category = "Box Collision")
		UBoxComponent* Box3;

	UPROPERTY(EditAnywhere, Category = "StaticMesh")
		UStaticMeshComponent* Block4;

	UPROPERTY(EditAnywhere, Category = "Box Collision")
		UBoxComponent* Box4;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Right();
	void UnRight();
	void SetRight();
	bool bSetRight;
	bool RightTime;

	void Left();
	void UnLeft();
	void SetLeft();
	bool bSetLeft;
	bool LeftTime;

	int CzyRozjebac;
	int KtoraStrona = 1;

	int Kolor;

	int iBox1;
	int iBox2;
	int iBox3;
	int iBox4;

	bool bLocation;
	bool bPrawy;
	bool bLewy;
	bool bDead;
	bool bRespienie;

	bool bBoxExtent;
	bool bDown;
	bool bPrzegrana;

	bool bUp1;
	bool bTetris1;
	bool bUp2;
	bool bTetris2;
	bool bUp3;
	bool bTetris3;
	bool bUp4;
	bool bTetris4;

	bool bBox1OverlapDestroy;
	bool bBox2OverlapDestroy;
	bool bBox3OverlapDestroy;
	bool bBox4OverlapDestroy;

	bool bBox1Destroy;
	bool bBox2Destroy;
	bool bBox3Destroy;
	bool bBox4Destroy;

	bool bBox1OverlapEnd;
	bool bBox2OverlapEnd;
	bool bBox3OverlapEnd;
	bool bBox4OverlapEnd;

	void SetLocation();
	void RotatePlus();
	void RotateMinus();

	void Down();
	void UnDown();
	void SoftDrop();
	bool bSoftDrop;
	bool DropTime;

	void HardDrop();
	void Respawn();
	void Przegrana();

	UFUNCTION()
	void Box_1_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hit);

	UFUNCTION()
	void Box_2_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hit);

	UFUNCTION()
	void Box_3_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hit);

	UFUNCTION()
	void Box_4_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& Hit);

	UFUNCTION()
	void Box_1_OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void Box_2_OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void Box_3_OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void Box_4_OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

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

private:

	UMaterialInterface* Material;

};
