#ifndef DYNRPG_DB_VARIABLE_H
#define DYNRPG_DB_VARIABLE_H

#include <DynRPG/DArray.h>
#include <DynRPG/DStringPtr.h>
#include <DynRPG/System.h>

namespace RPG
{
/*! \brief Access to variable names.
	\sa RPG::variables::name(int)
	\sa RPG::variables
*/
class DbVariable
{
public:
	void** vTable;
	void** id; //!< Not needed since its index is used in RPG::variables
	DStringPtr name; //!< The name of the variable
};
}

#endif // DYNRPG_DB_VARIABLE_H