// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::CursorTrace()
{
	// 충돌 결과를 저장할 FHitResult 변수 선언
	FHitResult CursorHit;
	// 현재 마우스 커서 아래의 충돌 정보를 가져옴
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	// 커서 아래에 유효한 충돌이 없으면 함수 종료
	if (!CursorHit.bBlockingHit) return;

	// 이전에 선택된 액터를 LastActor에 저장
	LastActor = ThisActor;
	// 현재 커서 아래의 액터를 ThisActor에 저장
	ThisActor = CursorHit.GetActor();

	// LastActor가 nullptr인지 확인
	if (LastActor == nullptr)
	{
		// ThisActor가 nullptr이 아닐 경우
		if (ThisActor != nullptr)
		{
			// 현재 액터를 하이라이트
			ThisActor->HighlightActor();
		}
		else
		{
			// ThisActor가 nullptr일 경우 (아무 동작 없음)
		}
	}
	else
	{
		// LastActor가 nullptr이 아닐 경우
		if (ThisActor == nullptr)
		{
			// 현재 액터가 없으면 LastActor의 하이라이트 해제
			LastActor->UnHighlightActor();
		}
		else
		{
			// LastActor와 ThisActor가 다를 경우
			if (LastActor != ThisActor)
			{
				// 이전 액터의 하이라이트 해제 및 현재 액터 하이라이트
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// LastActor와 ThisActor가 같을 경우 (아무 동작 없음)
			}
		}
	}

}


void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(AuraContext, 0);
	}
	

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
	
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.0f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
