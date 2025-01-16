// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UAuraAbilitySystemComponent;
class UAuraConfigInput;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IEnemyInterface;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	UPROPERTY(EditAnywhere, category = "Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();

	// IEnemyInterface를 구현한 액터에 대한 스크립트 인터페이스 변수 선언
	TScriptInterface<IEnemyInterface> LastActor; // 이전에 선택된 적 액터
	TScriptInterface<IEnemyInterface> ThisActor; // 현재 커서 아래의 적 액터

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	
	UPROPERTY(EditDefaultsOnly, category = "Input")
	TObjectPtr<UAuraConfigInput> ConfigInput;

	UPROPERTY()
	TObjectPtr<UAuraAbilitySystemComponent> AuraAbilitySystemComponent;

	UAuraAbilitySystemComponent* GetASC();
};

