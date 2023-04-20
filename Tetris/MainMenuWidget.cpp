// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextRenderComponent.h"
#include "Points.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"

void UMainMenuWidget::NativeConstruct()
{
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->bShowMouseCursor = true;

	if (StartBtn)
	{
		StartBtn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnStartClick);
		StartBtn->OnHovered.AddDynamic(this, &UMainMenuWidget::OnStartHover);
		StartBtn->OnUnhovered.AddDynamic(this, &UMainMenuWidget::OnStartUnHover);
	}
	
	if (ControlsBtn)
	{
		ControlsBtn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnControlsClick);
		ControlsBtn->OnHovered.AddDynamic(this, &UMainMenuWidget::OnControlsHover);
		ControlsBtn->OnUnhovered.AddDynamic(this, &UMainMenuWidget::OnControlsUnHover);
	}

	if (QuitBtn)
	{
		QuitBtn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnQuitClick);
		QuitBtn->OnHovered.AddDynamic(this, &UMainMenuWidget::OnQuitHover);
		QuitBtn->OnUnhovered.AddDynamic(this, &UMainMenuWidget::OnQuitUnHover);
	}

	if (BackBtn)
	{
		BackBtn->OnClicked.AddDynamic(this, &UMainMenuWidget::OnControlsClick);
		BackBtn->OnHovered.AddDynamic(this, &UMainMenuWidget::OnBackHover);
		BackBtn->OnUnhovered.AddDynamic(this, &UMainMenuWidget::OnBackUnHover);
	}

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APoints::StaticClass(), Buttons);
	Buttons[0]->GetWorldTimerManager().SetTimer(Mozna, this, &UMainMenuWidget::ZmianaMozna, 0.1f, false, 4.8f);	
}

void UMainMenuWidget::ZmianaMozna()
{
	CzyMozna = true;
	Buttons[0]->GetWorldTimerManager().ClearTimer(Mozna);
	if (CzyMuzyka == false)
	{
		Buttons[0]->GetWorldTimerManager().SetTimer(MusicVolumeHandle, this, &UMainMenuWidget::ChangeMusicVolume, 0.05f, true, 0.05f);
		AudioComponent = UGameplayStatics::SpawnSound2D(this, Music, MusicVolume);
		CzyMuzyka = true;
	}
}

void UMainMenuWidget::ChangeMusicVolume()
{
	MusicVolume += 0.01f;
	AudioComponent->SetVolumeMultiplier(MusicVolume);
	if (MusicVolume >= 0.50f) Buttons[0]->GetWorldTimerManager().ClearTimer(MusicVolumeHandle);
}

void UMainMenuWidget::OnStartClick()
{
	UWorld* World = GetWorld();

	if (World && CzyMozna == true && CzyBack == false)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		FVector SpawnLoc(2620.f, 4770.f, -10.f);
		GetWorld()->SpawnActor<AActor>(Fade, FTransform(SpawnLoc), SpawnParameters);

		Buttons[0]->GetWorldTimerManager().SetTimer(Black, this, &UMainMenuWidget::StartBlack, 0.1f, false, 2.1f);
	}
}

void UMainMenuWidget::StartBlack()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("tETRIS"));
}

void UMainMenuWidget::OnQuitClick()
{
	UWorld* World = GetWorld();

	if (World && CzyMozna == true && CzyBack == false)
	{
		UKismetSystemLibrary::ExecuteConsoleCommand(World, TEXT("quit"));
	}
}

