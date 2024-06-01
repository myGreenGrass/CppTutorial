// ����Ŀ���õ�����ҳ������д��Ȩ������

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeManager.generated.h"

UCLASS()
class TIMEPOWER_API ATimeManager : public AActor
{
	GENERATED_BODY()

public:
	// ���ø�Actor��Ĭ������ֵ
	ATimeManager();

protected:
	// ����Ϸ��ʼ������ʱ����
	virtual void BeginPlay() override;

	// ����ʱ������
	UPROPERTY(BlueprintReadWrite)
	float NormalTimeFactor = 1.f;
	// ����ʱ������
	UPROPERTY(BlueprintReadWrite)
	float ReverseTimeFactor = -3.f;
	// ��ǰʱ�����ӣ���ʼΪ����ʱ������
	UPROPERTY(BlueprintReadOnly)
	float CurrentTimeFactor = NormalTimeFactor;

	// ʱ�䵹������ֵ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ReverseTimeThreshold = 3.f;
	// ���ʱ�䵹��ʱ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ReverseTimeMaximum = 15.f;

	// ��ǰ��¼��ʱ��
	UPROPERTY(BlueprintReadOnly)
	float CurrentRecordedTime = 0.f;
	// ʱ�䵹�������Ƿ�����
	UPROPERTY(BlueprintReadOnly)
	bool TimeReversalEnable = false;

public:
	// ÿ֡����
	virtual void Tick(float DeltaTime) override;

	// ��ȡ��ǰʱ������
	UFUNCTION(BlueprintCallable)
	float GetTimeFactor();
	// ��ȡ��ǰ��¼��ʱ��
	UFUNCTION(BlueprintCallable)
	float GetCurrentRecordedTime();

	// ʱ�䵹������
	UFUNCTION(BlueprintCallable)
	void BeginTimeReverse();
	UFUNCTION(BlueprintCallable)
	void EndTimeReverse();

	// ���û����ʱ�䵹������
	UFUNCTION(BlueprintCallable)
	void EnableTimeReversal(bool Enable);

private:
	// ��˽�г�Ա����
};
