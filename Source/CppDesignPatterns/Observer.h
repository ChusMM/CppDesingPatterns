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

#include "CoreMinimal.h"
#include "Event.h"
#include "Observer.generated.h"

// UE4 interface.
// More info at: https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/Reference/Interfaces/

// This class does not need to be modified.
UINTERFACE(BlueprintType)
class UObserver : public UInterface
{
	GENERATED_BODY()
};

// Add interface functions to this class. 
// This is the class that will be inherited to implement this interface.
class CPPDESIGNPATTERNS_API IObserver
{
	GENERATED_BODY()

public:
	virtual void OnNotify(UObject* Entity, EEvent Event) = 0;
};
