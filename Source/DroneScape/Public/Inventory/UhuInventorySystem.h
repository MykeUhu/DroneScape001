// Copyright by MykeUhu
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UhuInventoryItemData.h"
#include "Components/UhuInventoryComponent.h"
#include "UhuInventorySystem.generated.h"

UCLASS()
class DRONESCAPE_API AUhuInventorySystem : public AActor
{
	GENERATED_BODY()

public:
	AUhuInventorySystem();

protected:
	virtual void BeginPlay() override;

public:
	// Referenz zur DataTable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UDataTable* InventoryDataTable;

	// Inventar-Komponente
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	UUhuInventoryComponent* InventoryComponent;

	// Funktion zum Hinzufügen eines Items
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(FName RowName, int32 Amount) const;

	// Funktion zum Entfernen eines Items
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(FName RowName, int32 Amount) const;

	// Funktion zur Überprüfung, ob ein Item vorhanden ist
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool HasItem(FName RowName, int32& OutAmount) const;

	// Funktion zur Generierung eines eindeutigen Tags
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	static FGameplayTag GenerateUniqueTag();
};
