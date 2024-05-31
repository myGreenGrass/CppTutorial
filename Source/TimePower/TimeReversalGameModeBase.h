// 在项目设置的描述页面中填写版权声明。

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
	// 在初始化actor之前调用
	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

public:
	// 获取全局管理时间的管理器
	UFUNCTION(BlueprintCallable)
	ATimeManager* GetTimeManager();

protected:
	// 时间管理器的属性
	UPROPERTY(BlueprintReadOnly)
	ATimeManager* TimeManager = nullptr;
};
