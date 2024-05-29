// ����Ŀ���õ�����ҳ����д��İ�Ȩ������

#pragma once

// ����������С��ͷ�ļ�
#include "CoreMinimal.h"
// ����Actor���ͷ�ļ�
#include "GameFramework/Actor.h"

// ������̬���������ͷ�ļ�
#include "Components/StaticMeshComponent.h"
// �������������ͷ�ļ�
#include "Components/BoxComponent.h"
// ����Ĭ��Pawn���ͷ�ļ�
#include "GameFramework/DefaultPawn.h"

// �������ɵ�MyCollectableActor���ͷ�ļ�
#include "MyCollectableActor.generated.h"

// ����һ����̬�ಥί�У���������������һ����������Actor��һ����������ԭʼ���
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnJumpTriggerSignature, AActor*, OtherActor, UPrimitiveComponent*, OtherComp);

// ����һ���Զ����Actor��
UCLASS()
class NEWCPPTUTORIAL_API AMyCollectableActor : public AActor
{
	GENERATED_BODY()

public:
	// �������Actor�����Ե�Ĭ��ֵ
	AMyCollectableActor();

	// ����һ����������ͼ�е��õĺ���������ʵ����Ծ����
	UFUNCTION(BlueprintCallable)
	void Jump(float velocity);

protected:
	// ����Ϸ��ʼ������ʱ����
	virtual void BeginPlay() override;

	// ������Actor���������ײ���ص�ʱ����
	UFUNCTION()
	void OnComponentBeginOverlap(class UBoxComponent* Component, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// �༭�κεط�����ͼ�пɶ�д�����ԣ���ʾ����ʱ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Livetime = 2.f;

	// �༭�κεط�����ͼ�пɶ�д�����ԣ���ʾ�ٶ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Velocity = 3.f;

	// �༭�κεط�����ͼ�пɶ�д�����ԣ���ʾ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UClass* TriggerClass = ADefaultPawn::StaticClass();

public:
	// ÿ֡����һ��
	virtual void Tick(float DeltaTime) override;

private:
	// ������Ⱦ�ľ�̬����
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMesh;

	// ������ײ���ĺ������
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* BoxCollision;

	// ������ͼ�з������Ծ����ί��
	UPROPERTY(BlueprintAssignable)
	FOnJumpTriggerSignature OnJumpTrigger;

	// ��ʾ�Ƿ��Ѿ�����
	bool IsLaunched = false;
};