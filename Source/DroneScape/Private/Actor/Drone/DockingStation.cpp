#include "Actor/Drone/DockingStation.h"

// Konstruktor
ADockingStation::ADockingStation()
{
	// Erstelle eine neue SceneComponent als Root-Komponente
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	// Erstelle das Mesh für die Docking-Station
	DockingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DockingMesh"));
	DockingMesh->SetupAttachment(RootComponent);
}

// BeginPlay wird aufgerufen, wenn das Spiel startet oder der Actor aktiviert wird
void ADockingStation::BeginPlay()
{
	Super::BeginPlay();
}

// Tick wird einmal pro Frame aufgerufen
void ADockingStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Funktion, um die Drohne zu pingen und ihre Position zurückzugeben
FVector ADockingStation::PingDrone()
{
	// Hier könnte man logische Überprüfungen einfügen
	return GetCurrentLocation(); // Gibt die aktuelle Position der Docking-Station zurück
}

// Gibt die aktuelle Position der Docking-Station zurück
FVector ADockingStation::GetCurrentLocation() const
{
	return GetActorLocation(); // Gibt den aktuellen Standort der Docking-Station zurück
}
