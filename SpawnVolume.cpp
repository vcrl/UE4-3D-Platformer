// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnRegion = CreateDefaultSubobject<UBoxComponent>(TEXT("Spawning Region"));
	

}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetSpawnPoint()
{
	FVector BoxExtent = SpawnRegion->GetScaledBoxExtent(); // Returns extent of the box X Y Z
	FVector BoxOrigin = SpawnRegion->GetComponentLocation(); // Returns center of the box
	FVector Point = UKismetMathLibrary::RandomPointInBoundingBox(BoxOrigin, BoxExtent); // Returns a random point in the box
	return Point;
}

void ASpawnVolume::SpawnActor_Implementation(UClass* Actor, FVector Location)
{
	if (Actor)
	{
		UWorld* World = GetWorld();
		FActorSpawnParameters SpawnParams;
		if (World)
		{
			World->SpawnActor<AActor>(Actor, Location, FRotator(0.f), SpawnParams);
		}
	}
}



