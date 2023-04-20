// Fill out your copyright notice in the Description page of Project Settings.


#include "TetrisPawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "DestroyActor.h"
#include "Points.h"
#include "NextActor.h"
#include "Components/TextRenderComponent.h"
#include "Blueprint/UserWidget.h"
#include "ChangeCamera.h"
#include "Camera/CameraActor.h"
#include "HoldActor.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "OdliczanieActor.h"


// Sets default values
ATetrisPawn::ATetrisPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxMain = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxMain"));
	RootComponent = BoxMain;

	Box1 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box1"));
	Box1->SetupAttachment(BoxMain);
	Box1->SetBoxExtent(FVector(88.f, 90.f, 90.f));
	Block1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Block1"));
	Block1->SetupAttachment(Box1);

	Box2 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box2"));
	Box2->SetupAttachment(BoxMain);
	Box2->SetBoxExtent(FVector(88.f, 90.f, 90.f));
	Block2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Block2"));
	Block2->SetupAttachment(Box2);

	Box3 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box3"));
	Box3->SetupAttachment(BoxMain);
	Box3->SetBoxExtent(FVector(88.f, 90.f, 90.f));
	Block3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Block3"));
	Block3->SetupAttachment(Box3);

	Box4 = CreateDefaultSubobject<UBoxComponent>(TEXT("Box4"));
	Box4->SetupAttachment(BoxMain);
	Box4->SetBoxExtent(FVector(88.f, 90.f, 90.f));
	Block4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Block4"));
	Block4->SetupAttachment(Box4);

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));

	Box1->SetGenerateOverlapEvents(true);
	Box2->SetGenerateOverlapEvents(true);
	Box3->SetGenerateOverlapEvents(true);
	Box4->SetGenerateOverlapEvents(true);

	Box1->OnComponentBeginOverlap.AddDynamic(this, &ATetrisPawn::Box_1_OnOverlapBegin);
	Box2->OnComponentBeginOverlap.AddDynamic(this, &ATetrisPawn::Box_2_OnOverlapBegin);
	Box3->OnComponentBeginOverlap.AddDynamic(this, &ATetrisPawn::Box_3_OnOverlapBegin);
	Box4->OnComponentBeginOverlap.AddDynamic(this, &ATetrisPawn::Box_4_OnOverlapBegin);

	Box1->OnComponentEndOverlap.AddDynamic(this, &ATetrisPawn::Box_1_OnOverlapEnd);
	Box2->OnComponentEndOverlap.AddDynamic(this, &ATetrisPawn::Box_2_OnOverlapEnd);
	Box3->OnComponentEndOverlap.AddDynamic(this, &ATetrisPawn::Box_3_OnOverlapEnd);
	Box4->OnComponentEndOverlap.AddDynamic(this, &ATetrisPawn::Box_4_OnOverlapEnd);
}

