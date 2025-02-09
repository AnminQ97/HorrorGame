#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HorrorObject.generated.h"

enum class HorrorObjectState : uint8
{
	Idle,
	Active,
	Finished
};

UCLASS()
class HORRORGAME_API AHorrorObject : public AActor
{
	GENERATED_BODY()
	
public:	
	AHorrorObject();

	virtual void BeginPlay() override;
	
protected:
	virtual void StartEvent();
	
	void PlaySound();

public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	TObjectPtr<USoundWave> SoundWave;

protected:
	HorrorObjectState currentState;
	
};
