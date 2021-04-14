// Udemy Shooter Game. All Rights Reserved

#include "Weapon/USRifleWeapon.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Weapon/Components/USWeaponFXComponent.h"

AUSRifleWeapon::AUSRifleWeapon()
{
	WeaponFXComponent = CreateDefaultSubobject<UUSWeaponFXComponent>("WeaponFXComponent");
}

void AUSRifleWeapon::BeginPlay()
{
	Super::BeginPlay();

	check(WeaponFXComponent);
}

void AUSRifleWeapon::StartFire()
{
	GetWorldTimerManager().SetTimer(ShootTimerHandle, this, &AUSRifleWeapon::MakeShoot, TimeBetweenShoots, true);
	MakeShoot();
}

void AUSRifleWeapon::StopFire()
{
	GetWorldTimerManager().ClearTimer(ShootTimerHandle);
}

void AUSRifleWeapon::MakeShoot()
{
	if (!GetWorld() || IsAmmoEmpty())
	{
		StopFire();
		return;
	}

	FVector TraceStart, TraceEnd;
	if (!GetTraceData(TraceStart, TraceEnd))
	{
		StopFire();
		return;
	}

	FHitResult HitResult;
	MakeHit(HitResult, TraceStart, TraceEnd);
	FVector HitDirection = HitResult.ImpactPoint - GetMuzzleWorldLocation();

	if (HitResult.bBlockingHit && FVector::DotProduct(HitDirection, GetMuzzleWorldRotation().Vector()) > 0)
	{
		MakeDamage(HitResult);
		WeaponFXComponent->PlayImpactFX(HitResult);
	}
	else
	{
		DrawDebugLine(GetWorld(), GetMuzzleWorldLocation(), TraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);
	}

	DecreaseAmmo();
}

bool AUSRifleWeapon::GetTraceData(FVector& TraceStart, FVector& TraceEnd) const
{
	FVector ViewLocation;
	FRotator ViewRotation;
	if (!GetViewPoint(ViewLocation, ViewRotation))
		return false;

	TraceStart = ViewLocation;
	const auto HalfRad = FMath::DegreesToRadians(BulletSpread);
	const FVector ShootDirection = FMath::VRandCone(ViewRotation.Vector(), HalfRad);
	TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
	return true;
}

void AUSRifleWeapon::MakeDamage(const FHitResult& HitResult)
{
	const auto DamagedActor = HitResult.GetActor();
	if (!DamagedActor)
		return;

	DamagedActor->TakeDamage(DamageAmount, FDamageEvent{}, GetPlayerController(), this);
}