// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



#include "RandomNPC.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class PLATFORMER_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Spawning")
	UBoxComponent* SpawnRegion;

	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetSpawnPoint();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Spawning") // EditAnywhere !!
	TSubclassOf<ARandomNPC> ActorToSpawn; // Allows to get an actor of subclass RandomNPC
    
};
