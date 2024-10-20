#include "AI/UhuAIController.h"
#include "Characters/UhuDroneCharacter.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AUhuAIController::AUhuAIController()
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
}

void AUhuAIController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay im AI Controller ausgelöst"));

	if (UseBlackboard(BlackboardComp->GetBlackboardAsset(), BlackboardComp))
	{
		UE_LOG(LogTemp, Warning, TEXT("Blackboard initialisiert"));

		if (BehaviorComp && BehaviorComp->GetCurrentTree())
		{
			BehaviorComp->StartTree(*BehaviorComp->GetCurrentTree());
			UE_LOG(LogTemp, Warning, TEXT("Behavior Tree gestartet"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Behavior Tree nicht gefunden"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Blackboard konnte nicht initialisiert werden"));
	}
}
