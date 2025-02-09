#include "HorrorAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "HorrorGame/HorrorGameCharacter.h"


AHorrorAIController::AHorrorAIController()
{
	PrimaryActorTick.bCanEverTick = true;
	
	PerCeptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception"));
	SetPerceptionComponent(*PerCeptionComp);
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 800.f;
	SightConfig->LoseSightRadius = 1200.f; 
	SightConfig->PeripheralVisionAngleDegrees = 120.f; 
	SightConfig->AutoSuccessRangeFromLastSeenLocation = -1.f;
	SightConfig->SetMaxAge(5.f); 

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	
	PerCeptionComp->ConfigureSense(*SightConfig);
	PerCeptionComp->SetDominantSense(SightConfig->GetSenseImplementation());
	PerCeptionComp->OnPerceptionUpdated.AddDynamic(this, &AHorrorAIController::OnPerceptionUpdate);
	
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>("BehaviorTreeComponent");
}

void AHorrorAIController::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsValid(BehaviorTree.Get()))
	{
		RunBehaviorTree(BehaviorTree.Get());
		BehaviorTreeComponent->StartTree(*BehaviorTree.Get());
	}
}

void AHorrorAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	OwnerEnemy = Cast<AHorrorEnemyCharacter>(InPawn);
	
	if (IsValid(Blackboard.Get()) && IsValid(BehaviorTree.Get()))
	{
		Blackboard->InitializeBlackboard(*BehaviorTree.Get()->BlackboardAsset.Get());
	}
}

void AHorrorAIController::OnUnPossess()
{
	Super::OnUnPossess();

	PerCeptionComp->OnPerceptionUpdated.Clear();
}

void AHorrorAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AHorrorAIController::OnPerceptionUpdate(const TArray<AActor*>& UpdatedActors)
{
	TArray<AActor*> actors;
	PerCeptionComp->GetCurrentlyPerceivedActors(NULL, actors);
	UE_LOG(LogTemp, Warning, TEXT("Player test") );
	TargetPlayer = nullptr;
	for (TObjectPtr<AActor> actor : actors)
	{
		UE_LOG(LogTemp, Display, TEXT("Player %s"), *actor->GetName());
		TargetPlayer = Cast<AHorrorGameCharacter>(actor);
		
		if (TargetPlayer)
			break;
	}

	if (IsValid(Blackboard))
	{
		Blackboard->SetValueAsObject("player", TargetPlayer);
	}
}

void AHorrorAIController::SetApproach()
{
	SetState(uint8(EBehaviorType::Approach));
}

void AHorrorAIController::SetPatrol()
{
	SetState(uint8(EBehaviorType::Patrol));
}

void AHorrorAIController::SetState(uint8 state)
{
	if (IsValid(Blackboard))
	{
		Blackboard->SetValueAsEnum("State", state);
	}
}
