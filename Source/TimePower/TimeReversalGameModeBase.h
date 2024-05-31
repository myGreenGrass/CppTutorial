// ����Ŀ���õ�����ҳ������д��Ȩ������

#pragma once

#include "TimeManager.h"

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TimeReversalGameModeBase.generated.h"

/**
 *
 */
UCLASS()
class TIMEPOWER_API ATimeReversalGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	// �ڳ�ʼ��actor֮ǰ����
	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

public:
	// ��ȡȫ�ֹ���ʱ��Ĺ�����
	UFUNCTION(BlueprintCallable)
	ATimeManager* GetTimeManager();

protected:
	// ʱ�������������
	UPROPERTY(BlueprintReadOnly)
	ATimeManager* TimeManager = nullptr;
};
