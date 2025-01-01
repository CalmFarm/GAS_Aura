// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// 위젯 컨트롤러를 설정하는 함수로, 블루프린트에서 호출할 수 있습니다.
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	// 위젯 컨트롤러를 저장하는 프로퍼티로, 블루프린트에서 읽기 전용입니다.
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	// 위젯 컨트롤러가 설정되었을 때 호출되는 이벤트로, 블루프린트에서 구현할 수 있습니다.
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();

	
};
