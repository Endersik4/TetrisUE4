// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameMode.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/GameUserSettings.h"

void AMainMenuGameMode::BeginPlay()
{
	if (MainMenuWidgetClass)
	{
		UUserWidget* Widget = CreateWidget(GetWorld(), MainMenuWidgetClass);

		if (Widget)
		{
			Widget->AddToViewport();
		}
	}
}
