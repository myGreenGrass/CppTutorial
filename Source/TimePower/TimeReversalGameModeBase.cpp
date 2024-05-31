// ����Ŀ���õ�����ҳ������д��Ȩ������

#include "TimeReversalGameModeBase.h"

// ��ȡʱ�������
ATimeManager* ATimeReversalGameModeBase::GetTimeManager()
{
	// ���ʱ��������Ƿ���Ч
	if (!TimeManager)
	{
		UE_LOG(LogTemp, Error, TEXT("������ʱ�����������֮ǰ����GetTimeManager()"));
	}
	return TimeManager;
}

// ��ʼ����Ϸ
void ATimeReversalGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	// ��ʼ��ʱ�������
	TimeManager = Cast<ATimeManager>(GetWorld()->SpawnActor(ATimeManager::StaticClass()));
	if (!TimeManager)
	{
		UE_LOG(LogTemp, Error, TEXT("����TimeManagerʧ�ܣ�"));
	}
}