// Called when the game starts or when spawned
void ATetrisPawn::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> PointsTime;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APoints::StaticClass(), PointsTime);

	for (int i = 0; i != PointsTime.Num(); i++)
	{
		auto Levels = Cast<APoints>(PointsTime[i]);
		if (Levels->JakiButton == "Level")
		{
			switch (Levels->Points)
			{
			case 1: Time_Level = 1.f; break;
			case 2: Time_Level = 0.793f; break;
			case 3: Time_Level = 0.6178f; break;
			case 4: Time_Level = 0.47273f; break;
			case 5: Time_Level = 0.3552f; break;
			case 6: Time_Level = 0.262f; break;
			case 7: Time_Level = 0.18968f; break;
			case 8: Time_Level = 0.13473f; break;
			case 9: Time_Level = 0.09388f; break;
			case 10: Time_Level = 0.06415f; break;
			case 11: Time_Level = 0.04298f; break;
			case 12: Time_Level = 0.02822f; break;
			case 13: Time_Level = 0.01815f; break;
			case 14: Time_Level = 0.01144f; break;
			case 15: Time_Level = 0.00706f; break;
			case 16: Time_Level = 0.00426f; break;
			case 17: Time_Level = 0.00252f; break;
			case 18: Time_Level = 0.00146f; break;
			case 19: Time_Level = 0.00082f; break;
			case 20: Time_Level = 0.00046f; break;
			}
			break;
		}
	}

	GetWorldTimerManager().SetTimer(LocationTimer, this, &ATetrisPawn::SetLocation, Time_Level, true, 0.f);

	/*Material = Block1->GetMaterial(0);
	UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(Material, this);

	Block1->SetMaterial(0, DynamicMaterial);
	Block2->SetMaterial(0, DynamicMaterial);
	Block3->SetMaterial(0, DynamicMaterial);
	Block4->SetMaterial(0, DynamicMaterial);
	DynamicMaterial->SetScalarParameterValue(TEXT("EmissiveStrength"), 50);
	//TO NIE JEST LOSOWE 
	int Which_Color = FMath::RandRange(0, 4);
	switch (Which_Color)
	{
	case 0:
		DynamicMaterial->SetVectorParameterValue(TEXT("Color"), FColor::FromHex("0055FF00")); //BLUE
		break;
	case 1:
		DynamicMaterial->SetVectorParameterValue(TEXT("Color"), FColor::FromHex("FFEB7F00")); //YELLOW
		break;
	case 2:
		DynamicMaterial->SetVectorParameterValue(TEXT("Color"), FColor::FromHex("FF270000")); //RED
		break;
	case 3:
		DynamicMaterial->SetVectorParameterValue(TEXT("Color"), FColor::FromHex("00F4FF00")); //LIGHT BLUE
		break;
	case 4:
		DynamicMaterial->SetVectorParameterValue(TEXT("Color"), FColor::FromHex("FF950000")); //ORANGE
		break;
	default:
		DynamicMaterial->SetVectorParameterValue(TEXT("Color"), FColor::FromHex("00FF2600")); //GREEN
		break;
	}
	*/
}

// Called every frame
void ATetrisPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDown == true)
	{
		FVector Location = BoxMain->GetComponentLocation();
		Location.Z -= 180;
		SetActorLocation(Location);
	}

	if (CzyRozjebac >= 4) Destroy();

	/*if (bBox1Destroy == true)
	{
		Block1->DestroyComponent();
		Box1->DestroyComponent();
		CzyRozjebac++;
		bBox1Destroy = false;
	}
	if (bBox2Destroy == true)
	{
		Block2->DestroyComponent();
		Box2->DestroyComponent();
		CzyRozjebac++;
		bBox2Destroy = false;
	}
	if (bBox3Destroy == true)
	{
		Block3->DestroyComponent();
		Box3->DestroyComponent();
		CzyRozjebac++;
		bBox3Destroy = false;
	}
	if (bBox4Destroy == true)
	{
		Block4->DestroyComponent();
		Box4->DestroyComponent();
		CzyRozjebac++;
		bBox4Destroy = false;
	}
	*/

	if (bBox1Destroy == true)
	{
		Block1->SetVisibility(false);
		Box1->SetVisibility(false);
		Box1->SetGenerateOverlapEvents(false);
		CzyRozjebac++;
		bBox1Destroy = false;
	}
	if (bBox2Destroy == true)
	{
		Block2->SetVisibility(false);
		Box2->SetVisibility(false);
		Box2->SetGenerateOverlapEvents(false);
		CzyRozjebac++;
		bBox2Destroy = false;
	}
	if (bBox3Destroy == true)
	{
		Block3->SetVisibility(false);
		Box3->SetVisibility(false);
		Box3->SetGenerateOverlapEvents(false);
		CzyRozjebac++;
		bBox3Destroy = false;
	}
	if (bBox4Destroy == true)
	{
		Block4->SetVisibility(false);
		Box4->SetVisibility(false);
		Box4->SetGenerateOverlapEvents(false);
		CzyRozjebac++;
		bBox4Destroy = false;
	}
}

