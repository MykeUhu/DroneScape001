// Copyright by MykeUhu

#pragma once

#include "CoreMinimal.h"
#include "DroneTaskManager.generated.h"

// Struktur, die eine Aufgabe beschreibt
USTRUCT(BlueprintType)
struct FDroneTask
{
	GENERATED_BODY()

	// Name der Aufgabe
	UPROPERTY(BlueprintReadWrite, Category="Task")
	FString TaskName;

	// Priorität der Aufgabe (höhere Priorität wird zuerst ausgeführt)
	UPROPERTY(BlueprintReadWrite, Category="Task")
	int32 Priority = 0;

	// Status, ob die Aufgabe aktiv ist
	UPROPERTY(BlueprintReadWrite, Category="Task")
	bool bIsActive = false;

	// Dauer der Aufgabe (wird heruntergezählt)
	UPROPERTY(BlueprintReadWrite, Category="Task")
	float TaskDuration = 0.0f;
};

// Klasse für das Task-Management
UCLASS(Blueprintable)
class DRONESCAPE_API UDroneTaskManager : public UObject
{
	GENERATED_BODY()

public:
	// Aufgabe zur Liste hinzufügen
	UFUNCTION(BlueprintCallable, Category="Tasks")
	void AddTask(FString TaskName, int32 Priority, float Duration);

	// Ändere die Priorität einer bestehenden Aufgabe
	UFUNCTION(BlueprintCallable, Category="Tasks")
	void ChangeTaskPriority(FString TaskName, int32 NewPriority);

	// Aktualisiere die Aufgabenliste (z.B. verringere TaskDuration)
	UFUNCTION(BlueprintCallable, Category="Tasks")
	void UpdateTaskList();

	// Gibt die aktuelle Aufgabenliste zurück
	UFUNCTION(BlueprintCallable, Category="Tasks")
	const TArray<FDroneTask>& GetTaskList() const;

private:
	// Liste der aktuellen Aufgaben
	UPROPERTY(BlueprintReadOnly, Category="Tasks", meta = (AllowPrivateAccess = "true"))
	TArray<FDroneTask> TaskList;
};
