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

// Forward declare it for the Achievement class to know it.
// This is done this way, so new achievement types can be added
// at the end of this file (in the enum).
enum class EAchievement : uint8;

class Achievement 
{
public:
	Achievement(EAchievement AchievementType);

	EAchievement GetType() const;
	const FName& GetDescription() const;

	// This method could be overriden in child classes
	// to implement the custom behaviour of the concrete
	// achievement
	virtual void RunBehaviour();

private:
	FName Description;
	EAchievement AchievementType;
};

enum class EAchievement : uint8
{
	ACHIEVEMENT_GOT_FIVE_PEARS,
	ACHIEVEMENT_GOT_FIVE_LOLLIPOPS,
	ACHIEVEMENT_GOT_FIVE_ICECREAMS,

	// Used to retrieve the number of elements in the enum
	LAST_ACHIEVEMENT
};