// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorSwitch.h"

// Sets default values
AFloorSwitch::AFloorSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box Collision");
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly); // QueryOnly -> Good for overlap things
	BoxComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic); // Type of object
	BoxComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BoxComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	BoxComponent->SetBoxExtent(FVector(62.f, 62.f, 32.f));
	RootComponent = BoxComponent;
	
	FloorSwitch = CreateDefaultSubobject<UStaticMeshComponent>("Switch Mesh");
	FloorSwitch->SetupAttachment(GetRootComponent());
	
	Door = CreateDefaultSubobject<UStaticMeshComponent>("Door Mesh");
	Door->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AFloorSwitch::BeginPlay()
{
	Super::BeginPlay();
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AFloorSwitch::OnOverlapBegin);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &AFloorSwitch::OnOverlapEnd);
	
}

// Called every frame
void AFloorSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFloorSwitch::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Begin"));
}

void AFloorSwitch::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap End"));
}

