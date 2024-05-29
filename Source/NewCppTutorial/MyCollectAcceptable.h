// 在项目设置的描述页面填写你的版权声明。

#pragma once

// 包含核心最小化头文件
#include "CoreMinimal.h"
// 包含UObject接口的头文件
#include "UObject/Interface.h"
// 包含生成的MyCollectAcceptable类的头文件
#include "MyCollectAcceptable.generated.h"

// 这个类不需要修改。
UINTERFACE(MinimalAPI, Blueprintable)
class UMyCollectAcceptable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 自定义的可收集接口类
 */
class NEWCPPTUTORIAL_API IMyCollectAcceptable
{
	GENERATED_BODY()

	// 在这个类中添加接口函数。这是将被继承以实现此接口的类。
public:
	// 声明一个在蓝图中可调用且可实现的事件函数
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Collect(UObject* SourceObj, float Count);
};