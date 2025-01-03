// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/AuraHUD.h"

#include "UI/WidgetController/OverlayWidgetController.h"
#include "Widgets/AuraUserWidget.h"


UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams) {
	// OverlayWidgetController가 초기화되지 않았는지 확인
	if (OverlayWidgetController == nullptr)
	{
		// 지정된 클래스를 사용하여 새로운 OverlayWidgetController 객체 생성
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		// 새로 생성된 위젯 컨트롤러에 매개변수 설정
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		// OverlayWidgetController의 종속성에 콜백 함수를 바인딩
		OverlayWidgetController->BindCallbacksToDependencies();

		// 생성 및 설정된 위젯 컨트롤러 반환
		return OverlayWidgetController;
	}
	// 이미 초기화된 경우 기존 위젯 컨트롤러 반환
	return OverlayWidgetController;
}

// 오버레이를 초기화하는 함수
void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	// OverlayWidgetClass가 초기화되었는지 확인, 초기화되지 않았다면 오류 메시지 출력
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class가 초기화되지 않았습니다, BP_AuraHUD를 설정해주세요"));
    
	// OverlayWidgetControllerClass가 초기화되었는지 확인, 초기화되지 않았다면 오류 메시지 출력
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, fill out BP_AuraHUD"));
    
	// OverlayWidgetClass를 기반으로 새로운 위젯 인스턴스 생성
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UAuraUserWidget>(Widget); // 생성된 위젯을 UAuraUserWidget으로 캐스팅

	// 위젯 컨트롤러 파라미터를 생성
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
    
	// 위젯 컨트롤러를 가져옴
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	// 오버레이 위젯에 위젯 컨트롤러 설정
	OverlayWidget->SetWidgetController(WidgetController);

	WidgetController->BroadcastInitialValues();
	
	// 위젯을 뷰포트에 추가하여 화면에 표시
	Widget->AddToViewport();
}


