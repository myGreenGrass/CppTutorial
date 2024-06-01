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
		// ��ʾʱ����ʱ������
		UPROPERTY(BlueprintReadWrite)
		float Time = 0.0f;

		// ��ֵ����������������ʱ���֮����в�ֵ
		UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		UTimepointBase* Interpolate(const UTimepointBase* Other, float Distance);

	private:
		// ��ֵ������ʵ��
		virtual UTimepointBase* Interpolate_Implementation(const UTimepointBase* Other, float Distance) const;
};
