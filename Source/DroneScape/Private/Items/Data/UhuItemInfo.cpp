#include "Items/Data/UhuItemInfo.h"

#include "GameplayTagContainer.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Engine/Engine.h" // Für Debug-Logs

// Exportiert die Item-Informationen in eine CSV-Datei
void UItemInfo::ExportItemInfoToCSV(const FString& FilePath)
{
    FString CSVData;
    CSVData.Append(TEXT("ItemName,ItemTag,ItemImagePath,ItemDescription,ItemWeight,ItemRarity,ItemDurability,GameplayEffects,NutrientValues,VitalValues,TechnicalValues,RowName\n"));

    for (const FUhuItemInfo& Info : ItemInformation)
    {
        FString GameplayEffectsStr = FString::JoinBy(Info.GameplayEffects, TEXT("|"), [](const FGameplayTag& Tag) {
            return Tag.GetTagName().ToString();
        });

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

        CSVData.Append(FString::Printf(TEXT("%s,%s,%s,%s,%f,%s,%d,%s,%s,%s,%s,%s\n"),
            *Info.ItemName.ToString(),
            *Info.ItemTag.GetTagName().ToString(),
            *Info.ItemImagePath,
            *Info.ItemDescription,
            Info.ItemWeight,
            *Info.ItemRarity,
            Info.ItemDurability,
            *GameplayEffectsStr,
            *NutrientValuesStr,
            *VitalValuesStr,
            *TechnicalValuesStr,
            *Info.RowName.ToString()));
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
        TArray<FString> Rows;
        CSVData.ParseIntoArray(Rows, TEXT("\n"), true);

        ItemInformation.Empty();

        for (int32 i = 1; i < Rows.Num(); ++i) // Beginne bei 1, um die Kopfzeile zu überspringen
        {
            TArray<FString> Columns;
            Rows[i].ParseIntoArray(Columns, TEXT(","), true);

            if (Columns.Num() == 12) // Überprüfen, ob alle Spalten vorhanden sind
            {
                FUhuItemInfo Info;
                Info.ItemName = FName(*Columns[0]);
                Info.ItemTag = FGameplayTag::RequestGameplayTag(FName(*Columns[1]));
                Info.ItemImagePath = Columns[2]; // Wir nehmen an, dass dies ein Pfad ist
                Info.ItemDescription = Columns[3];
                Info.ItemWeight = FCString::Atof(*Columns[4]);
                Info.ItemRarity = Columns[5];
                Info.ItemDurability = FCString::Atoi(*Columns[6]);

                // GameplayEffects
                TArray<FString> EffectTags;
                Columns[7].ParseIntoArray(EffectTags, TEXT("|"), true);
                for (const FString& TagString : EffectTags)
                {
                    Info.GameplayEffects.Add(FGameplayTag::RequestGameplayTag(FName(*TagString)));
                }

                // NutrientValues
                TArray<FString> Nutrients;
                Columns[8].ParseIntoArray(Nutrients, TEXT("|"), true);
                for (const FString& Nutrient : Nutrients)
                {
                    TArray<FString> KeyValue;
                    Nutrient.ParseIntoArray(KeyValue, TEXT(":"), true);
                    if (KeyValue.Num() == 2)
                    {
                        Info.NutrientValues.Add(FGameplayTag::RequestGameplayTag(FName(*KeyValue[0])), FCString::Atof(*KeyValue[1]));
                    }
                }

                // VitalValues
                TArray<FString> Vitals;
                Columns[9].ParseIntoArray(Vitals, TEXT("|"), true);
                for (const FString& Vital : Vitals)
                {
                    TArray<FString> KeyValue;
                    Vital.ParseIntoArray(KeyValue, TEXT(":"), true);
                    if (KeyValue.Num() == 2)
                    {
                        Info.VitalValues.Add(FGameplayTag::RequestGameplayTag(FName(*KeyValue[0])), FCString::Atof(*KeyValue[1]));
                    }
                }

                // TechnicalValues
                TArray<FString> Technicals;
                Columns[10].ParseIntoArray(Technicals, TEXT("|"), true);
                for (const FString& Technical : Technicals)
                {
                    TArray<FString> KeyValue;
                    Technical.ParseIntoArray(KeyValue, TEXT(":"), true);
                    if (KeyValue.Num() == 2)
                    {
                        Info.TechnicalValues.Add(FGameplayTag::RequestGameplayTag(FName(*KeyValue[0])), FCString::Atof(*KeyValue[1]));
                    }
                }

                Info.RowName = FName(*Columns[11]);

                ItemInformation.Add(Info);
            }
        }
    }
}
