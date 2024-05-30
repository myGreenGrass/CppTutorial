// 在项目设置的描述页面中填写版权声明。

#include "XPCharacter.h"

// 设置默认值
AXPCharacter::AXPCharacter()
{
	// 设置此角色每帧调用Tick()。如果不需要，可以关闭以提高性能。
	PrimaryActorTick.bCanEverTick = true;

	// 创建并附加玩家网格组件到胶囊组件
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetupAttachment(GetCapsuleComponent());

	// 创建并附加玩家摄像机组件到胶囊组件
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(GetCapsuleComponent());
}

// 游戏开始或生成时调用
void AXPCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// 每帧调用一次
void AXPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// 绑定功能到输入
void AXPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 注册轴映射
	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AXPCharacter::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AXPCharacter::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AXPCharacter::Rotate);
}

// 向前/向后移动
void AXPCharacter::MoveFB(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value * MoveSpeed);
}

// 向左/向右移动
void AXPCharacter::MoveLR(float Value)
{
	AddMovementInput(-GetActorRightVector(), Value * MoveSpeed);
}

// 旋转
void AXPCharacter::Rotate(float Value)
{
	AddControllerYawInput(Value * RotationSpeed);
}
