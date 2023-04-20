// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	TArray<AActor*> Buttons;
	bool CzyBack;
	UPROPERTY(EditAnywhere)
		class USoundCue* Select;
	UPROPERTY(EditAnywhere)
		class USoundCue* Music;
	bool CzyMuzyka;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor>Fade;
	void StartBlack();
	FTimerHandle Black;

	float MusicVolume = 0.1f;
	void ChangeMusicVolume();
	FTimerHandle MusicVolumeHandle;
	UAudioComponent* AudioComponent;

protected:

	bool CzyMozna;
	FTimerHandle Mozna;
	void ZmianaMozna();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* StartBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* QuitBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ControlsBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* BackBtn;

	virtual void NativeConstruct() override;

	UFUNCTION()
		void OnStartClick();

	UFUNCTION()
		void OnQuitClick();

	UFUNCTION()
		void OnControlsClick();

	UFUNCTION()
		void OnStartHover();

	UFUNCTION()
		void OnStartUnHover();

	UFUNCTION()
		void OnQuitHover();

	UFUNCTION()
		void OnQuitUnHover();

	UFUNCTION()
		void OnControlsHover();

	UFUNCTION()
		void OnControlsUnHover();
	
	UFUNCTION()
		void OnBackHover();

	UFUNCTION()
		void OnBackUnHover();
};
