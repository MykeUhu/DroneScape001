// Copyright by MykeUhu

#include "Actor/Drone/Tasks/DroneTaskManager.h"

// Fügt eine neue Aufgabe zur Liste hinzu
void UDroneTaskManager::AddTask(FString TaskName, int32 Priority, float Duration)
{
	// Neue Aufgabe erstellen und Parameter setzen
	FDroneTask NewTask;
	NewTask.TaskName = TaskName;
	NewTask.Priority = Priority;
	NewTask.TaskDuration = Duration;
	NewTask.bIsActive = true;

	// Aufgabe zur Liste hinzufügen
	TaskList.Add(NewTask);
}

// Ändert die Priorität einer bestehenden Aufgabe
void UDroneTaskManager::ChangeTaskPriority(FString TaskName, int32 NewPriority)
{
	// Durch die Aufgabenliste iterieren, um die gesuchte Aufgabe zu finden
	for (auto& Task : TaskList)
	{
		if (Task.TaskName == TaskName)
		{
			// Priorität ändern, sobald Aufgabe gefunden wird
			Task.Priority = NewPriority;
			break;
		}
	}
}

// Aktualisiert die Aufgabenliste (z.B. verringert die TaskDuration)
void UDroneTaskManager::UpdateTaskList()
{
	// Aktualisiere die Aufgaben, z.B. TaskDuration oder Entfernen von inaktiven Tasks
	for (int32 i = TaskList.Num() - 1; i >= 0; --i)
	{
		FDroneTask& Task = TaskList[i];

		// Beispiel: Deaktiviere die Aufgabe, wenn die Dauer abgelaufen ist
		if (Task.TaskDuration > 0)
		{
			Task.TaskDuration -= 1.0f; // Timer verringern, z.B. pro Sekunde
		}
		else
		{
			Task.bIsActive = false; // Aufgabe als inaktiv setzen
		}

		// Entferne abgeschlossene oder inaktive Aufgaben
		if (!Task.bIsActive)
		{
			TaskList.RemoveAt(i);
		}
	}
}

// Gibt die aktuelle Aufgabenliste zurück
const TArray<FDroneTask>& UDroneTaskManager::GetTaskList() const
{
	return TaskList;
}
