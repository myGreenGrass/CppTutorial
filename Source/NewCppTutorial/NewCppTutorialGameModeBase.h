// Epic Games的版权声明

#pragma once

// 包含核心最小化头文件
#include "CoreMinimal.h"
// 包含GameModeBase类的头文件
#include "GameFramework/GameModeBase.h"
// 包含DefaultPawn类的头文件
#include "GameFramework/DefaultPawn.h"
// 包含 XPPawn类
#include "XPPawn.h"
// 包含 Character类
#include "XPCharacter.h"
// 生成的头文件
#include "NewCppTutorialGameModeBase.generated.h"

/**
 * 自定义的游戏模式基类
 */
UCLASS()
class NEWCPPTUTORIAL_API ANewCppTutorialGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	// 重写初始化游戏状态的函数
	virtual void InitGameState() override;

private:
	// 编辑时可设置且不可清除的属性，表示自定义的XPCharacter类
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<AXPCharacter> CustomXPCharacterClass = AXPCharacter::StaticClass();
	//TSubclassOf<AXPPawn> CustomXPPawnClass = AXPPawn::StaticClass();

};
