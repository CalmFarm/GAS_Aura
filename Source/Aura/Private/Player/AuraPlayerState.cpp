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
	
	// 능력 시스템 컴포넌트의 복제 모드를 혼합 모드로 설정합니다.
	// Mixed 모드는 서버와 클라이언트 간의 상태를 부분적으로 동기화하여,
	// 필요한 경우에만 정보를 전송합니다.
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// AttributeSet을 UAuraAttributeSet 타입으로 기본 서브 오브젝트로 생성
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	
	// 네트워크 업데이트 주기를 설정 (초당 100회)
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
