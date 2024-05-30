// ����Ŀ���õ�����ҳ������д��Ȩ������

#include "XPCharacter.h"

// ����Ĭ��ֵ
AXPCharacter::AXPCharacter()
{
	// ���ô˽�ɫÿ֡����Tick()���������Ҫ�����Թر���������ܡ�
	PrimaryActorTick.bCanEverTick = true;

	// �����������������������������
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetupAttachment(GetCapsuleComponent());

	// ������������������������������
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(GetCapsuleComponent());
}

// ��Ϸ��ʼ������ʱ����
void AXPCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// ÿ֡����һ��
void AXPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// �󶨹��ܵ�����
void AXPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// ע����ӳ��
	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AXPCharacter::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AXPCharacter::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AXPCharacter::Rotate);
}

// ��ǰ/����ƶ�
void AXPCharacter::MoveFB(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value * MoveSpeed);
}

// ����/�����ƶ�
void AXPCharacter::MoveLR(float Value)
{
	AddMovementInput(-GetActorRightVector(), Value * MoveSpeed);
}

// ��ת
void AXPCharacter::Rotate(float Value)
{
	AddControllerYawInput(Value * RotationSpeed);
}
