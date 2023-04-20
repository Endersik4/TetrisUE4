// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuController.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API AMainMenuController : public APlayerController
{
	GENERATED_BODY()

		AMainMenuController();

	UFUNCTION()
		virtual void SetupInputComponent() override;
public:

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay();
};
