// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraPlayerState();
	
	// 능력 시스템 컴포넌트를 반환하는 가상 메서드
	// IAbilitySystemInterface에서 정의된 메서드를 재정의합니다.
	// 이 메서드는 PlayerState에서 능력 시스템 컴포넌트에 접근할 수 있도록 합니다.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	// 속성 집합을 반환하는 메서드
	// AttributeSet 포인터를 반환하여 외부에서 접근할 수 있도록 하며,
	// PlayerState에서 캐릭터의 속성 집합에 접근하는 데 사용됩니다.
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	
protected:
	// 능력 시스템 컴포넌트를 저장하는 포인터
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	// 속성 집합을 저장하는 포인터
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
	
};
