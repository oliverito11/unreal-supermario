// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinBlockActor.h"

#include "SuperMarioBrosCharacter.h"
#include "Kismet/GameplayStatics.h"

void ACoinBlockActor::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
                                bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
}

void ACoinBlockActor::FinishHit()
{
	BlockMesh->SetMaterial(0, Material);
}
