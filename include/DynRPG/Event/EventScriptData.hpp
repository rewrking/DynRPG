#ifndef RPG_EVENT_SCRIPT_DATA_HPP
#define RPG_EVENT_SCRIPT_DATA_HPP

#include <DynRPG/Event/EventScriptLine.hpp>
#include <DynRPG/Event/EventScriptList.hpp>

namespace RPG
{
//! Class used for the event script data of an event
struct EventScriptData
{
	// clang-format off
	void** vTable;
		int _unknown_4;
		int _unknown_8;
		int _unknown_C;
		int _unknown_10;
	EventScriptList* lines; //!< %Event script lines
	int currentLineId; //!< Current line number
	// clang-format on

	/*! \brief Returns a certain RPG::EventScriptLine
		\param index Line number (zero-based)
		\return %Event script line pointer
	*/
	EventScriptLine* line(int index);
};
}

#endif // RPG_EVENT_SCRIPT_DATA_HPP
