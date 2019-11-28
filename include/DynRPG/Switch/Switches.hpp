#ifndef RPG_SWITCHES_HPP
#define RPG_SWITCHES_HPP

#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/System/System.hpp>

namespace RPG
{
/*! \brief Provides easy access to in-game switches

	You may also use RPG::System::switches, but the RPG::Switches class
	will also tolerate negative indexes and is less to type.
	\sa RPG::switches
*/
struct Switches
{
	//! Array access operator
	inline bool& operator[](int index)
	{
		if (index > 0)
			return system->switches[index];
		return dummy = false;
	}

	//! \cond
	bool dummy;
	//! \endcond

	/*! \brief Gets the name of a switch
		\return The name of the switch
	*/
	static DStringPtr name(int index);
};

/*! \ingroup game_objects
	\brief %Switches array
*/
static Switches switches __attribute__((unused));

}

#endif // RPG_SWITCHES_HPP