// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructibleBlockActor.h"

#include "SuperMarioBrosCharacter.h"
#include "SuperMarioBrosGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADestructibleBlockActor::ADestructibleBlockActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Block mesh"));
	SetRootComponent(BlockMesh);
}

// Called when the game starts or when spawned
void ADestructibleBlockActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADestructibleBlockActor::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if(HitsToBreak <= 0) return;
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if(!Cast<ASuperMarioBrosCharacter>(Other)) return;
	UE_LOG(LogTemp, Warning, TEXT("Hit Normal: %s"), *HitNormal.ToString());
	if(HitNormal.Z != 1) return;
	ASuperMarioBrosGameMode *GameMode = Cast<ASuperMarioBrosGameMode>(UGameplayStatics::GetGameMode(this));
	if(!GameMode) return;
	
	HitsToBreak--;
	GameMode->AddScore(BlockScore);

	UGameplayStatics::PlaySoundAtLocation(this, BreakSound, GetActorLocation(), GetActorRotation());
	if(HitsToBreak <= 0)
	{
		FinishHit();
	}
}

void ADestructibleBlockActor::FinishHit()
{
	Destroy();
}

// Called every frame
void ADestructibleBlockActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

