// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraMyCharacterBase.h"


AAuraMyCharacterBase::AAuraMyCharacterBase()
{
	PrimaryActorTick.bCanEverTick =	false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}


void AAuraMyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

