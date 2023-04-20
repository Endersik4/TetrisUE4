// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeCamera.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AChangeCamera::AChangeCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChangeCamera::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
}

// Called every frame
void AChangeCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CzyInterpto == true)
	{
		CameraActors[0]->SetActorRotation(FMath::RInterpTo(CameraActors[0]->GetActorRotation(), KoncowaRotacja, DeltaTime, 3.1f));
	}
}

