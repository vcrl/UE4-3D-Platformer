// Fill out your copyright notice in the Description page of Project Settings.


#include "Main.h"

// Sets default values
AMain::AMain()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("Spring Arm Component");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->bUsePawnControlRotation = true; // Rotate arm based on controller
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>("Follow Camera");
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false; // Let the boom adjust to match the controller orientation

	BaseTurnRate = 65.f;
	BaseLookUpRate = 65.f;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//GetCharacterMovement()->bOrientRotationToMovement = true; //To edit in the BP
	//GetCharacterMovement()->bUseControllerDesiredRotation = true; //To edit in the BP
}

// Called when the game starts or when spawned
void AMain::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (PlayerInputComponent != nullptr)
	{
		PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
		PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	
		PlayerInputComponent->BindAxis("MoveForward", this, &AMain::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &AMain::MoveRight);

		PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
		PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("Nullptr playerinput"));
	}
}

void AMain::MoveForward(float Value)
{
	if (Controller != nullptr && Value != 0)
	{
		const FRotator ControllerRotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, ControllerRotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMain::MoveRight(float Value)
{
	{
		if (Controller != nullptr && Value != 0)
		{
			const FRotator ControllerRotation = Controller->GetControlRotation();
			const FRotator PitchRotation(0.f, ControllerRotation.Yaw, 0.f);

			const FVector Direction = FRotationMatrix(PitchRotation).GetUnitAxis(EAxis::Y);
			AddMovementInput(Direction, Value);
		}
	}
}

/*
void AMain::LookUpAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMain::TurnAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}
*/
