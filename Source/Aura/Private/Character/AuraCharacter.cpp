// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 400.f, 0);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// 서버를 위한 능력 액터 정보 초기화
	InitAbilityActorInfo();
	
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for teh Client
	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	// 플레이어 상태를 AAuraPlayerState로 가져옵니다.
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState); // 플레이어 상태가 유효한지 확인합니다.

	// 플레이어 상태의 Ability System Component를 초기화합니다.
	// 이 메서드는 해당 플레이어 상태와 현재 액터(캐릭터)를 연결하여,
	// 능력 시스템의 정보를 설정합니다.
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);

	// 현재 캐릭터의 Ability System Component를 저장합니다.
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();

	// 플레이어 상태의 Attribute Set을 가져와 저장합니다.
	AttributeSet = AuraPlayerState->GetAttributeSet();
}
