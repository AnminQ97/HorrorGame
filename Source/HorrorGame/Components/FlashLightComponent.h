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

	UFUNCTION(BlueprintCallable)
	void OnBlinkLightEvent();
	
protected:
	virtual void BeginPlay() override;
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UFUNCTION()
	void BlinkingLight(float intensity);

private:
	UPROPERTY()
	TObjectPtr<USpotLightComponent> FlashLight;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UCurveFloat> BlinkLigthCurve;
	
	FTimeline BlinkLightTimeline;

	float LightIntensity;
};
