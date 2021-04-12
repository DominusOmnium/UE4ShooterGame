// Udemy Shooter Game. All Rights Reserved

#include "Weapon/USLauncherWeapon.h"
#include "Weapon/USProjectile.h"

void AUSLauncherWeapon::StartFire()
{
	MakeShoot();
}

void AUSLauncherWeapon::MakeShoot()
{
	if (!GetWorld() || IsAmmoEmpty())
		return;

	FVector TraceStart, TraceEnd;
	if (!GetTraceData(TraceStart, TraceEnd))
		return;

	FHitResult HitResult;
	MakeHit(HitResult, TraceStart, TraceEnd);

	const FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd;
	const FVector Direction = (EndPoint - GetMuzzleWorldLocation()).GetSafeNormal();

	const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
	AUSProjectile* Projectile = GetWorld()->SpawnActorDeferred<AUSProjectile>(ProjectileClass, SpawnTransform, GetOwner());
	if (Projectile)
	{
		Projectile->SetShootDirection(Direction);
		Projectile->FinishSpawning(SpawnTransform);
	}

	DecreaseAmmo();
}
