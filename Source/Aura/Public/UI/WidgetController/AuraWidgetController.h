// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AuraWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class APlayerState;

// 위젯 컨트롤러의 파라미터를 저장하는 구조체
USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

	// 기본 생성자
	FWidgetControllerParams() {}

	// 파라미터를 받아서 초기화하는 생성자
	FWidgetControllerParams(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
		: PlayerController(PC), PlayerState(PS), AbilitySystemComponent(ASC), AttributeSet(AS) {}

	// 플레이어 컨트롤러 포인터 (게임의 플레이어를 제어하는 객체)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController = nullptr;

	// 플레이어 상태 포인터 (플레이어의 상태 정보를 담고 있는 객체)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState = nullptr;

	// 능력 시스템 컴포넌트 포인터 (능력 시스템 관련 기능을 제공하는 컴포넌트)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

	// 속성 세트 포인터 (플레이어의 속성 정보를 담고 있는 객체)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};


/**
 * 
 */


UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams& WCParams);
	
protected:

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<APlayerState> PlayerState;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category="WidgetController")
	TObjectPtr<UAttributeSet> AttributeSet;
};
