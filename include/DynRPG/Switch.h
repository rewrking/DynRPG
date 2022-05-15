#ifndef DYNRPG_SWITCH_H
#define DYNRPG_SWITCH_H

#include <DynRPG/DStringPtr.h>

namespace RPG
{
/*! \brief Access to switch names.
	\sa RPG::switches::name(int)
	\sa RPG::switches
*/
class Switch
{
public:
	void** vTable;
	void** id; //!< Not needed since its index is used in RPG::switches
	DStringPtr name; //!< The name of the switch
};
}

#endif // DYNRPG_SWITCH_H
