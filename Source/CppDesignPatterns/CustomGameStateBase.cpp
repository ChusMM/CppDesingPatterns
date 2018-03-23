#include "CustomGameStateBase.h"
#include "AchievementManager.h"

UAchievementManager* ACustomGameStateBase::GetAchievementManager()
{
	// If the AchievementManager has not been instanced yet, instance it
	// 
	// Why don't we override the HandleBeginPlay()? Because we don't know
	// when that method will be executed, and we have to make sure the instance
	// exists before any other BeginPlay event
	if (!AchievementManager.IsValid()) {
		// Notice how UObjects must be instanced with the NewObject factory
		// method instead of "new".
		AchievementManager = NewObject<UAchievementManager>();
	}

	return AchievementManager.Get();
}