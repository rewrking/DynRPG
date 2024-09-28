#ifndef DYNRPG_VARIABLES_H
#define DYNRPG_VARIABLES_H

#include <DynRPG/DArray.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/System.h>

namespace RPG
{
/*! \brief Provides easy access to in-game variables
	You may also use RPG::System::variables, but the RPG::Variables class
	will also tolerate negative indexes and is less to type.
	\sa RPG::variables
*/
class Variables
{
public:
	//! Array access operator
	inline int& operator[](int index)
	{
		if (index > 0)
			return RPG::system->variables[index];

		return dummy = 0;
	}

	//! \cond
	int dummy;
	//! \endcond
};

/*! \ingroup game_objects
	\brief %Variables array
*/
extern DYNRPG_API RPG::Variables variables;
}

#endif // DYNRPG_VARIABLES_H
