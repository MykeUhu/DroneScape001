// Copyright by MykeUhu


#include "Characters/UhuNPCCharacter.h"

// Sets default values
AUhuNPCCharacter::AUhuNPCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUhuNPCCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AUhuNPCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUhuNPCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

