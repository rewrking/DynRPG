#ifndef DYNRPG_EVENT_SCRIPT_LIST_H
#define DYNRPG_EVENT_SCRIPT_LIST_H

#include <DynRPG/DList.h>
#include <DynRPG/EventScriptLine.h>

namespace RPG
{
/*! \brief List of event script lines
	\note Do not ask me why this class is there, I didn't invent it.
*/
class EventScriptList
{
public:
	void** vTable;
	DList<EventScriptLine*>* list; //!< The actual RPG::DList
};
}

#endif // DYNRPG_EVENT_SCRIPT_LIST_H
