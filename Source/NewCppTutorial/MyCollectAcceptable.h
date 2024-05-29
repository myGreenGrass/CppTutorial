// ����Ŀ���õ�����ҳ����д��İ�Ȩ������

#pragma once

// ����������С��ͷ�ļ�
#include "CoreMinimal.h"
// ����UObject�ӿڵ�ͷ�ļ�
#include "UObject/Interface.h"
// �������ɵ�MyCollectAcceptable���ͷ�ļ�
#include "MyCollectAcceptable.generated.h"

// ����಻��Ҫ�޸ġ�
UINTERFACE(MinimalAPI, Blueprintable)
class UMyCollectAcceptable : public UInterface
{
	GENERATED_BODY()
};

/**
 * �Զ���Ŀ��ռ��ӿ���
 */
class NEWCPPTUTORIAL_API IMyCollectAcceptable
{
	GENERATED_BODY()

	// �����������ӽӿں��������ǽ����̳���ʵ�ִ˽ӿڵ��ࡣ
public:
	// ����һ������ͼ�пɵ����ҿ�ʵ�ֵ��¼�����
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void Collect(UObject* SourceObj, float Count);
};