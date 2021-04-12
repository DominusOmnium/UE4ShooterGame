// Udemy Shooter Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "USAnimNotify.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnNitifiedSignature, USkeletalMeshComponent*);

UCLASS()
class UDEMYSHOOTER_API UUSAnimNotify : public UAnimNotify
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	FOnNitifiedSignature OnNotified;
};
