/*********************************************************************
* Module 1. Programming Foundations
* Author: Santiago S�nchez Sobrino   Santiago.Sanchez@uclm.es
*         David Vallejo Fern�ndez    David.Vallejo@uclm.es
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

UENUM(BlueprintType)
enum class EEvent : uint8
{
	EVENT_GET_PEAR      UMETA(DisplayName = "Event: Get Pear"),
	EVENT_GET_LOLLIPOP  UMETA(DisplayName = "Event: Get Lollipop"),
	EVENT_GET_ICECREAM  UMETA(DisplayName = "Event: Get Ice Cream"),

	// Used to retrieve the number of elements in the enum
	LAST_EVENT          UMETA(Hidden)
};