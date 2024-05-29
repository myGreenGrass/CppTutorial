// 在项目设置的描述页面填写你的版权声明。

#pragma once

// 包含核心最小化头文件
#include "CoreMinimal.h"
// 包含Actor类的头文件
#include "GameFramework/Actor.h"

// 包含静态网格组件的头文件
#include "Components/StaticMeshComponent.h"
// 包含盒子组件的头文件
#include "Components/BoxComponent.h"
// 包含默认Pawn类的头文件
#include "GameFramework/DefaultPawn.h"

// 包含生成的MyCollectableActor类的头文件
#include "MyCollectableActor.generated.h"

// 声明一个动态多播委托，带有两个参数：一个是其他的Actor，一个是其他的原始组件
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnJumpTriggerSignature, AActor*, OtherActor, UPrimitiveComponent*, OtherComp);

// 声明一个自定义的Actor类
UCLASS()
class NEWCPPTUTORIAL_API AMyCollectableActor : public AActor
{
	GENERATED_BODY()

public:
	// 设置这个Actor的属性的默认值
	AMyCollectableActor();

	// 声明一个可以在蓝图中调用的函数，用于实现跳跃功能
	UFUNCTION(BlueprintCallable)
	void Jump(float velocity);

protected:
	// 当游戏开始或生成时调用
	virtual void BeginPlay() override;

	// 当其他Actor的组件与碰撞体重叠时调用
	UFUNCTION()
	void OnComponentBeginOverlap(class UBoxComponent* Component, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// 编辑任何地方，蓝图中可读写的属性，表示生存时间
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Livetime = 2.f;

	// 编辑任何地方，蓝图中可读写的属性，表示速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Velocity = 3.f;

	// 编辑任何地方，蓝图中可读写的属性，表示触发类
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UClass* TriggerClass = ADefaultPawn::StaticClass();

public:
	// 每帧调用一次
	virtual void Tick(float DeltaTime) override;

private:
	// 用于渲染的静态网格
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMesh;

	// 用于碰撞检测的盒子组件
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxCollision;

	// 可在蓝图中分配的跳跃触发委托
	UPROPERTY(BlueprintAssignable)
	FOnJumpTriggerSignature OnJumpTrigger;

	// 表示是否已经启动
	bool IsLaunched = false;
};