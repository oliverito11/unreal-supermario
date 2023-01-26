// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeathZoneActor.generated.h"

UCLASS()
class SUPERMARIOBROS_API ADeathZoneActor : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent *DebugMesh;

	UPROPERTY(EditAnywhere)
	UDamageType *DamageType;
public:	
	// Sets default values for this actor's properties
	ADeathZoneActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
};
