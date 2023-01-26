// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinActor.h"

#include "SuperMarioBrosCharacter.h"
#include "SuperMarioBrosGameMode.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACoinActor::ACoinActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin mesh"));
	SetRootComponent(CoinMesh);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision box"));
	BoxComponent->SetupAttachment(CoinMesh);
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoinActor::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ACoinActor::BeginPlay()
{
	Super::BeginPlay();
	
}
void ACoinActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OVERLAP"));
	if(!Cast<ASuperMarioBrosCharacter>(OtherActor)) return;

	ASuperMarioBrosGameMode *GameMode = Cast<ASuperMarioBrosGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if(!GameMode) return;

	UGameplayStatics::PlaySoundAtLocation(this, CoinSound, GetActorLocation(), GetActorRotation());
	GameMode->AddScore(Score);
	Destroy();
}

// Called every frame
void ACoinActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator{0,RotationSpeed * UGameplayStatics::GetWorldDeltaSeconds(this),0}, true);
}

