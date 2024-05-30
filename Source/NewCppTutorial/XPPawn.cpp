// ��д��Ȩ��������Ŀ���õ�����ҳ�档

#include "XPPawn.h"

// ����Ĭ��ֵ
AXPPawn::AXPPawn()
{
	// �������Pawnÿ֡����Tick()���������Ҫ�����Թر���������ܡ�
	PrimaryActorTick.bCanEverTick = true;

	// ����Ĭ���ٶ�
	this->MoveSpeed = 5.f;
	this->RotationSpeed = 2.f;

	// ����Ĭ��λ��
	//SetActorLocation(FVector(0.0f, 0.0f, 160.0f));

	// ��������㼶
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	RootComponent = PlayerMesh; // ��PlayerMesh����Ϊ�����
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(PlayerMesh); // ����������ӵ�PlayerMesh
}

// ��Ϸ��ʼ������ʱ����
void AXPPawn::BeginPlay()
{
	Super::BeginPlay();
}

// ÿ֡����һ��
void AXPPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// �󶨹��ܵ�����
void AXPPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// ����ӳ�䵽��Ӧ�����뺯��
	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AXPPawn::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AXPPawn::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AXPPawn::Rotate);
}

// ��ǰ/����ƶ�
void AXPPawn::MoveFB(float Value)
{
	auto Location = GetActorLocation(); // ��ȡ��ǰActorλ��
	Location += GetActorForwardVector() * Value * MoveSpeed; // ��������ֵ���ƶ��ٶȼ�����λ��
	SetActorLocation(Location); // ������λ��
}

// ����/�����ƶ�
void AXPPawn::MoveLR(float Value)
{
	auto Location = GetActorLocation(); // ��ȡ��ǰActorλ��
	Location += GetActorRightVector() * Value * MoveSpeed; // ��������ֵ���ƶ��ٶȼ�����λ��
	SetActorLocation(Location); // ������λ��
}

// ��ת
void AXPPawn::Rotate(float Value)
{
	auto Rotation = GetActorRotation(); // ��ȡ��ǰActor��ת�Ƕ�
	Rotation.Yaw += Value * RotationSpeed; // ��������ֵ����ת�ٶȼ����½Ƕ�
	SetActorRotation(Rotation); // �����½Ƕ�
}
