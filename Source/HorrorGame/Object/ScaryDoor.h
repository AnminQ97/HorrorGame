#pragma once

#include "CoreMinimal.h"
#include "HorrorObject.h"
#include "Components/TimelineComponent.h"
#include "ScaryDoor.generated.h"

UCLASS()
class HORRORGAME_API AScaryDoor : public AHorrorObject
{
	GENERATED_BODY()
	AScaryDoor();

public:
	virtual void BeginPlay() override;
	virtual void StartEvent() override;
	virtual void Tick(float DeltaSeconds) override;
private:
	UFUNCTION()
	void OpenDoor(float timeline);
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<USceneComponent> DefaultComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Door;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UCurveFloat* DoorCurve;

private:
	FTimeline OpeningTimeline;

	bool bIsEvent = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	float DoorRotateAngle = 90.0f;
};
