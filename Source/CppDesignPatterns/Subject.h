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

#include "Containers/Array.h"
#include "Event.h"
#include "Subject.generated.h"

class IObserver;

UCLASS(BlueprintType)
class CPPDESIGNPATTERNS_API USubject : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Observer Pattern")
	void AddObserver(TScriptInterface<IObserver> Observer);

	UFUNCTION(BlueprintCallable, Category = "Observer Pattern")
	void RemoveObserver(TScriptInterface<IObserver> Observer);

protected:
	UFUNCTION(BlueprintCallable, Category = "Observer Pattern")
	void Notify(UObject* Entity, EEvent Event);

private:
	// UINTERFACES generate their destructor private,
	// so shared pointer can't access it to manage its life cycle,
	// thus giving us an error at compile time if we try to use them.
	TArray<IObserver*> Observers;
};