void UMainMenuWidget::OnControlsClick()
{
	if (CzyMozna == true)
	{
		auto cos = Cast<APoints>(Buttons[1]);
		if (cos->PierwszyRazControls == false && CzyBack == false)
		{
			//cos->KoncowaRotacja.Yaw -= 90.f;
			//cos->PierwszyRazControls = true;
			cos->KoncowaRotacja = cos->CameraActors[0]->GetActorRotation();
			cos->KoncowaRotacja.Yaw -= 90.f;
			cos->PierwszyRazControls = true;
			CzyBack = true;
		}
		else if (cos->PierwszyRazControls == true && CzyBack == true )
		{
			//cos->KoncowaRotacja.Yaw = 90.f; */
			cos->KoncowaRotacja = cos->CameraActors[0]->GetActorRotation();
			cos->KoncowaRotacja.Yaw += 90.f;
			cos->PierwszyRazControls = false;
			CzyBack = false;
		}

		cos->CzyInterpto = true;
		CzyMozna = false;
		Buttons[0]->GetWorldTimerManager().SetTimer(Mozna, this, &UMainMenuWidget::ZmianaMozna, 0.1f, false, 2.f);
	}
}

void UMainMenuWidget::OnStartHover()
{
	if (CzyMozna == true && CzyBack == false)
	{
		for (int i = 0; i != Buttons.Num(); i++)
		{
			auto cos = Cast<APoints>(Buttons[i]);
			if (cos->JakiButton == "Start")
			{
				UGameplayStatics::PlaySound2D(this, Select);
				cos->Text->SetTextMaterial(cos->Material_2);
				break;
			}
		}
	}
}

void UMainMenuWidget::OnStartUnHover()
{
	for (int i = 0; i != Buttons.Num(); i++)
	{
		auto cos = Cast<APoints>(Buttons[i]);
		if (cos->JakiButton == "Start")
		{
			cos->Text->SetTextMaterial(cos->Material_1);
			break;
		}
	}
}

void UMainMenuWidget::OnQuitHover()
{
	if (CzyMozna == true && CzyBack == false)
	{
		for (int i = 0; i != Buttons.Num(); i++)
		{
			auto cos = Cast<APoints>(Buttons[i]);
			if (cos->JakiButton == "Quit")
			{
				UGameplayStatics::PlaySound2D(this, Select);
				cos->Text->SetTextMaterial(cos->Material_2);
				break;
			}
		}
	}
}

void UMainMenuWidget::OnQuitUnHover()
{
	for (int i = 0; i != Buttons.Num(); i++)
	{
		auto cos = Cast<APoints>(Buttons[i]);
		if (cos->JakiButton == "Quit")
		{
			cos->Text->SetTextMaterial(cos->Material_1);
			break;
		}
	}
}

void UMainMenuWidget::OnControlsHover()
{
	if (CzyMozna == true && CzyBack == false)
	{
		for (int i = 0; i != Buttons.Num(); i++)
		{
			auto cos = Cast<APoints>(Buttons[i]);
			if (cos->JakiButton == "Controls")
			{
				UGameplayStatics::PlaySound2D(this, Select);
				cos->Text->SetTextMaterial(cos->Material_2);
				break;
			}
		}
	}
}

void UMainMenuWidget::OnControlsUnHover()
{
	for (int i = 0; i != Buttons.Num(); i++)
	{
		auto cos = Cast<APoints>(Buttons[i]);
		if (cos->JakiButton == "Controls")
		{
			cos->Text->SetTextMaterial(cos->Material_1);
			break;
		}
	}
}

void UMainMenuWidget::OnBackHover()
{
	if (CzyMozna == true && CzyBack == true)
	{
		for (int i = 0; i != Buttons.Num(); i++)
		{
			auto cos = Cast<APoints>(Buttons[i]);
			if (cos->JakiButton == "Back")
			{
				UGameplayStatics::PlaySound2D(this, Select);
				cos->Text->SetTextMaterial(cos->Material_2);
				break;
			}
		}
	}
}

void UMainMenuWidget::OnBackUnHover()
{
	for (int i = 0; i != Buttons.Num(); i++)
	{
		auto cos = Cast<APoints>(Buttons[i]);
		if (cos->JakiButton == "Back")
		{
			cos->Text->SetTextMaterial(cos->Material_1);
			break;
		}
	}
}
