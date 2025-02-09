// Fill out your copyright notice in the Description page of Project Settings.


#include "HorrorTask_RandomLocationMove.h"

#include "AIController.h"
#include "HorrorAIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UHorrorTask_RandomLocationMove::UHorrorTask_RandomLocationMove()
{
	NodeName = "RandomLocationMove";
}

EBTNodeResult::Type UHorrorTask_RandomLocationMove::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (AHorrorAIController* contoller = Cast<AHorrorAIController>(OwnerComp.GetAIOwner()))
	{
		if (APawn* pawn = contoller->GetPawn())
		{
			FVector pawnLocation = pawn->GetActorLocation();

			if (UNavigationSystemV1* navi = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				FNavLocation location;
				//이동 가능한 지점에서 랜덤 위치 저장
				if (navi->GetRandomPointInNavigableRadius(pawnLocation, SearchRadius, location))
				{
					OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), location.Location);
				}

				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Succeeded;
}

FString UHorrorTask_RandomLocationMove::GetStaticDescription() const
{
	return Super::GetStaticDescription();
}
