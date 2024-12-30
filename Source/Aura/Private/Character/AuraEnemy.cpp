// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	// 적의 메쉬가 Visibility 채널에 대해 충돌 응답을 블록으로 설정
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	// AbilitySystemComponent를 UAuraAbilitySystemComponent 타입으로 기본 서브 오브젝트로 생성
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	// AbilitySystemComponent의 복제 여부를 설정 (네트워크에서 복제 가능)
	AbilitySystemComponent->SetIsReplicated(true);

	// AttributeSet을 UAuraAttributeSet 타입으로 기본 서브 오브젝트로 생성
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

}

void AAuraEnemy::HighlightActor()
{
	// 적의 메쉬에 커스텀 깊이 렌더링 활성화
	GetMesh()->SetRenderCustomDepth(true);
	// 커스텀 깊이 스텐실 값을 빨간색으로 설정
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	// 무기에 대한 커스텀 깊이 렌더링 활성화
	Weapon->SetRenderCustomDepth(true);
	// 무기의 커스텀 깊이 스텐실 값을 빨간색으로 설정
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnHighlightActor()
{
	// 적의 메쉬에 대한 커스텀 깊이 렌더링 비활성화
	GetMesh()->SetRenderCustomDepth(false);
    
	// 무기에 대한 커스텀 깊이 렌더링 비활성화
	Weapon->SetRenderCustomDepth(false);
}
