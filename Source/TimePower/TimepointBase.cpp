#include "TimepointBase.h"

UTimepointBase* UTimepointBase::Interpolate_Implementation(const UTimepointBase* Other, float Distance) const
{
	if (!Other) return nullptr;

	// 创建一个新的时间点对象
	UTimepointBase* NewTimepoint = DuplicateObject(this, nullptr);
	if (NewTimepoint)
	{
		// 计算插值时间
		NewTimepoint->Time = FMath::Lerp(Time, Other->Time, Distance);
	}
	return NewTimepoint;
}
