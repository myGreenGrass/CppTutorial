// ����Ŀ���õ�����ҳ������д��Ȩ������

#include "TimeManager.h"
#include "MathUtil.h"

// ����Ĭ��ֵ
ATimeManager::ATimeManager()
{
	// ���ø�Actorÿ֡����Tick()���������Ҫ�����Խ���ر���������ܡ�
	PrimaryActorTick.bCanEverTick = true;
}

// ����Ϸ��ʼ������ʱ����
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
}

// ÿ֡����
void ATimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ���������ʱ�䵹������
	if (TimeReversalEnable)
	{
		// ���¼�¼�ĵ�ǰʱ�䣬ȷ�����������ʱ��
		CurrentRecordedTime = FMath::Min(ReverseTimeMaximum, CurrentRecordedTime + DeltaTime * CurrentTimeFactor);
		if (CurrentRecordedTime <= 0.0f)
		{
			EndTimeReverse();
		}
	}
}

// ��ȡ��ǰʱ������
float ATimeManager::GetTimeFactor()
{
	return CurrentTimeFactor;
}

// ��ȡ��ǰ��¼��ʱ��
float ATimeManager::GetCurrentRecordedTime()
{
	return CurrentRecordedTime;
}

// ��ʼʱ�䵹��
void ATimeManager::BeginTimeReverse()
{
	if (TimeReversalEnable && CurrentRecordedTime >= ReverseTimeThreshold)
	{
		CurrentTimeFactor = ReverseTimeFactor;
	}
}

// ����ʱ�䵹��
void ATimeManager::EndTimeReverse()
{
	CurrentTimeFactor = NormalTimeFactor;
}

// ���û����ʱ�䵹������
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
