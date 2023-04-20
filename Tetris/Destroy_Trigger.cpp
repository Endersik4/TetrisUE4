// Fill out your copyright notice in the Description page of Project Settings.


#include "Destroy_Trigger.h"

#include "TetrisPawn.h"

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, String)

ADestroy_Trigger::ADestroy_Trigger()
{
	OnActorBeginOverlap.AddDynamic(this, &ADestroy_Trigger::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ADestroy_Trigger::OnOverlapEnd);
	
}

void ADestroy_Trigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	auto MyTetrisPawn = Cast<ATetrisPawn>(OtherActor);
	//TimerDel.BindUFunction(this, FName("Niszczenie"), OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("OVERLAP"));
	//GetWorldTimerManager().SetTimer(cos, TimerDel, 1.05f, true, 0.f);
	if (MyTetrisPawn->bBox1OverlapDestroy == true) { DestroyBox++; 	UE_LOG(LogTemp, Warning, TEXT("DestroyBox++ Box1")); }
	if (MyTetrisPawn->bBox2OverlapDestroy == true) { DestroyBox++; 	UE_LOG(LogTemp, Warning, TEXT("DestroyBox++ Box2")); }
	if (MyTetrisPawn->bBox3OverlapDestroy == true) { DestroyBox++; 	UE_LOG(LogTemp, Warning, TEXT("DestroyBox++ Box3")); }
	if (MyTetrisPawn->bBox4OverlapDestroy == true) { DestroyBox++; 	UE_LOG(LogTemp, Warning, TEXT("DestroyBox++ Box4")); }

	if (DestroyBox >= 10) CzyNiszczyc = true;
	else CzyNiszczyc = false;
	if (CzyNiszczyc == false)
	{
		if (MyTetrisPawn->bBox1OverlapDestroy == true) { MyTetrisPawn->bBox1Destroy = true; UE_LOG(LogTemp, Warning, TEXT("bBox1Destroy = true")); }
		if (MyTetrisPawn->bBox2OverlapDestroy == true) { MyTetrisPawn->bBox2Destroy = true; UE_LOG(LogTemp, Warning, TEXT("bBox2Destroy = true")); }
		if (MyTetrisPawn->bBox3OverlapDestroy == true) { MyTetrisPawn->bBox3Destroy = true; UE_LOG(LogTemp, Warning, TEXT("bBox3Destroy = true")); }
		if (MyTetrisPawn->bBox4OverlapDestroy == true) { MyTetrisPawn->bBox4Destroy = true; UE_LOG(LogTemp, Warning, TEXT("bBox4Destroy = true")); }
		DestroyBox = 0;
	}
}

void ADestroy_Trigger::Niszczenie(AActor* Inny)
{
	auto MyTetrisPawn = Cast<ATetrisPawn>(Inny);
	UE_LOG(LogTemp, Warning, TEXT("CZY OVERLAP TRUE"));
	if (MyTetrisPawn->bBox1OverlapDestroy == true) { DestroyBox++; 	UE_LOG(LogTemp, Warning, TEXT("DestroyBox++ Box1")); }
	if (MyTetrisPawn->bBox2OverlapDestroy == true) { DestroyBox++; 	UE_LOG(LogTemp, Warning, TEXT("DestroyBox++ Box2")); }
	if (MyTetrisPawn->bBox3OverlapDestroy == true) { DestroyBox++; 	UE_LOG(LogTemp, Warning, TEXT("DestroyBox++ Box3")); }
	if (MyTetrisPawn->bBox4OverlapDestroy == true) { DestroyBox++; 	UE_LOG(LogTemp, Warning, TEXT("DestroyBox++ Box4")); }

	if (DestroyBox >= 10) CzyNiszczyc = true;
	else CzyNiszczyc = false;
	if (CzyNiszczyc == false)
	{
		if (MyTetrisPawn->bBox1OverlapDestroy == true) { MyTetrisPawn->bBox1Destroy = true; UE_LOG(LogTemp, Warning, TEXT("bBox1Destroy = true")); }
		if (MyTetrisPawn->bBox2OverlapDestroy == true) { MyTetrisPawn->bBox2Destroy = true; UE_LOG(LogTemp, Warning, TEXT("bBox2Destroy = true")); }
		if (MyTetrisPawn->bBox3OverlapDestroy == true) { MyTetrisPawn->bBox3Destroy = true; UE_LOG(LogTemp, Warning, TEXT("bBox3Destroy = true")); }
		if (MyTetrisPawn->bBox4OverlapDestroy == true) { MyTetrisPawn->bBox4Destroy = true; UE_LOG(LogTemp, Warning, TEXT("bBox4Destroy = true")); }
		DestroyBox = 0;
	}
}

void ADestroy_Trigger::OnOverlapEnd(AActor* OverlappedActor, AActor	* OtherActor)
{
	auto MyTetrisPawn = Cast<ATetrisPawn>(OtherActor);
	if (MyTetrisPawn->bBox1OverlapDestroy == false) { DestroyBox--; UE_LOG(LogTemp, Warning, TEXT("DestroyBox-- Box1")); }
	if (MyTetrisPawn->bBox2OverlapDestroy == false) { DestroyBox--; UE_LOG(LogTemp, Warning, TEXT("DestroyBox-- Box2")); }
	if (MyTetrisPawn->bBox3OverlapDestroy == false) { DestroyBox--; UE_LOG(LogTemp, Warning, TEXT("DestroyBox-- Box3")); }
	if (MyTetrisPawn->bBox4OverlapDestroy == false) { DestroyBox--; UE_LOG(LogTemp, Warning, TEXT("DestroyBox-- Box4")); }
	//GetWorldTimerManager().ClearTimer(cos);
}
