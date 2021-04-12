// Udemy Shooter Game. All Rights Reserved


#include "Pickups/USHealthPickup.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthPickup, All, All);

bool AUSHealthPickup::GivePickupTo(APawn* PlayerPawn)
{
	UE_LOG(LogHealthPickup, Display, TEXT("Health was taken"));
	return true;
}