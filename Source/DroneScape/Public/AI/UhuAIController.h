// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "UhuAIController.generated.h"

/**
 * 
 */
UCLASS()
class DRONESCAPE_API AUhuAIController : public AAIController
{
	GENERATED_BODY()
public:
	AUhuAIController();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "AI")
	UBlackboardComponent* BlackboardComp;

	UPROPERTY(VisibleAnywhere, Category = "AI")
	UBehaviorTreeComponent* BehaviorComp;
};