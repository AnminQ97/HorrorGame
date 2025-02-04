#include "FlashLightComponent.h"

UFlashLightComponent::UFlashLightComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	BlinkTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineComponent"));

	InterpFloat.BindUFunction(this, FName("OnBlinkingLight"));
}

void UFlashLightComponent::BeginPlay()
{
	Super::BeginPlay();

	BlinkTimeline->SetLooping(false);
	BlinkTimeline->AddInterpFloat(BlinkLigthCurve, InterpFloat);
	BlinkTimeline->SetTimelineLength(TimelineLength);

	BlinkTimeline->PlayFromStart();
}


void UFlashLightComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UFlashLightComponent::OnBlinkingLight(float intensity)
{
	FlashLight->Intensity = intensity;
}

