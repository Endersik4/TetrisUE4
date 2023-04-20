// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverWidget.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	TArray<AActor*> Buttons;
	TArray<AActor*> Change;
	bool CzyBack;
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
		class UButton* RestartBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ScoreBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* MainMenuBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* BackBtn;

	virtual void NativeConstruct() override;

	UFUNCTION()
		void OnScoreClick();

	UFUNCTION()
		void OnMainMenuClick();

	UFUNCTION()
		void OnRestartClick();

	UFUNCTION()
		void OnBackClick();

	UFUNCTION()
		void OnScoreHover();

	UFUNCTION()
		void OnScoreUnHover();

	UFUNCTION()
		void OnMainMenuHover();

	UFUNCTION()
		void OnMainMenuUnHover();

	UFUNCTION()
		void OnRestartHover();

	UFUNCTION()
		void OnRestartUnHover();

	UFUNCTION()
		void OnBackHover();

	UFUNCTION()
		void OnBackUnHover();
};
