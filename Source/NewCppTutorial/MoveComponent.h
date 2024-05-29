// Ԥ����ָ�ȷ��ͷ�ļ�ֻ������һ�Σ���ֹ�ظ����塣
#pragma once

// CoreMinimal.h ��Unreal Engine�ĺ���ͷ�ļ���
#include "CoreMinimal.h"
// SceneComponent.h �ǳ��������ͷ�ļ���
#include "Components/SceneComponent.h"
// MoveComponent.generated.h ����Unreal Header Tool (UHT) �Զ����ɵ��ļ�������UCLASS��USTRUCT��UENUM�Ⱥꡣ
#include "MoveComponent.generated.h"

// ����һ����̬�ಥ������������������յ�ʱ�����¼���
// BlueprintAuthorityOnly ֻ��ӵ��Ȩ�޵�ʵ�����ܵ��á�
// FOnMoveComponentReachEndPointSignature ��������ơ�
// bool IsTopEndpoint ��������ʾ�Ƿ񵽴ﶥ�ˡ�
UDELEGATE(BlueprintAuthorityOnly)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoveComponentReachEndPointSignature, bool, IsTopEndpoint);

// ����һ���µ�UCLASS UMoveComponent �̳��� USceneComponent��
// ClassGroup=(NewCppTutorial) ������鵽ָ�����
// meta=(BlueprintSpawnableComponent) ������������ͼ�����ɡ�
// NEWCPPTUTORIAL_API ���ڵ������š�
UCLASS(ClassGroup = (NewCppTutorial), meta = (BlueprintSpawnableComponent))
class NEWCPPTUTORIAL_API UMoveComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// �����޲ι��캯��
	UMoveComponent();

	// ����һ����ͼ�ɵ��õĺ��� EnableMovement���������û�����ƶ���
	UFUNCTION(BlueprintCallable)
	void EnableMovement(bool ShouldMove);

	// ����һ����ͼ�ɵ��õĺ��� ResetMovement�����������ƶ���
	UFUNCTION(BlueprintCallable)
	void ResetMovement();

	// ����һ����ͼ�ɵ��õĺ��� SetMoveDirection�����������ƶ�����
	UFUNCTION(BlueprintCallable)
	void SetMoveDirection(int Direction);

protected:
	// ��д BeginPlay ����������Ϸ��ʼʱ���á�
	virtual void BeginPlay() override;

public:
	// ��д TickComponent ������ÿ֡���á�
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// ���� FMoveComponentVisualizer Ϊ UMoveComponent ����Ԫ�ࡣ
	friend class FMoveComponentVisualizer;

	// ����һ������ MoveOffset����ʾ�ƶ�ƫ������
	UPROPERTY(EditAnywhere)
	FVector MoveOffset = FVector(0,500,200);

	// ����һ������ Speed����ʾ�ƶ��ٶȣ�Ĭ��ֵΪ 1.0f��
	UPROPERTY(EditAnywhere)
	float Speed = 1.0f * 250;

	// ����һ������ MoveEnable����ʾ�Ƿ������ƶ���Ĭ��ֵΪ true��
	UPROPERTY(EditAnywhere)
	bool MoveEnable = true;

	//����һ������ OnEndpointReached���������յ�ʱ�������¼���
	UPROPERTY(BlueprintAssignable)
	FOnMoveComponentReachEndPointSignature OnEndpointReached;

	// StartRelativeLocation ��ʼ���λ�á�
	FVector StartRelativeLocation;
	// MoveOffsetNorm ��һ���ƶ�ƫ������
	FVector MoveOffsetNorm;
	// MaxDistance �����룬��ʼֵΪ 0.0f��
	float MaxDistance = 0.0f;
	// CurDistance ��ǰ���룬��ʼֵΪ 0.0f��
	float CurDistance = 0.0f;
	// MoveDirection �ƶ����򣬳�ʼֵΪ 1��
	int MoveDirection = 1;

};