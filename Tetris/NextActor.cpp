// Fill out your copyright notice in the Description page of Project Settings.


#include "NextActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ANextActor::ANextActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANextActor::BeginPlay()
{
	Super::BeginPlay();
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	const int Pawns = FMath::RandRange(0, 100);
	const int Pawns2 = FMath::RandRange(0, 100);
	const int Pawns3 = FMath::RandRange(0, 100);

	if (UKismetMathLibrary::InRange_FloatFloat(Pawns, 0, 15, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 90.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_T, SpawnLoc, SpawnRot, SpawnParameters);
		PierwszyPoziom = 1;
		PPoziom = 1;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns, 16, 25, true, true))
	{
		const FVector SpawnLoc(2190.f, 505.f, 180.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_I, SpawnLoc, SpawnRot, SpawnParameters);
		PierwszyPoziom = 2;
		PPoziom = 2;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns, 26, 40, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 90.f);
		const FRotator SpawnRot(-90.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_J, SpawnLoc, SpawnRot, SpawnParameters);
		PierwszyPoziom = 3;
		PPoziom = 3;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns, 41, 55, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 90.f);
		const FRotator SpawnRot(90.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_L, SpawnLoc, SpawnRot, SpawnParameters);
		PierwszyPoziom = 4;
		PPoziom = 4;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns, 56, 70, true, true))
	{
		const FVector SpawnLoc(2120.f, 461.f, 190.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_O, SpawnLoc, SpawnRot, SpawnParameters);
		PierwszyPoziom = 5;
		PPoziom = 5;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns, 71, 85, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 90.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_S, SpawnLoc, SpawnRot, SpawnParameters);
		PierwszyPoziom = 6;
		PPoziom = 6;
	}
	else
	{
		const FVector SpawnLoc(2126.f, 465.f, 90.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_Z, SpawnLoc, SpawnRot, SpawnParameters);
		PierwszyPoziom = 7;
		PPoziom = 7;
	}


	if (UKismetMathLibrary::InRange_FloatFloat(Pawns2, 0, 15, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 630.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_T, SpawnLoc, SpawnRot, SpawnParameters);
		DrugiPoziom = 1;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns2, 16, 25, true, true))
	{
		const FVector SpawnLoc(2190.f, 505.f, 720.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_I, SpawnLoc, SpawnRot, SpawnParameters);
		DrugiPoziom = 2;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns2, 26, 40, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 630.f);
		const FRotator SpawnRot(-90.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_J, SpawnLoc, SpawnRot, SpawnParameters);
		DrugiPoziom = 3;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns2, 41, 55, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 630.f);
		const FRotator SpawnRot(90.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_L, SpawnLoc, SpawnRot, SpawnParameters);
		DrugiPoziom = 4;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns2, 56, 70, true, true))
	{
		const FVector SpawnLoc(2120.f, 461.f, 730.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_O, SpawnLoc, SpawnRot, SpawnParameters);
		DrugiPoziom = 5;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns2, 71, 85, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 630.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_S, SpawnLoc, SpawnRot, SpawnParameters);
		DrugiPoziom = 6;
	}
	else
	{
		const FVector SpawnLoc(2126.f, 465.f, 630.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_Z, SpawnLoc, SpawnRot, SpawnParameters);
		DrugiPoziom = 7;
	}

	if (UKismetMathLibrary::InRange_FloatFloat(Pawns3, 0, 15, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 1170.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_T, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 1;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns3, 16, 25, true, true))
	{
		const FVector SpawnLoc(2190.f, 505.f, 1260.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_I, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 2;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns3, 26, 40, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 1170.f);
		const FRotator SpawnRot(-90.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_J, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 3;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns3, 41, 55, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 1170.f);
		const FRotator SpawnRot(90.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_L, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 4;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns3, 56, 70, true, true))
	{
		const FVector SpawnLoc(2120.f, 461.f, 1270.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_O, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 5;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns3, 71, 85, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 1170.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_S, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 6;
	}
	else
	{
		const FVector SpawnLoc(2126.f, 465.f, 1170.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_Z, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 7;
	}
	
}

// Called every frame
void ANextActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANextActor::Respienie()
{

	TArray<AActor*> PierwszyActor;
	switch (PPoziom)
	{
	case 1: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_T, PierwszyActor); } break;
	case 2: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_I, PierwszyActor); } break;
	case 3: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_J, PierwszyActor); } break;
	case 4: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_L, PierwszyActor); } break;
	case 5: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_O, PierwszyActor); } break;
	case 6: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_S, PierwszyActor); } break;
	case 7: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_Z, PierwszyActor); } break;
	}

	PierwszyActor[0]->Destroy();
	PierwszyActor.Empty();

	TArray<AActor*> DrugiActor;
	switch (PierwszyPoziom)
	{
	case 1: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_T, DrugiActor); } break;
	case 2: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_I, DrugiActor); } break;
	case 3: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_J, DrugiActor); } break;
	case 4: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_L, DrugiActor); } break;
	case 5: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_O, DrugiActor); } break;
	case 6: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_S, DrugiActor); } break;
	case 7: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_Z, DrugiActor); } break;
	}
	if (PierwszyPoziom == 1) UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_T, DrugiActor);
	else if (PierwszyPoziom == 2) UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_I, DrugiActor);
	else if (PierwszyPoziom == 3) UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_J, DrugiActor);
	else if (PierwszyPoziom == 4) UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_L, DrugiActor);
	else if (PierwszyPoziom == 5) UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_O, DrugiActor);
	else if (PierwszyPoziom == 6) UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_S, DrugiActor);
	else UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_Z, DrugiActor);

	if (PierwszyPoziom == 2) DrugiActor[0]->SetActorLocation(FVector(2190.f, 505.f, 180.f));
	else if (PierwszyPoziom == 5 && DrugiPoziom == 5) DrugiActor[1]->SetActorLocation(FVector(2120.f, 461.f, 190.f));
	else if (PierwszyPoziom == 5) DrugiActor[0]->SetActorLocation(FVector(2120.f, 461.f, 190.f));
	else if (PierwszyPoziom != DrugiPoziom) DrugiActor[0]->SetActorLocation(FVector(2126.f, 465.f, 90.f));
	else DrugiActor[1]->SetActorLocation(FVector(2126.f, 465.f, 90.f));
	DrugiActor.Empty();
	
	TArray<AActor*> TrzeciActor;
	switch (DrugiPoziom)
	{
	case 1: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_T, TrzeciActor); } break;
	case 2: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_I, TrzeciActor); } break;
	case 3: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_J, TrzeciActor); } break;
	case 4: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_L, TrzeciActor); } break;
	case 5: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_O, TrzeciActor); } break;
	case 6: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_S, TrzeciActor); } break;
	case 7: { UGameplayStatics::GetAllActorsOfClass(GetWorld(), Pawn_Z, TrzeciActor); } break;
	}
	
	if (DrugiPoziom == 2) TrzeciActor[0]->SetActorLocation(FVector(2190.f, 505.f, 720.f));
	else if (DrugiPoziom == 5) TrzeciActor[0]->SetActorLocation(FVector(2120.f, 461.f, 730.f));
	else TrzeciActor[0]->SetActorLocation(FVector(2126.f, 465.f, 630.f));
	TrzeciActor.Empty();
	
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	const int Pawns3 = FMath::RandRange(0, 100);

	if (UKismetMathLibrary::InRange_FloatFloat(Pawns3, 0, 15, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 1170.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_T, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 1;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns3, 16, 25, true, true))
	{
		const FVector SpawnLoc(2190.f, 505.f, 1260.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_I, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 2;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns3, 26, 40, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 1170.f);
		const FRotator SpawnRot(-90.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_J, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 3;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns3, 41, 55, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 1170.f);
		const FRotator SpawnRot(90.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_L, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 4;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns3, 56, 70, true, true))
	{
		const FVector SpawnLoc(2120.f, 461.f, 1270.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_O, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 5;
	}
	else if (UKismetMathLibrary::InRange_FloatFloat(Pawns3, 71, 85, true, true))
	{
		const FVector SpawnLoc(2126.f, 465.f, 1170.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_S, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 6;
	}
	else
	{
		const FVector SpawnLoc(2126.f, 465.f, 1170.f);
		const FRotator SpawnRot(0.f, 30.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Pawn_Z, SpawnLoc, SpawnRot, SpawnParameters);
		TrzeciPoziom = 7;
	}
	

	UE_LOG(LogTemp, Warning, TEXT("PIERWSZY : %i, DRUGI : %i, TRZECI: %i"), PierwszyPoziom, DrugiPoziom, TrzeciPoziom);
}

