// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DestructibleBlockActor.h"
#include "CoinBlockActor.generated.h"

/**
 * 
 */
UCLASS()
class SUPERMARIOBROS_API ACoinBlockActor : public ADestructibleBlockActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	UMaterial *Material;
protected:
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
	virtual void FinishHit() override;
};
