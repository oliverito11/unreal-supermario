// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathZoneActor.h"

#include "SuperMarioBrosCharacter.h"
#include "Engine/DamageEvents.h"

// Sets default values
ADeathZoneActor::ADeathZoneActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DebugMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Debug mesh"));
	SetRootComponent(DebugMesh);
}

// Called when the game starts or when spawned
void ADeathZoneActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADeathZoneActor::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if(ASuperMarioBrosCharacter *Character = Cast<ASuperMarioBrosCharacter>(Other))
	{
		Character->Dead();
	}
	Other->Destroy();
}