// Called to bind functionality to input
void ATetrisPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Soft_Drop", IE_Pressed, this, &ATetrisPawn::Down);
	InputComponent->BindAction("Soft_Drop", IE_Released, this, &ATetrisPawn::UnDown);

	InputComponent->BindAction("Hard_Drop", IE_Pressed, this, &ATetrisPawn::HardDrop);

	InputComponent->BindAction("Right", IE_Pressed, this, &ATetrisPawn::Right);
	InputComponent->BindAction("Right", IE_Released, this, &ATetrisPawn::UnRight);
	InputComponent->BindAction("Left", IE_Pressed, this, &ATetrisPawn::Left);
	InputComponent->BindAction("Left", IE_Released, this, &ATetrisPawn::UnLeft);

	InputComponent->BindAction("RotateQ", IE_Pressed, this, &ATetrisPawn::RotateMinus);
	InputComponent->BindAction("RotateE", IE_Pressed, this, &ATetrisPawn::RotatePlus);

	InputComponent->BindAction("Pause", IE_Pressed, this, &ATetrisPawn::PauseMenu);
	InputComponent->BindAction("Hold", IE_Pressed, this, &ATetrisPawn::Hold);
	
}


void ATetrisPawn::PauseMenu()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AChangeCamera::StaticClass(), Change);
	auto cos = Cast<AChangeCamera>(Change[0]);
	cos->CzyInterpto = true;
	cos->KoncowaRotacja.Yaw = 0.f;
	UUserWidget* Widget = CreateWidget(GetWorld(), PauseMenuWidgetClass);

	TArray<AActor*> Odliczanie;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOdliczanieActor::StaticClass(), Odliczanie);
	auto CastOdliczanie = Cast<AOdliczanieActor>(Odliczanie[0]);
	CastOdliczanie->StopMusicGame();

	if (Widget)
	{
		Widget->AddToViewport();
	}

	bLocation = true;
	bDead = true;
}

void ATetrisPawn::GameOverMenu()
{
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector SpawnLoc(-700.f, 4300.f, 1810.f);
	auto GameOverFade = GetWorld()->SpawnActor<AActor>(Fade2, FTransform(SpawnLoc), SpawnParameters);

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
	auto cos = Cast<ACameraActor>(CameraActors[0]);
	cos->SetActorRotation(FRotator(0.f, -180.f, 0.f));
	UUserWidget* Widget = CreateWidget(GetWorld(), GameOverWidgetClass);

	if (Widget)
	{
		Widget->AddToViewport();
	}
}

void ATetrisPawn::AddPoints()
{
	TArray<AActor*> PointActor;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APoints::StaticClass(), PointActor);
	for (int i = 0; i != PointActor.Num(); i++)
	{
		auto Punkty = Cast<APoints>(PointActor[i]);
		if (Punkty->JakiButton == "Score")
		{
			if (WhichPoints == 1)
			{
				Punkty->Points += SoftPoints;
			}
			else if (WhichPoints == 2)
			{
				Punkty->Points += HardPoints;
			}

			Punkty->Text->SetText(FText::AsNumber(Punkty->Points));
		}
	}
}

void ATetrisPawn::Hold()
{
	if (bDead == false)
	{
		TArray<AActor*> HoldActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHoldActor::StaticClass(), HoldActors);

		auto HoldCast = Cast<AHoldActor>(HoldActors[0]);
		if (HoldCast->CzyMozna == false)
		{
			HoldCast->JakiPawn = JakiPawn;
			if (HoldCast->CzyHoldZajety == true)
			{
				JakiPawn = HoldCast->PoprzedniPawn;
				InnyRespawn = true;
			}
			HoldCast->CzyZrespic();

			Destroy();
			Respawn();
			HoldCast->CzyHoldZajety = true;
			HoldCast->CzyMozna = true;
		}
	}
}

void ATetrisPawn::SetRight()
{
	if (bSetRight == true && bDead == false)
	{
		FVector Location = BoxMain->GetComponentLocation();
		Location.X += 180;
		SetActorLocation(Location);
		if (RightTime == false)
		{
			GetWorldTimerManager().SetTimer(RightTimer, this, &ATetrisPawn::SetRight, 0.1f, true, 0.f);
			RightTime = true;
		}
	}
}

