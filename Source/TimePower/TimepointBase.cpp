#include "TimepointBase.h"

UTimepointBase* UTimepointBase::Interpolate_Implementation(const UTimepointBase* Other, float Distance) const
{
	if (!Other) return nullptr;

	// ����һ���µ�ʱ������
	UTimepointBase* NewTimepoint = DuplicateObject(this, nullptr);
	if (NewTimepoint)
	{
		// �����ֵʱ��
		NewTimepoint->Time = FMath::Lerp(Time, Other->Time, Distance);
	}
	return NewTimepoint;
}
