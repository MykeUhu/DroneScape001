#include "Characters/UhuPlayerCharacter.h"
#include "AbilitySystemComponent.h"
#include "Abilities/UhuAbilitySystemComponent.h"
#include "Components/UhuInventoryComponent.h"
#include "Controllers/UhuPlayerController.h"
#include "Game/UhuPlayerState.h"
#include "UI/HUD/UhuHud.h"

AUhuPlayerCharacter::AUhuPlayerCharacter() : InventoryComponent(nullptr)
{
    // Konstruktor-Logik...
}

void AUhuPlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
    
    if (InventoryComponentClass)
    {
        InventoryComponent = NewObject<UUhuInventoryComponent>(this, InventoryComponentClass);
        if (InventoryComponent)
        {
            InventoryComponent->RegisterComponent();
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("InventoryComponent konnte nicht instanziiert werden!"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("InventoryComponentClass ist nicht gesetzt!"));
    }
}

void AUhuPlayerCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);
    // Init ability actor info for the Server
    InitAbilityActorInfo();
}

void AUhuPlayerCharacter::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();
    // Init ability actor info for the Client
    InitAbilityActorInfo();
}

void AUhuPlayerCharacter::InitAbilityActorInfo()
{
    AUhuPlayerState* UhuPlayerState = GetPlayerState<AUhuPlayerState>();
    check(UhuPlayerState);
    UhuPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(UhuPlayerState, this);
    Cast<UUhuAbilitySystemComponent>(UhuPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
    AbilitySystemComponent = UhuPlayerState->GetAbilitySystemComponent();
    AttributeSet = UhuPlayerState->GetAttributeSet();

    if (AUhuPlayerController* UhuPlayerController = Cast<AUhuPlayerController>(GetController()))
    {
        if (AUhuHud* UhuHUD = Cast<AUhuHud>(UhuPlayerController->GetHUD()))
        {
            UhuHUD->InitOverlay(UhuPlayerController, UhuPlayerState, AbilitySystemComponent, AttributeSet);
        }
    }
    InitializeDefaultAttributes();
}
