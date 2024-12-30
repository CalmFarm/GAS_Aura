// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	// AbilitySystemComponent를 UAuraAbilitySystemComponent 타입으로 기본 서브 오브젝트로 생성
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	// AbilitySystemComponent의 복제 여부를 설정 (네트워크에서 복제 가능)
	AbilitySystemComponent->SetIsReplicated(true);

	// AttributeSet을 UAuraAttributeSet 타입으로 기본 서브 오브젝트로 생성
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	
	// 네트워크 업데이트 주기를 설정 (초당 100회)
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
