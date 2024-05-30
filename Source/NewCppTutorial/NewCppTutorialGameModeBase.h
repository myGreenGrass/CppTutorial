// Epic Games�İ�Ȩ����

#pragma once

// ����������С��ͷ�ļ�
#include "CoreMinimal.h"
// ����GameModeBase���ͷ�ļ�
#include "GameFramework/GameModeBase.h"
// ����DefaultPawn���ͷ�ļ�
#include "GameFramework/DefaultPawn.h"
// ���� XPPawn��
#include "XPPawn.h"
// ���� Character��
#include "XPCharacter.h"
// ���ɵ�ͷ�ļ�
#include "NewCppTutorialGameModeBase.generated.h"

/**
 * �Զ������Ϸģʽ����
 */
UCLASS()
class NEWCPPTUTORIAL_API ANewCppTutorialGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	// ��д��ʼ����Ϸ״̬�ĺ���
	virtual void InitGameState() override;

private:
	// �༭ʱ�������Ҳ�����������ԣ���ʾ�Զ����XPCharacter��
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<AXPCharacter> CustomXPCharacterClass = AXPCharacter::StaticClass();
	//TSubclassOf<AXPPawn> CustomXPPawnClass = AXPPawn::StaticClass();

};
