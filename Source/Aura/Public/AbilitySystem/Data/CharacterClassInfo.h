// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "Engine/DataAsset.h"
#include "CharacterClassInfo.generated.h"

UENUM(blueprintType)
enum class ECharacterClass : uint8
{
	Elementalist,
	Warrior,
	Ranger,
};

USTRUCT(blueprintType)
struct FCharacterDefaultClassInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category="Class Defaults")
	TSubclassOf<UGameplayEffect> PrimaryAttributes;
};

/**
 * 
 */
UCLASS()
class AURA_API UCharacterClassInfo : public UDataAsset
{
	GENERATED_BODY()
public:

	UPROPERTY(EditDefaultsOnly, Category="Common Class Defaults")
	TMap<ECharacterClass, FCharacterDefaultClassInfo> CharacterClassInformation;
	
	UPROPERTY(EditDefaultsOnly, Category="Common Class Defaults")
	TSubclassOf<UGameplayEffect> SecondaryAttributes;

	UPROPERTY(EditDefaultsOnly, Category="Common Class Defaults")
	TSubclassOf<UGameplayEffect> VitalAttributes;

	FCharacterDefaultClassInfo GetClassDefaultInfo(ECharacterClass CharacterClass);
};
