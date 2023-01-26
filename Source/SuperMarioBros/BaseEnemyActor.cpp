// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemyActor.h"

#include "SuperMarioBrosCharacter.h"
#include "SuperMarioBrosGameMode.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseEnemyActor::ABaseEnemyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision trigger"));
	SetRootComponent(BoxComponent);
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ABaseEnemyActor::OnOverlapBegin);
	
	EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Enemy mesh"));
	EnemyMesh->SetupAttachment(BoxComponent);
}

// Called when the game starts or when spawned
void ABaseEnemyActor::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = Cast<ASuperMarioBrosCharacter>(UGameplayStatics::GetPlayerController(this, 0)->GetPawn());
}

void ABaseEnemyActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *SweepResult.Normal.ToString());

	MoveDirection *= -1;
	if(PlayerPawn == Cast<ASuperMarioBrosCharacter>(OtherActor))
	{
		if(SweepResult.Normal.Z <= -.5f)
		{
			PlayerPawn->LaunchCharacter(PlayerPawn->GetActorUpVector() * 1500, false, false);
			UGameplayStatics::PlaySoundAtLocation(this, DeadSound, GetActorLocation(), GetActorRotation());
			Destroy();
			ASuperMarioBrosGameMode *GameMode = Cast<ASuperMarioBrosGameMode>(UGameplayStatics::GetGameMode(this));
			if(!GameMode) return;
			GameMode->AddScore(Score);
			return;
		}
		PlayerPawn->Dead();
	}
}

// Called every frame
void ABaseEnemyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!PlayerPawn) return;

	if(FVector::Distance(PlayerPawn->GetActorLocation(), GetActorLocation()) <= ActivateDistance)
	{
		AddActorWorldOffset(GetActorRightVector() * MoveDirection * MoveSpeed * DeltaTime);
	}
}

