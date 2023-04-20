// Fill out your copyright notice in the Description page of Project Settings.


#include "Boki_Trigger.h"
#include "DrawDebugHelpers.h"
#include "Engine/BrushShape.h"
#include "TetrisPawn.h"
#include "Components/BoxComponent.h"

ABoki_Trigger::ABoki_Trigger()
{
	OnActorBeginOverlap.AddDynamic(this, &ABoki_Trigger::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ABoki_Trigger::OnOverlapEnd);
}

void ABoki_Trigger::BeginPlay()
{
	Super::BeginPlay();
}

void ABoki_Trigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	ATetrisPawn* MyTetrisPawn = Cast<ATetrisPawn>(OtherActor);
	if (bCzyWykrywa == false)
	{
		MyTetrisPawn->bLocation = false;
		if (bCzyPrawaStrona == true)
		{
			MyTetrisPawn->bPrawy = true;
		}
		else
		{
			MyTetrisPawn->bLewy = true;
		}
	}
	else
	{
		FVector Location = MyTetrisPawn->GetActorLocation();
		if (bCzyPrawaStrona == true)
		{
			Location.X -= 180;
			MyTetrisPawn->SetActorLocation(Location);
		}
		else
		{
			Location.X += 180;
			MyTetrisPawn->SetActorLocation(Location);
		}

	}
}

void ABoki_Trigger::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (bCzyWykrywa == false)
	{
		ATetrisPawn* MyTetrisPawn = Cast<ATetrisPawn>(OtherActor);
		MyTetrisPawn->bPrawy = false;
		MyTetrisPawn->bLewy = false;
	}
}