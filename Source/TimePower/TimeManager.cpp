// 在项目设置的描述页面中填写版权声明。

#include "TimeManager.h"
#include "MathUtil.h"

// 设置默认值
ATimeManager::ATimeManager()
{
	// 设置该Actor每帧调用Tick()。如果不需要，可以将其关闭以提高性能。
	PrimaryActorTick.bCanEverTick = true;
}

// 在游戏开始或生成时调用
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
}

// 每帧调用
void ATimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 如果启用了时间倒流功能
	if (TimeReversalEnable)
	{
		// 更新记录的当前时间，确保不超过最大时间
		CurrentRecordedTime = FMath::Min(ReverseTimeMaximum, CurrentRecordedTime + DeltaTime * CurrentTimeFactor);
		if (CurrentRecordedTime <= 0.0f)
		{
			EndTimeReverse();
		}
	}
}

// 获取当前时间因子
float ATimeManager::GetTimeFactor()
{
	return CurrentTimeFactor;
}

// 获取当前记录的时间
float ATimeManager::GetCurrentRecordedTime()
{
	return CurrentRecordedTime;
}

// 开始时间倒流
void ATimeManager::BeginTimeReverse()
{
	if (TimeReversalEnable && CurrentRecordedTime >= ReverseTimeThreshold)
	{
		CurrentTimeFactor = ReverseTimeFactor;
	}
}

// 结束时间倒流
void ATimeManager::EndTimeReverse()
{
	CurrentTimeFactor = NormalTimeFactor;
}

// 启用或禁用时间倒流功能
void ATimeManager::EnableTimeReversal(bool Enable)
{
	TimeReversalEnable = Enable;
	if (Enable)
	{
		BeginTimeReverse();
	}
	else
	{
		EndTimeReverse();
		CurrentRecordedTime = 0.0f;
	}
}
