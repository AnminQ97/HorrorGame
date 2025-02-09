#include "ScaryDoor.h"

AScaryDoor::AScaryDoor()
{
	DefaultComponent = CreateDefaultSubobject<USceneComponent>("DefaultComponent");
	RootComponent = DefaultComponent;

	Door = CreateDefaultSubobject<UStaticMeshComponent>("Door");
	Door->SetupAttachment(RootComponent);
}

void AScaryDoor::BeginPlay()
{
	Super::BeginPlay();

	if (DoorCurve)
	{
		FOnTimelineFloat progress;
		progress.BindDynamic(this, &AScaryDoor::OpenDoor);
		OpeningTimeline.AddInterpFloat(DoorCurve, progress);
	}
}

void AScaryDoor::StartEvent()
{
	Super::StartEvent();

	if (currentState == HorrorObjectState::Idle)
	{
		currentState = HorrorObjectState::Active;
		bIsEvent = true;
		OpeningTimeline.Play();

		PlaySound();
	}

}

void AScaryDoor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	OpeningTimeline.TickTimeline(DeltaSeconds);
}

void AScaryDoor::OpenDoor(float timeline)
{
	FRotator rot = FRotator(0.0f, DoorRotateAngle * timeline, 0.0f);
	Door->SetRelativeRotation(rot);
	
	if (DoorRotateAngle <= rot.Yaw)
	{
		OpeningTimeline.Stop();
		bIsEvent = false;
		currentState = HorrorObjectState::Finished;
	}
}
