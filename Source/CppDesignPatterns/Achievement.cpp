#include "Achievement.h"
#include "Public/Engine.h"

// This is done with just a 'switch' to keep it simple.  Alternative solutions:
//  - Hierarchy of achievements based on inheritance with custom behaviour
//  - Data driven achievements defined in some textual format (eg. xml, json, etc)
Achievement::Achievement(EAchievement AchievementType)
{
	this->AchievementType = AchievementType;

	switch (AchievementType) {
	case EAchievement::ACHIEVEMENT_GOT_FIVE_PEARS:
		this->Description = TEXT("[Achievement unlocked] Got five pears!");
		break;
	case EAchievement::ACHIEVEMENT_GOT_FIVE_LOLLIPOPS:
		this->Description = TEXT("[Achievement unlocked] Got five lollipops!");
		break;
	case EAchievement::ACHIEVEMENT_GOT_FIVE_ICECREAMS:
		this->Description = TEXT("[Achievement unlocked] Got five ice creams!");
		break;
	}
}

EAchievement Achievement::GetType() const
{
	return AchievementType;
}

const FName& Achievement::GetDescription() const
{
	return Description;
}

void Achievement::RunBehaviour()
{
	// Do something with the achievement.
	// For example, print it to the viewport, reward the player with something, etc.
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Emerald, GetDescription().ToString());
}
