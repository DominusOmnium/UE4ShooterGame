// Udemy Shooter Game. All Rights Reserved


#include "USGameModeBase.h"
#include "Player/USBaseCharacter.h"
#include "Player/USPlayerController.h"
#include "UI/USGameHud.h"

AUSGameModeBase::AUSGameModeBase()
{
	DefaultPawnClass = AUSBaseCharacter::StaticClass();
	PlayerControllerClass = AUSPlayerController::StaticClass();
	HUDClass = AUSGameHUD::StaticClass();
}

