#include "SpookyTexture.h"

ASpookyTexture::ASpookyTexture()
{
	DefaultComponent = CreateDefaultSubobject<USceneComponent>("DefaultComponent");
	RootComponent = DefaultComponent;
	
	Plane = CreateDefaultSubobject<UStaticMeshComponent>("Door");
	Plane->SetupAttachment(RootComponent);
}


void ASpookyTexture::StartEvent()
{
	Super::StartEvent();

	if (IsValid(SpookyTexture))
	{
		currentState = HorrorObjectState::Active;
		PlaySound();
		Plane->SetVisibility(true);

		FTimerHandle myTimerHandle;
		GetWorld()->GetTimerManager().SetTimer(myTimerHandle, FTimerDelegate::CreateLambda([&]()
		{
			Plane->SetVisibility(false);
			currentState = HorrorObjectState::Finished;
			GetWorld()->GetTimerManager().ClearTimer(myTimerHandle);
		}), ActiveTime, false);
	}
}

void ASpookyTexture::BeginPlay()
{
	Super::BeginPlay();

	Plane->SetVisibility(false);
}
