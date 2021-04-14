// Udemy Shooter Game. All Rights Reserved

#include "Weapon/Components/USWeaponFXComponent.h"
#include "NiagaraFunctionLibrary.h"

UUSWeaponFXComponent::UUSWeaponFXComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UUSWeaponFXComponent::PlayImpactFX(const FHitResult& Hit)
{
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Effect, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());
}
