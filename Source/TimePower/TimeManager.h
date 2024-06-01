// 在项目设置的描述页面中填写版权声明。

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeManager.generated.h"

UCLASS()
class TIMEPOWER_API ATimeManager : public AActor
{
	GENERATED_BODY()

public:
	// 设置该Actor的默认属性值
	ATimeManager();

protected:
	// 在游戏开始或生成时调用
	virtual void BeginPlay() override;

	// 正常时间因子
	UPROPERTY(BlueprintReadWrite)
	float NormalTimeFactor = 1.f;
	// 反向时间因子
	UPROPERTY(BlueprintReadWrite)
	float ReverseTimeFactor = -3.f;
	// 当前时间因子，初始为正常时间因子
	UPROPERTY(BlueprintReadOnly)
	float CurrentTimeFactor = NormalTimeFactor;

	// 时间倒流的阈值
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ReverseTimeThreshold = 3.f;
	// 最大时间倒流时间
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ReverseTimeMaximum = 15.f;

	// 当前记录的时间
	UPROPERTY(BlueprintReadOnly)
	float CurrentRecordedTime = 0.f;
	// 时间倒流功能是否启用
	UPROPERTY(BlueprintReadOnly)
	bool TimeReversalEnable = false;

public:
	// 每帧调用
	virtual void Tick(float DeltaTime) override;

	// 获取当前时间因子
	UFUNCTION(BlueprintCallable)
	float GetTimeFactor();
	// 获取当前记录的时间
	UFUNCTION(BlueprintCallable)
	float GetCurrentRecordedTime();

	// 时间倒流控制
	UFUNCTION(BlueprintCallable)
	void BeginTimeReverse();
	UFUNCTION(BlueprintCallable)
	void EndTimeReverse();

	// 启用或禁用时间倒流功能
	UFUNCTION(BlueprintCallable)
	void EnableTimeReversal(bool Enable);

private:
	// 无私有成员变量
};
