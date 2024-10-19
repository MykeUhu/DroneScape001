// Copyright by MykeUhu


#include "Characters/UhuDroneCharacter.h"

// Sets default values
AUhuDroneCharacter::AUhuDroneCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUhuDroneCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUhuDroneCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUhuDroneCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

