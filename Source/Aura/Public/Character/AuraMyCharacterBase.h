// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraMyCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AAuraMyCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraMyCharacterBase();

protected:
	virtual void BeginPlay() override;
	
};
