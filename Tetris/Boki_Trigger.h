// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Boki_Trigger.generated.h"

/**
 * 
 */
UCLASS()
class TETRIS_API ABoki_Trigger : public ATriggerVolume
{
	GENERATED_BODY()

public:
	ABoki_Trigger();

	UPROPERTY(EditAnywhere)
		bool bCzyPrawaStrona = true;
	UPROPERTY(EditAnywhere)
		bool bCzyWykrywa;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
};
