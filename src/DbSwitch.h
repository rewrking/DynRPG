#ifndef DYNRPG_DB_SWITCH_H
#define DYNRPG_DB_SWITCH_H

#include <DynRPG/DArray.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/System.h>

namespace RPG
{
/*! \brief Access to switch names.
	\sa RPG::switches::name(int)
	\sa RPG::switches
*/
class DbSwitch
{
public:
	void** vTable;
	void** id; //!< Not needed since its index is used in RPG::switches
	DStringPtr name; //!< The name of the switch
};
}

#endif // DYNRPG_DB_SWITCH_H
