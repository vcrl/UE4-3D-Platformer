// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Main.generated.h"

UCLASS()
class PLATFORMER_API AMain : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
    	USpringArmComponent* CameraBoom;
    	
    	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
    	UCameraComponent* FollowCamera;
    
    	UFUNCTION(BlueprintCallable, Category = "Movement Functions")
    	void MoveForward(float Value);
    
    	UFUNCTION(BlueprintCallable, Category = "Movement Functions")
    	void MoveRight(float Value);
    
    	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
    	float BaseTurnRate;
    
    	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
    	float BaseLookUpRate;

};
