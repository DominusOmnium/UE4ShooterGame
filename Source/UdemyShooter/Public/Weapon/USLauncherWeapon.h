// Udemy Shooter Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Weapon/USBaseWeapon.h"
#include "USLauncherWeapon.generated.h"

class AUSProjectile;

UCLASS()
class UDEMYSHOOTER_API AUSLauncherWeapon : public AUSBaseWeapon
{
	GENERATED_BODY()

public:
	virtual void StartFire() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<AUSProjectile> ProjectileClass;

	virtual void MakeShoot() override;
};
