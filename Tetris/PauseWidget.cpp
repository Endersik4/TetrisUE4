// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextRenderComponent.h"
#include "Points.h"
#include "ChangeCamera.h"
#include "TetrisPawn.h"
#include "OdliczanieActor.h"
#include "Sound/SoundCue.h"

void UPauseWidget::NativeConstruct()
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;

	if (ContinueBtn)
	{
		ContinueBtn->OnClicked.AddDynamic(this, &UPauseWidget::OnContinueClick);
		ContinueBtn->OnHovered.AddDynamic(this, &UPauseWidget::OnContinueHover);
		ContinueBtn->OnUnhovered.AddDynamic(this, &UPauseWidget::OnContinueUnHover);
	}

	if (MainMenuBtn)
	{
		MainMenuBtn->OnClicked.AddDynamic(this, &UPauseWidget::OnMainMenuClick);
		MainMenuBtn->OnHovered.AddDynamic(this, &UPauseWidget::OnMainMenuHover);
		MainMenuBtn->OnUnhovered.AddDynamic(this, &UPauseWidget::OnMainMenuUnHover);
	}

	if (RestartBtn)
	{
		RestartBtn->OnClicked.AddDynamic(this, &UPauseWidget::OnRestartClick);
		RestartBtn->OnHovered.AddDynamic(this, &UPauseWidget::OnRestartHover);
		RestartBtn->OnUnhovered.AddDynamic(this, &UPauseWidget::OnRestartUnHover);
	}

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APoints::StaticClass(), Buttons);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AChangeCamera::StaticClass(), Change);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATetrisPawn::StaticClass(), TetrisPawns);
	Buttons[0]->GetWorldTimerManager().SetTimer(Mozna, this, &UPauseWidget::ZmianaMozna, 0.1f, false, 1.4f);

}

void UPauseWidget::ZmianaMozna()
{
	CzyMozna = true;
	Buttons[0]->GetWorldTimerManager().ClearTimer(Mozna);
}

void UPauseWidget::OnContinueClick()
{
	UWorld* World = GetWorld();
	if (CzyMozna == true)
	{
		auto cos = Cast<AChangeCamera>(Change[0]);
		cos->KoncowaRotacja = cos->CameraActors[0]->GetActorRotation();
		cos->KoncowaRotacja.Yaw = -90.f;

		for (int i = 0; i != Buttons.Num(); i++)
		{
			auto ZmianaNaMaterial_1 = Cast<APoints>(Buttons[i]);
			if (ZmianaNaMaterial_1->JakiButton != "Score" && ZmianaNaMaterial_1->JakiButton != "Level" && ZmianaNaMaterial_1->JakiButton != "Lines")
			{
				ZmianaNaMaterial_1->Text->SetTextMaterial(ZmianaNaMaterial_1->Material_1);
			}
		}
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = false;

		TArray<AActor*> Odliczanie;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOdliczanieActor::StaticClass(), Odliczanie);
		auto CastOdliczanie = Cast<AOdliczanieActor>(Odliczanie[0]);
		CastOdliczanie->TimerCzekaj();

		CzyMozna = false;
		RemoveFromParent();
	}
}

void UPauseWidget::OnRestartClick()
{
	UWorld* World = GetWorld();

	if (World && CzyMozna == true)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		FVector SpawnLoc(450.f, 4300.f, 1810.f);
		FRotator SpawnRot(0.f, 90.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Fade, SpawnLoc, SpawnRot, SpawnParameters);

		Buttons[0]->GetWorldTimerManager().SetTimer(Black, this, &UPauseWidget::RestartBlack, 0.1f, false, 2.1f);
	}
}

void UPauseWidget::RestartBlack()
{
	UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(), TEXT("RestartLevel"));
}

void UPauseWidget::OnMainMenuClick()
{
	if (CzyMozna == true)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		FVector SpawnLoc(450.f, 4300.f, 1810.f);
		FRotator SpawnRot(0.f, 90.f, 0.f);
		GetWorld()->SpawnActor<AActor>(Fade, SpawnLoc, SpawnRot, SpawnParameters);

		Buttons[0]->GetWorldTimerManager().SetTimer(Black, this, &UPauseWidget::MainMenuBlack, 0.1f, false, 2.1f);

	}
}

void UPauseWidget::MainMenuBlack()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenu"));
}

void UPauseWidget::OnContinueHover()
{
	if (CzyMozna == true)
	{
		for (int i = 0; i != Buttons.Num(); i++)
		{
			auto cos = Cast<APoints>(Buttons[i]);
			if (cos->JakiButton == "Continue")
			{
				UGameplayStatics::PlaySound2D(this, Select);
				cos->Text->SetTextMaterial(cos->Material_2);
				break;
			}
		}
	}
}

void UPauseWidget::OnContinueUnHover()
{
	for (int i = 0; i != Buttons.Num(); i++)
	{
		auto cos = Cast<APoints>(Buttons[i]);
		if (cos->JakiButton == "Continue")
		{
			cos->Text->SetTextMaterial(cos->Material_1);
			break;
		}
	}
}

void UPauseWidget::OnRestartHover()
{
	if (CzyMozna == true)
	{
		for (int i = 0; i != Buttons.Num(); i++)
		{
			auto cos = Cast<APoints>(Buttons[i]);
			if (cos->JakiButton == "Restart")
			{
				UGameplayStatics::PlaySound2D(this, Select);
				cos->Text->SetTextMaterial(cos->Material_2);
				break;
			}
		}
	}
}

void UPauseWidget::OnRestartUnHover()
{
	for (int i = 0; i != Buttons.Num(); i++)
	{
		auto cos = Cast<APoints>(Buttons[i]);
		if (cos->JakiButton == "Restart")
		{
			cos->Text->SetTextMaterial(cos->Material_1);
			break;
		}
	}
}

void UPauseWidget::OnMainMenuHover()
{
	if (CzyMozna == true)
	{
		for (int i = 0; i != Buttons.Num(); i++)
		{
			auto cos = Cast<APoints>(Buttons[i]);
			if (cos->JakiButton == "MainMenu")
			{
				UGameplayStatics::PlaySound2D(this, Select);
				cos->Text->SetTextMaterial(cos->Material_2);
				break;
			}
		}
	}
}

void UPauseWidget::OnMainMenuUnHover()
{
	for (int i = 0; i != Buttons.Num(); i++)
	{
		auto cos = Cast<APoints>(Buttons[i]);
		if (cos->JakiButton == "MainMenu")
		{
			cos->Text->SetTextMaterial(cos->Material_1);
			break;
		}
	}
}
