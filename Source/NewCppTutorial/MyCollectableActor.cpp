// ����Ŀ���õ�����ҳ����д��İ�Ȩ������

#include "MyCollectableActor.h"

// ����Ĭ��ֵ
AMyCollectableActor::AMyCollectableActor()
{
	// �������actorÿ֡����Tick()���������Ҫ�����Թر���������ܡ�
	PrimaryActorTick.bCanEverTick = true;

	// ����������Ⱦ�ģ��������
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	// ������ײ��
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(StaticMesh);
}

// ʵ����Ծ����
void AMyCollectableActor::Jump(float velocity)
{
	// ȷ����Ծִֻ��һ��
	if (!IsLaunched)
	{
		// ʹ������ϵͳִ����Ծ
		StaticMesh->AddImpulse({ .0f, .0f, velocity * 500.f });

		// ������������
		SetActorTickEnabled(true);
		IsLaunched = true;
	}
}

// ����Ϸ��ʼ������ʱ����
void AMyCollectableActor::BeginPlay()
{
	Super::BeginPlay();

	// ����ÿ��ʵ����OnComponentOverlap�¼�
	FScriptDelegate DelegateSubscriber;
	DelegateSubscriber.BindUFunction(this, "OnComponentBeginOverlap");
	BoxCollision->OnComponentBeginOverlap.Add(DelegateSubscriber);

	// ֻ�������������ҪTick
	SetActorTickEnabled(false);
}

// ������Actor���������ײ���ص�ʱ����
void AMyCollectableActor::OnComponentBeginOverlap(class UBoxComponent* Component, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// ����Ļ����ʾ������Ϣ
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "EVENT", true, { 3,3 });

	// ����Ƿ�δ����������Actor�Ǵ�����
	if (!IsLaunched && OtherActor->IsA(TriggerClass))
	{
		// �㲥��Ծ�����¼�
		OnJumpTrigger.Broadcast(OtherActor, Component);
	}
}

// ÿ֡����һ��
void AMyCollectableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ����Ѿ�����
	if (IsLaunched)
	{
		// ��������ʱ��
		Livetime -= DeltaTime;

		// ����Ƿ���Ҫ����Actor
		if (Livetime <= 0.f)
		{
			Destroy();
		}
	}
}