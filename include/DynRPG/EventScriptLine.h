#ifndef DYNRPG_EVENT_SCRIPT_LINE_H
#define DYNRPG_EVENT_SCRIPT_LINE_H

#include <DynRPG/Enum/EventCommand.h>

#include <DynRPG/DArray.h>
#include <DynRPG/DStringPtr.h>

namespace RPG
{
/*! \brief Represents an event script line

	%Event script lines can have one string parameter and unlimited integer
	parameters.
*/
class DYNRPG_API EventScriptLine
{
public:
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

#endif // DYNRPG_EVENT_SCRIPT_LINE_H
