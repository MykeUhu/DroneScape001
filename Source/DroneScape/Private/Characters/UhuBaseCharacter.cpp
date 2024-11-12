#include "Characters/UhuBaseCharacter.h"
#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Net/UnrealNetwork.h"
#include "Misc/FileHelper.h"
#include "Engine/DataTable.h"

AUhuBaseCharacter::AUhuBaseCharacter()
{
    // Enable replication for multiplayer
    bReplicates = true;

    // Kamerarotation wird von der Controller-Eingabe gesteuert
    bUseControllerRotationPitch = true;
    bUseControllerRotationYaw = true;
    bUseControllerRotationRoll = false;

    GetCharacterMovement()->bOrientRotationToMovement = false;

    // SpringArm erstellen und auf Länge 0 für First-Person setzen
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 0.0f;  // Länge 0 für First-Person
    SpringArm->bUsePawnControlRotation = true;  // Kamera dreht sich mit dem Controller

    // Kamera an den SpringArm anhängen
    FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FirstPersonCamera->SetupAttachment(SpringArm);  // An den SpringArm heften
    FirstPersonCamera->bUsePawnControlRotation = true;  // Kamera dreht sich mit dem Controller

    // Initial in First-Person-Ansicht
    bIsThirdPersonView = false;
    
}

void AUhuBaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    // Starten in der First-Person-Ansicht
    SpringArm->TargetArmLength = 0.0f;
}

void AUhuBaseCharacter::SwitchCamera()
{
    if (SpringArm)
    {
        // Wechsel zwischen First-Person- und Third-Person-Ansicht
        bIsThirdPersonView = !bIsThirdPersonView;
        SpringArm->TargetArmLength = bIsThirdPersonView ? 300.0f : 0.0f; // Setze die Länge des SpringArms
    }
}

// Replikation setup
void AUhuBaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    // Replicate the camera view state to other clients
    DOREPLIFETIME(AUhuBaseCharacter, bIsThirdPersonView);
}

UAbilitySystemComponent* AUhuBaseCharacter::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}

void AUhuBaseCharacter::InitAbilityActorInfo()
{
    // Hier können weitere Initialisierungen vorgenommen werden
}

void AUhuBaseCharacter::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect>& GameplayEffectClass, float Level) const
{
    check(IsValid(GetAbilitySystemComponent())); // Überprüfe, ob das AbilitySystemComponent gültig ist
    check(GameplayEffectClass); // Überprüfe, ob die GameplayEffect-Klasse gültig ist
    FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
    ContextHandle.AddSourceObject(this);
    const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
    GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AUhuBaseCharacter::InitializeDefaultAttributes() const
{
    // Wenn Attribute von anderen abhängen, vorsichtig mit der Reihenfolge
    ApplyEffectToSelf(DefaultVitalAttributes, 1.f);
    ApplyEffectToSelf(DefaultNutrientAttributes, 1.f);
    ApplyEffectToSelf(DefaultDroneAttributes, 1.f);
}

// Entwicklertool: Exportiere Item-Info in CSV
void AUhuBaseCharacter::ExportItemInfoToCSV()
{
    if (ItemInfo)
    {
        ItemInfo->ExportItemInfoToCSV(TEXT("Development/ExportImport/Items.csv"));
        UE_LOG(LogTemp, Log, TEXT("Item information exported successfully to CSV."));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("ItemInfo is null. Cannot export."));
    }
}

// Entwicklertool: Importiere Item-Info aus CSV
void AUhuBaseCharacter::ImportItemInfoFromCSV()
{
    if (ItemInfo)
    {
        ItemInfo->ImportItemInfoFromCSV(TEXT("Development/ExportImport/Items.csv"));
        UE_LOG(LogTemp, Log, TEXT("Item information imported successfully from CSV."));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("ItemInfo is null. Cannot import."));
    }
}

// Entwicklertool: Exportiere Attribut-Info in CSV
void AUhuBaseCharacter::ExportAttributeInfoToCSV()
{
    if (AttributeInfo)
    {
        AttributeInfo->ExportAttributesToCSV(TEXT("Development/ExportImport/Attributes.csv"));
        UE_LOG(LogTemp, Log, TEXT("Attribute information exported successfully to CSV."));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AttributeInfo is null. Cannot export."));
    }
}

// Entwicklertool: Importiere Attribut-Info aus CSV
void AUhuBaseCharacter::ImportAttributeInfoFromCSV()
{
    if (AttributeInfo)
    {
        AttributeInfo->ImportAttributesFromCSV(TEXT("Development/ExportImport/Attributes.csv"));
        UE_LOG(LogTemp, Log, TEXT("Attribute information imported successfully from CSV."));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AttributeInfo is null. Cannot import."));
    }
}