void ATetrisPawn::Right()
{
	if (bPrawy == false && bDead == false)
	{
		FVector Location = BoxMain->GetComponentLocation();
		Location.X += 180;
		SetActorLocation(Location);
		bSetRight = true;
		GetWorldTimerManager().SetTimer(RightTimer_One, this, &ATetrisPawn::SetRight, 0.3f, false, 0.4f);
	}
}

void ATetrisPawn::UnRight()
{
	if (bDead == false)
	{
		bSetRight = false;
		GetWorldTimerManager().ClearTimer(RightTimer);
		GetWorldTimerManager().ClearTimer(RightTimer_One);
		RightTime = false;
	}
}

void ATetrisPawn::SetLeft()
{
	if (bSetLeft == true && bDead == false)
	{
		FVector Location = BoxMain->GetComponentLocation();
		Location.X -= 180;
		SetActorLocation(Location);
		if (LeftTime == false)
		{
			GetWorldTimerManager().SetTimer(LeftTimer, this, &ATetrisPawn::SetLeft, 0.1f, true, 0.f);
			LeftTime = true;
		}
	}
}

void ATetrisPawn::Left()
{
	if (bLewy == false && bDead == false)
	{
		FVector Location = BoxMain->GetComponentLocation();
		Location.X -= 180;
		SetActorLocation(Location);
		bSetLeft = true;
		GetWorldTimerManager().SetTimer(LeftTimer_One, this, &ATetrisPawn::SetLeft, 0.3f, false, 0.4f);
	}
}

void ATetrisPawn::UnLeft()
{
	if (bDead == false)
	{
		bSetLeft = false;
		GetWorldTimerManager().ClearTimer(LeftTimer);
		GetWorldTimerManager().ClearTimer(LeftTimer_One);
		LeftTime = false;
	}
}

void ATetrisPawn::RotatePlus()
{
	if (bDead == false)
	{
		if (KtoraStrona == 4) KtoraStrona = 1;
		else if (KtoraStrona < 4) KtoraStrona++;
		if (bBoxExtent == true)
		{
			bBoxExtent = false;
		}
		else if (bBoxExtent == false)
		{
			bBoxExtent = true;
		}

		if (bBoxExtent == true)
		{
			Box1->SetBoxExtent(FVector(90.f, 90.f, 88.f));
			Box2->SetBoxExtent(FVector(90.f, 90.f, 88.f));
			Box3->SetBoxExtent(FVector(90.f, 90.f, 88.f));
			Box4->SetBoxExtent(FVector(90.f, 90.f, 88.f));
		}
		else if (bBoxExtent == false)
		{
			Box1->SetBoxExtent(FVector(88.f, 90.f, 90.f));
			Box2->SetBoxExtent(FVector(88.f, 90.f, 90.f));
			Box3->SetBoxExtent(FVector(88.f, 90.f, 90.f));
			Box4->SetBoxExtent(FVector(88.f, 90.f, 90.f));
		}

		FRotator Rotation = BoxMain->GetComponentRotation();

		if (Rotation.Pitch == 0.f) Rotation.Pitch = -90.f;
		else if (Rotation.Pitch == -90.f) Rotation.Pitch = -180.f;
		else if (Rotation.Pitch >= 0.f && Rotation.Pitch <= 1.f) Rotation.Pitch = 90.f;
		else if (Rotation.Pitch == 90.f) Rotation.Pitch = 0.f;

		SetActorRotation(Rotation);
	}
}

