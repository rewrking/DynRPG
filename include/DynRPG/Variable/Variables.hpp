#ifndef RPG_VARIABLES_HPP
#define RPG_VARIABLES_HPP

#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/System/System.hpp>

namespace RPG
{

/*! \brief Provides easy access to in-game variables

	You may also use RPG::System::variables, but the RPG::Variables class
	will also tolerate negative indexes and is less to type.
	\sa RPG::variables
*/
struct Variables
{
	//! Array access operator
	inline int& operator[](int index)
	{
		if (index > 0)
			return system->variables[index];
		return dummy = 0;
	}

	//! \cond
	int dummy;
	//! \endcond

	/*! \brief Gets the name of a variable
		\return The name of the variable
	*/
	DStringPtr name(int index);
};

/*! \ingroup game_objects
	\brief %Variables array
*/
static Variables variables __attribute__((unused));
}

#endif // RPG_VARIABLES_HPP