#include "Abilities/Data/UhuAttributeInfo.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

FUhuAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
    for (const FUhuAttributeInfo& Info : AttributeInformation)
    {
        if (Info.AttributeTag.MatchesTagExact(AttributeTag))
        {
            return Info;
        }
    }
    if (bLogNotFound)
    {
        UE_LOG(LogTemp, Error, TEXT("Can't find Info for AttributeTag [%s] on AttributeInfo [%s]."), *AttributeTag.ToString(), *GetNameSafe(this));
    }
    return FUhuAttributeInfo();
}


// Developement only!!!
void UAttributeInfo::ExportAttributesToCSV(const FString& FilePath)
{
    FString CSVData;
    CSVData.Append(TEXT("AttributeTag,AttributeName,AttributeDescription,AttributeValue\n"));

    for (const FUhuAttributeInfo& Info : AttributeInformation)
    {
        CSVData.Append(FString::Printf(TEXT("%s,%s,%s,%f\n"),
            *Info.AttributeTag.ToString(),
            *Info.AttributeName.ToString(),
            *Info.AttributeDescription.ToString(),
            Info.AttributeValue));
    }

    FString FullPath = FPaths::ProjectDir() + FilePath;
    FFileHelper::SaveStringToFile(CSVData, *FullPath);
}

void UAttributeInfo::ImportAttributesFromCSV(const FString& FilePath)
{
    FString CSVData;
    FString FullPath = FPaths::ProjectDir() + FilePath;

    if (FFileHelper::LoadFileToString(CSVData, *FullPath))
    {
        TArray<FString> Rows;
        CSVData.ParseIntoArray(Rows, TEXT("\n"), true);

        AttributeInformation.Empty();

        for (int32 i = 1; i < Rows.Num(); ++i) // Start from 1 to skip header row
        {
            TArray<FString> Columns;
            Rows[i].ParseIntoArray(Columns, TEXT(","), true);

            if (Columns.Num() == 4)
            {
                FUhuAttributeInfo Info;
                Info.AttributeTag = FGameplayTag::RequestGameplayTag(FName(*Columns[0]));
                Info.AttributeName = FText::FromString(Columns[1]);
                Info.AttributeDescription = FText::FromString(Columns[2]);
                Info.AttributeValue = FCString::Atof(*Columns[3]);

                AttributeInformation.Add(Info);
            }
        }
    }
}