void ATetrisPawn::RotateMinus()
{
	if (bDead == false)
	{
		if (KtoraStrona == 1) KtoraStrona = 4;
		else if (KtoraStrona != 1) KtoraStrona--; 
		if (bBoxExtent == true)
		{
			bBoxExtent = false;
		}
		else if (bBoxExtent == false)
		{
			bBoxExtent = true;
		}

		if (bBoxExtent == true)
		{
			Box1->SetBoxExtent(FVector(90.f, 90.f, 88.f));
			Box2->SetBoxExtent(FVector(90.f, 90.f, 88.f));
			Box3->SetBoxExtent(FVector(90.f, 90.f, 88.f));
			Box4->SetBoxExtent(FVector(90.f, 90.f, 88.f));
		}
		else if (bBoxExtent == false)
		{
			Box1->SetBoxExtent(FVector(88.f, 90.f, 90.f));
			Box2->SetBoxExtent(FVector(88.f, 90.f, 90.f));
			Box3->SetBoxExtent(FVector(88.f, 90.f, 90.f));
			Box4->SetBoxExtent(FVector(88.f, 90.f, 90.f));
		}

		FRotator Rotation = BoxMain->GetComponentRotation();

		if (Rotation.Pitch == 0.f) Rotation.Pitch = 90.f;
		else if (Rotation.Pitch == 90.f) Rotation.Pitch = -180.f;
		else if (Rotation.Pitch >= 0.f && Rotation.Pitch <= 1.f) Rotation.Pitch = -90.f;
		else if (Rotation.Pitch == -90.f) Rotation.Pitch = 0.f;

		SetActorRotation(Rotation);
	}
}

void ATetrisPawn::SoftDrop()
{
	if (bSoftDrop == true)
	{
		FVector Location = BoxMain->GetComponentLocation();
		Location.Z -= 180.f;
		SetActorLocation(Location);
		WhichPoints = 1;
		AddPoints();
		HardPoints -= 2;
	}
}

void ATetrisPawn::Down()
{
	if (bDead == false)
	{
		bSoftDrop = true;
		if (DropTime == false)
		{
			GetWorldTimerManager().SetTimer(DownTimer, this, &ATetrisPawn::SoftDrop, 0.025f, true, 0.f);
			DropTime = true;
		}
	}
}

void ATetrisPawn::UnDown()
{
	if (bDead == false)
	{
		bSoftDrop = false;
	}
}

void ATetrisPawn::HardDrop()
{
	if (bDead == false)
	{
		WhichPoints = 2;
		AddPoints();
		bDown = true;
	}
}

void ATetrisPawn::Respawn()
{
	UGameplayStatics::PlaySound2D(this, walniecie);

		UWorld* World = GetWorld();
		if (World && bRespienie == false)
		{
			bDead = true;
			bLocation = true;
			bDown = false;
			bSoftDrop = false;
			GetWorldTimerManager().ClearTimer(LocationTimer);

			FActorSpawnParameters SpawnParameters;
			SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			APlayerController* controller;
			controller = UGameplayStatics::GetPlayerController(this, 0);
			controller->UnPossess();

			TArray<AActor*> NextActors;
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANextActor::StaticClass(), NextActors);

			auto Next = Cast<ANextActor>(NextActors[0]);

			if (InnyRespawn == false)
			{
				JakiPawn = Next->PierwszyPoziom;
				Next->PierwszyPoziom = Next->DrugiPoziom;
				Next->DrugiPoziom = Next->TrzeciPoziom;
				Next->Respienie();
				Next->PPoziom = Next->PierwszyPoziom;

				TArray<AActor*> HoldActors;
				UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHoldActor::StaticClass(), HoldActors);

				auto HoldCast = Cast<AHoldActor>(HoldActors[0]);
				HoldCast->CzyMozna = false;
			}

			if (JakiPawn == 1)
			{
				const FVector SpawnLoc(0.f, 10.f, 3420.f);
				auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_T, FTransform(SpawnLoc), SpawnParameters);
				NewTetrisPawn->JakiPawn = JakiPawn;
				if (NewTetrisPawn)
				{
					controller->Possess(NewTetrisPawn);
				}
			}
			else if (JakiPawn == 2)
			{
				FVector SpawnLoc(0.f, 10.f, 3240.f);
				auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_I, FTransform(SpawnLoc), SpawnParameters);
				NewTetrisPawn->JakiPawn = JakiPawn;
				if (NewTetrisPawn)
				{
					controller->Possess(NewTetrisPawn);
				}
			}
			else if (JakiPawn == 3)
			{
				FVector SpawnLoc(0.f, 10.f, 3420.f);
				auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_J, FTransform(SpawnLoc), SpawnParameters);
				NewTetrisPawn->JakiPawn = JakiPawn;
				if (NewTetrisPawn)
				{
					controller->Possess(NewTetrisPawn);
				}
			}
			else if (JakiPawn == 4)
			{
				FVector SpawnLoc(0.f, 10.f, 3420.f);
				auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_L, FTransform(SpawnLoc), SpawnParameters);
				NewTetrisPawn->JakiPawn = JakiPawn;
				if (NewTetrisPawn)
				{
					controller->Possess(NewTetrisPawn);
				}
			}
			else if (JakiPawn == 5)
			{
				FVector SpawnLoc(-90.f, 10.f, 3510.f);
				auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_O, FTransform(SpawnLoc), SpawnParameters);
				NewTetrisPawn->JakiPawn = JakiPawn;
				if (NewTetrisPawn)
				{
					controller->Possess(NewTetrisPawn);
				}
			}
			else if (JakiPawn == 6)
			{
				FVector SpawnLoc(0.f, 10.f, 3420.f);
				auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_S, FTransform(SpawnLoc), SpawnParameters);
				NewTetrisPawn->JakiPawn = JakiPawn;
				if (NewTetrisPawn)
				{
					controller->Possess(NewTetrisPawn);
				}
			}
			else
			{
				FVector SpawnLoc(0.f, 10.f, 3420.f);
				auto NewTetrisPawn = World->SpawnActor<ATetrisPawn>(Pawn_Z, FTransform(SpawnLoc), SpawnParameters);
				NewTetrisPawn->JakiPawn = JakiPawn;
				if (NewTetrisPawn)
				{
					controller->Possess(NewTetrisPawn);
				}
			}
			
			bRespienie = true;
		}
}

