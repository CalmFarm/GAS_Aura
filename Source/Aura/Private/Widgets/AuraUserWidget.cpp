// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/AuraUserWidget.h"

// 위젯 컨트롤러를 설정하고, 설정 완료 후 WidgetControllerSet 이벤트를 호출하는 함수입니다.
void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	// 전달받은 위젯 컨트롤러를 WidgetController 변수에 저장합니다.
	WidgetController = InWidgetController;
    
	// 위젯 컨트롤러가 설정되었음을 알리기 위해 WidgetControllerSet 이벤트를 호출합니다.
	WidgetControllerSet();
}

