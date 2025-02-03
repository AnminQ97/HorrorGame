// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HorrorObject.h"
#include "Engine/TriggerBox.h"
#include "HorrorObjectTrigger.generated.h"

/**
 * 
 */
UCLASS()
class HORRORGAME_API AHorrorObjectTrigger : public ATriggerBox
{
	GENERATED_BODY()

	AHorrorObjectTrigger();

private:
	UFUNCTION()
	void OnBeginOverlap(AActor* OverlappedComponent, AActor* OtherActor);


private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<AHorrorObject> HorrorObject;
};
