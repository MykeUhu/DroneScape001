// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/UhuInventoryComponent.h"
#include "Engine/DataTable.h"
#include "Components/UhuItemDataComponent.h"  
#include "UhuChest.generated.h"

UCLASS()
class DRONESCAPE_API AUhuChest : public AActor
{
	GENERATED_BODY()

public:
	// Konstruktor
	AUhuChest();

protected:
	virtual void BeginPlay() override;

public:
	// Inventar-Komponente
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	UUhuInventoryComponent* InventoryComponent;

	// Mesh-Komponente
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* ChestMesh;

	// Data Table für Items
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UDataTable* ItemDataTable;

	// Funktion zum Hinzufügen von Items zum Inventar
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItemsToInventory();
    
	// Funktion zum Abrufen von Item-Daten basierend auf Gameplay-Tag
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FUhuItemData GetItemDataByTag(FGameplayTag ItemTag);
};
