// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"

AAuraPlayerState::AAuraPlayerState()
{
	// 네트워크 업데이트 주기를 설정 (초당 100회)
	NetUpdateFrequency = 100.f;
}
