#ifndef DYNRPG_VARIABLES_H
#define DYNRPG_VARIABLES_H

#include <DynRPG/DStringPtr.h>

namespace RPG
{
/*! \brief Access to variable names.
	\sa RPG::variables::name(int)
	\sa RPG::variables
*/
class Variable
{
public:
	void** vTable;
	void** id; //!< Not needed since its index is used in RPG::variables
	DStringPtr name; //!< The name of the variable
};
}

#endif // DYNRPG_VARIABLES_H
