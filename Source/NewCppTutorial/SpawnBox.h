//	����Ŀ���õ�����ҳ����д��İ�Ȩ����

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "SpawnBox.generated.h"

//	ASpawnBox��������������Actor
UCLASS()
class NEWCPPTUTORIAL_API ASpawnBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// �������Actor��Ĭ������
	ASpawnBox();

protected:
	// ����Ϸ��ʼ������ʱ����
	virtual void BeginPlay() override;
	// ����Ϸ��ʼ������ʱ����
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// ��������ָ�����Actor
	UFUNCTION(BlueprintCallable)
	bool SpawnActor();

	// �ı��Ƿ�����Actor��״̬
	UFUNCTION(BlueprintCallable)
	void EnableActorSpawning(bool Enable);

private:
	// ��ʱ����Actor�ĺ���
	UFUNCTION()
	void SpawnActorScheduled();

	// ����Actor���ɵĵ���
	void ScheduleActorSpawn();

public:
	// Ҫ���ɵ�Actor��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ActorClassToBeSpawned;

	// ƽ������ʱ�䣨������������֣�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AvgSpawnTime = 5.f;

	// ����ʱ������ƫ����
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float RandomSpawnTimeOffset = 1.f;

private:
	//	��������Actor�ĺ������
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* SpawnBox;

	// ָʾ�Ƿ�Ӧ������Actor
	UPROPERTY(EditAnywhere)
	bool ShouldSpawn = true;

	// ���ڶ�ʱ�ĸ�������
	FTimerHandle SpawnTimerHandle;
};
