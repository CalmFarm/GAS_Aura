// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraMyCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "Aura/Aura.h"
#include "Components/CapsuleComponent.h"


AAuraMyCharacterBase::AAuraMyCharacterBase()
{
	PrimaryActorTick.bCanEverTick =	false;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Projectile, ECR_Overlap);
	GetMesh()->SetGenerateOverlapEvents(true);
	
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

FVector AAuraMyCharacterBase::GetCombatSocketLocation()
{
	check(Weapon);
	return Weapon->GetSocketLocation(WeaponTipSocketName);
}

void AAuraMyCharacterBase::InitAbilityActorInfo()
{
}

void AAuraMyCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AAuraMyCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttribute, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttribute, 1.f);
	ApplyEffectToSelf(DefaultVitalAttribute, 1.f);
}

void AAuraMyCharacterBase::AddCharacterAbilities()
{
	UAuraAbilitySystemComponent* AuraASC = CastChecked<UAuraAbilitySystemComponent>(AbilitySystemComponent);
	if (!HasAuthority()) return;

	AuraASC->AddCharacterAbilities(StartupAbilities);
}

