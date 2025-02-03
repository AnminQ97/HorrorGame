#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HorrorObject.generated.h"

enum class HorrorObjectState : uint8
{
	Idle,
	Active,
	Done
};

UCLASS()
class HORRORGAME_API AHorrorObject : public AActor
{
	GENERATED_BODY()
	
public:	
	AHorrorObject();

	virtual void StartEvent();
protected:
	virtual void BeginPlay() override;

	virtual void PlaySound();
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TObjectPtr<USoundWave> SoundWave;

	HorrorObjectState currentState;
};
