#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "HorrorTask_RandomLocationMove.generated.h"

UCLASS()
class HORRORGAME_API UHorrorTask_RandomLocationMove : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	UHorrorTask_RandomLocationMove();

private:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual FString GetStaticDescription() const override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	float SearchRadius = 1000.0f;
};
