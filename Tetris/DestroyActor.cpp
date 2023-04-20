// Fill out your copyright notice in the Description page of Project Settings.


#include "DestroyActor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TetrisPawn.h"
#include "Points.h"
#include "Components/TextRenderComponent.h"
#include "Sound/SoundCue.h"

// Sets default values
ADestroyActor::ADestroyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box_Main = CreateDefaultSubobject<UBoxComponent>(TEXT("Main"));
	RootComponent = Box_Main;

	//BOX 1//
	Box_1 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_1"));
	Box_1->SetupAttachment(Box_Main);
	Box_1->SetBoxExtent(FVector(85.f, 90.f, 90.f));
	Box_1->SetGenerateOverlapEvents(true);
	Box_1->OnComponentBeginOverlap.AddDynamic(this, &ADestroyActor::Box_1_OnOverlapBegin);
	
	//BOX 2//
	Box_2 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_2"));
	Box_2->SetupAttachment(Box_Main);
	Box_2->SetBoxExtent(FVector(85.f, 90.f, 90.f));
	Box_2->SetGenerateOverlapEvents(true);
	Box_2->OnComponentBeginOverlap.AddDynamic(this, &ADestroyActor::Box_2_OnOverlapBegin);

	//BOX 3//
	Box_3 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_3"));
	Box_3->SetupAttachment(Box_Main);
	Box_3->SetBoxExtent(FVector(85.f, 90.f, 90.f));
	Box_3->SetGenerateOverlapEvents(true);
	Box_3->OnComponentBeginOverlap.AddDynamic(this, &ADestroyActor::Box_3_OnOverlapBegin);

	//BOX 4//
	Box_4 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_4"));
	Box_4->SetupAttachment(Box_Main);
	Box_4->SetBoxExtent(FVector(85.f, 90.f, 90.f));
	Box_4->SetGenerateOverlapEvents(true);
	Box_4->OnComponentBeginOverlap.AddDynamic(this, &ADestroyActor::Box_4_OnOverlapBegin);

	//BOX 5//
	Box_5 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_5"));
	Box_5->SetupAttachment(Box_Main);
	Box_5->SetBoxExtent(FVector(85.f, 90.f, 90.f));
	Box_5->SetGenerateOverlapEvents(true);
	Box_5->OnComponentBeginOverlap.AddDynamic(this, &ADestroyActor::Box_5_OnOverlapBegin);

	//BOX 6//
	Box_6 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_6"));
	Box_6->SetupAttachment(Box_Main);
	Box_6->SetBoxExtent(FVector(85.f, 90.f, 90.f));
	Box_6->SetGenerateOverlapEvents(true);
	Box_6->OnComponentBeginOverlap.AddDynamic(this, &ADestroyActor::Box_6_OnOverlapBegin);

	//BOX 7//
	Box_7 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_7"));
	Box_7->SetupAttachment(Box_Main);
	Box_7->SetBoxExtent(FVector(85.f, 90.f, 90.f));
	Box_7->SetGenerateOverlapEvents(true);
	Box_7->OnComponentBeginOverlap.AddDynamic(this, &ADestroyActor::Box_7_OnOverlapBegin);

	//BOX 8//
	Box_8 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_8"));
	Box_8->SetupAttachment(Box_Main);
	Box_8->SetBoxExtent(FVector(85.f, 90.f, 90.f));
	Box_8->SetGenerateOverlapEvents(true);
	Box_8->OnComponentBeginOverlap.AddDynamic(this, &ADestroyActor::Box_8_OnOverlapBegin);

	//BOX 9//
	Box_9 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_9"));
	Box_9->SetupAttachment(Box_Main);
	Box_9->SetBoxExtent(FVector(85.f, 90.f, 90.f));
	Box_9->SetGenerateOverlapEvents(true);
	Box_9->OnComponentBeginOverlap.AddDynamic(this, &ADestroyActor::Box_9_OnOverlapBegin);

	//BOX 10//
	Box_10 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_10"));
	Box_10->SetupAttachment(Box_Main);
	Box_10->SetBoxExtent(FVector(85.f, 90.f, 90.f));
	Box_10->SetGenerateOverlapEvents(true);
	Box_10->OnComponentBeginOverlap.AddDynamic(this, &ADestroyActor::Box_10_OnOverlapBegin);
}

