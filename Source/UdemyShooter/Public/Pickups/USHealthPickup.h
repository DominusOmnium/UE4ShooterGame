// Udemy Shooter Game. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Pickups/USBasePickup.h"
#include "USHealthPickup.generated.h"

UCLASS()
class UDEMYSHOOTER_API AUSHealthPickup : public AUSBasePickup
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup", meta = (ClampMin = "1.0", ClampMax = "100.0"))
	float HealthAmount = 100.0;
	
private:
	virtual bool GivePickupTo(APawn* PlayerPawn) override;
};
