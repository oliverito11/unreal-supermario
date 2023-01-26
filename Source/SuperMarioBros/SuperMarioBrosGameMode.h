// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SuperMarioBrosGameMode.generated.h"

UCLASS(minimalapi)
class ASuperMarioBrosGameMode : public AGameModeBase
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere)
	float Score {0};
public:
	ASuperMarioBrosGameMode();

	void AddScore(float ScoreVal);

	UFUNCTION(BlueprintCallable)
	float GetScore() const { return this->Score; }
};