// 在项目设置的描述页面中填写版权声明。

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"

#include "XPCharacter.generated.h"

UCLASS()
class NEWCPPTUTORIAL_API AXPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// 设置此角色属性的默认值
	AXPCharacter();

protected:
	// 游戏开始或生成时调用
	virtual void BeginPlay() override;

public:
	// 每帧调用一次
	virtual void Tick(float DeltaTime) override;

	// 绑定功能到输入
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
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 1.0f;

	// 旋转速度
	UPROPERTY(EditAnywhere)
	float RotationSpeed = 1.0f;

	// 显示的网格
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* PlayerMesh;

	// 用于观察场景的摄像机
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* PlayerCamera;
};
