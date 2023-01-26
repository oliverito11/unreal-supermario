// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestructibleBlockActor.generated.h"

UCLASS()
class SUPERMARIOBROS_API ADestructibleBlockActor : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent *BlockMesh;

	UPROPERTY(EditAnywhere)
	int HitsToBreak {1};

	UPROPERTY(EditAnywhere)
	float BlockScore {100};

	UPROPERTY(EditDefaultsOnly)
	USoundBase *BreakSound;
public:	
	// Sets default values for this actor's properties
	ADestructibleBlockActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
	virtual void FinishHit();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
