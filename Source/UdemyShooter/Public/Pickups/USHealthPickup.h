// Udemy Shooter Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Pickups/USBasePickup.h"
#include "USHealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class UDEMYSHOOTER_API AUSHealthPickup : public AUSBasePickup
{
	GENERATED_BODY()
	
private:
	virtual bool GivePickupTo(APawn* PlayerPawn) override;
};
