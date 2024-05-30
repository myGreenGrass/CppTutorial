// ����Ŀ���õ�����ҳ������д��Ȩ������

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"

#include "XPCharacter.generated.h"

UCLASS()
class NEWCPPTUTORIAL_API AXPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// ���ô˽�ɫ���Ե�Ĭ��ֵ
	AXPCharacter();

protected:
	// ��Ϸ��ʼ������ʱ����
	virtual void BeginPlay() override;

public:
	// ÿ֡����һ��
	virtual void Tick(float DeltaTime) override;

	// �󶨹��ܵ�����
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
	UPROPERTY(EditAnywhere)
	float MoveSpeed = 1.0f;

	// ��ת�ٶ�
	UPROPERTY(EditAnywhere)
	float RotationSpeed = 1.0f;

	// ��ʾ������
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* PlayerMesh;

	// ���ڹ۲쳡���������
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* PlayerCamera;
};
