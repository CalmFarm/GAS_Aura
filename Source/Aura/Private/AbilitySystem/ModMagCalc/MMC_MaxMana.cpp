// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMagCalc/MMC_MaxMana.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	IntelligenceDef.AttributeToCapture = UAuraAttributeSet::GetIntelligenceAttribute();
	IntelligenceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	IntelligenceDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(IntelligenceDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	//Gather tags from source and targets
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParameters; // 속성 평가에 필요한 매개변수 구조체 생성
	EvaluateParameters.SourceTags = SourceTags; // 소스 태그 설정 (능력의 출처)
	EvaluateParameters.TargetTags = TargetTags; // 타겟 태그 설정 (능력이 적용될 대상)

	// Vigor 속성의 초기값을 0으로 설정
	float Int = 0.f;
	// VigorDef 속성 값을 Spec에서 가져와 Vigor 변수에 저장
	GetCapturedAttributeMagnitude(IntelligenceDef, Spec, EvaluateParameters, Int);
	// Int 값이 0보다 작으면 0으로 설정 (음수 방지)
	Int = FMath::Max<float>(Int, 0.0f);

	// CombatInterface를 통해 플레이어의 레벨을 가져오기 위한 캐스팅
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	// 플레이어 레벨 가져오기
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();
	
	return 50.f + 2.5f * Int + 15.f * PlayerLevel;
}
