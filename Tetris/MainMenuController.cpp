// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuController.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

AMainMenuController::AMainMenuController()
{
}

void AMainMenuController::BeginPlay()
{
	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);
}

void AMainMenuController::Tick(float DeltaTime)
{
}

void AMainMenuController::SetupInputComponent()
{
}

