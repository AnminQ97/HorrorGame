#include "HorrorObjectTrigger.h"

AHorrorObjectTrigger::AHorrorObjectTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &AHorrorObjectTrigger::OnBeginOverlap);
}

void AHorrorObjectTrigger::OnBeginOverlap(AActor* overlappedComponent, AActor* otherActor)
{
	if (otherActor && otherActor != this)
	{
		HorrorObject->StartEvent();
	}
}
