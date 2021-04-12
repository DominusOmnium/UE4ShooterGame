// Udemy Shooter Game. All Rights Reserved


#include "Components/USCharacterMovementComponent.h"
#include "Player/USBaseCharacter.h"

float UUSCharacterMovementComponent::GetMaxSpeed() const
{
	const float MaxSpeed = Super::GetMaxSpeed();
	const AUSBaseCharacter *Player = Cast<AUSBaseCharacter>(GetPawnOwner());
	return Player && Player->IsRunning() ? MaxSpeed * RunModifier : MaxSpeed;
}