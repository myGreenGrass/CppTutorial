// Epic Games�İ�Ȩ����

#include "NewCppTutorialGameModeBase.h"

// ��д��ʼ����Ϸ״̬�ĺ���
void ANewCppTutorialGameModeBase::InitGameState()
{
    // ���û����InitGameState����
    Super::InitGameState();

    // ����Ƿ�û��ǿ�Ƹ���Ĭ��Pawn��
    if (DefaultPawnClass == ADefaultPawn::StaticClass() || !DefaultPawnClass)
    {
        // ����Ϊ�Զ����ʵ�� 
        //DefaultPawnClass = AXPPawn::StaticClass();
        DefaultPawnClass = CustomXPPawnClass;
    }
}
