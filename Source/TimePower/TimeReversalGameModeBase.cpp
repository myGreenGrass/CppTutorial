// 在项目设置的描述页面中填写版权声明。

#include "TimeReversalGameModeBase.h"

// 获取时间管理器
ATimeManager* ATimeReversalGameModeBase::GetTimeManager()
{
	// 检查时间管理器是否有效
	if (!TimeManager)
	{
		UE_LOG(LogTemp, Error, TEXT("尝试在时间管理器存在之前调用GetTimeManager()"));
	}
	return TimeManager;
}

// 初始化游戏
void ATimeReversalGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	// 初始化时间管理器
	TimeManager = Cast<ATimeManager>(GetWorld()->SpawnActor(ATimeManager::StaticClass()));
	if (!TimeManager)
	{
		UE_LOG(LogTemp, Error, TEXT("创建TimeManager失败！"));
	}
}
