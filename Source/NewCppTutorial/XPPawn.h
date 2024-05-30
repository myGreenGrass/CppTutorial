// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "XPPawn.generated.h"

UCLASS()
class NEWCPPTUTORIAL_API AXPPawn : public APawn
{
	GENERATED_BODY()

public:
	// Mesh being dispayed
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* PlayerMesh;

	// Camera to view the scene
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* PlayerCamera;

public:
	// Sets default values for this pawn's properties
	AXPPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	void MoveFB(float Value);
	void MoveLR(float Value);
	void Rotate(float Value);

private:
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 1.f;

	UPROPERTY(EditAnywhere)
	float RotationSpeed = 1.f;
};
