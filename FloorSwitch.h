// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "FloorSwitch.generated.h"

UCLASS()
class PLATFORMER_API AFloorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorSwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Floor Switch")
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Floor Switch")
	UStaticMeshComponent* FloorSwitch;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Floor Switch")
	UStaticMeshComponent* Door;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floor Switch")
	FVector InitialDoorLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floor Switch")
	FVector InitialSwitchLocation;

	UFUNCTION(BlueprintCallable, Category = "Events")
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Events")
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintImplementableEvent, Category = "Door Events")
	void RaiseDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = "Door Events")
	void LowerDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = "Door Events")
	void RaiseSwitch();

	UFUNCTION(BlueprintImplementableEvent, Category = "Door Events")
	void LowerSwitch();

	UFUNCTION(BlueprintCallable, Category = "Door Events")
	void UpdateDoorLocation(float MovementOffset);

};