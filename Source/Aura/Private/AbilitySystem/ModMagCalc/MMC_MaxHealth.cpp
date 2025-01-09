// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/ModMagCalc/MMC_MaxHealth.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	VigorDef.AttributeToCapture = UAuraAttributeSet::GetVigorAttribute();
	VigorDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	VigorDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(VigorDef);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	//Gather tags from source and targets
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParameters; // 속성 평가에 필요한 매개변수 구조체 생성
	EvaluateParameters.SourceTags = SourceTags; // 소스 태그 설정 (능력의 출처)
	EvaluateParameters.TargetTags = TargetTags; // 타겟 태그 설정 (능력이 적용될 대상)

	// Vigor 속성의 초기값을 0으로 설정
	float Vigor = 0.f;
	// VigorDef 속성 값을 Spec에서 가져와 Vigor 변수에 저장
	GetCapturedAttributeMagnitude(VigorDef, Spec, EvaluateParameters, Vigor);
	// Vigor 값이 0보다 작으면 0으로 설정 (음수 방지)
	Vigor = FMath::Max<float>(Vigor, 0.0f);

	// CombatInterface를 통해 플레이어의 레벨을 가져오기 위한 캐스팅
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	// 플레이어 레벨 가져오기
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	// 최종 결과 계산: 기본값 80 + Vigor에 비례하는 값 + 플레이어 레벨에 비례하는 값 반환
	return 80.f + 2.5f * Vigor + 10.f * PlayerLevel;

}
