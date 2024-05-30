// 填写版权声明到项目设置的描述页面。

#include "XPPawn.h"

// 设置默认值
AXPPawn::AXPPawn()
{
	// 设置这个Pawn每帧调用Tick()。如果不需要，可以关闭以提高性能。
	PrimaryActorTick.bCanEverTick = true;

	// 设置默认速度
	this->MoveSpeed = 5.f;
	this->RotationSpeed = 2.f;

	// 设置默认位置
	//SetActorLocation(FVector(0.0f, 0.0f, 160.0f));

	// 设置组件层级
	PlayerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	RootComponent = PlayerMesh; // 将PlayerMesh设置为根组件
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	PlayerCamera->SetupAttachment(PlayerMesh); // 将摄像机附加到PlayerMesh
}

// 游戏开始或生成时调用
void AXPPawn::BeginPlay()
{
	Super::BeginPlay();
}

// 每帧调用一次
void AXPPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// 绑定功能到输入
void AXPPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 绑定轴映射到对应的输入函数
	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AXPPawn::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AXPPawn::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AXPPawn::Rotate);
}

// 向前/向后移动
void AXPPawn::MoveFB(float Value)
{
	auto Location = GetActorLocation(); // 获取当前Actor位置
	Location += GetActorForwardVector() * Value * MoveSpeed; // 根据输入值和移动速度计算新位置
	SetActorLocation(Location); // 设置新位置
}

// 向左/向右移动
void AXPPawn::MoveLR(float Value)
{
	auto Location = GetActorLocation(); // 获取当前Actor位置
	Location += GetActorRightVector() * Value * MoveSpeed; // 根据输入值和移动速度计算新位置
	SetActorLocation(Location); // 设置新位置
}

// 旋转
void AXPPawn::Rotate(float Value)
{
	auto Rotation = GetActorRotation(); // 获取当前Actor旋转角度
	Rotation.Yaw += Value * RotationSpeed; // 根据输入值和旋转速度计算新角度
	SetActorRotation(Rotation); // 设置新角度
}
