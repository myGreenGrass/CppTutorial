// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimepointBase.generated.h"

/**
 * 
 */
UCLASS()
class TIMEPOWER_API UTimepointBase : public UObject
{
	GENERATED_BODY()
	
	public:
		// 表示时间点的时间属性
		UPROPERTY(BlueprintReadWrite)
		float Time = 0.0f;

		// 插值函数，用于在两个时间点之间进行插值
		UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		UTimepointBase* Interpolate(const UTimepointBase* Other, float Distance);

	private:
		// 插值函数的实现
		virtual UTimepointBase* Interpolate_Implementation(const UTimepointBase* Other, float Distance) const;
};
