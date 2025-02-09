#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HorrorEnemyCharacter.generated.h"

UCLASS()
class HORRORGAME_API AHorrorEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AHorrorEnemyCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	uint8 GetTeamID() {return TeamID;}
	
private:
	UPROPERTY(EditAnywhere)
	uint8 TeamID = 1;
};
