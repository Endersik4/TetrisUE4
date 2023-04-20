// Fill out your copyright notice in the Description page of Project Settings.


#include "Points.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

// Sets default values
APoints::APoints()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Text = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Points"));
	Text->SetTextRenderColor(FColor::Black);
	//Text->SetText(FText::FromString("Cos"));

}

// Called when the game starts or when spawned
void APoints::BeginPlay()
{
	Super::BeginPlay();
	if (CzyLiczby == false)Text->SetText(FText::AsNumber(Points));
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
}

// Called every frame
void APoints::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CzyInterpto == true)
	{
		CameraActors[0]->SetActorRotation(FMath::RInterpTo(CameraActors[0]->GetActorRotation(), KoncowaRotacja, DeltaTime, 3.1f));
	}

}

