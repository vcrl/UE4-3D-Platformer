// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Main_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMER_API UMain_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	public:

	virtual void NativeInitializeAnimation() override; // Similar to the constructor / Beginplay of an Actor
	
	UFUNCTION(BlueprintCallable, Category = "AnimationProperties")
	void UpdateAnimationProperties(); // Function that should be linked to "Event Blueprint Update Animation" in...
	// ...  Blueprints to be called every frames. (Equivalent to Tick function for Actors)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MovementSpeed; // Used to store the MovementSpeed from the velocity of Pawn->GetVelocity()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	bool bIsInAir; // If true = in the air, if false = on the ground

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	APawn* Pawn; // Pointer to APawn class
	
};
