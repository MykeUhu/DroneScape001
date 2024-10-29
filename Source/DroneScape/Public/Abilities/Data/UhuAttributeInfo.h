#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UhuAttributeInfo.generated.h"

USTRUCT(BlueprintType)
struct FUhuAttributeInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag AttributeTag = FGameplayTag();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeName = FText();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeDescription = FText();

	UPROPERTY(BlueprintReadOnly)
	float AttributeValue = 0.f;
};

UCLASS()
class DRONESCAPE_API UAttributeInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	FUhuAttributeInfo FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound = false) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FUhuAttributeInfo> AttributeInformation;

	// Developement only!!!
	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void ExportAttributesToCSV(const FString& FilePath);

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void ImportAttributesFromCSV(const FString& FilePath);
};
