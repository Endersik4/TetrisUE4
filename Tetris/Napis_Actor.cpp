// Fill out your copyright notice in the Description page of Project Settings.


#include "Napis_Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

// Sets default values
ANapis_Actor::ANapis_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANapis_Actor::BeginPlay()
{
	Super::BeginPlay();
	//(X=400.000000,Y=110.000000,Z=2700.000000)
	const FVector SpawnLoc(370.f, 110.f, 2800.f);
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AActor>(Main_1, FTransform(SpawnLoc), SpawnParameters);
	GetWorld()->SpawnActor<AActor>(Main_2, FTransform(SpawnLoc), SpawnParameters);
	GetWorld()->SpawnActor<AActor>(Main_3, FTransform(SpawnLoc), SpawnParameters);
	GetWorld()->SpawnActor<AActor>(Main_4, FTransform(SpawnLoc), SpawnParameters);
	GetWorld()->SpawnActor<AActor>(Main_5, FTransform(SpawnLoc), SpawnParameters);
	GetWorld()->SpawnActor<AActor>(Main_6, FTransform(SpawnLoc), SpawnParameters);
	GetWorld()->SpawnActor<AActor>(Main_7, FTransform(SpawnLoc), SpawnParameters);

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Main_1, Main1);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Main_2, Main2);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Main_3, Main3);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Main_4, Main4);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Main_5, Main5);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Main_6, Main6);
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Main_7, Main7);

	
	GetWorldTimerManager().SetTimer(Czas, this, &ANapis_Actor::SetLocation, 0.55f, true, 0.04f);
}

void ANapis_Actor::SetLocation()
{
	FVector Location;
	if (int_Main1 != 13)
	{
		Location = Main1[0]->GetActorLocation();
		Location.Z -= 180.f;
		Main1[0]->SetActorLocation(Location);
		int_Main1++;
		if (int_Main1 >= 13)
		{
			GetWorldTimerManager().ClearTimer(Czas);
			UGameplayStatics::PlaySound2D(this, Walniecie);
		}
		GetWorldTimerManager().SetTimer(Czas, this, &ANapis_Actor::SetLocation, 0.55f, true, 0.04f);
	}
	else if (int_Main2 != 13)
	{
		Location = Main2[0]->GetActorLocation();
		Location.Z -= 180.f;
		Main2[0]->SetActorLocation(Location);
		int_Main2++;
		if (int_Main2 >= 13)
		{
			UGameplayStatics::PlaySound2D(this, Walniecie);
			GetWorldTimerManager().ClearTimer(Czas);
		}
		GetWorldTimerManager().SetTimer(Czas, this, &ANapis_Actor::SetLocation, 0.55f, true, 0.04f);
	}
	else if (int_Main3 != 13)
	{
		Location = Main3[0]->GetActorLocation();
		Location.Z -= 180.f;
		Main3[0]->SetActorLocation(Location);
		int_Main3++;
		if (int_Main3 >= 13)
		{
			UGameplayStatics::PlaySound2D(this, Walniecie);
			GetWorldTimerManager().ClearTimer(Czas);
		}
		GetWorldTimerManager().SetTimer(Czas, this, &ANapis_Actor::SetLocation, 0.55f, true, 0.04f);
	}
	else if (int_Main4 != 13)
	{
		Location = Main4[0]->GetActorLocation();
		Location.Z -= 180.f;
		Main4[0]->SetActorLocation(Location);
		int_Main4++;
		if (int_Main4 >= 13) 
		{
			UGameplayStatics::PlaySound2D(this, Walniecie);
			GetWorldTimerManager().ClearTimer(Czas);
		}
		GetWorldTimerManager().SetTimer(Czas, this, &ANapis_Actor::SetLocation, 0.55f, true, 0.04f);
	}
	else if (int_Main5 != 13)
	{
		Location = Main5[0]->GetActorLocation();
		Location.Z -= 180.f;
		Main5[0]->SetActorLocation(Location);
		int_Main5++;
		if (int_Main5 >= 13)
		{
			UGameplayStatics::PlaySound2D(this, Walniecie);
			GetWorldTimerManager().ClearTimer(Czas);
		}
		GetWorldTimerManager().SetTimer(Czas, this, &ANapis_Actor::SetLocation, 0.55f, true, 0.04f);
	}
	else if (int_Main6 != 13)
	{
		Location = Main6[0]->GetActorLocation();
		Location.Z -= 180.f;
		Main6[0]->SetActorLocation(Location);
		int_Main6++;
		if (int_Main6 >= 13)
		{
			UGameplayStatics::PlaySound2D(this, Walniecie);
			GetWorldTimerManager().ClearTimer(Czas);
		}
		GetWorldTimerManager().SetTimer(Czas, this, &ANapis_Actor::SetLocation, 0.55f, true, 0.04f);
	}
	else if (int_Main7 != 13)
	{
		Location = Main7[0]->GetActorLocation();
		Location.Z -= 180.f;
		Main7[0]->SetActorLocation(Location);
		int_Main7++;
		if (int_Main7 >= 13)
		{
			UGameplayStatics::PlaySound2D(this, Walniecie);
			GetWorldTimerManager().ClearTimer(Czas);
		}
		GetWorldTimerManager().SetTimer(Czas, this, &ANapis_Actor::SetLocation, 0.55f, true, 0.04f);
	}
	else GetWorldTimerManager().ClearTimer(Czas);
}

// Called every frame
void ANapis_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

