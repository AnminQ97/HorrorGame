#include "FlashLightComponent.h"

UFlashLightComponent::UFlashLightComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UFlashLightComponent::OnBlinkLightEvent()
{
	BlinkLightTimeline.Play();
	
}

void UFlashLightComponent::BeginPlay()
{
	Super::BeginPlay();

	if (BlinkLigthCurve)
	{
		FOnTimelineFloat progress;
		progress.BindDynamic(this, &UFlashLightComponent::BlinkingLight);
		BlinkLightTimeline.AddInterpFloat(BlinkLigthCurve, progress);
	}

	LightIntensity = FlashLight->Intensity;
}

void UFlashLightComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	BlinkLightTimeline.TickTimeline(DeltaTime);
}

void UFlashLightComponent::BlinkingLight(float intensity)
{
	FlashLight->SetIntensity(LightIntensity * intensity);
}