// Called when the game starts or when spawned
void ADestroyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADestroyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Pawns Num = %i"), Pawns.Num());
	//UE_LOG(LogTemp, Warning, TEXT("Rodzaj = %i DestroyBlock = %i"), JakiRodzaj, DestroyBlocks);
	if (JakiRodzaj == 1) UE_LOG(LogTemp, Warning, TEXT("DestroyBlock = %i"), DestroyBlocks);
	if (DestroyBlocks >= 10)
	{
		CzyWykonacDestroy = true;
		CzyDestroy = true;
		FTimerHandle elo;
		GetWorldTimerManager().SetTimer(elo, this, &ADestroyActor::UnoMomento, 1.f, false, 0.3f);
		/*TArray<AActor*> PointActor;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APoints::StaticClass(), PointActor);

		//LINES//
		auto Punkty = Cast<APoints>(PointActor[0]);
		Punkty->Points++;
		Punkty->Text->SetText(FText::AsNumber(Punkty->Points));

		//LEVELS//
		auto Levels = Cast<APoints>(PointActor[1]);
		if (Punkty->Points == 10 * Levels->Points)
		{
			Levels->Points++;
			Levels->Text->SetText(FText::AsNumber(Levels->Points));
		}


		for (int i = 0; i < 10; i++)
		{
			if (Pawns[i]->bBox1OverlapDestroy == true && Pawns[i]->iBox1 == JakiRodzaj) { Pawns[i]->bBox1Destroy = true; Pawns[i]->bBox1OverlapEnd = true;}
			if (Pawns[i]->bBox2OverlapDestroy == true && Pawns[i]->iBox2 == JakiRodzaj) { Pawns[i]->bBox2Destroy = true; Pawns[i]->bBox2OverlapEnd = true;}
			if (Pawns[i]->bBox3OverlapDestroy == true && Pawns[i]->iBox3 == JakiRodzaj) { Pawns[i]->bBox3Destroy = true; Pawns[i]->bBox3OverlapEnd = true;}
			if (Pawns[i]->bBox4OverlapDestroy == true && Pawns[i]->iBox4 == JakiRodzaj) { Pawns[i]->bBox4Destroy = true; Pawns[i]->bBox4OverlapEnd = true;}
		}
		Pawns.Empty();
		DestroyBlocks = 0;
		TArray<AActor*> TetrisPawns;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATetrisPawn::StaticClass(), TetrisPawns);
		for (int i = 0; i != TetrisPawns.Num(); i++)
		{
			auto Tetrisek = Cast<ATetrisPawn>(TetrisPawns[i]);
			if (Tetrisek->iBox1 > JakiRodzaj)
			{
				FVector Location = Tetrisek->Box1->GetRelativeLocation();
				if (Tetrisek->KtoraStrona == 1) Location.Z -= 180.f;
				else if (Tetrisek->KtoraStrona == 2) Location.X += 180.f;
				else if (Tetrisek->KtoraStrona == 3) Location.Z += 180.f;
				else if (Tetrisek->KtoraStrona == 4) Location.X -= 180.f;

				Tetrisek->Box1->SetRelativeLocation(Location);
			}
			if (Tetrisek->iBox2 > JakiRodzaj)
			{
				FVector Location = Tetrisek->Box2->GetRelativeLocation();
				if (Tetrisek->KtoraStrona == 1) Location.Z -= 180.f;
				else if (Tetrisek->KtoraStrona == 2) Location.X += 180.f;
				else if (Tetrisek->KtoraStrona == 3) Location.Z += 180.f;
				else if (Tetrisek->KtoraStrona == 4) Location.X -= 180.f;
				Tetrisek->Box2->SetRelativeLocation(Location);
			}
			if (Tetrisek->iBox3 > JakiRodzaj)
			{
				FVector Location = Tetrisek->Box3->GetRelativeLocation();
				if (Tetrisek->KtoraStrona == 1) Location.Z -= 180.f;
				else if (Tetrisek->KtoraStrona == 2) Location.X += 180.f;
				else if (Tetrisek->KtoraStrona == 3) Location.Z += 180.f;
				else if (Tetrisek->KtoraStrona == 4) Location.X -= 180.f;
				Tetrisek->Box3->SetRelativeLocation(Location);
			}
			if (Tetrisek->iBox4 > JakiRodzaj)
			{
				FVector Location = Tetrisek->Box4->GetRelativeLocation();
				if (Tetrisek->KtoraStrona == 1) Location.Z -= 180.f;
				else if (Tetrisek->KtoraStrona == 2) Location.X += 180.f;
				else if (Tetrisek->KtoraStrona == 3) Location.Z += 180.f;
				else if (Tetrisek->KtoraStrona == 4) Location.X -= 180.f;
				Tetrisek->Box4->SetRelativeLocation(Location);
			}
		}
		*/
	}

}
void ADestroyActor::UnoMomento()
{
	if (DestroyBlocks >= 10)
	{

		TArray<AActor*> PointActor;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APoints::StaticClass(), PointActor);

		//LINES//
		for (int i = 0; i != PointActor.Num(); i++)
		{
			auto Punkty = Cast<APoints>(PointActor[i]);
			if (Punkty->JakiButton == "Lines")
			{
				Punkty->Points++;
				Punkty->Text->SetText(FText::AsNumber(Punkty->Points));
			}
		}

		//LEVELS//
		for (int i = 0; i != PointActor.Num(); i++)
		{
			auto Levels = Cast<APoints>(PointActor[i]);
			if (Levels->JakiButton == "Level")
			{
				for (int j = 0; j != PointActor.Num(); j++)
				{
					auto Punkty = Cast<APoints>(PointActor[j]);
					if (Punkty->JakiButton == "Lines")
					{
						if (Punkty->Points == 10 * Levels->Points)
						{
							Levels->Points++;
							LevelsDestroy = Levels->Points;
							Levels->Text->SetText(FText::AsNumber(Levels->Points));
						}
					}
				}
			}
		}

		//SCORE//
		TArray<AActor*> DestroyActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADestroyActor::StaticClass(), DestroyActors);
		if (CzyDestroy2 == false)
		{
			for (int j = 0; j != DestroyActors.Num(); j++)
			{
				auto NiszczenieTetrisa = Cast<ADestroyActor>(DestroyActors[j]);
				if (NiszczenieTetrisa->CzyDestroy == true && NiszczenieTetrisa->JakiRodzaj != JakiRodzaj)
				{
					IleDestroy++;
					//UE_LOG(LogTemp, Warning, TEXT("RODZAJ = %i, DESTROY = %i"), JakiRodzaj, IleDestroy);
					NiszczenieTetrisa->CzyDestroy = false;
					NiszczenieTetrisa->CzyDestroy2 = true;
				}
				if (IleDestroy > 4) IleDestroy = 4;
			}
			for (int i = 0; i != PointActor.Num(); i++)
			{
				auto Score = Cast<APoints>(PointActor[i]);
				if (Score->JakiButton == "Score")
				{
					if (IleDestroy == 2 && CzyDestroy == true)
					{
						Score->Points += 300 * LevelsDestroy;
						//UE_LOG(LogTemp, Warning, TEXT("300 PUNKTOW | RODZAJ = %i"), JakiRodzaj);
					}
					else if (IleDestroy == 3 && CzyDestroy == true)
					{
						Score->Points += 500 * LevelsDestroy;
						//UE_LOG(LogTemp, Warning, TEXT("500 PUNKTOW | RODZAJ = %i"), JakiRodzaj);
					}
					else if (IleDestroy == 4 && CzyDestroy == true)
					{
						Score->Points += 800 * LevelsDestroy;
						//UE_LOG(LogTemp, Warning, TEXT("800 PUNKTOW | RODZAJ = %i"), JakiRodzaj);
					}
					else
					{
						Score->Points += 100 * LevelsDestroy;
					}
					Score->Text->SetText(FText::AsNumber(Score->Points));
					UGameplayStatics::PlaySound2D(this, LineClear);
				}
			}
		}	

		for (int i = 0; i < 10; i++)
		{
			if (Pawns[i]->bBox1OverlapDestroy == true && Pawns[i]->iBox1 == JakiRodzaj) { Pawns[i]->bBox1Destroy = true; Pawns[i]->bBox1OverlapEnd = true; }
			if (Pawns[i]->bBox2OverlapDestroy == true && Pawns[i]->iBox2 == JakiRodzaj) { Pawns[i]->bBox2Destroy = true; Pawns[i]->bBox2OverlapEnd = true; }
			if (Pawns[i]->bBox3OverlapDestroy == true && Pawns[i]->iBox3 == JakiRodzaj) { Pawns[i]->bBox3Destroy = true; Pawns[i]->bBox3OverlapEnd = true; }
			if (Pawns[i]->bBox4OverlapDestroy == true && Pawns[i]->iBox4 == JakiRodzaj) { Pawns[i]->bBox4Destroy = true; Pawns[i]->bBox4OverlapEnd = true; }
		}
		Pawns.Empty();
		DestroyBlocks = 0;

		TArray<AActor*> TetrisPawns;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATetrisPawn::StaticClass(), TetrisPawns);
		for (int i = 0; i != TetrisPawns.Num(); i++)
		{
			auto Tetrisek = Cast<ATetrisPawn>(TetrisPawns[i]);
			if (Tetrisek->iBox1 > JakiRodzaj && Tetrisek->bRespienie == true)
			{
				FVector Location = Tetrisek->Box1->GetRelativeLocation();
				if (Tetrisek->KtoraStrona == 1) Location.Z -= 180.f;
				else if (Tetrisek->KtoraStrona == 2) Location.X += 180.f;
				else if (Tetrisek->KtoraStrona == 3) Location.Z += 180.f;
				else if (Tetrisek->KtoraStrona == 4) Location.X -= 180.f;

				Tetrisek->Box1->SetRelativeLocation(Location);
			}
			if (Tetrisek->iBox2 > JakiRodzaj && Tetrisek->bRespienie == true)
			{
				FVector Location = Tetrisek->Box2->GetRelativeLocation();
				if (Tetrisek->KtoraStrona == 1) Location.Z -= 180.f;
				else if (Tetrisek->KtoraStrona == 2) Location.X += 180.f;
				else if (Tetrisek->KtoraStrona == 3) Location.Z += 180.f;
				else if (Tetrisek->KtoraStrona == 4) Location.X -= 180.f;
				Tetrisek->Box2->SetRelativeLocation(Location);
			}
			if (Tetrisek->iBox3 > JakiRodzaj && Tetrisek->bRespienie == true)
			{
				FVector Location = Tetrisek->Box3->GetRelativeLocation();
				if (Tetrisek->KtoraStrona == 1) Location.Z -= 180.f;
				else if (Tetrisek->KtoraStrona == 2) Location.X += 180.f;
				else if (Tetrisek->KtoraStrona == 3) Location.Z += 180.f;
				else if (Tetrisek->KtoraStrona == 4) Location.X -= 180.f;
				Tetrisek->Box3->SetRelativeLocation(Location);
			}
			if (Tetrisek->iBox4 > JakiRodzaj && Tetrisek->bRespienie == true)
			{
				FVector Location = Tetrisek->Box4->GetRelativeLocation();
				if (Tetrisek->KtoraStrona == 1) Location.Z -= 180.f;
				else if (Tetrisek->KtoraStrona == 2) Location.X += 180.f;
				else if (Tetrisek->KtoraStrona == 3) Location.Z += 180.f;
				else if (Tetrisek->KtoraStrona == 4) Location.X -= 180.f;
				Tetrisek->Box4->SetRelativeLocation(Location);
			}
		}
	}
	IleDestroy = 1;
	CzyDestroy = false;
	CzyDestroy2 = false;
	CzyWykonacDestroy = false;
}


