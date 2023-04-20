// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextRenderComponent.h"
#include "Points.h"
#include "ChangeCamera.h"
#include "TetrisPawn.h"
#include "OdliczanieActor.h"
#include "Sound/SoundCue.h"

void UGameOverWidget::NativeConstruct()
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;

	if (ScoreBtn)
	{
		ScoreBtn->OnClicked.AddDynamic(this, &UGameOverWidget::OnScoreClick);
		ScoreBtn->OnHovered.AddDynamic(this, &UGameOverWidget::OnScoreHover);
		ScoreBtn->OnUnhovered.AddDynamic(this, &UGameOverWidget::OnScoreUnHover);
	}

	if (MainMenuBtn)
	{
		MainMenuBtn->OnClicked.AddDynamic(this, &UGameOverWidget::OnMainMenuClick);
		MainMenuBtn->OnHovered.AddDynamic(this, &UGameOverWidget::OnMainMenuHover);
		MainMenuBtn->OnUnhovered.AddDynamic(this, &UGameOverWidget::OnMainMenuUnHover);
	}

	if (RestartBtn)
	{
		RestartBtn->OnClicked.AddDynamic(this, &UGameOverWidget::OnRestartClick);
		RestartBtn->OnHovered.AddDynamic(this, &UGameOverWidget::OnRestartHover);
		RestartBtn->OnUnhovered.AddDynamic(this, &UGameOverWidget::OnRestartUnHover);
	}

	if (BackBtn)
	{
		BackBtn->OnClicked.AddDynamic(this, &UGameOverWidget::OnBackClick);
		BackBtn->OnHovered.AddDynamic(this, &UGameOverWidget::OnBackHover);
		BackBtn->OnUnhovered.AddDynamic(this, &UGameOverWidget::OnBackUnHover);
	}

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APoints::StaticClass(), Buttons);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AChangeCamera::StaticClass(), Change);
	Buttons[0]->GetWorldTimerManager().SetTimer(Mozna, this, &UGameOverWidget::ZmianaMozna, 0.1f, false, 2.0f);
}

void UGameOverWidget::ZmianaMozna()
{
	CzyMozna = true;
	Buttons[0]->GetWorldTimerManager().ClearTimer(Mozna);
}

void UGameOverWidget::OnScoreClick()
{
	UWorld* World = GetWorld();
	if (CzyMozna == true && CzyBack == false)
	{
		auto cos = Cast<AChangeCamera>(Change[0]);
		cos->KoncowaRotacja = cos->CameraActors[0]->GetActorRotation();
		cos->CzyInterpto = true;
		cos->KoncowaRotacja.Yaw = -270.f;

		for (int i = 0; i != Buttons.Num(); i++)
		{
			auto ZmianaNaMaterial_1 = Cast<APoints>(Buttons[i]);
			if (ZmianaNaMaterial_1->JakiButton != "Score" && ZmianaNaMaterial_1->JakiButton != "Level" && ZmianaNaMaterial_1->JakiButton != "Lines")
			{
				ZmianaNaMaterial_1->Text->SetTextMaterial(ZmianaNaMaterial_1->Material_1);
			}
		}

		CzyBack = true;
		CzyMozna = false;
		Buttons[0]->GetWorldTimerManager().SetTimer(Mozna, this, &UGameOverWidget::ZmianaMozna, 0.1f, false, 1.5f);
	}
}

void UGameOverWidget::OnMainMenuClick()
{
	if (CzyMozna == true && CzyBack == false)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		FVector SpawnLoc(-700.f, 4300.f, 1810.f);
		FRotator SpawnRot(0.f, -90.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Fade, SpawnLoc, SpawnRot, SpawnParameters);
		
		Buttons[0]->GetWorldTimerManager().SetTimer(Black, this, &UGameOverWidget::MainMenuBlack, 0.1f, false, 2.1f);
	}
}
void UGameOverWidget::MainMenuBlack()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenu"));
}

