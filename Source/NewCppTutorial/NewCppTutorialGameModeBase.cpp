// Epic Games的版权声明

#include "NewCppTutorialGameModeBase.h"

// 重写初始化游戏状态的函数
void ANewCppTutorialGameModeBase::InitGameState()
{
    // 调用基类的InitGameState函数
    Super::InitGameState();

    // 检查是否没有强制覆盖默认Pawn类
    if (DefaultPawnClass == ADefaultPawn::StaticClass() || !DefaultPawnClass)
    {
        // 更新为自定义的实现 
        //DefaultPawnClass = AXPPawn::StaticClass();
        DefaultPawnClass = CustomXPPawnClass;
    }
}
