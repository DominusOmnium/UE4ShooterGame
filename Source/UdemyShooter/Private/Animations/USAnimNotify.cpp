// Udemy Shooter Game. All Rights Reserved


#include "Animations/USAnimNotify.h"

void UUSAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	OnNotified.Broadcast(MeshComp);
	Super::Notify(MeshComp, Animation);
}

