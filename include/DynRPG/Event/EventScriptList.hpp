#ifndef RPG_EVENT_SCRIPT_LIST_HPP
#define RPG_EVENT_SCRIPT_LIST_HPP

#include <DynRPG/Delphi/DList.hpp>
#include <DynRPG/Event/EventScriptLine.hpp>

namespace RPG
{
/*! \brief List of event script lines
	\note Do not ask me why this class is there, I didn't invent it.
*/
struct EventScriptList
{
	void** vTable;
	DList<EventScriptLine*>* list; //!< The actual RPG::DList
};
}

#endif // RPG_EVENT_SCRIPT_LIST_HPP
