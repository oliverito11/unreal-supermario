// Copyright Epic Games, Inc. All Rights Reserved.

#include "SuperMarioBrosGameMode.h"
#include "SuperMarioBrosCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASuperMarioBrosGameMode::ASuperMarioBrosGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ASuperMarioBrosGameMode::AddScore(float ScoreVal)
{
	this->Score += ScoreVal;
}