void ATetrisPawn::SetLocation()
{
	if (bLocation == false && bDead == false && bRespienie == false && bSoftDrop == false)
	{
		FVector Location = BoxMain->GetComponentLocation();
		Location.Z -= 180.f;
		SetActorLocation(Location);
		HardPoints -= 2;
	}
}

void ATetrisPawn::Przegrana()
{
	TArray<AActor*> Odliczanie;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOdliczanieActor::StaticClass(), Odliczanie);
	auto CastOdliczanie = Cast<AOdliczanieActor>(Odliczanie[0]);
	CastOdliczanie->StopMusicGame();

	bPrzegrana = true;
	UE_LOG(LogTemp, Warning, TEXT("RESTART GAME DUDE "));
	bDead = true;
	bLocation = true;
	bDown = false;
	bRespienie = true;
	bSoftDrop = false;
	
	UGameplayStatics::PlaySound2D(this, GameOver);

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	FVector SpawnLoc(-170.f, 2900.f, 1810.f);
	auto GameOverFade = GetWorld()->SpawnActor<AActor>(Fade, FTransform(SpawnLoc), SpawnParameters);

	FTimerHandle GameOverHandle;
	GetWorldTimerManager().SetTimer(GameOverHandle, this, &ATetrisPawn::GameOverMenu, 0.1f, false, 2.1f);
}

void ATetrisPawn::Box_1_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	if (bPrzegrana == false)
	{
		if (OtherActor->ActorHasTag("Up")) { bUp1 = true;}
		else if (!OtherActor->ActorHasTag("Destroy") && !OtherActor->ActorHasTag("Boki")) { bTetris1 = true; }

		if ((bTetris1 == true || bTetris2 == true || bTetris3 == true || bTetris4 == true) && (bUp1 == true || bUp2 == true || bUp3 == true || bUp4 == true))
		{
			Przegrana();
		}

		if (OtherActor->ActorHasTag("Destroy"))
		{
			//if (bPrzegranaDestroy == true)
			//{
				bBox1OverlapDestroy = true;
				auto DestroyActors = Cast<ADestroyActor>(OtherActor);
				DestroyActors->DestroyBlocks++;
				iBox1 = DestroyActors->JakiRodzaj;
				//UE_LOG(LogTemp, Warning, TEXT("BOX 1 BEGIN - Jaki Rodzaj = %i, Destroy BLocks = %i"), DestroyActors->JakiRodzaj, DestroyActors->DestroyBlocks);
			//}
		}
		else if (!OtherActor->ActorHasTag("Boki") && bRespienie == false && !OtherActor->ActorHasTag("Up"))
		{
			bDead = true;
			bLocation = true;
			Respawn();
		}
	}
}

