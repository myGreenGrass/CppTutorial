// 在项目设置的描述页面填写你的版权声明。

#include "MyCollectableActor.h"

// 设置默认值
AMyCollectableActor::AMyCollectableActor()
{
	// 设置这个actor每帧调用Tick()。如果不需要，可以关闭以提高性能。
	PrimaryActorTick.bCanEverTick = true;

	// 创建用于渲染的（根）组件
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	// 创建碰撞盒
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(StaticMesh);
}

// 实现跳跃功能
void AMyCollectableActor::Jump(float velocity)
{
	// 确保跳跃只执行一次
	if (!IsLaunched)
	{
		// 使用物理系统执行跳跃
		StaticMesh->AddImpulse({ .0f, .0f, velocity * 500.f });

		// 启动对象销毁
		SetActorTickEnabled(true);
		IsLaunched = true;
	}
}

// 当游戏开始或生成时调用
void AMyCollectableActor::BeginPlay()
{
	Super::BeginPlay();

	// 设置每个实例的OnComponentOverlap事件
	FScriptDelegate DelegateSubscriber;
	DelegateSubscriber.BindUFunction(this, "OnComponentBeginOverlap");
	BoxCollision->OnComponentBeginOverlap.Add(DelegateSubscriber);

	// 只有在启动后才需要Tick
	SetActorTickEnabled(false);
}

// 当其他Actor的组件与碰撞体重叠时调用
void AMyCollectableActor::OnComponentBeginOverlap(class UBoxComponent* Component, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 在屏幕上显示调试信息
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "EVENT", true, { 3,3 });

	// 检查是否未启动且其他Actor是触发类
	if (!IsLaunched && OtherActor->IsA(TriggerClass))
	{
		// 广播跳跃触发事件
		OnJumpTrigger.Broadcast(OtherActor, Component);
	}
}

// 每帧调用一次
void AMyCollectableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 如果已经启动
	if (IsLaunched)
	{
		// 减少生存时间
		Livetime -= DeltaTime;

		// 检查是否需要销毁Actor
		if (Livetime <= 0.f)
		{
			Destroy();
		}
	}
}