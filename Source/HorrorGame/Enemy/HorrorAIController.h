// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "HorrorEnemyCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "HorrorGame/HorrorGameCharacter.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "HorrorAIController.generated.h"

UENUM(BlueprintType)
enum class EBehaviorType : uint8
{
	Approach, Patrol
};

UCLASS()
class HORRORGAME_API AHorrorAIController : public AAIController
{
	GENERATED_BODY()

	AHorrorAIController();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;\
	virtual void OnUnPossess() override;

	virtual void Tick(float DeltaSeconds) override;
	
public:
	UFUNCTION()
	void OnPerceptionUpdate(const TArray<AActor*>& UpdatedActors);
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UAIPerceptionComponent> PerCeptionComp;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UAISenseConfig_Sight> SightConfig;

	UFUNCTION(BlueprintCallable)
	AHorrorGameCharacter* GetTargetPlayer() {return TargetPlayer;};

	void SetApproach();
	void SetPatrol();
	void SetState(uint8 state);
private:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;

	UPROPERTY()
	TObjectPtr<AHorrorEnemyCharacter> OwnerEnemy;
	
	UPROPERTY()
	TObjectPtr<AHorrorGameCharacter> TargetPlayer;
};
