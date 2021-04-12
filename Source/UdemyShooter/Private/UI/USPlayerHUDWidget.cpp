// Udemy Shooter Game. All Rights Reserved

#include "UI/USPlayerHUDWidget.h"
#include "Components/USHealthComponent.h"
#include "Components/USWeaponComponent.h"
#include "USUtils.h"

float UUSPlayerHUDWidget::GetHealthPercent() const
{
	const auto HealthComponent = USUtils::GetUSPlayerComponent<UUSHealthComponent>(GetOwningPlayerPawn());
	if (!HealthComponent)
		return 0.0f;

	return HealthComponent->GetHealthPercent();
}

bool UUSPlayerHUDWidget::GetCurrentWeaponUIData(FWeaponUIData& UIData) const
{
	const auto WeaponComponent = USUtils::GetUSPlayerComponent<UUSWeaponComponent>(GetOwningPlayerPawn());
	if (!WeaponComponent)
		return false;

	return WeaponComponent->GetCurrentWeaponUIData(UIData);
}

bool UUSPlayerHUDWidget::GetCurrentWeaponAmmoData(FAmmoData& AmmoData) const
{
	const auto WeaponComponent = USUtils::GetUSPlayerComponent<UUSWeaponComponent>(GetOwningPlayerPawn());
	if (!WeaponComponent)
		return false;

	return WeaponComponent->GetCurrentWeaponAmmoData(AmmoData);
}

bool UUSPlayerHUDWidget::IsPlayerAlive() const
{
	const auto HealthComponent = USUtils::GetUSPlayerComponent<UUSHealthComponent>(GetOwningPlayerPawn());
	return HealthComponent && !HealthComponent->IsDead();
}

bool UUSPlayerHUDWidget::IsPlayerSpectating() const
{
	const auto Controller = GetOwningPlayer();
	return Controller && Controller->GetStateName() == NAME_Spectating;
}