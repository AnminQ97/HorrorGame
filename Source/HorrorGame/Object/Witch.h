#pragma once

#include "CoreMinimal.h"
#include "HorrorObject.h"
#include "Witch.generated.h"

UCLASS()
class HORRORGAME_API AWitch : public AHorrorObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Witch;
};
