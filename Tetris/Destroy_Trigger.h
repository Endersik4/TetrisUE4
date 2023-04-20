// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Destroy_Trigger.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API ADestroy_Trigger : public ATriggerVolume
{
	GENERATED_BODY()

public:
	ADestroy_Trigger();

private:
	int DestroyBox;
	bool CzyNiszczyc;
	void Niszczenie(class AActor* Inny);	

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	
};
