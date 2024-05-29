// 预处理指令，确保头文件只被编译一次，防止重复定义。
#pragma once

// CoreMinimal.h 是Unreal Engine的核心头文件。
#include "CoreMinimal.h"
// SceneComponent.h 是场景组件的头文件。
#include "Components/SceneComponent.h"
// MoveComponent.generated.h 是由Unreal Header Tool (UHT) 自动生成的文件，处理UCLASS、USTRUCT、UENUM等宏。
#include "MoveComponent.generated.h"

// 声明一个动态多播代理，用于在组件到达终点时触发事件：
// BlueprintAuthorityOnly 只有拥有权限的实例才能调用。
// FOnMoveComponentReachEndPointSignature 代理的名称。
// bool IsTopEndpoint 参数，表示是否到达顶端。
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveComponentReachEndPointSignature, bool, IsTopEndpoint);

// 声明一个新的UCLASS UMoveComponent 继承自 USceneComponent：
// ClassGroup=(NewCppTutorial) 将类分组到指定类别。
// meta=(BlueprintSpawnableComponent) 允许该组件在蓝图中生成。
// NEWCPPTUTORIAL_API 用于导出符号。
UCLASS(ClassGroup = (NewCppTutorial), meta = (BlueprintSpawnableComponent))
class NEWCPPTUTORIAL_API UMoveComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// 公共无参构造函数
	UMoveComponent();

	// 声明一个蓝图可调用的函数 EnableMovement，用于启用或禁用移动：
	UFUNCTION(BlueprintCallable)
	void EnableMovement(bool ShouldMove);

	// 声明一个蓝图可调用的函数 ResetMovement，用于重置移动。
	UFUNCTION(BlueprintCallable)
	void ResetMovement();

	// 声明一个蓝图可调用的函数 SetMoveDirection，用于设置移动方向：
	UFUNCTION(BlueprintCallable)
	void SetMoveDirection(int Direction);

protected:
	// 重写 BeginPlay 函数，在游戏开始时调用。
	virtual void BeginPlay() override;

public:
	// 重写 TickComponent 函数，每帧调用。
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// 声明 FMoveComponentVisualizer 为 UMoveComponent 的友元类。
	friend class FMoveComponentVisualizer;

	// 声明一个属性 MoveOffset，表示移动偏移量：
	UPROPERTY(EditAnywhere)
	FVector MoveOffset = FVector(0,500,200);

	// 声明一个属性 Speed，表示移动速度，默认值为 1.0f。
	UPROPERTY(EditAnywhere)
	float Speed = 1.0f * 250;

	// 声明一个属性 MoveEnable，表示是否启用移动，默认值为 true。
	UPROPERTY(EditAnywhere)
	bool MoveEnable = true;

	//声明一个属性 OnEndpointReached，当到达终点时触发的事件：
	UPROPERTY(BlueprintAssignable)
	FOnMoveComponentReachEndPointSignature OnEndpointReached;

	// StartRelativeLocation 起始相对位置。
	FVector StartRelativeLocation;
	// MoveOffsetNorm 归一化移动偏移量。
	FVector MoveOffsetNorm;
	// MaxDistance 最大距离，初始值为 0.0f。
	float MaxDistance = 0.0f;
	// CurDistance 当前距离，初始值为 0.0f。
	float CurDistance = 0.0f;
	// MoveDirection 移动方向，初始值为 1。
	int MoveDirection = 1;

};