void ADestroyActor::Box_1_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	auto MyTetrisPawn = Cast<ATetrisPawn>(OtherActor);
	Pawns.Add(MyTetrisPawn);
}

void ADestroyActor::Box_2_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	auto MyTetrisPawn1 = Cast<ATetrisPawn>(OtherActor);
	Pawns.Add(MyTetrisPawn1);
}

void ADestroyActor::Box_3_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	auto MyTetrisPawn2 = Cast<ATetrisPawn>(OtherActor);
	Pawns.Add(MyTetrisPawn2);
}

void ADestroyActor::Box_4_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	auto MyTetrisPawn3 = Cast<ATetrisPawn>(OtherActor);
	Pawns.Add(MyTetrisPawn3);
}

void ADestroyActor::Box_5_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	auto MyTetrisPawn4 = Cast<ATetrisPawn>(OtherActor);
	Pawns.Add(MyTetrisPawn4);
}

void ADestroyActor::Box_6_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	auto MyTetrisPawn5 = Cast<ATetrisPawn>(OtherActor);
	Pawns.Add(MyTetrisPawn5);
}

void ADestroyActor::Box_7_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	auto MyTetrisPawn6 = Cast<ATetrisPawn>(OtherActor);
	Pawns.Add(MyTetrisPawn6);
}

void ADestroyActor::Box_8_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	auto MyTetrisPawn7 = Cast<ATetrisPawn>(OtherActor);
	Pawns.Add(MyTetrisPawn7);
}

void ADestroyActor::Box_9_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	auto MyTetrisPawn8 = Cast<ATetrisPawn>(OtherActor);
	Pawns.Add(MyTetrisPawn8);
}

void ADestroyActor::Box_10_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	auto MyTetrisPawn9 = Cast<ATetrisPawn>(OtherActor);
	Pawns.Add(MyTetrisPawn9);
}

