#include "AchievementManager.h"

bool UAchievementManager::Instantiated_ = false;

UAchievementManager::UAchievementManager()
{
	// Check if the class is being created as a CDO (i.e., at the editor startup).
	// If that's the case, we allow its creation without affecting the only-one-instance behaviour.
	if (!HasAnyFlags(RF_ClassDefaultObject)) {
		verifyf(!Instantiated_, TEXT("Trying to instance more than one class of UAchievementManager"));
		Instantiated_ = true;
	}

	EventsCounter.Add(EEvent::EVENT_GET_PEAR, 0);
	EventsCounter.Add(EEvent::EVENT_GET_LOLLIPOP, 0);
	EventsCounter.Add(EEvent::EVENT_GET_ICECREAM, 0);
}

UAchievementManager::~UAchievementManager()
{
	Instantiated_ = false;
}

void UAchievementManager::OnNotify(UObject* Entity, EEvent Event)
{
	switch (Event) {
	case EEvent::EVENT_GET_PEAR:
		IncreaseEventCounter(Event);
		if (EventsCounter[Event] == 5) {
			Unlock(EAchievement::ACHIEVEMENT_GOT_FIVE_PEARS);
		}
		break;
	case EEvent::EVENT_GET_LOLLIPOP:
		IncreaseEventCounter(Event);
		if (EventsCounter[Event] == 5) {
			Unlock(EAchievement::ACHIEVEMENT_GOT_FIVE_LOLLIPOPS);
		}
		break;
	case EEvent::EVENT_GET_ICECREAM:
		IncreaseEventCounter(Event);
			if (EventsCounter[Event] == 5) {
				Unlock(EAchievement::ACHIEVEMENT_GOT_FIVE_ICECREAMS);
			}
			break;
	}
}

void UAchievementManager::IncreaseEventCounter(EEvent Event)
{
	// We need to keep a counter of the number of events that have arriven,
	// in order to unlock the appropriate achievements.
	// But we do not need to increase EVERY event; just the ones related to
	// the achievements.
	EventsCounter.Add(Event, ++EventsCounter[Event]);
}

void UAchievementManager::Unlock(EAchievement AchievementType)
{
	// Save the achievement by its type, just in case we want to do something
	// with it in the future
	Achievement CurrentAchievement = Achievement(AchievementType);
	Achievements.Add(AchievementType, CurrentAchievement);

	// Run the achievement custom behaviour
	CurrentAchievement.RunBehaviour();
}
