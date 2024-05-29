// 包含 MoveComponent 类的头文件。
#include "MoveComponent.h"

// 设置此组件属性的默认值
UMoveComponent::UMoveComponent()
{
	//	设置该组件在游戏开始时初始化，并在每一帧被调用。你可以关闭这些功能以提高性能，如果你不需要它们的话。
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

//	EnableMovement 函数，用于启用或禁用移动：
void UMoveComponent::EnableMovement(bool ShouldMove)
{
	//	MoveEnable 赋值为 ShouldMove。
	MoveEnable = ShouldMove;
	//	SetComponentTickEnabled(MoveEnable); 根据 MoveEnable 设置组件的tick启用状态。
	SetComponentTickEnabled(MoveEnable);
}

// 清除距离并重置到初始位置
void UMoveComponent::ResetMovement()
{
	CurDistance = 0.0f;		//	重置为 0.0f。
	SetRelativeLocation(StartRelativeLocation);			// 重置组件到初始相对位置。
}

// SetMoveDirection 函数，用于设置移动方向：
void UMoveComponent::SetMoveDirection(int Direction)
{
	MoveDirection = Direction >= 1 ? 1 : -1;
}

//	在游戏开始时调用
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	//	设置起始位置
	StartRelativeLocation = GetRelativeLocation();	//设置初始相对位置。

	// 计算归一化移动偏移量
	MoveOffsetNorm = MoveOffset;	// 赋值移动偏移量。
	MoveOffsetNorm.Normalize();		// 归一化移动偏移量。
	MaxDistance = MoveOffset.Length();	// 计算最大距离。

	// 检查是否需要tick
	SetComponentTickEnabled(MoveEnable);	//根据 MoveEnable 设置组件的tick启用状态。
}


// 每帧调用
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);		// TickComponent 函数，每帧调用：

	// 设置当前距离
	if (MoveEnable)			// 如果 MoveEnable 为真：
	{
		CurDistance += DeltaTime * Speed * MoveDirection;		// CurDistance 根据 DeltaTime, Speed 和 MoveDirection 递增或递减。
		if (CurDistance >= MaxDistance || CurDistance <= 0.0f)		// 如果 CurDistance 超过 MaxDistance 或小于等于 0.0f：
		{
			// 反转方向
			MoveDirection *= -1;	//	MoveDirection 反转方向。

			// 触发事件
			OnEndpointReached.Broadcast(CurDistance >= MaxDistance);		// 触发 OnEndpointReached 事件。

			// 限制距离
			CurDistance = FMath::Clamp(CurDistance, 0.0f, MaxDistance);		// CurDistance 限制在 0.0f 和 MaxDistance 之间。

		}
	}

	// 计算并设置当前位置
	SetRelativeLocation(StartRelativeLocation + MoveOffsetNorm * CurDistance);		// 计算并设置组件的相对位置为 StartRelativeLocation + MoveOffsetNorm * CurDistance。
}
