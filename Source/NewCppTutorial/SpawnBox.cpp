// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnBox.h"

// ���캯��
// ����Ĭ��ֵ
ASpawnBox::ASpawnBox()
{
 	// �������Actorÿ֡����Tick()���������Ҫ�����Թر�����������ܡ�
	PrimaryActorTick.bCanEverTick = false;

	// ��ʼ����Ա
	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	RootComponent = SpawnBox;
}

// ����Ϸ������Actor������ʱ����
void ASpawnBox::BeginPlay()
{
	Super::BeginPlay();

	// ����������ɣ����ŵ�һ������
	if (ShouldSpawn)
	{
		ScheduleActorSpawn();
	}
}

// ����Ϸ������Actor������ʱ����
void ASpawnBox::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// ������˶���ʵ����صĶ�ʱ��
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

// ����ָ�����Actor
bool ASpawnBox::SpawnActor()
{
	bool SpawnedActor = false;
	if (ActorClassToBeSpawned)
	{
		//	������ӵı߽�
		FBoxSphereBounds BoxBounds = SpawnBox->CalcBounds(GetActorTransform());
		
		// ������ӱ߽��ڵ����λ��
		FVector SpawnLocation = BoxBounds.Origin;
		SpawnLocation.X += -BoxBounds.BoxExtent.X + 2 * BoxBounds.BoxExtent.X * FMath::FRand();
		SpawnLocation.Y += -BoxBounds.BoxExtent.Y + 2 * BoxBounds.BoxExtent.Y * FMath::FRand();
		SpawnLocation.Z += -BoxBounds.BoxExtent.Z + 2 * BoxBounds.BoxExtent.Z * FMath::FRand();

		//	����Actor
		SpawnedActor = GetWorld()->SpawnActor(ActorClassToBeSpawned, &SpawnLocation) != nullptr;
	}
	return SpawnedActor;
}

// ���û����Actor����
void ASpawnBox::EnableActorSpawning(bool Enable)
{
	// �����ڲ�״̬
	ShouldSpawn = Enable;

	// ����Enable��ֵ���Ż������ʱ��
	if (Enable)
	{
		ScheduleActorSpawn();
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);

	}
}

//	����Actor���ɵĵ���
void ASpawnBox::ScheduleActorSpawn()
{
	// �������ɵ�ʱ��ƫ��
	float DeltaToNextSpawn = AvgSpawnTime + (-RandomSpawnTimeOffset + 2 * RandomSpawnTimeOffset * FMath::FRand());

	// ��������
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnBox::SpawnActorScheduled, DeltaToNextSpawn, false);
}

// ��ʱ����Actor�ĺ���
void ASpawnBox::SpawnActorScheduled()
{
	// ���ɲ�����Ҫʱ���°���
	if (SpawnActor())
	{
		if (ShouldSpawn)
		{
			ScheduleActorSpawn();
		}
	}
	else {
		// TODO: ��¼������־
	}
}