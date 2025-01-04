// Fill out your copyright notice in the Description page of Project Settings.


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")));
	
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* Target, const TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	// 대상의 Ability System Component를 가져옵니다.
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (TargetASC == nullptr) return;

	check(GameplayEffectClass);
	// 효과 컨텍스트 핸들을 생성합니다.
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	// 이 효과의 소스 오브젝트를 설정합니다.
	EffectContextHandle.AddSourceObject(this);
	// 효과 사양 핸들을 생성합니다. (지속 시간: 1초)
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
	// 생성된 효과 사양을 대상에게 적용합니다.
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}



