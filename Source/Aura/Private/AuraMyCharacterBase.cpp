// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraMyCharacterBase.h"

// Sets default values
AAuraMyCharacterBase::AAuraMyCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAuraMyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAuraMyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAuraMyCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

