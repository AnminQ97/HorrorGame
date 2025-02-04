#include "HorrorObject.h"

#include "Kismet/GameplayStatics.h"

AHorrorObject::AHorrorObject()
{
	PrimaryActorTick.bCanEverTick = true;

	currentState = HorrorObjectState::Idle;
}

void AHorrorObject::StartEvent()
{
}

void AHorrorObject::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHorrorObject::PlaySound()
{
	if (SoundWave)
	{
		UGameplayStatics::PlaySound2D(GetWorld(), SoundWave);
	}
}
