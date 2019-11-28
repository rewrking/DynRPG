#ifndef RPG_SWITCH_HPP
#define RPG_SWITCH_HPP

#include <DynRPG/Delphi/DStringPtr.hpp>

namespace RPG
{
/*! \brief Access to switch names.
	\sa RPG::switches::name(int)
	\sa RPG::switches
*/
struct Switch
{
	void** vTable;
	void** id; //!< Not needed since its index is used in RPG::switches
	DStringPtr name; //!< The name of the switch
};
}

#endif // RPG_SWITCH_HPP
