// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnBox.h"

// 构造函数
// 设置默认值
ASpawnBox::ASpawnBox()
{
 	// 设置这个Actor每帧调用Tick()。如果不需要，可以关闭它来提高性能。
	PrimaryActorTick.bCanEverTick = false;

	// 初始化成员
	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = SpawnBox;
}

// 当游戏结束或Actor被销毁时调用
void ASpawnBox::BeginPlay()
{
	Super::BeginPlay();

	// 如果允许生成，安排第一次生成
	if (ShouldSpawn)
	{
		ScheduleActorSpawn();
	}
}

// 当游戏结束或Actor被销毁时调用
void ASpawnBox::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// 消除与此对象实例相关的定时器
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

// 生成指定类的Actor
bool ASpawnBox::SpawnActor()
{
	bool SpawnedActor = false;
	if (ActorClassToBeSpawned)
	{
		//	计算盒子的边界
		FBoxSphereBounds BoxBounds = SpawnBox->CalcBounds(GetActorTransform());
		
		// 计算盒子边界内的随机位置
		FVector SpawnLocation = BoxBounds.Origin;
		SpawnLocation.X += -BoxBounds.BoxExtent.X + 2 * BoxBounds.BoxExtent.X * FMath::FRand();
		SpawnLocation.Y += -BoxBounds.BoxExtent.Y + 2 * BoxBounds.BoxExtent.Y * FMath::FRand();
		SpawnLocation.Z += -BoxBounds.BoxExtent.Z + 2 * BoxBounds.BoxExtent.Z * FMath::FRand();

		//	生成Actor
		SpawnedActor = GetWorld()->SpawnActor(ActorClassToBeSpawned, &SpawnLocation) != nullptr;
	}
	return SpawnedActor;
}

// 启用或禁用Actor生成
void ASpawnBox::EnableActorSpawning(bool Enable)
{
	// 更新内部状态
	ShouldSpawn = Enable;

	// 根据Enable的值安排或清除定时器
	if (Enable)
	{
		ScheduleActorSpawn();
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);

	}
}

//	安排Actor生成的调度
void ASpawnBox::ScheduleActorSpawn()
{
	// 计算生成的时间偏移
	float DeltaToNextSpawn = AvgSpawnTime + (-RandomSpawnTimeOffset + 2 * RandomSpawnTimeOffset * FMath::FRand());

	// 安排生成
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnBox::SpawnActorScheduled, DeltaToNextSpawn, false);
}

// 定时生成Actor的函数
void ASpawnBox::SpawnActorScheduled()
{
	// 生成并在需要时重新安排
	if (SpawnActor())
	{
		if (ShouldSpawn)
		{
			ScheduleActorSpawn();
		}
	}
	else {
		// TODO: 记录错误日志
	}
}