// 填写版权声明到项目设置的描述页面。
#pragma once // 防止头文件重复包含

#include "CoreMinimal.h" // 包含Unreal引擎的核心最小化头文件
#include "GameFramework/Pawn.h" // 包含Pawn类的定义
#include "Components/StaticMeshComponent.h" // 包含静态网格组件的定义
#include "Camera/CameraComponent.h" // 包含摄像机组件的定义
#include "XPPawn.generated.h" // 自动生成的头文件，用于UCLASS宏等

// 声明一个新的类 AXPPawn 继承自 APawn
UCLASS()
class NEWCPPTUTORIAL_API AXPPawn : public APawn
{
	GENERATED_BODY() // 生成类所需的标准宏

public:
	// 显示的静态网格体组件
	UPROPERTY(EditDefaultsOnly) // 仅在编辑器中可编辑
		UStaticMeshComponent* PlayerMesh;

	// 用于查看场景的摄像机组件
	UPROPERTY(EditDefaultsOnly) // 仅在编辑器中可编辑
		UCameraComponent* PlayerCamera;

public:
	// 为该Pawn的属性设置默认值
	AXPPawn();

protected:
	// 当游戏开始或生成该Pawn时调用
	virtual void BeginPlay() override;

public:
	// 每帧调用一次
	virtual void Tick(float DeltaTime) override;

	// 用于将功能绑定到输入
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// 向前/向后移动
	void MoveFB(float Value);

	// 向左/向右移动
	void MoveLR(float Value);

	// 旋转
	void Rotate(float Value);

private:
	// 移动速度
	UPROPERTY(EditAnywhere) // 可在编辑器和代码中编辑
		float MoveSpeed = 1.f;

	// 旋转速度
	UPROPERTY(EditAnywhere) // 可在编辑器和代码中编辑
		float RotationSpeed = 1.f;
};
