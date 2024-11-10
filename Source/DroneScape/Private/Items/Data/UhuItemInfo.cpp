#include "Items/Data/UhuItemInfo.h"
#include "GameplayTagContainer.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Engine/Engine.h" // Für Debug-Logs


FUhuItemInfo UItemInfo::FindAttributeForTag(const FGameplayTag& ItemTag, bool bLogNotFound) const
{
    for (const FUhuItemInfo& Info : ItemInformation)
    {
        if (Info.ItemTag.MatchesTagExact(ItemTag))
        {
            return Info;
        }
    }
    if (bLogNotFound)
    {
        UE_LOG(LogTemp, Error, TEXT("Can't find Info for ItemTag [%s] on ItemInfo [%s]."), *ItemTag.ToString(), *GetNameSafe(this));
    }
    return FUhuItemInfo();

}

// Exportiert die Item-Informationen in eine CSV-Datei
void UItemInfo::ExportItemInfoToCSV(const FString& FilePath)
{
    FString CSVData;
    CSVData.Append(TEXT("ItemName,ItemTag,RarityTag,ItemImage,ItemDescription,ItemWeight,ItemDurability,NutrientValues,VitalValues,TechnicalValues\n"));

    for (const FUhuItemInfo& Info : ItemInformation)
    {
        // Den Pfad des ItemImage-Assets speichern
        FString ItemImagePath = Info.ItemImage ? *Info.ItemImage->GetPathName() : TEXT("None");

        FString NutrientValuesStr;
        for (const auto& Pair : Info.NutrientValues)
        {
            NutrientValuesStr.Append(FString::Printf(TEXT("%s:%f|"), *Pair.Key.GetTagName().ToString(), Pair.Value));
        }

        FString VitalValuesStr;
        for (const auto& Pair : Info.VitalValues)
        {
            VitalValuesStr.Append(FString::Printf(TEXT("%s:%f|"), *Pair.Key.GetTagName().ToString(), Pair.Value));
        }

        FString TechnicalValuesStr;
        for (const auto& Pair : Info.TechnicalValues)
        {
            TechnicalValuesStr.Append(FString::Printf(TEXT("%s:%f|"), *Pair.Key.GetTagName().ToString(), Pair.Value));
        }

        CSVData.Append(FString::Printf(TEXT("%s,%s,%s,%s,%s,%f,%d,%s,%s,%s\n"),
            *Info.ItemName.ToString(),
            *Info.ItemTag.ToString(),
            *Info.RarityTag.ToString(),
            *ItemImagePath,
            *Info.ItemDescription,
            Info.ItemWeight,
            Info.ItemDurability,
            *NutrientValuesStr,
            *VitalValuesStr,
            *TechnicalValuesStr));
    }

    FString FullPath = FPaths::ProjectDir() + FilePath;
    FFileHelper::SaveStringToFile(CSVData, *FullPath);
}

// Importiert die Item-Informationen aus einer CSV-Datei

void UItemInfo::ImportItemInfoFromCSV(const FString& FilePath)
{
    FString CSVData;
    FString FullPath = FPaths::ProjectDir() + FilePath;

    if (FFileHelper::LoadFileToString(CSVData, *FullPath))
    {
        UE_LOG(LogTemp, Log, TEXT("CSV-Datei erfolgreich geladen: %s"), *FullPath);

        TArray<FString> Rows;
        CSVData.ParseIntoArray(Rows, TEXT("\n"), true);

        ItemInformation.Empty();

        for (int32 i = 1; i < Rows.Num(); ++i) // Start from 1 to skip header row
        {
            TArray<FString> Columns;
            Rows[i].ParseIntoArray(Columns, TEXT(","), true);

            if (Columns.Num() == 10)
            {
                FUhuItemInfo Item;
                Item.ItemName = FName(*Columns[0]);
                Item.ItemTag = FGameplayTag::RequestGameplayTag(FName(*Columns[1]));
                Item.RarityTag = FGameplayTag::RequestGameplayTag(FName(*Columns[2]));
                Item.ItemImage = LoadObject<UTexture2D>(nullptr, *Columns[3]);
                Item.ItemDescription = Columns[4];
                Item.ItemWeight = FCString::Atof(*Columns[5]);
                Item.ItemDurability = FCString::Atoi(*Columns[6]);

                TArray<FString> NutrientValuesArray;
                Columns[7].ParseIntoArray(NutrientValuesArray, TEXT("|"), true);
                for (const FString& Nutrient : NutrientValuesArray)
                {
                    if (!Nutrient.IsEmpty())
                    {
                        TArray<FString> Pair;
                        Nutrient.ParseIntoArray(Pair, TEXT(":"), true);
                        if (Pair.Num() == 2)
                        {
                            Item.NutrientValues.Add(FGameplayTag::RequestGameplayTag(FName(*Pair[0])), FCString::Atof(*Pair[1]));
                        }
                    }
                }

                TArray<FString> VitalValuesArray;
                Columns[8].ParseIntoArray(VitalValuesArray, TEXT("|"), true);
                for (const FString& Vital : VitalValuesArray)
                {
                    if (!Vital.IsEmpty())
                    {
                        TArray<FString> Pair;
                        Vital.ParseIntoArray(Pair, TEXT(":"), true);
                        if (Pair.Num() == 2)
                        {
                            Item.VitalValues.Add(FGameplayTag::RequestGameplayTag(FName(*Pair[0])), FCString::Atof(*Pair[1]));
                        }
                    }
                }

                TArray<FString> TechnicalValuesArray;
                Columns[9].ParseIntoArray(TechnicalValuesArray, TEXT("|"), true);
                for (const FString& Technical : TechnicalValuesArray)
                {
                    if (!Technical.IsEmpty())
                    {
                        TArray<FString> Pair;
                        Technical.ParseIntoArray(Pair, TEXT(":"), true);
                        if (Pair.Num() == 2)
                        {
                            Item.TechnicalValues.Add(FGameplayTag::RequestGameplayTag(FName(*Pair[0])), FCString::Atof(*Pair[1]));
                        }
                    }
                }

                ItemInformation.Add(Item);

                UE_LOG(LogTemp, Log, TEXT("Item erfolgreich importiert: %s"), *Item.ItemName.ToString());
            }
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Fehler beim Laden der CSV-Datei: %s"), *FullPath);
    }
}