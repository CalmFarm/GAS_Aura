// Fill out your copyright notice in the Description page of Project Settings.


#include "Input/AuraConfigInput.h"

const UInputAction* UAuraConfigInput::FindAbilityInputActionForTag(const FGameplayTag& InputTag,
	bool bLogNotFound) const
{
	for (const FAuraInputAction& Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("() not found"));
	}
	return nullptr;
}
