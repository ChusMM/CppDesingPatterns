/*********************************************************************
* Module 1. Programming Foundations
* Author: Santiago Sánchez Sobrino   Santiago.Sanchez@uclm.es
*         David Vallejo Fernández    David.Vallejo@uclm.es
*
* You can redistribute and/or modify this file under the terms of the
* GNU General Public License ad published by the Free Software
* Foundation, either version 3 of the License, or (at your option)
* and later version. See <http://www.gnu.org/licenses/>.
*
* This file is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*********************************************************************/

#pragma once

#include "Observer.h"
#include "Achievement.h"
#include "AchievementManager.generated.h"

// UObjects enable multiple inheritance ONLY for UInterfaces
UCLASS()
class CPPDESIGNPATTERNS_API UAchievementManager : public UObject, public IObserver
{
	GENERATED_BODY()

public:
	UAchievementManager();
	~UAchievementManager();

	void OnNotify(UObject* Entity, EEvent Event) override;

private:
	void IncreaseEventCounter(EEvent Event);
	void Unlock(EAchievement AchievementType);

private:
	TMap<EEvent, uint32> EventsCounter;
	TMap<EAchievement, Achievement> Achievements;

	static bool Instantiated_;
};
