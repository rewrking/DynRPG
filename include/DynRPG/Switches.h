#ifndef DYNRPG_SWITCH_H
#define DYNRPG_SWITCH_H

#include <DynRPG/DArray.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/System.h>

namespace RPG
{
/*! \brief Provides easy access to in-game switches
	You may also use RPG::System::switches, but the RPG::Switches class
	will also tolerate negative indexes and is less to type.
	\sa RPG::switches
*/
class Switches
{
public:
	//! Array access operator
	inline bool& operator[](int index)
	{
		if (index > 0)
			return RPG::system->switches[index];

		return dummy = false;
	}

	//! \cond
	bool dummy;
	//! \endcond
};

/*! \ingroup game_objects
	\brief %Switches array
*/
extern DYNRPG_API Switches switches;
}

#endif // DYNRPG_SWITCH_H
