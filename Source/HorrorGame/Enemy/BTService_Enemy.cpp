#include "BTService_Enemy.h"

#include "HorrorAIController.h"

UBTService_Enemy::UBTService_Enemy()
{
}

void UBTService_Enemy::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AHorrorAIController* controller = Cast<AHorrorAIController>(OwnerComp.GetOwner()); //트리의 오너인 컨트롤러
	TObjectPtr<AHorrorGameCharacter> player =  controller->GetTargetPlayer();

	if (player)
	{
		controller->SetApproach();
		return;
	}

	controller->SetPatrol();
}