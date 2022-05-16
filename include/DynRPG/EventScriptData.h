#ifndef DYNRPG_EVENT_SCRIPT_DATA_H
#define DYNRPG_EVENT_SCRIPT_DATA_H

#include <DynRPG/EventScriptLine.h>
#include <DynRPG/EventScriptList.h>

namespace RPG
{

//! Class used for the event script data of an event
class DYNRPG_API EventScriptData
{
public:
	void** vTable;
	int _unknown_4;
	int _unknown_8;
	int _unknown_C;
	int _unknown_10;
	EventScriptList* lines; //!< %Event script lines
	int currentLineId; //!< Current line number

	/*! \brief Returns a certain RPG::EventScriptLine
		\param index Line number (zero-based)
		\return %Event script line pointer
	*/
	RPG::EventScriptLine* line(int index);
};
}

#endif // DYNRPG_EVENT_SCRIPT_DATA_H
