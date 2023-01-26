// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseEnemyActor.generated.h"

class ASuperMarioBrosCharacter;
class UBoxComponent;
UCLASS()
class SUPERMARIOBROS_API ABaseEnemyActor : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent *EnemyMesh;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent *BoxComponent;
	
	UPROPERTY(EditDefaultsOnly)
	float MoveSpeed {300};

	UPROPERTY(EditAnywhere)
	float MoveDirection {-1};

	UPROPERTY(VisibleAnywhere)
	ASuperMarioBrosCharacter *PlayerPawn;
	
	UPROPERTY(EditDefaultsOnly)
	float ActivateDistance {10};

	UPROPERTY(EditAnywhere)
	float Score {500};

	UPROPERTY(EditDefaultsOnly)
	USoundBase *DeadSound;

public:	
	// Sets default values for this actor's properties
	ABaseEnemyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
