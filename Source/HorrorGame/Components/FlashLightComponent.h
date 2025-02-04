// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SpotLightComponent.h"
#include "Components/TimelineComponent.h"
#include "FlashLightComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HORRORGAME_API UFlashLightComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFlashLightComponent();

	void SetFlashLigth(TObjectPtr<USpotLightComponent> ligth) { FlashLight = ligth; }
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


private:
	void OnBlinkingLight(float intensity);


private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess = "true"))
	UCurveFloat* BlinkLigthCurve;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess = "true"))
	float TimelineLength = 1.0f;
	
	UPROPERTY()
	TObjectPtr<USpotLightComponent> FlashLight;

	UPROPERTY()
	TObjectPtr<UTimelineComponent> BlinkTimeline;

private:
	FOnTimelineFloat InterpFloat;


};
