// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemy.h"

#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	// 적의 메쉬가 Visibility 채널에 대해 충돌 응답을 블록으로 설정
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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
