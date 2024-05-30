//	在项目设置的描述页面填写你的版权声明

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "SpawnBox.generated.h"

//	ASpawnBox类用于生成其他Actor
UCLASS()
class NEWCPPTUTORIAL_API ASpawnBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// 设置这个Actor的默认属性
	ASpawnBox();

protected:
	// 当游戏开始或生成时调用
	virtual void BeginPlay() override;
	// 当游戏开始或生成时调用
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// 立即生成指定类的Actor
	UFUNCTION(BlueprintCallable)
	bool SpawnActor();

	// 改变是否生成Actor的状态
	UFUNCTION(BlueprintCallable)
	void EnableActorSpawning(bool Enable);

private:
	// 定时生成Actor的函数
	UFUNCTION()
	void SpawnActorScheduled();

	// 安排Actor生成的调度
	void ScheduleActorSpawn();

public:
	// 要生成的Actor类
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorClassToBeSpawned;

	// 平均生成时间（不包含随机部分）
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AvgSpawnTime = 5.f;

	// 生成时间的随机偏移量
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float RandomSpawnTimeOffset = 1.f;

private:
	//	用于生成Actor的盒子组件
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* SpawnBox;

	// 指示是否应该生成Actor
	UPROPERTY(EditAnywhere)
	bool ShouldSpawn = true;

	// 用于定时的辅助工具
	FTimerHandle SpawnTimerHandle;
};
