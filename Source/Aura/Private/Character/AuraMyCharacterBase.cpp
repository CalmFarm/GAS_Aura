// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraMyCharacterBase.h"


AAuraMyCharacterBase::AAuraMyCharacterBase()
{
	PrimaryActorTick.bCanEverTick =	false;

	// 무기(Weapon) 컴포넌트를 SkeletalMeshComponent 타입으로 기본 서브 오브젝트로 생성
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	// 무기를 캐릭터의 메시에 부착하고, "WeaponHandSocket" 소켓을 사용하여 위치 설정
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	// 무기의 충돌을 비활성화
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	
}

UAbilitySystemComponent* AAuraMyCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AAuraMyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

