// Udemy Shooter Game. All Rights Reserved


#include "Pickups/USAmmoPickup.h"
#include "Components/USHealthComponent.h"
#include "Components/USWeaponComponent.h"
#include "USUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All);

bool AUSAmmoPickup::GivePickupTo(APawn* PlayerPawn)
{
	const auto HealthComponent = USUtils::GetUSPlayerComponent<UUSHealthComponent>(PlayerPawn);
	if (!HealthComponent || HealthComponent->IsDead())
		return false;

	const auto WeaponComponent = USUtils::GetUSPlayerComponent<UUSWeaponComponent>(PlayerPawn);
	if (!WeaponComponent)
		return false;

	return WeaponComponent->TryToAddAmmo(WeaponType, ClipsAmount);
}