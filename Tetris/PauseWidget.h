// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseWidget.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API UPauseWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	TArray<AActor*> Buttons;
	TArray<AActor*> Change;
	TArray<AActor*> TetrisPawns;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor>Fade;
	void MainMenuBlack();
	void RestartBlack();
	FTimerHandle Black;


	UPROPERTY(EditAnywhere)
		class USoundCue* Select;

protected:
	bool CzyMozna = false;
	FTimerHandle Mozna;
	void ZmianaMozna();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ContinueBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* RestartBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* MainMenuBtn;

	virtual void NativeConstruct() override;

	UFUNCTION()
		void OnContinueClick();

	UFUNCTION()
		void OnMainMenuClick();

	UFUNCTION()
		void OnRestartClick();

	UFUNCTION()
		void OnContinueHover();

	UFUNCTION()
		void OnContinueUnHover();

	UFUNCTION()
		void OnMainMenuHover();

	UFUNCTION()
		void OnMainMenuUnHover();

	UFUNCTION()
		void OnRestartHover();

	UFUNCTION()
		void OnRestartUnHover();
};

