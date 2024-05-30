// ��д��Ȩ��������Ŀ���õ�����ҳ�档
#pragma once // ��ֹͷ�ļ��ظ�����

#include "CoreMinimal.h" // ����Unreal����ĺ�����С��ͷ�ļ�
#include "GameFramework/Pawn.h" // ����Pawn��Ķ���
#include "Components/StaticMeshComponent.h" // ������̬��������Ķ���
#include "Camera/CameraComponent.h" // �������������Ķ���
#include "XPPawn.generated.h" // �Զ����ɵ�ͷ�ļ�������UCLASS���

// ����һ���µ��� AXPPawn �̳��� APawn
UCLASS()
class NEWCPPTUTORIAL_API AXPPawn : public APawn
{
	GENERATED_BODY() // ����������ı�׼��

public:
	// ��ʾ�ľ�̬���������
	UPROPERTY(EditDefaultsOnly) // ���ڱ༭���пɱ༭
		UStaticMeshComponent* PlayerMesh;

	// ���ڲ鿴��������������
	UPROPERTY(EditDefaultsOnly) // ���ڱ༭���пɱ༭
		UCameraComponent* PlayerCamera;

public:
	// Ϊ��Pawn����������Ĭ��ֵ
	AXPPawn();

protected:
	// ����Ϸ��ʼ�����ɸ�Pawnʱ����
	virtual void BeginPlay() override;

public:
	// ÿ֡����һ��
	virtual void Tick(float DeltaTime) override;

	// ���ڽ����ܰ󶨵�����
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// ��ǰ/����ƶ�
	void MoveFB(float Value);

	// ����/�����ƶ�
	void MoveLR(float Value);

	// ��ת
	void Rotate(float Value);

private:
	// �ƶ��ٶ�
	UPROPERTY(EditAnywhere) // ���ڱ༭���ʹ����б༭
		float MoveSpeed = 1.f;

	// ��ת�ٶ�
	UPROPERTY(EditAnywhere) // ���ڱ༭���ʹ����б༭
		float RotationSpeed = 1.f;
};