void ATetrisPawn::Box_2_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	if (bPrzegrana == false)
	{
		if (OtherActor->ActorHasTag("Up")) { bUp2 = true; }
		else if (!OtherActor->ActorHasTag("Destroy") && !OtherActor->ActorHasTag("Boki")) { bTetris2 = true; }

		if ((bTetris1 == true || bTetris2 == true || bTetris3 == true || bTetris4 == true) && (bUp1 == true || bUp2 == true || bUp3 == true || bUp4 == true))
		{
			Przegrana();
		}

		if (OtherActor->ActorHasTag("Destroy"))
		{
			//if (bPrzegranaDestroy == true)
			//{
			bBox2OverlapDestroy = true;
			auto DestroyActors = Cast<ADestroyActor>(OtherActor);
			DestroyActors->DestroyBlocks++;
			iBox2 = DestroyActors->JakiRodzaj;
			//UE_LOG(LogTemp, Warning, TEXT("BOX 2 BEGIN - Jaki Rodzaj = %i, Destroy BLocks = %i"), DestroyActors->JakiRodzaj, DestroyActors->DestroyBlocks);
		//}
		}
		else if (!OtherActor->ActorHasTag("Boki") && bRespienie == false && !OtherActor->ActorHasTag("Up"))
		{
			bDead = true;
			bLocation = true;
			Respawn();
		}
	}
}

void ATetrisPawn::Box_3_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	if (bPrzegrana == false)
	{
		if (OtherActor->ActorHasTag("Up")) { bUp3 = true; }
		else if (!OtherActor->ActorHasTag("Destroy") && !OtherActor->ActorHasTag("Boki")) { bTetris3 = true; }

		if ((bTetris1 == true || bTetris2 == true || bTetris3 == true || bTetris4 == true) && (bUp1 == true || bUp2 == true || bUp3 == true || bUp4 == true))
		{
			Przegrana();
		}

		if (OtherActor->ActorHasTag("Destroy"))
		{
			//if (bPrzegranaDestroy == true)
			//{
			bBox3OverlapDestroy = true;
			auto DestroyActors = Cast<ADestroyActor>(OtherActor);
			DestroyActors->DestroyBlocks++;
			iBox3 = DestroyActors->JakiRodzaj;
			//UE_LOG(LogTemp, Warning, TEXT("BOX 3 BEGIN - Jaki Rodzaj = %i, Destroy BLocks = %i"), DestroyActors->JakiRodzaj, DestroyActors->DestroyBlocks);
		//}
		}
		else if (!OtherActor->ActorHasTag("Boki") && bRespienie == false && !OtherActor->ActorHasTag("Up"))
		{
			bDead = true;
			bLocation = true;
			Respawn();
		}
	}
}

void ATetrisPawn::Box_4_OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& Hit)
{
	if (bPrzegrana == false)
	{
		if (OtherActor->ActorHasTag("Up")) { bUp4 = true;}
		else if (!OtherActor->ActorHasTag("Destroy") && !OtherActor->ActorHasTag("Boki")) { bTetris4 = true; }

		if ((bTetris1 == true || bTetris2 == true || bTetris3 == true || bTetris4 == true) && (bUp1 == true || bUp2 == true || bUp3 == true || bUp4 == true))
		{
			Przegrana();
		}

		if (OtherActor->ActorHasTag("Destroy"))
		{
			//if (bPrzegranaDestroy == true)
			//{
			bBox4OverlapDestroy = true;
			auto DestroyActors = Cast<ADestroyActor>(OtherActor);
			DestroyActors->DestroyBlocks++;
			iBox4 = DestroyActors->JakiRodzaj;
			//UE_LOG(LogTemp, Warning, TEXT("BOX 3 BEGIN - Jaki Rodzaj = %i, Destroy BLocks = %i"), DestroyActors->JakiRodzaj, DestroyActors->DestroyBlocks);
		//}
		}
		else if (!OtherActor->ActorHasTag("Boki") && bRespienie == false && !OtherActor->ActorHasTag("Up"))
		{
			bDead = true;
			bLocation = true;
			Respawn();
		}
	}
}

