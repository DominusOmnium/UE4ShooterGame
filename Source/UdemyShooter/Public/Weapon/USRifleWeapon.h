// Udemy Shooter Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Weapon/USBaseWeapon.h"
#include "USRifleWeapon.generated.h"

class UUSWeaponFXComponent;

UCLASS()
class UDEMYSHOOTER_API AUSRifleWeapon : public AUSBaseWeapon
{
	GENERATED_BODY()

public:
	AUSRifleWeapon();

	virtual void StartFire() override;
	virtual void StopFire() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float TimeBetweenShoots = 0.1f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float BulletSpread = 1.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float DamageAmount = 10.0f;

	UPROPERTY(VisibleAnywhere, Category = "VFX")
	UUSWeaponFXComponent* WeaponFXComponent;

	virtual void BeginPlay() override;
	virtual void MakeShoot() override;
	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const override;

private:
	FTimerHandle ShootTimerHandle;
	void MakeDamage(const FHitResult& HitResult);
};
