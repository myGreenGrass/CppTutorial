// ���� MoveComponent ���ͷ�ļ���
#include "MoveComponent.h"

// ���ô�������Ե�Ĭ��ֵ
UMoveComponent::UMoveComponent()
{
	//	���ø��������Ϸ��ʼʱ��ʼ��������ÿһ֡�����á�����Թر���Щ������������ܣ�����㲻��Ҫ���ǵĻ���
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

//	EnableMovement �������������û�����ƶ���
void UMoveComponent::EnableMovement(bool ShouldMove)
{
	//	MoveEnable ��ֵΪ ShouldMove��
	MoveEnable = ShouldMove;
	//	SetComponentTickEnabled(MoveEnable); ���� MoveEnable ���������tick����״̬��
	SetComponentTickEnabled(MoveEnable);
}

// ������벢���õ���ʼλ��
void UMoveComponent::ResetMovement()
{
	CurDistance = 0.0f;		//	����Ϊ 0.0f��
	SetRelativeLocation(StartRelativeLocation);			// �����������ʼ���λ�á�
}

// SetMoveDirection ���������������ƶ�����
void UMoveComponent::SetMoveDirection(int Direction)
{
	MoveDirection = Direction >= 1 ? 1 : -1;
}

//	����Ϸ��ʼʱ����
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	//	������ʼλ��
	StartRelativeLocation = GetRelativeLocation();	//���ó�ʼ���λ�á�

	// �����һ���ƶ�ƫ����
	MoveOffsetNorm = MoveOffset;	// ��ֵ�ƶ�ƫ������
	MoveOffsetNorm.Normalize();		// ��һ���ƶ�ƫ������
	MaxDistance = MoveOffset.Length();	// ���������롣

	// ����Ƿ���Ҫtick
	SetComponentTickEnabled(MoveEnable);	//���� MoveEnable ���������tick����״̬��
}


// ÿ֡����
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);		// TickComponent ������ÿ֡���ã�

	// ���õ�ǰ����
	if (MoveEnable)			// ��� MoveEnable Ϊ�棺
	{
		CurDistance += DeltaTime * Speed * MoveDirection;		// CurDistance ���� DeltaTime, Speed �� MoveDirection ������ݼ���
		if (CurDistance >= MaxDistance || CurDistance <= 0.0f)		// ��� CurDistance ���� MaxDistance ��С�ڵ��� 0.0f��
		{
			// ��ת����
			MoveDirection *= -1;	//	MoveDirection ��ת����

			// �����¼�
			OnEndpointReached.Broadcast(CurDistance >= MaxDistance);		// ���� OnEndpointReached �¼���

			// ���ƾ���
			CurDistance = FMath::Clamp(CurDistance, 0.0f, MaxDistance);		// CurDistance ������ 0.0f �� MaxDistance ֮�䡣

		}
	}

	// ���㲢���õ�ǰλ��
	SetRelativeLocation(StartRelativeLocation + MoveOffsetNorm * CurDistance);		// ���㲢������������λ��Ϊ StartRelativeLocation + MoveOffsetNorm * CurDistance��
}
