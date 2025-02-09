#pragma once

#include "CoreMinimal.h"
#include "HorrorObject.h"
#include "SpookyTexture.generated.h"

UCLASS()
class HORRORGAME_API ASpookyTexture : public AHorrorObject
{
	GENERATED_BODY()

	ASpookyTexture();

	virtual void StartEvent() override;
	virtual void BeginPlay() override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> SpookyTexture;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> DefaultComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> Plane;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ActiveTime = 1.0f;
};
