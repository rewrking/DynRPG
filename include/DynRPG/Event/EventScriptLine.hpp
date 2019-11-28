#ifndef RPG_EVENT_SCRIPT_LINE_HPP
#define RPG_EVENT_SCRIPT_LINE_HPP

#include <DynRPG/Delphi/DArray.hpp>
#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/Event/EventCommand.hpp>

namespace RPG
{

/*! \brief Represents an event script line

	%Event script lines can have one string parameter and unlimited integer
	parameters.
*/
struct EventScriptLine
{
	void** vTable;
	EventCommand command; //!< The command type
	int treeDepth; //!< The level of indention (\c 0 for none)
	DStringPtr stringParameter; //!< The string parameter
	DArray<int> parameters; //!< The integer parameters

	/*! \brief Returns an integer parameter (\c 0 if the parameter doesn't exist)
		\param index Parameter index (zero-based)
		\return The parameter's value or \c 0 if the parameter doesn't exist
	*/
	int parameter(int index);
};
}

#endif // RPG_EVENT_SCRIPT_LINE_HPP
