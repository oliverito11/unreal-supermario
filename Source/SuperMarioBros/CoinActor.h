// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoinActor.generated.h"

class UBoxComponent;
UCLASS()
class SUPERMARIOBROS_API ACoinActor : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent *CoinMesh;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent *BoxComponent;

	UPROPERTY(EditAnywhere)
	float Score {200};

	UPROPERTY(EditAnywhere)
	float RotationSpeed {60};

	UPROPERTY(EditDefaultsOnly)
	USoundBase *CoinSound;
public:	
	// Sets default values for this actor's properties
	ACoinActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