void ATetrisPawn::Box_1_OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->ActorHasTag("Up")) { bUp1 = false;}
	else if (OtherActor->ActorHasTag("Destroy"))
	{
		//if (bPrzegranaDestroy == true)
		//{
		if (bBox1OverlapEnd == false)
		{
			bBox1OverlapDestroy = false;
			auto DestroyActors = Cast<ADestroyActor>(OtherActor);
			if (DestroyActors->DestroyBlocks > 0) DestroyActors->DestroyBlocks--;
			DestroyActors->Pawns.RemoveSingle(this);
			iBox1 = 0;
			//UE_LOG(LogTemp, Warning, TEXT("BOX 1 END - Jaki Rodzaj = %i, Destroy BLocks = %i"), DestroyActors->JakiRodzaj, DestroyActors->DestroyBlocks);
		}
		else if (bBox1OverlapEnd == true) bBox1OverlapEnd = false;
		//}
	}
	else if (!OtherActor->ActorHasTag("Boki"))
	{
		bTetris1 = false;
	}
}

void ATetrisPawn::Box_2_OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->ActorHasTag("Up")) { bUp2 = false; }
	else if (OtherActor->ActorHasTag("Destroy"))
	{
		//if (bPrzegranaDestroy == true)
		//{
		if (bBox2OverlapEnd == false)
		{
			bBox2OverlapDestroy = false;
			auto DestroyActors = Cast<ADestroyActor>(OtherActor);
			if (DestroyActors->DestroyBlocks > 0) DestroyActors->DestroyBlocks--;
			DestroyActors->Pawns.RemoveSingle(this);
			iBox2 = 0;
			//UE_LOG(LogTemp, Warning, TEXT("BOX 2 END - Jaki Rodzaj = %i, Destroy BLocks = %i"), DestroyActors->JakiRodzaj, DestroyActors->DestroyBlocks);
		}
		else if (bBox2OverlapEnd == true) bBox2OverlapEnd = false;
		//}
	}
	else if (!OtherActor->ActorHasTag("Boki"))
	{
		bTetris2 = false;
	}
}

void ATetrisPawn::Box_3_OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->ActorHasTag("Up")) { bUp3 = false; }
	else if (OtherActor->ActorHasTag("Destroy"))
	{
		//if (bPrzegranaDestroy == true)
		//{
		if (bBox3OverlapEnd == false)
		{
			bBox3OverlapDestroy = false;
			auto DestroyActors = Cast<ADestroyActor>(OtherActor);
			if (DestroyActors->DestroyBlocks > 0) DestroyActors->DestroyBlocks--;
			DestroyActors->Pawns.RemoveSingle(this);
			iBox3 = 0;
		}
		else if (bBox3OverlapEnd == true) bBox3OverlapEnd = false;
		//}
	}
	else if (!OtherActor->ActorHasTag("Boki"))
	{
		bTetris3 = false;
	}
}

void ATetrisPawn::Box_4_OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->ActorHasTag("Up")) { bUp4 = false; }
	else if (OtherActor->ActorHasTag("Destroy"))
	{
		//if (bPrzegranaDestroy == true)
		//{
		if (bBox4OverlapEnd == false)
		{
			bBox4OverlapDestroy = false;
			auto DestroyActors = Cast<ADestroyActor>(OtherActor);
			if (DestroyActors->DestroyBlocks > 0) DestroyActors->DestroyBlocks--;
			DestroyActors->Pawns.RemoveSingle(this);
			iBox4 = 0;
		}
		else if (bBox4OverlapEnd == true) bBox4OverlapEnd = false;
		//}

	}
	else if (!OtherActor->ActorHasTag("Boki"))
	{
		bTetris4 = false;
	}
}