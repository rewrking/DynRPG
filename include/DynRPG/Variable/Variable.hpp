#ifndef RPG_VARIABLE_HPP
#define RPG_VARIABLE_HPP

#include <DynRPG/Delphi/DStringPtr.hpp>

namespace RPG
{
/*! \brief Access to variable names.
	\sa RPG::variables::name(int)
	\sa RPG::variables
*/
struct Variable
{
	void** vTable;
	void** id; //!< Not needed since its index is used in RPG::variables
	DStringPtr name; //!< The name of the variable
};
}

#endif // RPG_VARIABLE_HPP
