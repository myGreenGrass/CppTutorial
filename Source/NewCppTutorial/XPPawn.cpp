// Fill out your copyright notice in the Description page of Project Settings.


#include "XPPawn.h"

// Sets default values
AXPPawn::AXPPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//setup component hirachy
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	RootComponent = PlayerMesh;
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(PlayerMesh);


}

// Called when the game starts or when spawned
void AXPPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AXPPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AXPPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// 
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AXPPawn::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AXPPawn::MoveLR);


}


void AXPPawn::MoveFB(float Value)
{
	auto Location = GetActorLocation();
	Location.X -= Value;
	SetActorLocation(Location);
}

void AXPPawn::MoveLR(float Value)
{
	auto Location = GetActorLocation();
	Location.Y += Value;
	SetActorLocation(Location);
}