void UGameOverWidget::OnRestartClick()
{
	UWorld* World = GetWorld();

	if (World && CzyMozna == true && CzyBack == false)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		FVector SpawnLoc(-700.f, 4300.f, 1810.f);
		FRotator SpawnRot(0.f, -90.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Fade, SpawnLoc, SpawnRot, SpawnParameters);

		Buttons[0]->GetWorldTimerManager().SetTimer(Black, this, &UGameOverWidget::RestartBlack, 0.1f, false, 2.1f);
		
	}
}

void UGameOverWidget::RestartBlack()
{
	UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(), TEXT("RestartLevel"));
}

void UGameOverWidget::OnBackClick()
{
	if (CzyMozna == true && CzyBack == true)
	{
		auto cos = Cast<AChangeCamera>(Change[0]);
		cos->KoncowaRotacja = cos->CameraActors[0]->GetActorRotation();
		cos->CzyInterpto = true;
		cos->KoncowaRotacja.Yaw = -180.f;
		
		CzyBack = false;
		CzyMozna = false;
		Buttons[0]->GetWorldTimerManager().SetTimer(Mozna, this, &UGameOverWidget::ZmianaMozna, 0.1f, false, 1.5f);
	}
}

void UGameOverWidget::OnScoreHover()
{
	if (CzyMozna == true && CzyBack == false)
	{
		for (int i = 0; i != Buttons.Num(); i++)
		{
			auto cos = Cast<APoints>(Buttons[i]);
			if (cos->JakiButton == "ScoreGame")
			{
				UGameplayStatics::PlaySound2D(this, Select);
				cos->Text->SetTextMaterial(cos->Material_2);
				break;
			}
		}
	}
}

void UGameOverWidget::OnScoreUnHover()
{
	for (int i = 0; i != Buttons.Num(); i++)
	{
		auto cos = Cast<APoints>(Buttons[i]);
		if (cos->JakiButton == "ScoreGame")
		{
			cos->Text->SetTextMaterial(cos->Material_1);
			break;
		}
	}
}

void UGameOverWidget::OnMainMenuHover()
{
	if (CzyMozna == true && CzyBack == false)
	{
		for (int i = 0; i != Buttons.Num(); i++)
		{
			auto cos = Cast<APoints>(Buttons[i]);
			if (cos->JakiButton == "MainMenuGame")
			{
				UGameplayStatics::PlaySound2D(this, Select);
				cos->Text->SetTextMaterial(cos->Material_2);
				break;
			}
		}
	}
}

void UGameOverWidget::OnMainMenuUnHover()
{
	for (int i = 0; i != Buttons.Num(); i++)
	{
		auto cos = Cast<APoints>(Buttons[i]);
		if (cos->JakiButton == "MainMenuGame")
		{
			cos->Text->SetTextMaterial(cos->Material_1);
			break;
		}
	}
}

void UGameOverWidget::OnRestartHover()
{
	if (CzyMozna == true && CzyBack == false)
	{
		for (int i = 0; i != Buttons.Num(); i++)
		{
			auto cos = Cast<APoints>(Buttons[i]);
			if (cos->JakiButton == "RestartGame")
			{
				UGameplayStatics::PlaySound2D(this, Select);
				cos->Text->SetTextMaterial(cos->Material_2);
				break;
			}
		}
	}
}

void UGameOverWidget::OnRestartUnHover()
{
	for (int i = 0; i != Buttons.Num(); i++)
	{
		auto cos = Cast<APoints>(Buttons[i]);
		if (cos->JakiButton == "RestartGame")
		{
			cos->Text->SetTextMaterial(cos->Material_1);
			break;
		}
	}
}

void UGameOverWidget::OnBackHover()
{
	if (CzyMozna == true && CzyBack == true)
	{
		for (int i = 0; i != Buttons.Num(); i++)
		{
			auto cos = Cast<APoints>(Buttons[i]);
			if (cos->JakiButton == "BackGame")
			{
				UGameplayStatics::PlaySound2D(this, Select);
				cos->Text->SetTextMaterial(cos->Material_2);
				break;
			}
		}
	}
}

void UGameOverWidget::OnBackUnHover()
{
	for (int i = 0; i != Buttons.Num(); i++)
	{
		auto cos = Cast<APoints>(Buttons[i]);
		if (cos->JakiButton == "BackGame")
		{
			cos->Text->SetTextMaterial(cos->Material_1);
			break;
		}
	}
}
